/*         
*      	       |
*  	       |
*              |
*              ▼
*          │  'E'   │ ← queue     
*          ├────────┤
*          │  'D'   │
*          ├────────┤
*          │  'C'   │
*    ^     ├────────┤
*    |     │  'B'   │
*          ├────────┤
*          │  'A'   │ ← tete
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

//3.ajouter un fichier a la fin du file 
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
				       //
	nv_fichier->next = NULL;
	//1 ere cas si la tete et queue s'ont null c-a-d le file est vide
	if (*tete ==NULL)
		(*tete)=(*queue)=nv_fichier;	
	else{
		(*queue)->next = nv_fichier;
		(*queue)= nv_fichier;
	}
}

//4. suprimer un fichier du file au debut
void supprimer_Fichier(Fichier **tete, Fichier **queue) {
    // Vérifier si la file est vide
    if (*tete == NULL) {
        printf("La file est vide, rien à supprimer.\n");
        return;
    }
    
    Fichier *temp = *tete;       // Sauvegarder le premier fichier à supprimer
    *tete = (*tete)->next;       // Avancer la tête vers le fichier suivant
    
    // Si la file devient vide après la suppression
    // ce condition est specificement pour le dernier element du file 
    if (*tete == NULL) {
        *queue = NULL;           // Mettre aussi la queue à NULL
    }
    
    free(temp);                  // Libérer la mémoire de l'ancien premier fichier
}


//5.affich les elements du list
void afficher(Fichier *tete) {//pas de retour 
    if (tete == NULL) {//passage par valeur sufisant
        printf("La file est vide.\n");
        return;
    }

    while (tete != NULL) {
        printf("Nom: %s, Taille: %d octets\n", tete->nom, tete->taill);
        tete = tete->next;
    }
}
