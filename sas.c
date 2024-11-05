#include <stdio.h>
#include <string.h>
#include <time.h>

struct tache {
    char title[100];
    char description[100];
    char date[11]; 
    int priorite;
    int status;
};



void creer(struct tache *tache) {
    int year, month, day;
    char input[11];

    printf("Title : ");
    scanf(" %[^\n]%*c", tache->title); 

    printf("Description : ");
    scanf(" %[^\n]%*c", tache->description); 

    while (1) { 
        printf("Date (YYYY-MM-DD): ");
        scanf("%4d-%2d-%2d", &year, &month, &day); 

        if (year >= 2024 && month >= 1 && month <= 12 && day >= 1 && day <= 31) {
            sprintf(tache->date, "%04d-%02d-%02d", year, month, day);
            break; 
        } else {
            printf("Invalid date entered. Please enter a valid date (YYYY-MM-DD) .\n");
        }

    }

    printf("Priorite (1 for High, 0 for Low) : ");
    scanf("%d", &tache->priorite); 
   
}

void afficher(struct tache tache) {
    printf("----------------------- Informations de %s ----------------------\n", tache.title);
    printf("title : %s\n", tache.title);
    printf("description : %s\n", tache.description);
    printf("date : %s\n", tache.date);  
    printf("priorite : %s\n", tache.priorite ? "High" : "Low");  
    printf("status : %s\n", tache.status ? "complete" : "incomplete");  
}

void modifie(struct tache *tache) {
    int year, month, day;
    printf("Modifier le title : \n");
    scanf(" %[^\n]%*c", tache->title); 

    printf("Modifier description : \n");
    scanf(" %[^\n]%*c", tache->description); 

    while (1) { 
        printf("Date (YYYY-MM-DD): ");
        scanf("%4d-%2d-%2d", &year, &month, &day); 

        if (year >= 2024 && month >= 1 && month <= 12 && day >= 1 && day <= 31) {
            sprintf(tache->date, "%04d-%02d-%02d", year, month, day);
            break; 
        } else {
            printf("Invalid date entered. Please enter a valid date (YYYY-MM-DD) .\n");
        }

    } 

    printf("Modifier la priorite : \n");
    scanf("%d", &tache->priorite); 
}

void supprimer(struct tache tache[], int *nbrtache, int index) {
    for (int i = index; i < (*nbrtache) - 1; i++) {
        tache[i] = tache[i + 1];
    }
    (*nbrtache)--;
}

void filtrer_par_statut(struct tache taches[], int nbrtache, int status) {
    printf("\n--- Tâches avec statut %s ---\n", status == 1 ? "Complete" : "Incomplete");
    for (int i = 0; i < nbrtache; i++) {
        if (taches[i].status == status) {
            afficher(taches[i]);
        }
    }
}

void Status(struct tache *tache) {
    tache->status = !tache->status;
    printf("Task marked as %s.\n", tache->status ? "Complete" : "Incomplete");
}

void filtrer_par_priorite(struct tache taches[], int nbrtache, int priorite) {

    printf("\n--- Tâches avec priorite %s ---\n", priorite == 1 ? "High" : "Low");
    for (int i = 0; i < nbrtache; i++) {
        if (taches[i].priorite == priorite) {
            afficher(taches[i]);
        }
    }
}

void croissantdate(struct tache tache[], int taskCount) {
    for (int i = 0; i < taskCount - 1; i++) { 
        int indexMin = i;
        for (int j = i + 1; j < taskCount; j++) {
            if (strcmp(tache[j].date, tache[indexMin].date) < 0) {
                indexMin = j;
            }
        }
        if (indexMin != i) {
            struct tache temp = tache[i];
            tache[i] = tache[indexMin];
            tache[indexMin] = temp;
        }
    }

    printf("Tasks ordered by ascending date\n");
    printf("--------------------------------------------\n");
}

void decroissantdate(struct tache tache[], int taskCount) {
    for (int i = 0; i < taskCount - 1; i++) {  
        int indexMax = i;
        for (int j = i + 1; j < taskCount; j++) {
            if (strcmp(tache[j].date, tache[indexMax].date) > 0) {
                indexMax = j;
            }
        }
        if (indexMax != i) {
            struct tache temp = tache[i];
            tache[i] = tache[indexMax];
            tache[indexMax] = temp;
        }
    }

    printf("Tasks ordered by descending date\n");
    printf("--------------------------------------------\n");
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
        printf("5. Filtrer par prioeite\n");
        printf("6. Filtrer par status\n");
        printf("7. tri croissant \n");
        printf("8. tri decroissant\n");
        printf("9. marquer une tache comme complete/incomplete\n");
        printf("10. affiche par indece\n");
        printf("11. Quitter\n");
        printf("hoisissez une option : ");
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
                    printf("Entrez lindice de la tache a modifier (0 à %d) : ", nbrtache - 1);
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
                    printf("Entrez lindice de la tache a supprimer (0 à %d) : ", nbrtache - 1);
                    scanf("%d", &indice);
                    if (indice >= 0 && indice < nbrtache) {
                        supprimer(tache, &nbrtache, indice);
                        printf("Tache supprimee.\n");
                    } else {
                        printf("Indice invalide.\n");
                    }
                }
                break;

            case 5:
                if (nbrtache == 0) {
                    printf("Aucune Tache enregistree.\n");
                } else {
                    int priorite;
                    printf("Entrez la Priorité a filtrer (0 pour High, 1 pour Low) : ");
                    scanf("%d", &priorite);
                    filtrer_par_priorite(tache, nbrtache, priorite);
                }
                break;
            case 6:
                if (nbrtache == 0) {
                    printf("Aucune Tache enregistree.\n");
                } else {
                    int status;
                    printf("Entrez la status a filtrer (0 pour incomplete, 1 pour complete) : ");
                    scanf("%d", &status);
                    filtrer_par_statut(tache, nbrtache, status);
                }
                break;
            case 7:
                if (nbrtache == 0) {
                    printf("Aucune Tache enregistree.\n");
                } else {
                    croissantdate(tache, nbrtache);
                        for (int i = 0; i < nbrtache; i++) {
                        afficher(tache[i]);
                    }

                }
                break;
            case 8:
                if (nbrtache == 0) {
                    printf("Aucune Tache enregistree.\n");
                } else {
                     decroissantdate(tache, nbrtache);
                  for (int i = 0; i < nbrtache; i++) {
                        afficher(tache[i]);
                    }

                }
                break;
            case 9:
                if (nbrtache == 0) {
                    printf("Aucune tache enregistree.\n");
                } else {
                    printf("Entrez lindice de la tache a marquer comme Complete/Incomplete (0 à %d) : ", nbrtache - 1);
                    scanf("%d", &indice);
                    if (indice >= 0 && indice < nbrtache) {
                        Status(&tache[indice]);
                    } else {
                        printf("Indice invalide.\n");
                    }
                }
                break;
            case 10: 
                printf("Au revoir!\n");
                break;

            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }
    } while (choix != 10); 

    return 0;
}
