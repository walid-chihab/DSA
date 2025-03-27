#include <stdio.h>

int rech_seq ( int t[], int taill, int x){
        for (int i=0; i<taill ; i++){
                if (t[i]==x)
                    return i;   
        }                                                                 
                return -1;                                                        
    }
int main () {                                                                                                                                                
        int taill, i,x;
        printf("Entrez la taille du tableau: ");
        scanf("%d", &taill);
        int t[taill];                       
        printf("Remplissez votre tableau:\n");
	for (i = 0; i < taill; i++) {
                printf ("t[%d]=",i+1);
                scanf("%d", &t[i]);
        }
        printf ("le chiffre que vous chercher? :");
        scanf ("%d",&x);
        int result = rech_seq(t,taill,x);
        if (result == -1)
                printf ("votre chiffre n'existe pas. merci!");
        else
                printf ("votre chiffre  %d est palce dans t[%d]",x,result+1);

    return 0;
} 
