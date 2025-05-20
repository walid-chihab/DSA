
void	insertionEnTete (node** tete, int valeur)
{
	node* nouveau =(node*)
	malloc(sizeof(node));
	nouveau -> data= valeur;
	nouveau -> next = *tete;
	*tete = nouveau;
}
