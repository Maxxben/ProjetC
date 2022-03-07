/* 
 * File:   manager.c
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

connection_t* connections[MAXSIMULTANEOUSCLIENTS];

cfgServer cfgSrv;

void init_sockets_array() {
    for (int i = 0; i < MAXSIMULTANEOUSCLIENTS; i++) {
        connections[i] = NULL;
    }
}

void add(connection_t *connection) {
    for (int i = 0; i < MAXSIMULTANEOUSCLIENTS; i++) {
        if (connections[i] == NULL) {
            connections[i] = connection;
            return;
        }
    }
    perror("Too much simultaneous connections");
    exit(-5);
}

void del(connection_t *connection) {
    for (int i = 0; i < MAXSIMULTANEOUSCLIENTS; i++) {
        if (connections[i] == connection) {
            connections[i] = NULL;
            return;
        }
    }
    perror("Connection not in pool ");
    exit(-5);
}

/**
 * @brief Remplissage de la variable globale du fichier
 * @param cfg configuration hydratée venant du main
 */
void setCfgServer(cfgServer cfg){
    cfgSrv = cfg;
}

/**
 * @brief Thread allowing server to handle multiple client connections
 * @param ptr connection_t 
 * @return 
 */
void *threadProcess(void *ptr) {

    int len;
    connection_t *connection;
    cfgClient cfgCli;

    if (!ptr) pthread_exit(0);
    connection = (connection_t *) ptr;
    
    printf("--------------------------------\n");
    printf("*New incoming connection* \n\n");
    add(connection);
    while((len = read(connection->sockfd, &cfgCli, sizeof(cfgClient))) > 0){

        printf("Hello from %d\n", cfgCli.id_Client);

        if(cfgCli.id_Client == cfgSrv.room_client_1 || cfgCli.id_Client == cfgSrv.room_client_2)
        {
            printf("Le client %d est connecté a la room %s\n", cfgCli.id_Client, cfgSrv.room_name);
        }
        else
        {
            printf("Le client %d est n'appartient pas a la room\n", cfgCli.id_Client);
        }
        printf("--------------------------------\n");

        break;
    }

    deroulementDuJeu();

    ecritureDesResultats();

    printf("\nConnection to client %i ended \n", connection->index);
    close(connection->sockfd);
    del(connection);
    free(connection);
    pthread_exit(0);

}


/**
 * @brief Creer un nouveau socket serveur
 * @param cfg 
 */
int create_server_socket(cfgServer cfg) {
    int sockfd = -1;
    struct sockaddr_in address;

    /* create socket */
    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd <= 0) {
        fprintf(stderr, "%s: error: cannot create socket\n");
        return -3;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(cfg.server_IP);
    address.sin_port = htons(cfg.server_Port);

    /* prevent the 60 secs timeout */
    int reuse = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (const char*) &reuse, sizeof (reuse));

    /* bind */
    if (bind(sockfd, (struct sockaddr *) &address, sizeof (struct sockaddr_in)) < 0) {
        fprintf(stderr, "error: cannot bind socket to port %d\n", cfg.server_Port);
        return -4;
    }

    return sockfd;
}