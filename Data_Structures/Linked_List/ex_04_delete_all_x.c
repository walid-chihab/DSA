// Fonction pour supprimer tous les maillons contenant la valeur x
void deleting(node** tete, int x) {
    node* courant = *tete;     // Pointeur courant pour parcourir la liste
    node* precedent = NULL;    // Pointeur vers le maillon précédent

    while (courant != NULL) {
        if (courant->data == x) {   // Si on trouve la valeur à supprimer
            node* temp = courant;   // Sauvegarder le maillon à supprimer

            if (precedent == NULL) {
                // Si le maillon à supprimer est en tête
                *tete = courant->next; // La tête devient le suivant
                courant = *tete;       // On avance au suivant
            } else {
                // Si le maillon à supprimer n'est pas en tête
                precedent->next = courant->next; // Sauter le maillon courant
                courant = courant->next;         // Avancer
            }

            free(temp); // Libérer la mémoire du maillon supprimé
        } else {
            // Si la valeur n’est pas x, on avance normalement
            precedent = courant;         // Mettre à jour le précédent
            courant = courant->next;     // Passer au suivant
        }
    }
}
