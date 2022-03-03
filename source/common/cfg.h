#ifndef CFG_H
#define CFG_H
#define MAXSIMULTANEOUSCLIENTS 50

/**
* @brief Structure : informations de configuration du Serveur
*
* @param server_IP
* @param server_Port
*/
typedef struct {
    char *server_IP;
    int server_Port;
    char *room_name;
    int room_start_balance;
    int room_client_1;
    int room_client_2;
} cfgServer;


/**
* @brief Structure : informations de configuration du Client
*
* @param server_IP
* @param server_Port
* @param id_Client
*/
typedef struct {
    char server_IP[15];
    int server_Port;
    int id_Client;
} cfgClient;


cfgClient initCfgCli();
cfgServer initCfgSrv();

void affciherConfigCli(cfgClient cfg);
void affciherConfigSrv(cfgServer cfg);

#endif /* CFG.H */