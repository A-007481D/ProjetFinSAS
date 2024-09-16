#include<stdio.h>
#include<string.h>

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
int nbrEtds = 8;

int main()
{
    int choix;

    do
    {

        printf("Entrez votre choix : ");
        scanf("%d", &choix);
        switch (choix)
        {
        case 1: 
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