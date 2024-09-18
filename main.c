#include<stdio.h>
#include<string.h>

#define max_etds 100
#define note_max 20.00
#define note_min 0.00
#define seuil_reussite 10.00

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

Etudiant etudiant_t[max_etds] = {
    {11, "Labid", "Abdelmalek", "25/11/2000", "Gestion", 16.22},
    {12, "Lmerrakchi", "Hamza", "25/11/2010", "Sciences", 15.21},
    {13, "Youness", "MrToken", "25/11/2006", "Art et Design", 11.65},
    {14, "Mokhtar", "hafid", "25/11/2001", "Gestion", 10.22} ,
    {15, "Boutaib", "Anass", "12/12/2004", "Informatique", 20.78},
    {16, "Yamal", "Lamine", "12/12/2006", "Sciences", 9.99},
    {17, "Eddarkaoui", "Oussama", "04/12/2005", "Informatique", 14.33},
    {18, "Taoudi", "Ahmed", "11/22/2001", "Gestion", 12.32}

};

int nbrEtds = 8;

void afficher_menu()
{
    printf("\n+=============================================================+");
    printf("\n|              ---------Menu Principal------------             |");
    printf("\n+=============================================================+\n");
    printf(" 1️⃣ => Ajouter un etudiant                                       |\n");
    printf(" 2️⃣ => Afficher les details d'un etudiant                        |\n");
    printf(" 3️⃣ => Rechercher un etudiant                                    |\n");
    printf(" 4️⃣ => Modifier ou supprimer un etudiant                         |\n");
    printf(" 5️⃣ => Trier les etudiants                                       |\n");
    printf(" 6️⃣ => Calculer la moyenne generale                              |\n");
    printf(" 7️⃣ => Statistiques                                              |\n");
    printf(" 0️⃣ => Quitter                                                   |\n");
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
    if (nbrEtds >= max_etds) 
    {
    printf("Limite maximale des etudiants atteinte.\n");
    return;
    }

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
        printf("Note Generale entre (%2.f et %2.f): ", note_min, note_max);
        scanf("%f", &etudiant_t[nbrEtds].noteGeneral);
    } while (etudiant_t[nbrEtds].noteGeneral < note_min || etudiant_t[nbrEtds].noteGeneral > note_max);

    printf("Etudiant '%s' a ete ajoute avec succes #%d.\n", etudiant_t[nbrEtds].nom, nbrEtds + 1);
    nbrEtds++;
}


void afficherDetails()
{
    if (nbrEtds == 0)
    {
        printf("Aucun etudiant enregistre.\n");
        return;
    }

    printf("+-------+------------------+------------------+-------------------+------------------+\n");
    printf("|  ID   |       Nom        |     Prenom       |  Date Naissance   |   Departement    |\n");
    printf("+-------+------------------+------------------+-------------------+------------------+\n");

    for (int i = 0; i < nbrEtds; i++)
    {
        printf("| %5d | %-16s | %-16s | %-17s | %-16s |\n", 
            etudiant_t[i].numUnique, 
            etudiant_t[i].nom, 
            etudiant_t[i].prenom, 
            etudiant_t[i].dateNaissance, 
            etudiant_t[i].departement);
    }

    printf("+-------+------------------+------------------+-------------------+------------------+\n");
}


void rechercher()
{
    int i, choix;
        printf("\n+=============================================================+");
        printf("\n|              --------- Recherche ----------                 |");
        printf("\n+=============================================================+\n");
        printf("\n1️⃣ => Recherche par nom\n2️⃣ => Recherche par departement\n3️⃣ => Retour\n");
        printf("\n+=============================================================+\n");
    printf("Saisir votre choix  : ");
    scanf("%d", &choix);

    if (choix == 1)
    {
        char nom[20];
        int i;
        printf("Entrez le nom de l'etudiant a rechercher : ");
        scanf("%s", nom);
        for (i = 0; i < nbrEtds; i++)
        {
            if (strcmp(etudiant_t[i].nom, nom) == 0)
            {
                printf("+-------+------------------+------------------+-------------------+------------------+\n");
                printf("|  ID   |       Nom        |     Prenom       |  Date Naissance   |   Departement    |\n");
                printf("+-------+------------------+------------------+-------------------+------------------+\n");
    {
                printf("| %5d | %-16s | %-16s | %-17s | %-16s |\n", 
                etudiant_t[i].numUnique, 
                etudiant_t[i].nom, 
                etudiant_t[i].prenom, 
                etudiant_t[i].dateNaissance, 
                etudiant_t[i].departement);
    }

                printf("+-------+------------------+------------------+-------------------+------------------+\n");
                // printf("\nNumero unique: %d | Nom: %s | Prenom: %s | Date de naissance: %s | Departement: %s | Note generale: %.2f\n", etudiant_t[i].numUnique, etudiant_t[i].nom, etudiant_t[i].prenom, etudiant_t[i].dateNaissance, etudiant_t[i].departement, etudiant_t[i].noteGeneral);
            } 
        }
        printf("Etudiant non trouve.\n");
    }
    else if (choix == 2)
    {
        int i, id_dept;
        char deprt[20];
        printf("\n+=============================================================+");
        printf("\n|              ---------Departement----------                 |");
        printf("\n+=============================================================+\n");
        printf("\n1️⃣ => Informatique\n2️⃣ => Sciences\n3️⃣ => Gestion\n4️⃣ => Art et Design\n");
        printf("\n+=============================================================+\n");
    
        printf("Entrez le departement a rechercher : ");
        scanf("%d", &id_dept);

        if (id_dept == 1) { strcpy(deprt, "Informatique"); } 
        else if (id_dept == 2){ strcpy(deprt, "Sciences"); } 
        else if (id_dept == 3){ strcpy(deprt, "Gestion");} 
        else if (id_dept == 4){ strcpy(deprt, "Art et Design");} 
        else { 
            return;
            
        }

        for(i = 0; i < nbrEtds; i++)
        {
            if (strcmp(etudiant_t[i].departement, deprt) == 0)
            {
                printf("+-------+------------------+------------------+-------------------+------------------+\n");
                printf("|  ID   |       Nom        |     Prenom       |  Date Naissance   |   Departement    |\n");
                printf("+-------+------------------+------------------+-------------------+------------------+\n");
    {
                printf("| %5d | %-16s | %-16s | %-17s | %-16s |\n", 
                etudiant_t[i].numUnique, 
                etudiant_t[i].nom, 
                etudiant_t[i].prenom,               //fix wrong display later
                etudiant_t[i].dateNaissance, 
                etudiant_t[i].departement);
    }

                printf("+-------+------------------+------------------+-------------------+------------------+\n");
                // printf("\nNumero unique: %d | Nom: %s | Prenom: %s | Date de naissance: %s | Departement: %s | Note generale: %.2f\n", etudiant_t[i].numUnique, etudiant_t[i].nom, etudiant_t[i].prenom, etudiant_t[i].dateNaissance, etudiant_t[i].departement, etudiant_t[i].noteGeneral);
            }
        }
    }

    
}

void modiferSupprimer()
{
    int num, i, j, choix;
    printf("Entrez le numero unique de l'etudiant : ");
    scanf("%d", &num);

    for(i = 0; i < nbrEtds; i++)
    {
        if(etudiant_t[i].numUnique == num)
        {
            printf("1️⃣ => Modifier l'etudiant\n");
            printf("2️⃣ => Supprimer l'etudiant\n");
            printf("0️⃣ => Return\n");
            printf("Saisir votre choix  : ");
            scanf("%d", &choix);
            if (choix == 1)
            {

                printf("Nouveau Prenom : ");
                scanf("%s", etudiant_t[i].prenom);
                printf("Nouvelle Date de naissance (jour-mois-annee) : ");
                scanf("%s", etudiant_t[i].dateNaissance);
                return;
            }
            else if(choix == 2)
            {

                for(j = i; j < nbrEtds; j++)
                {
                    etudiant_t[j] = etudiant_t[j+1];
                }
                nbrEtds--;
                printf("Etudiant supprimé avec succes.\n");
                return;
            }
        }
    }
    printf("Etudiant non trouve.\n");
}

void trierA2Z()
{
    int i, j;
    // printf(" nom : %s\n", etudiant_t[0].nom);
    // printf(" nom : %d\n", nbrEtds);

    for (i = 0; i < nbrEtds - 1; i++)
    {
        for (j = 0; j < nbrEtds - i - 1; j++)
        {
            if (strcmp(etudiant_t[j].nom, etudiant_t[j + 1].nom) > 0)
            {
                Etudiant temp = etudiant_t[j];
                etudiant_t[j] = etudiant_t[j + 1];
                etudiant_t[j + 1] = temp;
            }
        }
    }
    printf("Etudiants tries par ordre alphabetique (A-Z).\n");
    int k;
    for (k = 0; k < nbrEtds; k++)
    {
        printf("\nNumero unique: %d | Nom: %s | Prenom: %s | Date de naissance: %s | Departement: %s | Note generale: %.2f\n", etudiant_t[k].numUnique, etudiant_t[k].nom, etudiant_t[k].prenom, etudiant_t[k].dateNaissance, etudiant_t[k].departement, etudiant_t[k].noteGeneral);
    }
}


void trierZ2A()
{
    int i, j;

    for(i = 0; i < nbrEtds - 1; i++){
        for(j = 0; j < nbrEtds - i - 1; j++){
            if(strcmp(etudiant_t[j].nom, etudiant_t[j + 1].nom) < 0)
            {
                Etudiant temp = etudiant_t[j];
                etudiant_t[j] = etudiant_t[j + 1];
                etudiant_t[j + 1] = temp;    
            }
        }
    }
    printf("Etudiants tries par ordre alphabetique (Z-A).\n");
    int k;
    for (k = 0; k < nbrEtds; k++)
    {
        printf("\nNumero unique: %d | Nom: %s | Prenom: %s | Date de naissance: %s | Departement: %s | Note generale: %.2f\n", etudiant_t[k].numUnique, etudiant_t[k].nom, etudiant_t[k].prenom, etudiant_t[k].dateNaissance, etudiant_t[k].departement, etudiant_t[k].noteGeneral);
    }

}

void trierStatus()
{
    int i, k;
    printf("\nEtudiants Admis.\n");
    for (i = 0; i < 3; i++)
    {
        if (etudiant_t[i].noteGeneral >= seuil_reussite)
        {
            printf("\nNumero unique: %d | Nom: %s | Prenom: %s | Date de naissance: %s | Departement: %s | Note generale: %.2f\n", etudiant_t[i].numUnique, etudiant_t[i].nom, etudiant_t[i].prenom, etudiant_t[i].dateNaissance, etudiant_t[i].departement, etudiant_t[i].noteGeneral);
        }
    }

    printf("\nEtudiants non Admis.\n");
    for (k = 0; k < nbrEtds; k++)
    {
        if (etudiant_t[k].noteGeneral <= seuil_reussite)
        {
            printf("\nNumero unique: %d | Nom: %s | Prenom: %s | Date de naissance: %s | Departement: %s | Note generale: %.2f\n", etudiant_t[k].numUnique, etudiant_t[k].nom, etudiant_t[k].prenom, etudiant_t[k].dateNaissance, etudiant_t[k].departement, etudiant_t[k].noteGeneral);
        }
    }
}

void trierMoyGen()
{
    int i, j, k;
    for (i = 0; i < nbrEtds; i++)
    {
        for (j = 0; j < nbrEtds - i - 1; j++)
        {
            if (etudiant_t[j].noteGeneral > etudiant_t[j+1].noteGeneral)
            {
                Etudiant temp = etudiant_t[j];
                etudiant_t[j] = etudiant_t[j + 1];
                etudiant_t[j + 1] = temp;
            }
        }
    }
    printf("\nEtudiants tries par moyenne generale.\n");
    for (k = 0; k < nbrEtds; k++)
    {
        printf("\nNumero unique: %d | Nom: %s | Prenom: %s | Date de naissance: %s | Departement: %s | Note generale: %.2f\n", etudiant_t[k].numUnique, etudiant_t[k].nom, etudiant_t[k].prenom, etudiant_t[k].dateNaissance, etudiant_t[k].departement, etudiant_t[k].noteGeneral);
    }

}


void statistiques()
{

    int i, choix, nbrReussite = 0;
    printf("\nChoisir votre operation de statistiques : ");
    printf("\n1️⃣ => Afficher le nombre total d'étudiants inscrits.\n2️⃣ => Afficher le nombre d'étudiants dans chaque département.\n3️⃣ => Afficher les étudiants ayant une moyenne générale supérieure à un certain seuil.\n4️⃣ => Afficher les 3 étudiants ayant les meilleures notes.\nChoisir votre operation: ");
    scanf("%d", &choix);

    if (choix == 1){
        printf("Nombre total des etudiants inscrits : %d", nbrEtds);
    }
    else if (choix == 2 ) {
        int deptEtds[4] = {0};
        for (i = 0; i < nbrEtds; i++){
            if(strcmp(etudiant_t[i].departement, "Informatique") == 0){
                deptEtds[0]++;
            }
            else if(strcmp(etudiant_t[i].departement, "Gestion") == 0){
                deptEtds[1]++;
            }
            else if (strcmp(etudiant_t[i].departement, "Sciences") == 0){
                deptEtds[2]++;
            }
            else {
                deptEtds[3]++;
            }
        }

        printf("Le nombre des etudiants de departement Informatique : %.d\n",deptEtds[0]);
        printf("Le nombre des etudiants de departement Gestion : %d\n",deptEtds[1]);
        printf("Le nombre des etudiants de departement Sciences : %d\n",deptEtds[2]);
        printf("Le nombre des etudiants de departement Art et dEsign : %d\n", deptEtds[3]);

    }

    else if (choix ==3){
        float seuil;

        printf("entrez la seuil : ");
        scanf("%f", &seuil);
        for (i = 0; i < nbrEtds; i++) {
            if (etudiant_t[i].noteGeneral > seuil) {
            printf("\nNumero unique: %d | Nom: %s | Prenom: %s | Date de naissance: %s | Departement: %s | Note generale: %.2f\n", etudiant_t[i].numUnique, etudiant_t[i].nom, etudiant_t[i].prenom, etudiant_t[i].dateNaissance, etudiant_t[i].departement, etudiant_t[i].noteGeneral);
            }
        }
    }

    else if (choix == 4){
        int i, j;
        for (i = 0; i < nbrEtds; i++)
        {
            for (j = 0; j < nbrEtds - i - 1; j++)
            {
                if (etudiant_t[j].noteGeneral < etudiant_t[j+1].noteGeneral)
                {
                    Etudiant temp = etudiant_t[j];
                    etudiant_t[j] = etudiant_t[j + 1];
                    etudiant_t[j + 1] = temp;
                }
            }
        }

        for (i = 0; i < 3; i++) {
            printf("\nNumero unique: %d | Nom: %s | Prenom: %s | Date de naissance: %s | Departement: %s | Note generale: %.2f\n", etudiant_t[i].numUnique, etudiant_t[i].nom, etudiant_t[i].prenom, etudiant_t[i].dateNaissance, etudiant_t[i].departement, etudiant_t[i].noteGeneral);
            }
    }
     

     
     
     
     
    else if(choix == 5){
        for (i = 0; i < nbrEtds; i++)
    {
        if (etudiant_t[i].noteGeneral >= seuil_reussite)
        {
            nbrReussite++;
        }
    }
    printf("Nombre d'etudiants reussi (>= %.2f) : %d\n", seuil_reussite, nbrReussite);

    }
    else {
        printf("Retour...");
    }
    
}


void calculerMoy()
{   
    float deptMoy[4] = {0};
    int deptEtds[4] = {0};
    int i;
    float somme = 0;

    for (i = 0; i < nbrEtds; i++){
        if(strcmp(etudiant_t[i].departement, "Informatique") == 0){
            deptMoy[0] += etudiant_t[i].noteGeneral;
            deptEtds[0]++;
        }
        else if(strcmp(etudiant_t[i].departement, "Gestion") == 0){
            deptMoy[1] += etudiant_t[i].noteGeneral;
            deptEtds[1]++;
        }
        else if (strcmp(etudiant_t[i].departement, "Sciences") == 0){
            deptMoy[2] += etudiant_t[i].noteGeneral;
            deptEtds[2]++;
        }
        else {
            deptMoy[3] += etudiant_t[i].noteGeneral;
            deptEtds[3]++;
        }

    
        somme += etudiant_t[i].noteGeneral;
    }
    
    printf("La moyenne de departement Informatique : %.2f\n", deptMoy[0] / deptEtds[0]);
    printf("La moyenne de departement Gestion : %.2f\n", deptMoy[1] / deptEtds[1]);
    printf("La moyenne de departement Sciences : %.2f\n", deptMoy[2] / deptEtds[2]);
    printf("La moyenne de departement Art et dEsign : %.2f\n", deptMoy[3] / deptEtds[3]);
    printf("La moyenne generale des etudiants est : %.2f\n", somme / nbrEtds);
}


void triOps()
{
    int choix;
    printf("\n+=============================================================+");
    printf("\n|       --------Menu Des operations du Triage ---------       |");
    printf("\n+=============================================================+\n");
    printf("\nChoisir votre operation de triage : ");
    printf("\n1=> Trier par ordre alphabetique(A -> Z)\n2=> Trier par ordre alphabetique(Z -> A)\n3=> Trier par moyenne generale(du plus élevé au plus faible.)\n4=> Tri par statut de réussite (>= 10/20)\n0=> Retour au menu principal\nChoisir votre operation: ");
    scanf("%d", &choix);
    switch (choix)
    {
    case 1: trierA2Z(); break;
    case 2: trierZ2A(); break;
    case 3: trierMoyGen(); break;
    case 4: trierStatus(); break;
    default: printf("retour au menu...");
    }
}

int main()
{
    int choix;

    do
    {
        afficher_menu();
        printf("Entrez votre choix : ");
        scanf("%d", &choix);
        switch (choix)
        {
        case 1: ajouter_etudiant(); break;
        case 2: afficherDetails(); break;
        case 3: rechercher(); break;
        case 4: modiferSupprimer(); break;
        case 5: triOps();break;
        case 6: calculerMoy(); break;
        case 7: statistiques(); break;
        case 0: printf("En sortie.\n");
        return 0;
        default: printf("choix invalide, essayer a nouveau!\n");
        }
    } while (choix != 0);

    return 0;
}