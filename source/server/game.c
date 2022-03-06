/*
* File : game.c
* Author: Thomas
*
*/

#include <string.h>
#include <stdio.h>
#include "game.h"

/**
 * @brief Traitement d'un round (mises, decisions et calcul du score) a partir de données initiales (RoudRestant, Budget, Mises, Décisions et Score)
 * et renvoi d'une structure de données résultats (RoudRestant, Budget, Mises, Décisions et Score)
 * @param[in] jeuClient c1 Structure : informations de données de jeu du Client1
 * @param[in] jeuClient c2 Structure : informations de données de jeu du Client2
 * 
 * @param[out] Result_Round R : Structure de données de résultat, composée de deux instances de structure de données de jeu de clients (RoudRestant, Budget, Mises, Décisions et Score)
 */
Result_Round RoundProcess(jeuClient c1, jeuClient c2)
{

    Result_Round R;
    // Constante multiplicatrice de gains en cas de DoubleCoopération
    int doubleCooperation = 2;

    // Traitement du round

    if (c1.RoundRestant > 0 && c2.RoundRestant > 0)
    {

        // les 2 coopèrent
        if (c1.Décision == 0 && c2.Décision == 0)
        {
            R.rc1.Score = c1.Mise * doubleCooperation;
            R.rc2.Score = c2.Mise * doubleCooperation;
        }
        // joueur A coopère & joueur B trahi
        else if (c1.Décision == 0 && c2.Décision == 1)
        {
            R.rc1.Score = 0;
            R.rc2.Score = c1.Mise + c2.Mise;
        }
        // joueur A trahi & joueur B coopère
        else if (c1.Décision == 1 && c2.Décision == 0)
        {
            R.rc1.Score = c1.Mise + c2.Mise;
            R.rc2.Score = 0;
        }
        // les 2 trahissent
        else
        {
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

        R.rc1.RoundRestant = c1.RoundRestant - 1;
        R.rc2.RoundRestant = c2.RoundRestant - 1;
    }

    return R;
}

/**
 * @brief Extraction des données de résultat (RoudRestant, Budget, Mises, Décisions et Score)
 * @param[in] Result_Round R :      Structure de données de résultat, composée de deux 
 *                                  instances de structure de données de jeu de clients 
 *                                  (RoudRestant, Budget, Mises, Décisions et Score)
 * @param[out] jeuClient Rescli :   Structure de données de résultat de jeu du Client1
 */

jeuClient ExtractResultStruct1(Result_Round r)
{
    jeuClient ResCli;

    ResCli = r.rc1;
    return ResCli;
}

/**
 * @brief Extraction des données de résultat (RoudRestant, Budget, Mises, Décisions et Score)
 * @param[in] Result_Round R :      Structure de données de résultat, composée de deux 
 *                                  instances de structure de données de jeu de clients 
 *                                  (RoudRestant, Budget, Mises, Décisions et Score)
 * @param[out] jeuClient Rescli :   Structure de données de résultat de jeu du Client2
 */

jeuClient ExtractResultStruct2(Result_Round r)
{
    jeuClient ResCli;

    ResCli = r.rc2;
    return ResCli;
}

/**
 * @brief                                   Initialisation de la config de la partie
 * @param[out] Result_Round InitResult :    Structure de données de résultat, composée de deux 
 *                                          instances de structure de données de jeu de clients 
 *                                          (RoudRestant, Budget, Mises, Décisions et Score)
 */

Result_Round InitGame()
{
    config_t cfg;
    config_init(&cfg);


    int initRoundRestant = 0;
    int initBudget = 0;
    int initMise = 0;
    int initDecision = 0;
    int initScore = 0;

    config_lookup_string(&cfg, "initRoundRestant", &initRoundRestant);
    config_lookup_string(&cfg, "initBudget", &initBudget);
    config_lookup_string(&cfg, "initMise", initMise);
    config_lookup_string(&cfg, "initDecision", initDecision);
    config_lookup_string(&cfg, "initScore", initScore);

    Result_Round InitResult;
    InitResult.rc1.RoundRestant = initRoundRestant;
    InitResult.rc2.RoundRestant = initRoundRestant;
    InitResult.rc1.Budget = initBudget;
    InitResult.rc2.Budget = initBudget;
    InitResult.rc1.Mise = initMise;
    InitResult.rc2.Mise = initMise;
    InitResult.rc1.Décision = initDecision;
    InitResult.rc2.Décision = initDecision;
    InitResult.rc1.Score = initScore;
    InitResult.rc2.Score = initScore;

    return InitResult;

}