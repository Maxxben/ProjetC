#ifndef CFG_H
#define CFG_H
#define MAXSIMULTANEOUSCLIENTS 50

typedef struct {
    char *server_IP;
    int server_Port;
    int id_Client;
} cfgServer;

typedef struct {
    char server_IP[15];
    int server_Port;
    int id_Client;
} cfgClient;


cfgClient initCfgCli();
cfgServer initCfgSrv();

void showcfgClient(cfgClient cfg);
void showServerConfig(cfgServer cfg);

#endif /* CFG.H */