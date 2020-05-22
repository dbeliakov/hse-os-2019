#include <sys/timerfd.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <unistd.h>

int main() {
    int tfd = timerfd_create(CLOCK_REALTIME, 0);
    struct itimerspec spec = {};
    spec.it_value.tv_sec = 5;
    if (timerfd_settime(tfd, 0, &spec, NULL) < 0) {
        exit(1);
    }
    uint64_t count;
    if (read(tfd, &count, sizeof count) < 0) {
        exit(1);
    }
    printf("Timer!\n");

    return 0;
}
