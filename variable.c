#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "variable.h"

#define TAILLE_MAX 1000

 
char* variable(char* nomfich, int nb)
{
    char* res = calloc(50 ,1);
	int caractereLu = 1;
	int ligne = 1;
	FILE* fichier = NULL;
    char chaine[TAILLE_MAX] = "";
	
     fichier = fopen(nomfich, "r");
 
    if (fichier != NULL)
    {
		
		 while (caractereLu!=EOF && ligne<nb)
       {
		     caractereLu=fgetc(fichier);
           if (caractereLu=='\n'){
             ligne++;
		   }
		   
	   }
	   fgets(chaine,TAILLE_MAX,fichier);
	   strcpy(res,chaine);
	   
    } 
	fclose(fichier);
	
	return res ;
}

char* transition(char* nomfich)
{
	 char* res = calloc(TAILLE_MAX ,TAILLE_MAX);
	 int cpt = 4;
	while(cpt < 9){
	strncat(res,variable(nomfich,cpt),TAILLE_MAX);
	cpt++;
	}
	return res;
}

void affichageVariable(char* variable)
{
	printf("%s",variable);
	
}

void affichageComplet(char* nomFichier)
{
	char* alphabet = variable(nomFichier,1);
	printf("Alphabet : %s", alphabet);
	char* entrant = variable(nomFichier,2);
	printf("Etat entrant : %s", entrant);
	char* acceptant = variable(nomFichier,3);
	printf("Etat acceptant : %s", acceptant);
	char* tableauTransition = transition(nomFichier);
	printf("Table de transition : \n%s \n", tableauTransition);
}

int convertisseur(char* variable, int nb)
{
	int res = -1;
	char table[strlen(variable)];
	int cpt = 1;
	while(cpt != nb+1) {
		
		table[cpt] = *variable;
		variable++;
		cpt++;
	}
	res = (int) table[nb] - '0'; 
	return res;
}
int nombreEtat(char* variable)
{
	return strlen(variable);
	
}
