#include <stdio.h>

int main() {
    int chang, taille, i, j;

    printf("Entrez la taille du tableau: ");
    scanf("%d", &taille);

    int t[taille];

    printf("Entrez les éléments du tableau:\n");
    for (i = 0; i < taille; i++) {
        printf ("\tt[%d]=",i+1);
        scanf("%d", &t[i]);
    }

    for (i = 1; i < taille ; i++) {
        chang=t[i];
        for ( j=i-1 ; j >=0 ; j--) {
            if (( t[j]>chang ) && j>=0)
                t[j+1]=t[j];
            
            else
                break;
        }
        t[j+1]=chang;
    }
    printf("\nTableau trié par insertions  sous forme croissant:\n\n");
    for (i = 0; i < taille; i++) {
        printf("\t%d\t ", t[i]);
    }
    printf("\n");

    return 0;
}
