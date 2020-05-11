#ifndef affichage_H_INCLUDED
#define affichage_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

char* variable(char* nomfich, int nb);

char* transition(char* nomfich);

void affichageVariable(char* variable);

void affichageComplet(char* nomFichier);

int convertisseur(char* variable, int nb);

int nombreEtat(char* variable);

#endif 
