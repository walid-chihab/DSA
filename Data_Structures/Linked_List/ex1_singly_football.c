/************************************************************************************************/
/*	On considère la liste des coupes du football au Maroc, on veut décrire une structure de	*/
/*	données adéquate pour pouvoir répondre aux requêtes suivantes :				*/
/*	1. Quelle est l’équipe qui a emporté la coupe en l’année X ?				*/
/*	2. Combien de fois une équipe E a t- elle emporté la coupe ?				*/
/*	3. En quelle année une équipe E a t- elle emporté la coupe pour la dernière fois ?	*/
/*	 a. Proposer une structure de données pour représenter le problème, justifier.(comment)	*/
/*	 b. Faite les déclarations nécessaires en langage C.					*/
/*	 c. Ecrire un programme faisant appel aux fonctions suivantes :				*/
/*		i.Une  fonction pour la création de la liste					*/
/*		ii. Une fonction pour la requête 1						*/
/*		iii. Une fonction pour la requête 2						*/
/*		iiii. Une fonction pour la requête 3						*/
/************************************************************************************************/

#include <unistd.h>
#include <stdio.h>
#include<string.h>
#include <stdlib.h>

typedef struct coup{
	char equip[50];
	int annes;
	struct coup *suivant;
}coup;

coup cree_coup(char _equip, int _annes){

	coup *nv_coup = (coup*)malloc (sizepf(coup));
	if (nv_coup == NUL){	
		printf ("erreur d'allocation!");
		return ;
	}
	strcpy(nv_coup->equip,_equip);
	nv_coup -> annes = _annes;
	nv_coup -> suivant = NULL ;
	return coup;
}

void compt_coup(coup *tete , int _annes ){

	coup *courant= tete;
	while (courant != NULL ){
	if (  _annes == courant->annes)
		printf("%s est l'equipe qui gagne la coup %d",courant->equipe, _annes);
	
	}
	printf ("y-a-pas d'equipe qui gagne la coupe dans %d",-annes);
}

