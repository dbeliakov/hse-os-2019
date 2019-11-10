#include <stdio.h>
#include <unistd.h>

int main()
{
    for (int i=0; i<10; ++i) fprintf(stdout, "%d",i);
    sleep(3);
    return 0;
}
