#include <unistd.h>
#include <fcntl.h>
#include <inttypes.h>
#include <sys/wait.h>
#include <stdio.h>
#include <errno.h>

void increment()
{
    for (int i = 0; i < 1000; ++i) {
        int fl;
        for (;;) {
            errno = 0;
            fl = open("test.lock", O_CREAT | O_EXCL | O_RDWR, 0600);
            if (fl > 0) {
                // Lock created
                break;
            }
            if (errno != EEXIST) {
                fprintf(stderr, "Cannot create lock");
                _exit(1);
            }
            usleep(1);
        }

        int fd = open("test.txt", O_RDWR);
        if (fd < 0) {
            fprintf(stderr, "Cannot open file");
            close(fl);
            unlink("test.lock");
            _exit(1);
        }

        uint32_t value;
        int count = read(fd, &value, sizeof(value));
        if (count != sizeof(value)) {
            close(fd);
            close(fl);
            unlink("test.lock");
            fprintf(stderr, "Cannot read: count == %d", count);
            _exit(1);
        }
        ++value;

        int pos = lseek(fd, 0, SEEK_SET);
        if (pos < 0) {
            close(fd);
            close(fl);
            unlink("test.lock");
            fprintf(stderr, "Cannot lseek");
            _exit(1);
        }
        count = write(fd, &value, sizeof(value));
        if (count != sizeof(value)) {
            close(fd);
            close(fl);
            unlink("test.lock");
            fprintf(stderr, "Cannot write: count == %d", count);
            _exit(1);
        }
        close(fd);
        close(fl);
        unlink("test.lock");
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
    for (int i = 0; i < 2; ++i) {
        create_incrementer();
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
