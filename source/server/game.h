#include "../common/cfg.h"
#ifndef GAME_H
#define GAME_H

/**
* @brief Structure : Structure de 2 instances de structure jeuClient
*
* @param jeuClient rc1  Structure : informations de données de jeu du Client1
* @param jeuClient rc2  Structure : informations de données de jeu du Client2
*/
typedef struct  {
    jeuClient rc1;
    jeuClient rc2;
}Result_Round;
#endif /* GAME_H */

 Result_Round RoundProcess(jeuClient, jeuClient);
 jeuClient ExtractResultStruct1(Result_Round);
 jeuClient ExtractResultStruct2(Result_Round);
 Result_Round InitGame();

// int GameProcess(jeuClient, jeuClient);