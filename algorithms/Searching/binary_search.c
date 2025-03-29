#include <stdio.h>

int rech_dec( int t[],int x,int inf,int sup){
        while(inf <=sup){
                int mil=(inf + sup)/2;
                if (t[mil]==x)
                    return mil;
                else if (t[mil<x])
                    inf=mil+1;
                else 
                    sup=mil-1;
        }
                return -1;
    }
int main () {                                                                                                                                               
        int taill, i,x;
        printf("Entrez la taille du tableau: ");
        scanf("%d", &taill);
        int t[taill];
        printf("Remplissez votre tableau de manière triée par ordre croissant :\n");
        for (i = 0; i < taill; i++) {
                printf ("t[%d]=",i+1);
                scanf("%d", &t[i]);
        }
        printf ("le chiffre que vous chercher? :");
        scanf ("%d",&x);
        int result = rech_dec(t,x,0,taill-1);
        if (result == -1)
                printf ("votre chiffre n'existe pas. merci!");
        else
                printf ("votre chiffre  %d est palce dans t[%d]",x,result+1);

    return 0;
}
