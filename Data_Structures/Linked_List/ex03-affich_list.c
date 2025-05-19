void	afficherListe(node* tete)
{
	node* temp = tete;
	printf("Les éléments de la liste sont :\n");
	while (temp != NULL) 
		{
			printf("%d ->", temp->data);
			temp = temp->next;
		}
	printf("NULL\n"); // Indiquer la fin de la liste
}
