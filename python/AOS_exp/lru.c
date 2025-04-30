#include <stdio.h>

int main() {
    int a[9] = {1, 2, 3, 4, 5, 3, 2, 4, 5}; // Page requests
    int b[3] = {-1, -1, -1};            // Cache initialized to empty
    int n = 9;
    int capacity = 3;
    int pointer = 0; // To track LRU position
    int hits = 0, misses = 0;

    for (int i = 0; i < n; i++) {
        int page = a[i];
        int found = 0;

        // Check for HIT
        for (int j = 0; j < capacity; j++) {
            if (b[j] == page) {
                found = 1;
                hits++;
                printf("\nPage %d: HIT", page);
                break;
            }
        }

        // On MISS
        if (!found) {
            misses++;
            printf("\nPage %d: MISS", page);
            b[pointer] = page;
            pointer = (pointer + 1) % capacity; // Move to next replaceable position
        }

        // Print cache
        printf("\nCache: ");
        for (int j = 0; j < capacity; j++) {
            printf("%d ", b[j]);
        }
        printf("\n");
    }

    printf("\nTotal Hits: %d", hits);
    printf("\nTotal Misses: %d\n", misses);

    return 0;
}
