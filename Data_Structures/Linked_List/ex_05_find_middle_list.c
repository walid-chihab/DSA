/*
 *   trouvon le milieu d'un liste 
 *   par un seul passage de list
 *
 *
 *
 *
 */



node *search(node *tete){

	node *faster = tete;
	node * slower = tete;

	while (faster != NULL && faster-> next != NULL){
		faster = faster->next->next;
		slower = slower->next;
	}
	printf ("la val du centre noed est %d ", slower->data);
	return slower;
}
