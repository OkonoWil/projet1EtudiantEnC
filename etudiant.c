#include "etudiant.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE_NOM 25

//Implémentation du sous-programme nombreFille
int nombreFille(){
    int nbrEtudiant=nombreEtudiant();
    int compteur=0;
    FILE *fichier = NULL;
    fichier = fopen("SaveDir.sav", "r");
    if(fichier != NULL){
        Etudiant etud;
       while(!(feof(fichier))&&nbrEtudiant>0){
            fscanf(fichier,"%s %s %d %s %d %s %s %s %d %s", etud.nom, etud.prenom, &etud.dateDeNaissance.jour, etud.dateDeNaissance.mois, &etud.dateDeNaissance.annee, etud.lieu, etud.matricule, etud.parcourtTypes, &etud.niveau, etud.sexe);
            if(strcmp(etud.sexe,"F")==0 || strcmp(etud.sexe,"f")==0){//si le sexe de l'étudiant est féminin
                compteur++; //Le compteur est incrémenté à chaque le if est vérifié
                nbrEtudiant--;
            }
       }
        fclose(fichier);
    }
    return compteur;
}

//Implémentation du sous-programme nombreGarçon
int nombreGarcon(){
    int nbrEtudiant=nombreEtudiant();
    int compteurEtudiant=0;
    FILE *fichier = NULL;
    fichier = fopen("SaveDir.sav", "r");
    if(fichier != NULL){
        Etudiant etud;
        while(!(feof(fichier))&&nbrEtudiant>0){
            fscanf(fichier,"%s %s %d %s %d %s %s %s %d %s", etud.nom, etud.prenom, &etud.dateDeNaissance.jour, etud.dateDeNaissance.mois, &etud.dateDeNaissance.annee, etud.lieu, etud.matricule, etud.parcourtTypes, &etud.niveau, etud.sexe);
            if(strcmp(etud.sexe,"M")==0 || strcmp(etud.sexe,"m")==0){//si le sexe de l'étudiant est féminin
                compteurEtudiant++; //Le compteur est incrémenté à chaque le if est vérifié
                nbrEtudiant--;
                printf("%d -> ",compteurEtudiant);
        }
        }
        fclose(fichier);
    }
    return compteurEtudiant;
}

//Implémentation du sous-programme ageMoyenne
int ageMoyen(){
    int nbrEtudiant=nombreEtudiant();
    int moyenne; //déclaration de la variable qui va contenir la moyenne
    int sommeAge = 0;//la variable intermédiare qui contiendra la somme d'âge.
    FILE *fichier = NULL;
    fichier = fopen("SaveDir.sav", "r");
    if(fichier != NULL){
        Etudiant etud;
        while(!(feof(fichier))&&nbrEtudiant>0){
            fscanf(fichier,"%s %s %d %s %d %s %s %s %d %s", etud.nom, etud.prenom, &etud.dateDeNaissance.jour, etud.dateDeNaissance.mois, &etud.dateDeNaissance.annee, etud.lieu, etud.matricule, etud.parcourtTypes, &etud.niveau, etud.sexe);
            sommeAge+=(2021-etud.dateDeNaissance.annee);
            nbrEtudiant--;
        }
        fclose(fichier);
    }
    nbrEtudiant=nombreEtudiant();
    moyenne = sommeAge / nbrEtudiant;
    return moyenne;
}

//Implémentation du sous-programme rechercheEtudiant
int rechercheEtudiant(char matriculeEtu[10]){//Fonction
    int nbrEtudiant=nombreEtudiant();
    FILE *fichier = NULL;
    int i = 0;//int i = -1;
    int verification = 0;
    fichier = fopen("SaveDir.sav", "r");
    if(fichier != NULL){
        Etudiant etud;
        while(!(feof(fichier))&&nbrEtudiant>0){
            fscanf(fichier,"%s %s %d %s %d %s %s %s %d %s", etud.nom, etud.prenom, &etud.dateDeNaissance.jour, etud.dateDeNaissance.mois, &etud.dateDeNaissance.annee, etud.lieu, etud.matricule, etud.parcourtTypes, &etud.niveau, etud.sexe);
            if(strcmp(etud.matricule, matriculeEtu)!=0)
                /*  Ici la condiction pour sortir de la boucle while est que:
                    Soit on trouve le matricule
                    soit on parcourt tout le groupe d'étudiant
                */
                i++;
            nbrEtudiant--;
            }
        fclose(fichier);
        nbrEtudiant=nombreEtudiant();
        if(i < nbrEtudiant)//si est égale à la taille du groupe d'étudiant
            verification = 1;
    }
    return verification;
}

//Implémentation du sous-programme afficheEudiant
void afficheEtudiant(Etudiant etu){
    printf("\n---------------------------------------------------------------------------------------------\n");
    printf("Nom : %s\t Prenom : %s\t Date et lieu de naissance : %d %s %d a %s\n",
            etu.nom, etu.prenom, etu.dateDeNaissance.jour, etu.dateDeNaissance.mois,
             etu.dateDeNaissance.annee, etu.lieu);
    printf("Matricule : %s\t Parcourt-Types : %s\t Niveau : %d\t Sexe : %s \n", etu.matricule,
            etu.parcourtTypes, etu.niveau, etu.sexe);
}
void afficheGroupeEtudiant(){
    int nbrEtudiant=nombreEtudiant();
    FILE *fichier = NULL;
    fichier = fopen("SaveDir.sav", "r");
    if(fichier != NULL){
        printf("Voici les %d membres du groupe d'etudiant\n", nbrEtudiant);
        Etudiant etud;
        while(!(feof(fichier))&&nbrEtudiant>0){
            fscanf(fichier,"%s %s %d %s %d %s %s %s %d %s", etud.nom, etud.prenom, &etud.dateDeNaissance.jour, etud.dateDeNaissance.mois, &etud.dateDeNaissance.annee, etud.lieu, etud.matricule, etud.parcourtTypes, &etud.niveau, etud.sexe);
            afficheEtudiant(etud);
            nbrEtudiant--;
        }
        fclose(fichier);
    }
}

//Implémentation du sous-programme addNewStudent celle-ci permet de créer un nouveau etudiant
//Et de l'ajouter dans le groupe
void addNewStudent(){
    printf("Combien d'etudiant voulez vous ajouter au groupe?  ");
    int nEtudiant;
    scanf("%d", &nEtudiant);
    for (int i = 0; i < nEtudiant; i++)
    {
        printf("\nEntrez les informations de l'etudiant %d\n", i+1);
        Etudiant newStudent;
        printf("Entrez son nom : ");
        scanf("%s", newStudent.nom);
        printf("Entrez son prenom : ");
        scanf("%s", newStudent.prenom);
        printf("Entrez son jour de naissance : ");
        scanf("%d", &newStudent.dateDeNaissance.jour);
        printf("Entrez son mois de naissance : ");
        scanf("%s", newStudent.dateDeNaissance.mois);
        printf("Entrez son annee de naissance : ");
        scanf("%d", &newStudent.dateDeNaissance.annee);
         printf("Entrez son lieu de naissance : ");
        scanf("%s", newStudent.lieu);
        printf("Entrez son sexe (M ou F) : ");
        scanf("%s", newStudent.sexe);
        printf("Entrez son matricule : ");
        scanf("%s", newStudent.matricule);
        printf("Entrez son parcourt-types : ");
        scanf("%s", newStudent.parcourtTypes);
        printf("Entrez son niveau : ");
        scanf("%d", &newStudent.niveau);
        saveStudent(newStudent); //Nous enregistrons ainsi les données du nouveau étudiant dans notre fichier.
    }


}

void decision(char *pointeurOpt){
    printf("\nVoulez vous quitter ( 'OUI' ou 'NON' ) ?  \t");
    scanf("%s", pointeurOpt);
}
void decision2(char *pointeurOpt){
    printf("\nVoulez vous vraiment quitter le mini-programme ( 'OUI' ou 'NON' ) ?  \t");
    scanf("%s", pointeurOpt);
}

//Implémentation du programme menu
void menu(){
    char option[3] = "NON";
    while((strcmp(option, "OUI") !=0) && (strcmp(option, "oui") !=0)){  //while pour repéter le menu tant que l'utilisateur n'entre pas OUI ou oui au moment indiquer
        int choixMenu;
        printf("\n\n  ==================  Menu ==================\n\n");
        printf("1 - Ajouter des etudiant dans le groupe.\n");
        printf("2 - Determiner le nombre de fiile dans le groupe.\n");
        printf("3 - Determiner le nombre de Garcon dans le groupe.\n");
        printf("4 - Rechercher un etudiant.\n");
        printf("5 - Determiner l'age moyenne du groupe.\n");
        printf("6 - Afficher les membres du groupe.\n");
        printf("7 - Determiner le nombre d'etudiant present dans le groupe.\n");
        printf("8 - Quitter le programme.\n ");
        printf("Entrez votre choix ?  \t");
        scanf("%d", &choixMenu);
        printf("\n");

        switch(choixMenu)
        {
            case 1:
                addNewStudent();
                decision(option);
                break;
            case 2:
                printf("Dans le groupe d'etudiant il y'a : %d fille(s)\n", nombreFille());
                decision(option);
                break;
            case 3:
                printf("Dans le groupe d'etudiant il y'a : %d Garcon(s)\n", nombreGarcon());
                decision(option);
                break;
            case 4:
                printf("Entrez le matricule de l'etudiant que vous rechercher :");
                char matEtudiant[8];
                scanf("%s", matEtudiant);
                char* deci="NON";
                if(rechercheEtudiant(matEtudiant)==1)//pour afficher OUI ou NON comme resultat de la recherche
                    deci="OUI";
                printf("L'etudiant de matricule %s est-il present : %s\n", matEtudiant, deci);
                decision(option);
                break;
            case 5:
                printf("Dans le groupe d'etudiant la moyenne d'age est : %d an(s)\n", ageMoyen());
                decision(option);
                break;
            case 6:
                afficheGroupeEtudiant();
                decision(option);
                break;
            case 7:
                printf("Le nombre d'etudiant est %d etudiant(s)\n", nombreEtudiant());
                decision(option);
                break;
            case 8:
                decision2(option);
                break;
            default:
                decision(option);
                break;

        }
    }

    printf("\nMerci d'avoir utiliser notre mini-programme. :)\n");
    printf("\n  =========================  Arret =========================\n\n");
}

void saveStudent(Etudiant etud){
    FILE *fichier = NULL;
    fichier = fopen("SaveDir.sav", "a");
    if(fichier != NULL)
        fprintf(fichier,"%s %s %d %s %d %s %s %s %d %s\n",etud.nom, etud.prenom, etud.dateDeNaissance.jour, etud.dateDeNaissance.mois, etud.dateDeNaissance.annee, etud.lieu, etud.matricule, etud.parcourtTypes, etud.niveau, etud.sexe);
    fclose(fichier);

}



int nombreEtudiant(){
    int a=-1;
    FILE *fichier = NULL;
    fichier = fopen("SaveDir.sav", "r");
    if(fichier != NULL){
        Etudiant etud;
       while(!(feof(fichier))){
            fscanf(fichier,"%s %s %d %s %d %s %s %s %d %s", etud.nom, etud.prenom, &etud.dateDeNaissance.jour, etud.dateDeNaissance.mois, &etud.dateDeNaissance.annee, etud.lieu, etud.matricule, etud.parcourtTypes, &etud.niveau, etud.sexe);
            a++;
        }
        fclose(fichier);
    }
    return a;
}
