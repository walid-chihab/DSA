#include <stdio.h>

int main() {
    int taille, i, j, temp;

    printf("Entrez la taille du tableau: ");
    scanf("%d", &taille);

    int t[taille];

    printf("Entrez les éléments du tableau:\n");
    for (i = 0; i < taille; i++) {
        printf ("\tt[%d]=",i+1);
        scanf("%d", &t[i]);
    }

    for (i = 0; i < taille - 1; i++) {
        for (j = i + 1; j < taille; j++) {
            if (t[j] < t[i]) {
                temp = t[i];
                t[i] = t[j];
                t[j] = temp;
            }
        }
    }

    printf("\nTableau trié par selection  sous forme croissant:\n\n");
    for (i = 0; i < taille; i++) {
        printf("\t%d\t ", t[i]);
    }
     return 0;
}
