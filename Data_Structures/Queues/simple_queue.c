/*         
*      	       |
*  	       |
*              |
*              ▼
*          │  'E'   │ ← top     
*          ├────────┤
*          │  'D'   │
*          ├────────┤
*          │  'C'   │
*          ├────────┤
*          │  'B'   │
*          ├────────┤
*          │  'A'   │ ← Base de la pile
*              |
*              |
*              |
*              ▼
*	       'A'
*
*           First In, First Out
*
*                 fifo
*/

//1.declaration du structure
typedef struct Fichier{
	char nom[20];//le max 20 caracteres
	int taill;

	struct Fichier *next ;
}Fichier;

//2.initialisatiomn du fichier
void init_queue(Fichier **tete,Fichier **queue){
	*tete = NULL;
	*queue = NULL;
}

//3.ajouter un fichier a la file
 void ajout_Fichier(Fichier **tete, Fichier **queue){
	 //allocation dynamique
	 Fichier *nv_fichier = (Fichier*) malloc (sizeof(Fichier));
	 if (!nv_fichier){
		 printf ("erreur d'allocation!");
		 return ;//pas de type de retour dans la fct
	}
	printf("\nentrer le nom du fichier .txt!:");
	scanf("%19s",nv_fichier->nom);//on fait pas & car va stocker ladresse du premier caractere du tab de caractere
	printf ("entrer la taille de ce fichier en octet");
	scanf("%d",&nv_fichier->taill);//il faut fair & pour stocker l'adresse et pas la val (crash)
	

	nv_fichier->next = NULL;
	//1 ere cas si la tete et queue s'ont null c-a-d le file est vide
	if (*tete ==NULL)
		(*tete)=(*queue)=nv_fichier;	
	else{
		(*queue)->next = nv_fichier;
		(*queue)= nv_fichier;
	}
}
