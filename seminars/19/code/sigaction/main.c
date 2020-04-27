#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int cnt = 0;
volatile int flag = 0;

struct sigaction orig_sigint_handler;

void sigint_handler(int signo)
{
    (void)signo;
    flag = 1;
    if (++cnt == 3) {
        sigaction(SIGINT, &orig_sigint_handler, NULL);
        raise(SIGINT);
    }
}


int main(void)
{
    struct sigaction sa;
    sa.sa_handler = sigint_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
    sigaction(SIGINT, &sa, &orig_sigint_handler);

    while (1) {
        if (flag) {
            printf("Ctrl-C pressed\n");
            flag = 0;
        } else {
            printf("Some string to print\n");
            sleep(1);
        }
    }
    return 0;
}

