#include <stdio.h>

void    next_adding(int j[],int nv_taill){
    for (int i=1; i<nv_taill; i++){
        j[i]=j[i-1]+j[i];
    }
}

void    changer(int j[],int t[],int taill, int nv_taill){
    for (int i=0 ; i < taill ;i++){
        int x=t[i];
        //Out of Bounds
        if (x < nv_taill && x >= 0)
            j[x]++;//nombre de repetition de chaque element du ancien tab
    }
}

//Cherchons le plus grand élément de l'ancien tableau.
    int pg_(int t[],int taill) {
    int pg =t[0];
    for (int i=1 ;i<taill ;i++){
        if (t[i]>pg)
            pg=t[i];
    }
    return pg;
}

int main() {
    
   int taill,nv_taill,y, i;

    //taill du tab-> taill
    printf("Entrez la taille du tableau: ");
    scanf("%d", &taill);

    int t[taill];
    
    //remplisage des element
    printf("Entrez les éléments du tableau:\n");
    for (i = 0; i < taill; i++) {
        printf ("\tt[%d]=",i+1);
        scanf("%d", &t[i]);
    }
    
    //pour éviter un dépassement des limites du tableau. "+1"
    nv_taill= pg_(t,taill)+1;
    
    //neauvou tableau j du taill du plus grand element dans t/
    int j[nv_taill];
    
    //initialisation des element de nv_tab par 0
    for (i=0 ; i<nv_taill ;i++){
        j[i]=0;
    }
    
    //nombre de repetition de chaque element du tab
    changer(j,t,taill,nv_taill);
    
    //sum
    next_adding(j,nv_taill);
    
    int k[taill];
    
    //finishing fixer les les element 
    for (i=taill-1 ;i>=0 ; i--){
       y = --j[t[i]];
       k[j[t[i]]]=t[i];
    }
    
    printf("\nTableau trié par tas sous forme croissant:\n\n");
    //affichag des element trie
    for (i = 0; i < taill; i++) {
        printf("\t%d\t ", k[i]);
    }

    return 0;
}
