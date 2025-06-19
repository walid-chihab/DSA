//leur sujet dans lautre fichier .control

// Parcours infixé : gauche → racine → droite
void afficher_infixe(Node* racine) {
    if (racine == NULL) return;
    afficher_infixe(racine->gauche);
    printf("%c ", racine->data);
    afficher_infixe(racine->droite);
}

// Parcours préfixé : racine → gauche → droite
void afficher_prefixe(Node* racine) {
    if (racine == NULL) return;
    printf("%c ", racine->data);
    afficher_prefixe(racine->gauche);
    afficher_prefixe(racine->droite);
}

// Parcours postfixé : gauche → droite → racine
void afficher_postfixe(Node* racine) {
    if (racine == NULL) return;
    afficher_postfixe(racine->gauche);
    afficher_postfixe(racine->droite);
    printf("%c ", racine->data);
}

