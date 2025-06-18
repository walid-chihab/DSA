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
    printf("NULL");//on point la fin de list
    
}


// ajout un element au debut du list par valeur 
etudiant* add_first_list_val(etudiant *tete, int _age, float _moyenne, char _name[]) {
    etudiant *nv = cree_etudiant(_age, _moyenne, _name);
    if (nv == NULL) {
        printf("Erreur d'allocation de mémoire.\n");
        return tete;
    }
    nv->suivant = tete;
    tete = nv;
    return tete;
}

//mais le ttype de retur et void 
void add_first_list_adr(etudiant **tete, e, int _age, float _moyenne, char _name[]) {
    etudiant *nv = cree_etudiant(_age, _moyenne, _name);
    if (nv == NULL) {
        printf("Erreur d'allocation de mémoire.\n");
        return;
    }
    nv->suivant = *tete;
    *tete = nv;
    return;
}

//ajouter nv_element a la fin de liste
void add_last_list (etudiant *tete, char _name[], float _moyenne ,int  _age )
{
    etudiant *nv_etudiant = cree_etudiant( _name, _moyenne ,  _age);
    etudiant *courant =tete;

    if (tete == NULL) return ;
    while (courant ->suivant != NULL){
        courant = courant ->suivant;
    }
    courant ->suivant = nv_etudiant;
}

void add_midl_list (etudiant **tete , char name ,float _moyenne, inta _age ){
    int i=0 , j=0;
    etudiant *initialise ;
    etudiant *courant = *tete;
    etudiant *nv_e = cree_etudiant ( _name , _moyenne ,_age);
    while(courant -> suivant != NULL){
        courant = courant -> suivant;
        i++;
    }
    i = i/2;
    courant = *tete;
    while (j < i){
        courant = courant -> suivant;
    }
    //pour n'obliant pas l'autre partie du list
    initialise = courant ->suivant ;

    courant -> suivant = nv_e;
    nv_e ->suivant = initialise;
}

void    sup_prm_elem_list(etudiant ** tete)//appeler dans le main et sera direct
{
    if (*tete == NULL) return ;
    etudiant *courant = * tete ;
    *tete = (*tete) ->suivant ;
    free(courant);
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
	

	/* appelant la fct search_liste mais avant 
		char c[]="walid";
        	etudiant * resultat =search_element(tete,c);
        	if (resultat == NULL)
			printf ("element pas trouvable!");
		else 
        		printf ("age = %d \n moyenne = %.1f", resultat->age ,resultat->moyenne)
	*/

	/* obliger de renitialiser l'adrees qui est dans le tete car elle est changer 
	tete=add_first_list-val(tete, 30,11.8,"ali");//tete point sur la nouveau noed
	*/

	/* pour cette methode c'est pas grave car c'est un passage par adresse
	 add_first_list_adr(&tete);
	*/

	/* pour voir si l'element est ajouter ou pas
		affich_list(tete);
		printf ("        ======================================\n");
		add_last_list(tete,"wasim" , 16.98 , 23);
		affich_list(tete);
	*/

	//appelde fct midll_list 
	//add_midl_list(&tete, "yassin",19.3, 25);  
        //add_midl_list(&tete, "fatin", 16.02, 0);

	//liberer lespace
	etudiant *courant = tete;
	while (courant != NULL) 
		{
        		etudiant *temp = courant;
        		courant = courant->suivant;
			free(temp);
		}
    return 0;
}
