#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "../common/cfg.h"

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

void printLine(FILE *file,Resultat res){
    fprintf(file,"%d, %s, %s, %d, %d, %d, %d\n", res.numeroRound, res.JeuJ1, res.JeuJ2, res.MiseDeJ1, res.MiseDeJ2, res.Score1, res.Score2);
}

void ecritureDesResultats(){

    printf("\n\t*Creation du fichier de resultats*\n");

    Resultat resultat;

    resultat.numeroRound = 1;
    resultat.JeuJ1 = "Trahi";
    resultat.JeuJ2 = "Confiance";
    resultat.MiseDeJ1 = 50;
    resultat.MiseDeJ2 = 100;
    resultat.Score1 = 600;
    resultat.Score2 = 700;

    FILE *fpt;
    fpt = fopen("GestionDesParties.csv", "a");
    
    printEnTete(fpt);
    printLine(fpt,resultat);
    printLine(fpt,resultat);
    printLine(fpt,resultat);
    fprintf(fpt,"       \n");

    printf("\n\t*Fin ecriture - fichier créer : GestionDesParties.csv*\n");

}

void deroulementDuJeu(){

    printf("\nPartie en cours ...\n");

    //TODO : Deroulement de la partie

    printf("\nPartie en terminée ...\n");
}