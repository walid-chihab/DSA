/*
 * fusionner deux listes triees en une seul liste triee sans cree de neauvoux maillons 
 *    exp:
 *        l1: 2->3->9->NULL
 *        l2: 3->6->11->NULL
 *  resultat: 2->3->6->9->11->NULL
 *
 */
//fct qui cree les nouds du nouvelle liste
node *cree_node(int val){
	node *nv_node = (node*) malloc(sizeof(nv_node));
	if (nv_node == NULL)return;
	nv_node -> data = x;
	nv_node -> next = NULL;
	return nv_node;
	
}


//suposant que les deux sous liste sont deja triee sinon on va developer le code u peut 
void merging (node *tete1, node *tete2 )
{
	node *courant1 = *tete1;
	node *courant2 = *tete2;
	while ( courant1 != NULL && courant2 != NULL ){
		int x;
		if ( courant1- >data < courant2- >data){
			cree_node(courant1->data);///on va cree un nouveau champ de notre nouveau list avec cett valeur
			*tete = courant1 -> suivant;//changer l a tete du sous premier list
			merging (node *tete1, node *tete2 );// utilisant la recurciviter de fct mais avec des nouveau argument
		}
		else {
                        cree_node(courant2->data);//on va cree un nouveau champ de notre nouveau list avec cett valeur
                        *tete = courant2 -> suivant;//changer l a tete du sous premier list
                        merging (node *tete1, node *tete2 );// utilisant la recurciviter de fct mais avec des nouveau argument
        	}
	}













