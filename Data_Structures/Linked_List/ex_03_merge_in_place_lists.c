/*
 * fusionner deux listes triees en une seul liste triee sans cree de neauvoux maillons 
 *    les deux sous liste sont deja trie
 *    exp:
 *        l1: 2->3->9->NULL
 *        l2: 3->6->11->NULL
 *  resultat: 2->3->6->9->11->NULL
 *
 */

node * merg_place (node * tete1 , node * tete2){
	//si l'une des deux liste est telment vide
	if (tete1 == NULL) return tete2;
	if (tete2 == NULL) return tete1;

	node *courant1 = tete1;//marchant dans la list 1
	node *courant2 = tete2;//marchant dans la list 2
	node *courant = NULL;//marchant dans la nouvou list
	node *tete = NULL;//pour pas oblier la tete de neauvou tete
	
	//choisisant la tete du nouveau list
	if (courant1->data < courant2->data){
		tete = courant1;
	}else {
		 tete = courant2;
        }

	courant = tete;

	//les autre noeds du deux lists
	while( courant1 != NULL && courant2 != NULL){
		if (courant1->data < courant2->data){
                	courant->next=courant1;
			courant1=courant1->next;
        	}else {
               		  courant->next=courant2;
			  courant2=courant2->next;
       		}
		courant = courant->next;
	}
	if (courant1 != NULL)
		courant->next = courant1;
	else 
		courant->next = courant2;
	return tete;
}
