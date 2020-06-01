#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int counter = 0;
_Atomic int atomic_counter = 0;

enum { THREADS_COUNT = 10 };
enum { ITERATIONS = 100000 };

void* incrementer(void* ptr) {
    (void)ptr;
    for (int i = 0; i < ITERATIONS; ++i) {
        ++counter;
        ++atomic_counter;
    }
    return NULL;
}

int main()
{
    pthread_t threads[THREADS_COUNT];
    for (int i = 0; i < THREADS_COUNT; ++i) {
        if (pthread_create(&threads[i], NULL, incrementer, NULL) != 0) {
            exit(1);
        }
    }
    for (int i = 0; i < THREADS_COUNT; ++i) {
        pthread_join(threads[i], NULL);
    }
    printf("Counter: %d\n", counter);
    printf("Atomic counter: %d\n", atomic_counter);
    return 0;
}
