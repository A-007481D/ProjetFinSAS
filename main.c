#include<stdio.h>
#include<string.h>
#define max_etds 100
#define informatique 1
#define sciences 2
#define gestion 3
#define art_design 4

typedef struct
{
    int numUnique;
    char nom[20];
    char prenom[50];
    char dateNaissance[20];
    char departement[20];
    float noteGeneral;
} Etudiant;

Etudiant etudiant_t[max_etds];
int nbrEtds = 0;

void afficher_menu()
{
    printf("\n+=============================================================+");
    printf("\n|              ---------Menu Principal------------             |");
    printf("\n+=============================================================+\n");
    printf(" 1=> Ajouter un etudiant                                       |\n");
    printf(" 2=> Afficher les details d'un etudiant                        |\n");
    printf(" 3=> Rechercher un etudiant                                    |\n");
    printf(" 4=> Modifier ou supprimer un etudiant                         |\n");
    printf(" 5=> Trier les etudiants                                       |\n");
    printf(" 6=> Calculer la moyenne generale                              |\n");
    printf(" 7=> Statistiques                                              |\n");
    printf(" 0=> Quitter                                                   |\n");
    printf("+=============================================================+\n");
}

int departement(char depart[])
{
    int choix;
    printf("\n+=============================================================+");
    printf("\n|              --------Departement---------                   |");
    printf("\n+=============================================================+\n");
    printf("\n1=> Informatique\n2=> Sciences\n3=> Gestion\n4=> Art et Design\nChoisir votre departement : ");
    scanf("%d", &choix);

    switch (choix)
    {
    case informatique: strcpy(depart, "Informatique"); break;
    case sciences: strcpy(depart, "Sciences"); break;
    case gestion: strcpy(depart, "Gestion"); break;
    case art_design: strcpy(depart, "Art et Design"); break;
    default: printf("choix invalide, essayer a nouveau!");
    departement(depart);
    }
    return 0;
}

void ajouter_etudiant()
{

    printf("Entrer les informations de l'etudiant:\n");
    printf("Numero unique : ");
    scanf("%d", &etudiant_t[nbrEtds].numUnique);
    printf("Nom : ");
    scanf("%s", etudiant_t[nbrEtds].nom);
    printf("Prenom : ");
    scanf("%s", etudiant_t[nbrEtds].prenom);
    printf("Date de naissance (jour-mois-annee) : ");
    scanf("%s", etudiant_t[nbrEtds].dateNaissance);

    departement(etudiant_t[nbrEtds].departement);
    do
    {
        printf("Note Generale entre 0 et 20: ");
        scanf("%f", &etudiant_t[nbrEtds].noteGeneral);
    } while (etudiant_t[nbrEtds].noteGeneral < 0 || etudiant_t[nbrEtds].noteGeneral > 20);

    printf("Etudiant '%s' a ete ajoute avec succes nbr (%d).\n", etudiant_t[nbrEtds].nom, nbrEtds);
    nbrEtds++;
}


int main()
{
    int choix;

    do
    {

        printf("Entrez votre choix : ");
        scanf("%d", &choix);
        switch (choix)
        {
        case 1: ajouter_etudiant(); break;
        case 2: 
        case 3: 
        case 4: 
        case 5: 
        case 6: 
        case 7: 
        case 0: 
        return 0;
        default: 
        }
    } while (choix != 0);

    return 0;
}