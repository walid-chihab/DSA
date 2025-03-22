#include <stdio.h>
void echang(int *x, int *y){
    int temp= *x;
    *x=*y;
    *y=temp;
}
void tas(int t[], int taill ,int i){
    int max_idx=i;
    int g=2*i+1;
    int d=2*i+2;
    if ( g<taill && t[g]>t[max_idx])
        max_idx=g;
    if ( d<taill && t[d]>t[max_idx])
        max_idx=d;
    if (max_idx != i){
        echang(&t[i],&t[max_idx]);
        tas(t,taill,max_idx);
    } 
}
void tritas(int t[] ,int taill){
    for (int i=taill/2-1 ; i>=0 ;i--)
        tas(t,taill,i);
    for(int i=taill-1 ; i>=0 ;i--){
        echang(&t[0], &t[i]);
        tas(t,i,0);
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
    tritas(t,taill);
    printf("\nTableau trié par tas sous forme croissant:\n\n");
    for (i = 0; i < taill; i++) {
        printf("\t%d\t ", t[i]);
    }
     return 0;
}
