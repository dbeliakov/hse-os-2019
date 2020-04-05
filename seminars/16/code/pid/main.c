#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = getpid();
    pid_t ppid = getppid();

    printf("PID: %d\nPPID: %d\n", pid, ppid);

    return 0;
}
