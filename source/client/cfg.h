#ifndef CFG_H
#define CFG_H

typedef struct {
    char server_IP[15];
    int server_Port;
    int id_Client;
} cfgClient;

cfgClient initCfg();


#endif /* CFG.H */