/* 
 * File:   main.c
 * Author: Maxxben
 *
 */

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

int main(int argc, char** argv) {
    int sockfd = -1;
    int index = 1;
    connection_t *connection;
    pthread_t thread;

    cfgServer cfg = initCfgSrv();
    showServerConfig(cfg);

    /* init array*/
    init_sockets_array();
    /* create socket */
    sockfd = create_server_socket(cfg);

    if (listen(sockfd, 50) < 0) {
        fprintf(stderr, "%s: erreur : impossible d'écouter sur le port\n", argv[0]);
        return -5;
    }
    /* listen on port , stack size 50 for incoming connections*/

    printf("ready and listening\n");

    //Wait for connection
    while (true) {
        /* accept incoming connections */
        connection = (connection_t *) malloc(sizeof (connection_t));
        connection->sockfd = accept(sockfd, &connection->address, &connection->addr_len);
        connection->index = index++;
        if (connection->sockfd <= 0) {
            free(connection);
        } else {
            /* start a new thread but do not wait for it */
            pthread_create(&thread, 0, threadProcess, (void *) connection);
            pthread_detach(thread);
        }
    }
    return (EXIT_SUCCESS);
}