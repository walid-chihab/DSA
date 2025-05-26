/*
 *
 *
 *
 *
 */

void	inverserListe(Node** tete) {
	Node* precedent = NULL;
	Node* courant = *tete;
	Node* suivant = NULL;

	while (courant != NULL) {
		suivant = courant->next;
		courant->next = precedent;
		precedent = courant;
		courant = suivant;
	}

	*tete = precedent;
}
