#include "../common/cfg.h"
#ifndef MANAGER_H
#define MANAGER_H

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

#endif /* MANAGER_H */