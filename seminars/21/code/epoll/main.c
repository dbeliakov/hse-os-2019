#include <stdio.h>
#include <sys/epoll.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int efd = epoll_create1(0);
    if (efd < 0) {
        exit(0);
    }
    struct epoll_event event = {};
    event.events = EPOLLIN;
    event.data.fd = STDIN_FILENO;
    if (epoll_ctl(efd, EPOLL_CTL_ADD, STDIN_FILENO, &event) < 0) {
        exit(1);
    }

    struct epoll_event events[1];
    for (;;) {
        int count;
        if ((count = epoll_pwait(efd, events, 1, -1, NULL)) < 0) {
            exit(1);
        }
        for (int i = 0; i < count; i++) {
            struct epoll_event e = events[i];
            if (e.events & EPOLLIN == 0) {
                continue;
            }
            uint8_t buf[1024];
            int readed;
            if ((readed = read(STDIN_FILENO, buf, 1024)) < 0) {
                exit(1);
            }
            if (readed == 0) {
                printf("CLOSED!\n");
                exit(1);
            }
            printf("DATA!\n");
        }
    }
    return 0;
}
