#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include "manager.h"
#include "../common/cfg.h"


void *threadProcess(void * ptr) {
    int sockfd = *((int *) ptr);

    
    close(sockfd);
}

int open_connection(cfgClient cfg) {
    int sockfd;

    struct sockaddr_in serverAddr;

    // Create the socket. 
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    //Configure settings of the server address
    
    // Address family is Internet 
    serverAddr.sin_family = AF_INET;

    //Set port number, using htons function 
    serverAddr.sin_port = htons(cfg.server_Port);

    //Set IP address to localhost
    serverAddr.sin_addr.s_addr = inet_addr(cfg.server_IP);

    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

    //Connect the socket to the server using the address
    if (connect(sockfd, (struct sockaddr *) &serverAddr, sizeof (serverAddr)) != 0) {
        printf("Fail to connect to server");
        exit(-1);
    };

    return sockfd;
}