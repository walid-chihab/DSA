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


//creation du fonction qui alloue ynamiquement de la memoire et initialise les champs 
// fonction avec type de retoure etudiant
etudiant * cree_etudiant( int _age, float _moyenne, char _name[] ){

	etudiant *nv_etudiant = ( etudiant* ) malloc ( sizeof(etudiant) );
	
	//verifier si ya de espace memoire pour ce element 
	if (nv_etudiant == NULL)
		return NULL;//on peut pas return -1 car type de retour de la fonction  est un poiteur

	nv_etudiant -> age = _age;
	nv_etudiant -> moyenne = _moyenne;
	strcpy( nv_etudiant -> name , _name );
	nv_etudiant-> suivant = NULL;
	return nv_etudiant;
}

//affich les element de la liste etudiant 
void affich_list(etudiant *tete){
    etudiant *courant =tete;
    while (courant != NULL ){
        printf ("(name = %s , age = %d , moyenne = %.1f ) ~>",courant ->name, courant->age ,courant->moyenne);
        courant = courant-> suivant;//poit sur la suivant du dernier node
    }
    printf("NULL");//
    
}

int main (){
	//cree un poiteur de type etudiant
	 etudiant *tete;

	//creation des champs et remplisage
	etudiant *premier = cree_etudiant ( 22 , 16.20 , "walid" );
	etudiant *deuxiemme = cree_etudiant ( 21 , 11.80 , "chaimae" );
	etudiant *queue = cree_etudiant ( 25 , 17.50 , "zakaryae" );

	//lie les nodes de la structure
	tete = premier;
	premier -> suivant = deuxiemme;
	deuxiemme -> suivant = queue;
	queue -> suivant = NULL ;

	//appelant la fct affich_list avec largument tete
	affich_list(tete);

	return 0;
}
