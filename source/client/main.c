#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include "cfg.h"

int main(int argc, char** argv) {

    cfgClient cfg = initCfg();
    int sockfd;
    pthread_t thread;
    sockfd = open_connection();

    write(sockfd, &cfg, sizeof(cfg));

    //Creation d'un pthread de lecture
    pthread_create(&thread, 0, threadProcess, &sockfd);

    //write(connection->sock,"Main APP Still running",15);
    pthread_detach(thread);

    return (EXIT_SUCCESS);
}