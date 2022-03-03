#include "../common/cfg.h"
#ifndef MANAGER_H
#define MANAGER_H

/**
* @brief Structure du socket
*
* @param sockfd
* @param address structure sockaddr
* @param addr_len
* @param index
*/
typedef struct {
    int sockfd;
    struct sockaddr address;
    int addr_len;
    int index;
} connection_t;

void init_sockets_array();
void add(connection_t *connection);
void del(connection_t *connection);
void *threadProcess(void *ptr);
int create_server_socket(cfgServer cfg);
void setCfgServer(cfgServer cfg);

#endif /* MANAGER_H */