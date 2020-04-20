#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    int pid1, pid2;
    if (pipe(fd) < 0) {
        perror("pipe");
        exit(1);
    }

    if ((pid1 = fork()) < 0) {
        perror("fork");
        exit(1);
    }
    if (!pid1) {
        /* child 1: "ls -l" */
        dup2(fd[1], 1);
        close(fd[0]);
        close(fd[1]);
        execlp("ls", "ls", "-l", NULL);
        perror("execlp");
        _exit(1);
    }

    if ((pid2 = fork()) < 0) {
        perror("fork");
        exit(1);
    }
    if (!pid2) {
        /* child 2: "wc -l" */
        dup2(fd[0], 0);
        close(fd[0]);
        close(fd[1]);
        execlp("wc", "wc", "-l", NULL);
        perror("execlp");
        _exit(1);
    }

    close(fd[0]);
    close(fd[1]);
    wait(NULL);
    wait(NULL);
    return 0;
}
