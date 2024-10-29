#include <stdio.h>

struct tache {
    char title[100];
    char description[100];
    char date[10];
    int priorite;
};

void creer(struct tache *tache) {
    printf("Title : ");
    scanf(" %[^\n]%*c", tache->title); 

    printf("Description : ");
    scanf(" %[^\n]%*c", tache->description); 

    printf("Date (format: YYYY-MM-DD) : ");
    scanf("%9s", tache->date); 

    printf("Priorite (1 for High, 0 for Low) : ");
    scanf("%d", &tache->priorite); 
}


void afficher(struct tache tache) {
    printf("----------------------- Informations de %s ----------------------\n", tache.title);
    printf("title : %s\n", tache.title);
    printf("description : %s\n", tache.description);
    printf("date : %s\n", tache.date);  
    printf("priorite : %s\n", tache.priorite? "Hight" : "Low");  
}

void modifie(struct tache *tache) {
    printf("Modifier le title : \n");
    scanf("%s", tache->title); 

    printf("Modifier description : \n");
    scanf("%d", &tache->description); 

    printf("Modifier date : \n");
    scanf("%s", tache->date); 

    printf("Modifier la priorite : \n");
    scanf("%s", tache->priorite); 

}

void supprimer(struct tache tache[], int *nbrtache, int index) {
    for (int i = index; i < (*nbrtache) - 1; i++) {
        tache[i] = tache[i + 1];
    }
    (*nbrtache)--;
}


int main() {
    struct tache tache[50];  
    int nbrtache = 0;           
    int choix, indice;

    do {
        printf("\n------------------Menu-----------------\n");
        printf("1. Ajouter une Tache\n");
        printf("2. Afficher la Liste des Tches\n");
        printf("3. Modifier une Tache\n");
        printf("4. Supprimer une Tache\n");
        printf("5. Filtrer les Taches\n");
        printf("6. Quitter\n");
        printf("Choisissez une option : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: 
                if (nbrtache < 50) {
                    creer(&tache[nbrtache]);
                    nbrtache++;
                } else {
                    printf("Erreur : Le tableau est plein.\n");
                }
                break;

            case 2: 
                if (nbrtache == 0) {
                    printf("Aucune Tache enregistree.\n");
                } else {
                    printf("\nListe des tache :\n");
                    for (int i = 0; i < nbrtache; i++) {
                        afficher(tache[i]);
                    }
                }
                break;

            case 3: 
                if (nbrtache == 0) {
                    printf("Aucune tache enregistree.\n");
                } else {
                    printf("Entrez l'indice de la tache à modifier (0 à %d) : ", nbrtache - 1);
                    scanf("%d", &indice);
                    if (indice >= 0 && indice < nbrtache) {
                        modifie(&tache[indice]);
                    } else {
                        printf("Indice invalide.\n");
                    }
                }
                break;

            case 4: 
                if (nbrtache == 0) {
                    printf("Aucune tache enregistree.\n");
                } else {
                    printf("Entrez lindice de la tache a supprimer ( 0 à %d) : ", nbrtache - 1);
                    scanf("%d", &indice);
                    if (indice >= 0 && indice < nbrtache) {
                        supprimer(tache, &nbrtache, indice);
                        printf("tache supprimee.\n");
                    } else {
                        printf("Indice invalide.\n");
                    }
                }
                break;

           

            case 5: 
                printf("Au revoir!\n");
                break;

            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }
    } while (choix != 5);

    return 0;
}
