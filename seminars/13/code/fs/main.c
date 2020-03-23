#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <dirent.h>

int main()
{
    char buf[PATH_MAX + 1];
    printf("cwd: %s\n", getcwd(buf, PATH_MAX + 1));
    chdir("test");
    printf("cwd: %s\n", getcwd(buf, PATH_MAX + 1));
    chdir("..");
    printf("cwd: %s\n", getcwd(buf, PATH_MAX + 1));

    DIR* dir = opendir("test");
    struct dirent* test;
    while ((test = readdir(dir)) != NULL) {
        printf("%s\n", test->d_name);
    }
    closedir(dir);
    return 0;
}
