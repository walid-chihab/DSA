#include <stdio.h>

int main() {
    int chang, taill, i, j;

    printf("Entrez la taille du tableau: ");
    scanf("%d", &taill);

    int t[taill];

    printf("Entrez les éléments du tableau:\n");
    for (i = 0; i < taill; i++) {
        printf ("\tt[%d]=",i+1);
        scanf("%d", &t[i]);
    }

    for ( i=taill ; i>=0 ; i--) {
        for ( j=0 ; j<taill-1 ; j++) {
            if ( t[j]>t[j+1] ) {
                chang=t[j+1];
                t[j+1]=t[j];
                t[j]=chang;
            }
        }
    }
    printf("\nTableau trié par bull  sous forme croissant:\n\n");
    for (i = 0; i < taill; i++) {
        printf("\t%d\t ", t[i]);
    }
    printf("\n");

    return 0;
}
