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

    write(sockfd, &jeu1, sizeof(jeu1));

    //Creation d'un pthread de lecture
    pthread_create(&thread, 0, threadProcess, &sockfd);

    //write(connection->sock,"Main APP Still running",15);
    pthread_detach(thread);
    do {
        fgets(msg, 100, stdin);
        //printf("sending : %s\n", msg);
        status = write(sockfd,&jeu1,sizeof(jeu));
        //memset(msg,'\0',100);
    } while (status != -1);

    return (EXIT_SUCCESS);
}