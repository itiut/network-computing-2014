#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include "safe_functions.h"

int safe_socket(int domain, int type, int protocol) {
    int sock = socket(domain, type, protocol);
    if (sock == -1) {
        perror("safe_socket: socket(2)");
        exit(1);
    }
    return sock;
}

void safe_bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen) {
    int ret = bind(sockfd, addr, addrlen);
    if (ret == -1) {
        perror("safe_bind: bind(2)");
        close(sockfd);
        exit(1);
    }
}

void safe_listen(int sockfd, int backlog) {
    int ret = listen(sockfd, backlog);
    if (ret == -1) {
        perror("safe_listen: listen(2)");
        close(sockfd);
        exit(1);
    }
}

int safe_accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen) {
    int ret = accept(sockfd, addr, addrlen);
    if (ret == -1) {
        perror("safe_accept: accept(2)");
        close(sockfd);
        exit(1);
    }
    return ret;
}
