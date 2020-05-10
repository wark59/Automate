#ifndef tableau_H_INCLUDED
#define tableau_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

void construireStatusEtat(char* nomFichier);

void affichageStatusEtat();

void construireTransition2(char* nomFichier);

int codeLettre(char lettre);



int automate(char* c);

#endif 