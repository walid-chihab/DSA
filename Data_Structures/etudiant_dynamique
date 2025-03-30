#include <stdio.h>
#include <stdlib.h>//malloc,free

typedef struct{
    int jour;
    int mois;
    int annes;
} dat;// Cette structure est imbriquée dans la structure etudiant

typedef struct{
    char nom[50];
    char prenom[50];
    dat date;
} etudiant;
int main (){
    int nbr,i;//l'allocation sera dynamique 
    printf ("----bonjour-------\n entrer votre n'ombre d'etudiant :");
    scanf ("%d",&nbr);
    etudiant *e= malloc (sizeof(etudiant) * nbr);/* retourne l'adresse du premier octet de la mémoire réservée*/
    if (e == NULL){// Vérifier si malloc a réussi-_-
        printf ("espace memoire indisponible!");
        return -1;
    }
    for ( i=0 ;i< nbr; i++){ // remplisage par l'utcilisateur
        printf ("pour etudiant_%d :\n",i+1);
        printf ("nom:");
        scanf ("%s",e[i].nom);
        printf ("prenom:");
        scanf ("%s",e[i].prenom);
        printf ("dat de naissance(jj/mmmm/aaaa): ");
        scanf ("%d %d %d",&e[i].date.jour,&e[i].date.mois,&e[i].date.annes);
    }
    printf("\nListe des étudiants :\n");
    for ( i=0 ;i< nbr; i++){ //affichage du donnes
            printf ("\npour etudiant_%d :\n",i+1);
            printf ("nom:%s\t",e[i].nom);
            printf ("prenom:%s\t",e[i].prenom);
            printf ("dat de naissance : %d/%d/%d \n",e[i].date.jour,e[i].date.mois,e[i].date.annes);
     }
     
     int v;
     printf ("Y a-t-il d'autres étudiants ? '1' pour oui : ");
    scanf("%d",&v);
     if (v != 1){
         free(e);
        return 0;
     }
     while (v == 1){
        
    // Supposons que l'utilisateur veut ajouter plus d'étudiants
    int nv_nbr;
    printf("\nEntrez le nouveau nombre d'étudiants : ");
    scanf("%d", &nv_nbr);

    // Utilisation de realloc pour redimensionner le tableau d'étudiants
    e = realloc(e, sizeof(etudiant) * nv_nbr);

    if (e == NULL) {
        printf("pas de espace memoire pour les neauvou etudiants !\n");
        return 2;// pour connu que realoc qui pas traiter
    }

    // Remplissage des informations pour les nouveaux étudiants
    for (i = nbr; i < nv_nbr; i++) {
        printf("Pour l'étudiant %d :\n", i + 1);
        printf("Nom : ");
        scanf("%s", e[i].nom);
        printf("Prénom : ");
        scanf("%s", e[i].prenom);
        printf("Date de naissance (jj mm aaaa) : ");
        scanf("%d %d %d", &e[i].date.jour, &e[i].date.mois, &e[i].date.annes);
    }

    // Affichage des informations des étudiants
    printf("\nListe des étudiants :\n");
    for (i = 0; i < nv_nbr; i++) {
        printf ("\npour etudiant_%d :\n",i+1);
            printf ("nom:%s\t",e[i].nom);
            printf ("prenom:%s\t",e[i].prenom);
            printf ("dat de naissance : %d/%d/%d \n",e[i].date.jour,e[i].date.mois,e[i].date.annes);
    }

    // Libération de la mémoire reserver
    free(e);
}
        
    return 0;
}
