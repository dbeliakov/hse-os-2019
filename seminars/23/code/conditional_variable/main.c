#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

int counter = 0;

bool need_increment = false;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

enum { THREADS_COUNT = 10 };
enum { ITERATIONS = 10000 };

void* producer(void* ptr) {
    (void)ptr;
    for (int i = 0; i < ITERATIONS; ++i) {
        sleep(1);
        pthread_mutex_lock(&mutex);
        need_increment = true;
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void* consumer(void* ptr) {
    (void)ptr;
    pthread_mutex_lock(&mutex);
    for (;;) {
        while (!need_increment) {
            pthread_cond_wait(&cond, &mutex);
        }
        need_increment = false;
        ++counter;
        printf("New counter value: %d\n", counter);
    }
    // Unreachable
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main()
{
    pthread_t t1, t2;
    if (pthread_create(&t1, NULL, producer, NULL) != 0) {
        exit(1);
    }
    if (pthread_create(&t2, NULL, consumer, NULL) != 0) {
        exit(1);
    }
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}
