#include "../common/cfg.h"
#ifndef MANAGER_H
#define MANAGER_H

void *threadProcess(void * ptr);
int open_connection(cfgClient cfg);

#endif /* MANAGER_H */