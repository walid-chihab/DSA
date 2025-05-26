/*
 *
 *
 *
 *
 */

void	inverserListe(Node** tete) {
	Node* precedent = NULL;//pour donne le next fu premier noed la val NULL
	Node* courant = *tete;
	Node* suivant = NULL;//on renitialiser dans la boucle 

	while (courant != NULL) {
		suivant = courant->next;
		courant->next = precedent;
		precedent = courant;
		courant = suivant;
	}

	*tete = precedent;
}
