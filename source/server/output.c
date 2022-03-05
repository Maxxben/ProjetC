/*
* File : output.c
* Created by Thomas
* Author: Jeremy on 11/26/2021
*
*/

#include <time.h>
#include <stdio.h>
#include "output.h"

/**
 * @brief Ecrit l'en tete d'un résultat de partie (par round) avec les informations correspondantes
 * @param[in] file Fichier de sortie dans lequelle les resultats sont inscrits
 */

void printEnTete(FILE *file){
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    int h, min, s, day, mois, an;
    h = local->tm_hour;
    min = local->tm_min;
    s = local->tm_sec;
    day = local->tm_mday;
    mois = local->tm_mon + 1;
    an = local->tm_year + 1900;
    fprintf(file,"%02d/%02d/%d - %02d:%02d:%02d, JeuJ1, JeuJ2, MiseDeJ1, MiseDeJ2, Score de J1, Score de J2\n",day, mois, an, h, min, s);
}

/**
 * @brief Ecrit dans un fichier une ligne avec le resultat du round actuel
 * @param[in] file  Fichier de sortie dans lequelle les resultats sont inscrits
 * @param[in] res   Structure où sont stockés les resultats du round actuel
 */

void printLine(FILE *file,Result_Round res){
    fprintf(file,"%d, %s, %s, %d, %d, %d, %d\n", res.rc1.Décision, res.rc2.Décision, res.rc1.Mise, res.rc2.Mise, res.rc1.Score, res.rc2.Score);
}