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

/**
* @brief Structure : informations de la partie en cours (Elles servent a ecrire le fichier de resultat)
*
* @param numeroRound
* @param JeuJ1
* @param JeuJ2
* @param MiseDeJ1
* @param MiseDeJ2
* @param Score1
* @param Score2
*/
typedef struct {
    int numeroRound;
    char* JeuJ1;
    char* JeuJ2;
    int MiseDeJ1;
    int MiseDeJ2;
    int Score1;
    int Score2;
}Resultat;


void printEnTete(FILE *file);
void printLine(FILE *file,Resultat res);
void deroulementDuJeu();
void ecritureDesResultats();

cfgClient initCfgCli();
cfgServer initCfgSrv();

void afficherConfigCli(cfgClient cfg);
void afficherConfigSrv(cfgServer cfg);


#endif /* CFG.H */