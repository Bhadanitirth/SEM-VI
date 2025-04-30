#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define SIZE 3

int buffer[SIZE];
int in = 0, out = 0;
int count = 0;

pthread_mutex_t mutex;

void* producer(void* arg) {
    int item;
    for (int i = 0; i < 10; i++) {
        item = rand() % 100;

        // while (1) {
            pthread_mutex_lock(&mutex);
            if (count < SIZE) {
                buffer[in] = item;
                in = (in + 1) % SIZE;
                count++;
                printf("Producer produced: %d\n", item);
                pthread_mutex_unlock(&mutex);
                // break;
            }
            pthread_mutex_unlock(&mutex);
            // Busy wait
        //     usleep(100000); // 0.1 sec
        // }

        sleep(1);
    }
    return NULL;
}

void* consumer(void* arg) {
    int item;
    for (int i = 0; i < 5; i++) {
        // while (1) {
            pthread_mutex_lock(&mutex);
            if (count > 0) {
                item = buffer[out];
                out = (out + 1) % SIZE;
                count--;
                printf("Consumer consumed: %d\n", item);
                pthread_mutex_unlock(&mutex);
                // break;
            }
            pthread_mutex_unlock(&mutex);
            // Busy wait
        //     usleep(100000); // 0.1 sec
        // }

        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t prod, cons;

    pthread_mutex_init(&mutex, NULL);

    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    pthread_mutex_destroy(&mutex);

    return 0;
}
