#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

const char* hello_reply = "HTTP/1.1 200 OK\n"
"Content-Type: text/html\n"
"Connection: close\n"
"Content-length: 53\n"
"\n"
"<html>\n"
"<body>\n"
"<h1>Hello, world!</h1>\n"
"</body>\n"
"</html>\n";

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "usage: %s PORT\n", argv[0]);
        return 1;
    }

    int ans = 0;
    struct sockaddr_in addr;

    signal(SIGPIPE, SIG_IGN);

    long port = strtol(argv[1], NULL, 10);
    int lfd = socket(PF_INET, SOCK_STREAM, 0);
    if (lfd < 0) {
        fprintf(stderr, "cannot create socket\n");
        return 1;
    }

    int val = 1;
    setsockopt(lfd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
    setsockopt(lfd, SOL_SOCKET, SO_REUSEPORT, &val, sizeof(val));

    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;
    int ret = bind(lfd, (struct sockaddr*) &addr, sizeof(addr));
    if (ret < 0) {
        fprintf(stderr, "cannot bind socket\n");
        return 2;
    }

    ret = listen(lfd, 5);
    if (ret < 0) {
        fprintf(stderr, "cannot listen\n");
        return 3;
    }

    while (1) {
        int size = sizeof(addr);
        int sfd = accept(lfd, (struct sockaddr*) &addr, (socklen_t*)&size);
        if (sfd < 0) {
            fprintf(stderr, "cannot accept");
            return 4;
        }

        int count = write(sfd, hello_reply, sizeof(char) * strlen(hello_reply));
        printf("Writed %d bytes...\n", count);
        close(sfd);
    }
    printf("%d\n", ans);

    return 0;
}

