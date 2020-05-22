#include <sys/time.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

enum {
    SECOND = 1000,
};

volatile int counter = 0;

void on_timer(int sig) {
    printf("Timer!\n");
    ++counter;
    if (counter >= 5) {
        exit(0);
    }
    struct itimerval val;
    if (getitimer(ITIMER_REAL, &val) < 0) {
        exit(1);
    }
    val.it_interval.tv_sec *= 2;
    if (setitimer(ITIMER_REAL, &val, NULL) < 0) {
        exit(1);
    }
}

int main() {
    const int64_t timeout = 1 * SECOND;

    signal(SIGALRM, on_timer);

    struct itimerval to = {};
    to.it_value.tv_sec = timeout / SECOND;
    to.it_value.tv_usec = (timeout % SECOND) * SECOND;
    to.it_interval.tv_sec = 2 * timeout / SECOND;

    setitimer(ITIMER_REAL, &to, NULL);

    for (;;) {
        pause();
    }

    return 0;
}
