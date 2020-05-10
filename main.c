#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "variable.h"
#include "tableau.h"

#define ECHEC       1
/*
Fonction externe disponible : variable(fich,nbLigne)
							  transition(fich)
							  affichageVariable(char*)
							  affichageComplet()
							  convertisseur(char*)
							  motFonctionne(char*,char*)
							  nombreEtat(char*)
							  construireStatusEtat(char*)
							  affichageStatusEtat();

*/
 
int main(int argc, char *argv[])
{
	char* nomFichier = argv[1];
	char* mot = argv[2];
	affichageComplet(nomFichier);
	construireStatusEtat(nomFichier);
	construireTransition2(nomFichier);
	if(automate(mot)==ECHEC) printf("Mot Non reconnu !\n"); else printf("Mot Reconnu !\n");

	return 0;
}