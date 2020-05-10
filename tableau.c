#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "variable.h"

#define ACCEPTATION 0
#define ECHEC       1
#define TAILLE_MAX 1000
#define MAX_ETAT    10
#define ALPHABET    26

int status_etat[MAX_ETAT];

int transition2[MAX_ETAT][ALPHABET];

void construireStatusEtat(char* nomFichier)
{
  int i;
  int cpt = 1;
  char* chaine = variable(nomFichier,3);
  
  for(i=0;i<MAX_ETAT;i++)
  {
	  status_etat[i]= ECHEC;
  }
	 while( cpt != nombreEtat(chaine))
	{
		status_etat[convertisseur(chaine,cpt)] = ACCEPTATION;
		cpt++;
	}
}

void construireTransition2(char* nomFichier)
{
	int etat;	//etat= numéro Etat
	int lettre;  // lettre=lettreTransition

  for(etat=0;etat<MAX_ETAT;etat++)
  {
    for(lettre=0;lettre<26;lettre++)
	{
		transition2[etat][lettre]=-1;
	}
  }
	int taille = strlen(transition(nomFichier));
	char tab[taille];
	for(int i =0; i< taille; i++) 
	{
    tab[i] = *(transition(nomFichier)+i);
	}
	int comptx = 0;
	int compty = 0;
  for(int j =0; j< taille; j++) 
  {
    if(tab[j] == ';') 
	{
      comptx++;
	  //printf("; \n");
    }
    else if(tab[j] == '\n') 
	{
      comptx = 0;
      compty++;
	  //printf("retour a la ligne \n");
    }
	else if(tab[j] != ';') {
      transition2[compty][((int)tab[j]-'a')]=comptx;
	  //printf("caractere \n");
    }
	
  }
    
}

void affichageStatusEtat(){
	for(int i=0;i < MAX_ETAT; i++)
	{
	printf("%d",status_etat[i]);
	}
}
int codeLettre(char* mot,int indice)
{
	int res = -1;
	char table[strlen(mot)];
	int cpt = 1;
	while(cpt != indice+1) {
		
		table[cpt] = *mot;
		mot++;
		cpt++;
	}
	res = (int) table[indice] - 'a'; 
	return res;
}

int automate(char* c)
{
	int e=0; /* etat courant */
	int cpt = 1;

while(cpt != strlen(c)+1){

   e=transition2[e][codeLettre(c,cpt)];
   if(e==-1) return(ECHEC);
   cpt++;
  }

 return status_etat[e];
}