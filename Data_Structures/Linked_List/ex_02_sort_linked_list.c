/*
*
* Écrire une fonction qui ordonne une liste chaînée par ordre croissant sans créer
* de maillon supplémentaire.
*
*/

void	sorting ( node **tete ){

	node *temp = *tete;
	 
	int compt = 0;
	while (temp != NULL){
	
		compt++;
		temp  = temp ->next;
	}
	int i = 0; // pour boucler
	while(compt > 1){
		 int swap ;
   		 node *precedent = *tete;
		 node *courant = precedent->next;
		 i = 0;
		while(	i < compt - 1 && courant != NULL ){
			if (precedent->data > courant->data){ //tri a bull croissant!!
				swap = precedent->data;
				precedent->data = courant->data;
				courant->data = swap;
			}
			precedent = courant ;
			courant = courant->next;
			i++;
		}
		compt--;
	}
}
