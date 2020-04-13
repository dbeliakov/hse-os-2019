#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(void)
{
	int pid, fd;
    pid = fork();
    if (!pid) {
	    chdir("/usr/bin");
        fd = open("/tmp/log.txt", O_WRONLY | O_CREAT | O_TRUNC, 0600);
        dup2(fd, 1);
        close(fd);
	    execlp("/bin/ls", "/bin/ls", "-l", NULL);
        fprintf(stderr, "Exec failed\n");
        _exit(1);
    }
    wait(NULL);
    return 0;
}
