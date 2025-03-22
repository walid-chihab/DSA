#include <stdio.h>
void chang(int *x, int *y){
    int temp= *x;
        *x=*y;
        *y=temp;
}
void tri_shell(int t[], int taill){
    for ( int vl=taill/2 ; vl>0 ;vl=vl/2){
        for( int j=vl ; j<taill ; j++){
            for( int i=j-vl ; i>=0 ; i=i-vl){
                if( t[i]<=t[i+vl])
                    break;
                else
                    chang(&t[i],&t[i+vl]);
            }
        }
    }
}
int main() {
    int taill, i;

    printf("Entrez la taille du tableau: ");
    scanf("%d", &taill);

    int t[taill];

    printf("Entrez les éléments du tableau:\n");
    for (i = 0; i < taill; i++) {
        printf ("\tt[%d]=",i+1);
        scanf("%d", &t[i]);
    }
    tri_shell(t,taill);
    
    printf("\nTableau trié par shell  sous forme croissant:\n\n");
    for (i = 0; i < taill; i++) {
        printf("\t%d\t ", t[i]);
    }
     return 0;
}
