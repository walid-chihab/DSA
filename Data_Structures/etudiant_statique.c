#include <stdio.h>

typedef struct{
    int jour;
    int mois;
    int annes;
} dat;//structure imbriquer dans etudiant

typedef struct{
    char nom[50];
    char prenom[50];
    dat date;
} etudiant;
int main (){
    int nbr,i;//nbr c'est le nombre d'element qui est fixe par utilisateur
    printf ("----bonjour-------\n entrer votre n'ombre d'etudiant :");
    scanf ("%d",&nbr);
    etudiant e[nbr];//pas vraiment statique car la creation ets pas dans la compilation 
    for ( i=0 ;i< nbr; i++){ // remplisage par l'utilisateur
        printf ("pour etudiant_%d :\n",i+1);
        printf ("nom:");
        scanf ("%s",e[i].nom);
        printf ("prenom:");
        scanf ("%s",e[i].prenom);
        printf ("datde naissance(jj/mmmm/aaaa): ");
        scanf ("%d %d %d",&e[i].date.jour,&e[i].date.mois,&e[i].date.annes);
    }
     for ( i=0 ;i< nbr; i++){ //affichage du list
            printf ("pour etudiant_%d :\n",i+1);
            printf ("nom:%s\t",e[i].nom);
            printf ("prenom:%s \t",e[i].prenom);
            printf ("dat de naiss\sance :%d / %d / %d \n",e[i].date.jour,e[i].date.mois,e[i].date.annes);
     }
    return 0;
}
