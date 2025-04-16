#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//creation de la structure 
typedef	struct	etudiant {
	int age;
       	float moyenne;
       	char name[50];
	struct etudiant *suivant;
}etudiant;


//fct qui cherch sur un element de la structure  spesifier puis affich tout les element du noued
etudiant * search_element(etudiant * tete , char c[]){
    etudiant *courant =tete;
    while(courant != NULL){
        if (strcmp(courant ->name,c) == 0){
            printf ("les information de %s est : \n",courant->name);
            return courant ;
        }
        courant=courant -> suivant;

    }
    return NULL;
}

//creation du fonction qui alloue dynamiquement de la memoire et initialise les champs 
// fonction avec type de retour etudiant
etudiant * cree_etudiant( int _age, float _moyenne, char _name[] ){

	etudiant *nv_etudiant = ( etudiant* ) malloc ( sizeof(etudiant) );
	
	//verifier si ya de espace memoire pour ce element 
	if (nv_etudiant == NULL)
		return NULL;//on peut pas return -1 car type de retour de la fonction  est un pointeur

	nv_etudiant -> age = _age;
	nv_etudiant -> moyenne = _moyenne;
	strcpy( nv_etudiant -> name , _name );
	nv_etudiant-> suivant = NULL;
	return nv_etudiant;
}



//affich les elements de la liste etudiant 
void affich_list(etudiant *tete){
    etudiant *courant =tete;
    while (courant != NULL ){
        printf ("(name = %s , age = %d , moyenne = %.1f ) ~>",courant ->name, courant->age ,courant->moyenne);
        courant = courant-> suivant;//poit sur la suivant du dernier node
    }
    printf("NULL");//
    
}


// ajout un element au debut du list
etudiant* add_first_list(etudiant *tete, int _age, float _moyenne, char _name[]) {
    etudiant *nv = cree_etudiant(_age, _moyenne, _name);
    if (nv == NULL) {
        printf("Erreur d'allocation de mémoire.\n");
        return tete;
    }
    nv->suivant = tete;
    tete = nv;
    return tete;
}


//fct qui calcule la taile d'une list
int taill_list(etudiant *tete){
    int i=0;
    etudiant *courant = tete;
    while (courant != NULL){
        i++;
        courant = courant ->suivant;
    }
    return i;
}


int main (){
	//cree un pointeur de type etudiant
	 etudiant *tete = NULL;//eliminer garbage value

	//creation des champs et remplisage
	etudiant *premier = cree_etudiant ( 22 , 16.20 , "walid" );
	etudiant *deuxiemme = cree_etudiant ( 21 , 11.80 , "chaimae" );
	etudiant *queue = cree_etudiant ( 25 , 17.50 , "zakaryae" );

	//liee les nodes de la structure
	tete = premier;
	premier -> suivant = deuxiemme;
	deuxiemme -> suivant = queue;
	queue -> suivant = NULL ;

	//appelant la fct affich_list avec largument tete
	//affich_list(tete);


	//appelant la fct taill_list pour calculer la taill
	//printf ("la taille de votre liste est : %d",taill_list(tete));
	

	//appelant la fct search_liste mais avant 
        //char c[]="walid";
        //etudiant * resultat =search_element(tete,c);
        //if (resultat == NULL)
        //    printf ("element pas trouvable!");
        //else {
        //    printf ("age = %d \n moyenne = %.1f", resultat->age ,resultat->moyenne);
        //}
	
	//tete=add_first_list(tete, 30,11.8,"ali");//tete point sur la nouveau noed
						

	//liberer lespace
	etudiant *courant = tete;
    while (courant != NULL) {
        etudiant *temp = courant;
        courant = courant->suivant;
        free(temp);
    }
    return 0;
}
