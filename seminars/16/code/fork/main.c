#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {

    pid_t p_fork;

    // Set buffer with some data
    // printf("Cached ");

    if ((p_fork = fork()) < 0) {
        printf("Failed...\n");
        exit(1);
    } else if (p_fork == 0) {
        // Sleep for 1s
        sleep(1);
        printf("In child...\n");
    } else {
        printf("In parent...\n");
    }

    pid_t pid, ppid;
    pid = getpid();
    ppid = getppid();
    printf("PID: %d\nPPID: %d\n", pid, ppid);

    sleep(3);

    return 0;
}
