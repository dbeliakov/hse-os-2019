#include <stdio.h>
#include <pthread.h>

enum { THREADS_COUNT = 4 };
enum { ITERATIONS = 20 };

void* increment(void* ptr) {
    int num = *(int*)ptr;
    for (int i = 0; i < ITERATIONS; ++i) {
        printf("Hello from %d thread!\n", num);
        sched_yield();
    }
    return NULL;
}

int main() {
    pthread_t threads[THREADS_COUNT];
    int nums[THREADS_COUNT];
    for (int i = 0; i < THREADS_COUNT; ++i) {
        nums[i] = i + 1;
        pthread_create(&threads[i], NULL, increment, &nums[i]);
    }
    for (int i = 0; i < THREADS_COUNT; ++i) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}
