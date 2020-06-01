#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int counter = 0;
int safe_counter = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

enum { THREADS_COUNT = 10 };
enum { ITERATIONS = 1000000 };

void* incrementer(void* ptr) {
    (void)ptr;
    for (int i = 0; i < ITERATIONS; ++i) {
        ++counter;
        pthread_mutex_lock(&mutex);
        ++safe_counter;
        pthread_mutex_unlock(&mutex);
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
    printf("Safe counter: %d\n", safe_counter);
    return 0;
}
