#include <stdio.h>
void chang(int *x ,int *y){//fonction pour swap
    int temp=*x;
         *x=*y;
         *y=temp;   
}
int partition(int t[], int bas, int haut){
    int pivot=t[haut];
    int i= bas-1;
    for (int j=bas ; j<haut ; j++){
        if (t[j]<=pivot){
            i++;
            chang(&t[i],&t[j]);
            
        }
    }
    chang(&t[i+1],&t[haut]);//appelle de la fonction
    return(i+1);
}

void trirapid (int t[], int bas, int haut){
    if (bas < haut){//pour positioner  les sous tableau 
        int pi= partition(t,bas,haut);
        trirapid(t, bas, pi-1);//appelon la fonction trirapid d'une manier recursive
        trirapid(t, pi+1, haut);//aussi mais par condition
    }
}
int main() {
    int taill, i;

    printf("Entrez la taille du tableau: ");
    scanf("%d", &taill);

    int t[taill];//declaration du tableau apres connu le nombre d'element apres on reserve un espace sufisant

    printf("Entrez les éléments du tableau:\n");
    for (i = 0; i < taill; i++) {
        printf ("\tt[%d]=",i+1);
        scanf("%d", &t[i]);
    }
    trirapid(t,0,taill-1);//cause indexes start whith 0

    printf("\nTableau trié utilisant le tri rapid  sous forme croissant:\n\n");
    for (i = 0; i < taill; i++) {
        printf("\t%d\t ", t[i]);
    }
     return 0;
}
