/*
* File : game.c
* Author: Thomas
*
*/

#include <string.h>
#include <stdio.h>
#include "game.h"


/**
 * @brief Rafraichissement de l'interface avec les données jeuClient c recue du serveur (RoudRestant, Budget, Mises, Décisions et Score)
 * @param[in] jeuClient c Structure : informations de données de jeu du Client
 */

void RefreshInterface(jeuClient c) {
    
    int gladeBudget = c.Budget;
    int gladeRoundRestant = c.RoundRestant;
    int gladeScore = c.Score;

    //TODO Implementation de l'interface -Refresh 
}

/**
 * @brief Construction de la structure sendc a envoyer au serveur avec les données résultant des choix de l'utilisateur (Mises et Décisions)
 * @param[in] jeuClient c           Structure : informations de données de jeu du Client
 * @param[in] int gladeMise         Int : mise de l'utilisateur 
 * @param[in] int gladeDécision     Int : décision de l'utilisateur 
 */

jeuClient BuildStruct(jeuClient sendc, int gladeMise, int gladeDecision) {
    sendc.Décision = gladeDecision;
    if (sendc.Mise <= sendc.Budget)
    {
        sendc.Mise = gladeMise;
    }
    

    return sendc;
}