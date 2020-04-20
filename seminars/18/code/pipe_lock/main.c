#include <unistd.h>
#include <fcntl.h>
#include <inttypes.h>
#include <sys/wait.h>
#include <stdio.h>

int pfd[2];

void increment()
{
    for (int i = 0; i < 1000; ++i) {
        uint8_t ticket;
        int count = read(pfd[0], &ticket, sizeof(ticket));
        if (count != sizeof(ticket)) {
            _exit(1);
        }

        int fd = open("test.txt", O_RDWR);
        if (fd < 0) {
            fprintf(stderr, "Cannot open file");
            _exit(1);
        }

        uint32_t value;
        count = read(fd, &value, sizeof(value));
        if (count != sizeof(value)) {
            close(fd);
            fprintf(stderr, "Cannot read: count == %d", count);
            _exit(1);
        }
        ++value;

        int pos = lseek(fd, 0, SEEK_SET);
        if (pos < 0) {
            close(fd);
            fprintf(stderr, "Cannot lseek");
            _exit(1);
        }
        count = write(fd, &value, sizeof(value));
        if (count != sizeof(value)) {
            close(fd);
            fprintf(stderr, "Cannot write: count == %d", count);
            _exit(1);
        }
        close(fd);

        count = write(pfd[1], &ticket, sizeof(ticket));
        if (count != sizeof(ticket)) {
            _exit(1);
        }
    }
    _exit(0);
}

void create_incrementer() {
    int pid = fork();
    if (pid < 0) {
        _exit(1);
    }
    if (pid > 0) {
        // In parent
        return;
    }
    increment();
}

void print_value() {
    int fd = open("test.txt", O_RDWR);
    if (fd < 0) {
        fprintf(stderr, "Cannot open file");
        _exit(1);
    }
    uint32_t value;
    int count = read(fd, &value, sizeof(value));
    if (count != sizeof(value)) {
        close(fd);
        fprintf(stderr, "Cannot read: count == %d", count);
        _exit(1);
    }
    printf("Value == %" PRId32 "\n", value);
    close(fd);
}

int main()
{
    if (pipe(pfd) < 0) {
        _exit(1);
    }
    for (int i = 0; i < 2; ++i) {
        create_incrementer();
    }
    uint8_t start = 0;
    int count = write(pfd[1], &start, sizeof(start));
    if (count != sizeof(start)) {
        return 1;
    }
    for (int i = 0; i < 2; ++i) {
        int status;
        wait(&status);
        if (!WIFEXITED(status) || WEXITSTATUS(status) != 0) {
            fprintf(stderr, "Failure. Exit status == %d\n", WEXITSTATUS(status));
            return 1;
        }
    }
    print_value();
    return 0;
}
