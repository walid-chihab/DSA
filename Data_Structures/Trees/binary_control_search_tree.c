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

// Fonction pour créer un arbre binaire de recherche à partir d’un tableau d'entiers
Node* creer_arbre(int tab[], int n) {
    Node* racine = NULL; // Commencer par une racine vide
    for (int i = 0; i < n; i++) {
        racine = inserer(racine, tab[i]); // Insérer chaque élément du tableau dans l’arbre
    }
    return racine; // Retourner la racine de l’arbre formé
}


// Définition de la fonction de suppression d'un nœud dans un arbre binaire de recherche
Node* deleteNode(Node* root, int key) {
    // Si l'arbre est vide ou si on atteint une feuille vide, rien à supprimer
    if (root == NULL)
        return NULL;

    // Si la valeur à supprimer est plus petite que la valeur du nœud actuel,
    // on continue la recherche dans le sous-arbre gauche
    if (key < root->valeur) {
        root->gauche = deleteNode(root->gauche, key);
    }
    // Si la valeur à supprimer est plus grande que la valeur du nœud actuel,
    // on continue la recherche dans le sous-arbre droit
    else if (key > root->valeur) {
        root->droite = deleteNode(root->droite, key);
    }
    // Sinon, on a trouvé le nœud à supprimer
    else {
        // Cas 1 : le nœud n’a pas d’enfants (feuille)
        if (root->gauche == NULL && root->droite == NULL) {
            free(root);        // On libère la mémoire
            return NULL;       // Et on retourne NULL pour déconnecter ce nœud
        }

        // Cas 2 : le nœud a un seul enfant à droite
        if (root->gauche == NULL) {
            Node* temp = root->droite; // On garde un pointeur vers le fils droit
            free(root);                // On libère le nœud actuel
            return temp;               // Et on retourne le fils droit
        }

        // Cas 3 : le nœud a un seul enfant à gauche
        if (root->droite == NULL) {
            Node* temp = root->gauche; // On garde un pointeur vers le fils gauche
            free(root);                // On libère le nœud actuel
            return temp;               // Et on retourne le fils gauche
        }

        // Cas 4 : le nœud a deux enfants
        // On cherche le plus petit nœud dans le sous-arbre droit (le successeur)
        Node* succParent = root;
        Node* succ = root->droite;
        while (succ->gauche != NULL) {
            succParent = succ;
            succ = succ->gauche;
        }

        // On remplace la valeur du nœud courant par celle du successeur
        root->valeur = succ->valeur;

        // Puis on supprime le successeur à sa position d'origine
        if (succParent == root)
            succParent->droite = deleteNode(succParent->droite, succ->valeur);
        else
            succParent->gauche = deleteNode(succParent->gauche, succ->valeur);
    }

    // On retourne la racine mise à jour
    return root;
}

