#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "game.h"

/**
 * @brief Traitement d'un round (mises, decisions et calcul du score) a partir de données initiales (Mises, Décisions et Budget) 
 * et renvoi d'une structure de données résultats (Mises, Décisions, Score et Budget)
 * @param[in] jeuClient c1 Structure : informations de données de jeu du Client1
 * @param[in] jeuClient c2 Structure : informations de données de jeu du Client2
 * 
 * @param[out] Result_Round R : Structure de données de résultat, composée de deux instances de structure de données de jeu de clients (Budget, mise, décision et score)
 */
 Result_Round RoundProcess(jeuClient c1, jeuClient c2) {

    Result_Round R;
    // Constante multiplicatrice de gains en cas de DoubleCoopération
    int doubleCooperation = 2;


// Traitement du round
    

    // les 2 coopèrent
    if(c1.Décision == 0 && c2.Décision == 0) {
        R.rc1.Score = c1.Mise*doubleCooperation;
        R.rc2.Score = c2.Mise*doubleCooperation; 
    }
    // joueur A coopère & joueur B trahi
    else if(c1.Décision == 0 && c2.Décision == 1) {
        R.rc1.Score = 0;
        R.rc2.Score = c1.Mise + c2.Mise;        
    }
    // joueur A trahi & joueur B coopère
    else if(c1.Décision == 1 && c2.Décision == 0) {
        R.rc1.Score = c1.Mise + c2.Mise;
        R.rc2.Score = 0;
    }
    // les 2 trahissent
    else {
        int divMise = (c1.Mise + c2.Mise) / 2;
        R.rc1.Score = divMise;
        R.rc2.Score = divMise;
    }


//Implémentation de la structure de Resultat


    // Soustraction de la mise aux Budget
    R.rc1.Budget = c1.Budget - c1.Mise;
    R.rc2.Budget = c2.Budget - c2.Mise;
    
    R.rc1.Mise = c1.Mise;
    R.rc2.Mise = c2.Mise;

    R.rc1.Décision = c1.Décision;
    R.rc2.Décision = c2.Décision;

    // Addition du score
    R.rc1.Score = c1.Score + R.rc1.Score;
    R.rc2.Score = c2.Score + R.rc2.Score;

    return R;
}

