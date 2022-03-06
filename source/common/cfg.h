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
* @brief Structure : informations de données de jeu du Client
*
* @param RoundRestant Nombre de round restant avant la fin de la partie ; Défini en début de partie par le Serveur
* @param Budget     Unités (utilisées lors de la mise) restantes; Défini en début de partie par le Serveur
* @param Mise       Montant d'unités misées ; Décidée par le joueur à chaque round ; Influe le nombre de point gagné lors d'un round selon la décision
* @param Décision   Choix du joueur (Trahir/Collaborer) ; Décidée par le joueur à chaque round ; Décide de la victoire, de la défaite ou d'une égalité lors d'un round
* @param Score      Somme cumulative des points remportés à chaque round ; Critère de victoire de la partie (à la fin du dernier round)
*/
typedef struct {
    int RoundRestant;
    int Budget;
    int Mise;
    int Décision;
    int Score;
} jeuClient;



cfgClient initCfgCli();
cfgServer initCfgSrv();

void afficherConfigCli(cfgClient cfg);
void afficherConfigSrv(cfgServer cfg);

#endif /* CFG.H */