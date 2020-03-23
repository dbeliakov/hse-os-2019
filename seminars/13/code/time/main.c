#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>

int main()
{
    printf("time %ld\n", time(NULL));
    struct timeval tp;
    gettimeofday(&tp, NULL);
    printf("time: seconds = %ld, microseconds = %d\n", tp.tv_sec, tp.tv_usec);

    time_t now = time(NULL);
    struct tm* utc = gmtime(&now);
    struct tm* local = localtime(&now);
    printf("utc: %d, local: %d\n", utc->tm_hour, local->tm_hour);

    printf("time %ld\n", mktime(local));

    printf("%s", asctime(local));
    printf("%s", ctime(&now));

    char str[20];
    strftime(str, 20, "%H:%M\n", local);
    printf("%s", str);

    return 0;
}
