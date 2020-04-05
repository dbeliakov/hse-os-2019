#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    pid_t p_fork;
    if ((p_fork = fork()) < 0) {
        exit(1);
    } else if (p_fork == 0) {
        char * args[] = {"date"};
        execve("/bin/date", args, NULL);
        exit(1);
    }

    int status;
    if (wait(&status) < 0 || !WIFEXITED(status) || WEXITSTATUS(status) != 0) {
        exit(1);
    }
    exit(0);
}
