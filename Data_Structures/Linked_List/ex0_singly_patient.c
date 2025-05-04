/********************************************************************************************************/
/*	On considère l’ensemble des patients qui arrivent chez un médecin, à priori on ne		*/
/*	connaît pas le nombre de personnes qui peuvent joindre le cabinet. C’est pour cela on		*/
/*	préfère utiliser les listes chainées. A l’entrée on note le nom, le prénom et l’âge du patient.	*/
/*	1. Ecrire la fonction qui permet d’enregistrer les informations des patients.			*/
/*	2. Ajouter une fonction qui permet de lister l’ensemble des patients.				*/
/*	3. Ajouter une fonction qui permet de chercher le patient le plus âgé.				*/
/*	4. Ecrire le programme appelant.							        */
/********************************************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

typedef struct patient {
	char nom [50];
	char prenom [70];
	int age ;
	struct patient * suivant;
}patient;

patient *cree_patient(char _nom[],char _prenom[],int _age){
	patient *nv_patient = (patient*) malloc(sizeof(patient));
	if (nv_patient == NULL){
		printf ("erreure d'allocation");
		exit(1);
	}
	strcpy(nv_patient->nom, _nom);
	strcpy(nv_patient->prenom, _prenom);
	nv_patient->age = _age;
	nv_patient->suivant = NULL;
	return nv_patient;
}

void	affich_patient(patient *tete){
	patient *courant = tete;
	int i = 0;
	while (courant != NULL ){
		printf ("patient(%d)  M:%s - %s d'age %d \n",i+1,courant->nom,courant->prenom,courant->age);
		i++;
		courant=courant->suivant;
	}
}

void  age_patient(patient *tete){
	if (tete == NULL){
		printf ("list patient vide!");
		return;
	}
	patient *courant = tete;
	patient *max_age = tete;
	while (courant != NULL){
		if (courant->age > max_age->age){
			max_age = courant;
		}
		courant=courant->suivant;
	}
	printf("le plus grand patient est %s -%s de %d ans",max_age->nom,max_age->prenom,max_age->age);
}

int main (){
	
	patient *tete = NULL;
	patient *premier;
	patient *deuxieme;
      
	premier= cree_patient("walid","chihab",20 );
	deuxieme= cree_patient("anas","glioula",21);

	tete = premier;

	premier->suivant=deuxieme;
	deuxieme->suivant=NULL;

	affich_patient(tete);
	printf("---------------------");
	age_patient(tete);
	return 0;
}
