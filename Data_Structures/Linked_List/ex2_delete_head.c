/****************************************************************************************/
/* Dans cette série, on considère une liste chaînée d’entiers. En exploitant les	*/
/*fonctions déjà vues en cours, void insertionEnTête(node** tete, int valeur)		*/
/*pour remplir la liste et void afficherListe(node* tete) pour l'afficher,		*/
/*implémentez et testez les fonctions de cette série d’exercices.			*/
/****************************************************************************************/

void insertionEnTete (node** tete, int valeur)
{
	node* nouveau =(node*)
	malloc(sizeof(node));
	nouveau -> data= valeur;
	nouveau -> next = *tete;
	*tete = nouveau;
}

void	afficherListe(node* tete) {
node* temp = tete;
printf("Les éléments de la liste sont :\n");
while (temp != NULL) {
printf("%d -> ", temp -> data);
temp = temp->next;
}
printf("NULL\n"); // Indiquer la fin de la liste
}


