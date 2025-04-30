#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

int *buffer;
int in = 0, out = 0;
int count = 0;
int SIZE;

pthread_mutex_t mutex;

void displayBuffer() {
    printf("Current Buffer: ");
    if (count == 0) {
        printf("Empty\n");
        return;
    }
    int i = out;
    for (int j = 0; j < count; j++) {
        printf("%d ", buffer[i]);
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

void* producer_consumer(void* arg) {
    char command;
    int item;

    while (1) {
        printf("\nEnter command (s: produce, c: consume, e: exit): ");
        scanf(" %c", &command);

        pthread_mutex_lock(&mutex);

        if (command == 's') {
            if (count < SIZE) {
                printf("Enter item to produce: ");
                scanf("%d", &item);
                buffer[in] = item;
                in = (in + 1) % SIZE;
                count++;
                printf("Produced: %d\n", item);
            } else {
                printf("Buffer is full! Cannot produce.\n");
            }
        } else if (command == 'c') {
            if (count > 0) {
                item = buffer[out];
                out = (out + 1) % SIZE;
                count--;
                printf("Consumed: %d\n", item);
            } else {
                printf("Buffer is empty! Cannot consume.\n");
            }
        } else if (command == 'e') {
            pthread_mutex_unlock(&mutex);
            break;
        } else {
            printf("Invalid command! Use s/c/e only.\n");
        }

        displayBuffer();
        pthread_mutex_unlock(&mutex);

        usleep(100000); // slight sleep to avoid hogging CPU
    }
    return NULL;
}

int main() {
    pthread_t thread;

    printf("Enter buffer size: ");
    scanf("%d", &SIZE);

    buffer = (int*) malloc(SIZE * sizeof(int));

    pthread_mutex_init(&mutex, NULL);

    pthread_create(&thread, NULL, producer_consumer, NULL);

    pthread_join(thread, NULL);

    pthread_mutex_destroy(&mutex);
    free(buffer);

    printf("Program exited successfully.\n");
    return 0;
}
