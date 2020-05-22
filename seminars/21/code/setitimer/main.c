#include <sys/time.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

enum {
    SECOND = 1000,
};

void on_timer(int sig) {
    exit(0);
}

int main() {
    const int64_t timeout = 5 * SECOND;

    signal(SIGALRM, on_timer);
    signal(SIGVTALRM, on_timer);
    signal(SIGPROF, on_timer);

    struct itimerval to = {};
    to.it_value.tv_sec = timeout / SECOND;
    to.it_value.tv_usec = (timeout % SECOND) * SECOND;
    setitimer(ITIMER_REAL, &to, NULL);

    for (;;) {
        pause();
    }

    return 0;
}
