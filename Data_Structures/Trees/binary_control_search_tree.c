#include <stdio.h>
#include <stdlib.h>

// Définition de la structure d'un nœud de l'arbre binaire
typedef struct Node {
    int valeur;           // La valeur entière stockée dans le nœud
    struct Node *gauche;  // Pointeur vers le sous-arbre gauche
    struct Node *droite;  // Pointeur vers le sous-arbre droit
} Node;

// Fonction pour créer un nouveau nœud avec une valeur donnée
Node* creer_noeud(int val) {
    Node* nouveau = (Node*)malloc(sizeof(Node)); // Allocation dynamique mémoire
    if (nouveau == NULL) {
        printf("Erreur d'allocation mémoire\n");
        exit(1);  // Quitter le programme si l'allocation échoue
    }
    nouveau->valeur = val;    // Initialiser la valeur du nœud
    nouveau->gauche = NULL;   // Initialiser les sous-arbres à NULL
    nouveau->droite = NULL;
    return nouveau;           // Retourner le pointeur vers le nouveau nœud
}

// Fonction pour insérer une valeur dans l'arbre binaire de recherche
Node* inserer(Node* racine, int val) {
    if (racine == NULL) {
        // Si la position est vide, créer et retourner un nouveau nœud
        return creer_noeud(val);
    }
    if (val < racine->valeur) {
        // Si la valeur à insérer est plus petite, insérer dans le sous-arbre gauche
        racine->gauche = inserer(racine->gauche, val);
    } else if (val > racine->valeur) {
        // Si la valeur est plus grande, insérer dans le sous-arbre droit
        racine->droite = inserer(racine->droite, val);
    }
    // Si la valeur est égale, ne rien faire (valeurs distinctes)
    return racine;  // Retourner la racine inchangée
}
