#include "etudiant.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Déclaration des variable globale
int compteurEtudiant = 0;//variable contenant le nombre d'etudiant présent dans le groupe
GroupeEtudiant G;

//Implémentation du sous-programme nombreFille
int nombreFille(){
    int compteur = 0;//compteur initialisé à 0.
    for(int i = 0; i<compteurEtudiant; i++){ //la boucle for pour parcourire le groupe
        if(strcmp(G[i].sexe,"F")==0)//si le sexe de l'étudiant est féminin
            compteur++; //Le compteur est incrémenté à chaque le if est vérifié
    }
    return compteur;
}

//Implémentation du sous-programme nombreGarçon
int nombreGarcon(){
    int compteur = compteurEtudiant - nombreFille();
    return compteur;
}

//Implémentation du sous-programme ageMoyenne
int ageMoyen(){
    int moyenne; //déclaration de la variable qui va contenir la moyenne
    int sommeAge = 0;//la variable intermédiare qui contiendra la somme d'âge.
    for(int i = 0; i<compteurEtudiant; i++){
        sommeAge+=(2021-G[i].dateDeNaissance.annee);
    }
    if(compteurEtudiant==0)//Teste si la taille du tableau est vide
        moyenne=0;//dans ce cas de figure la moyenne est nul
    else
        moyenne=sommeAge/compteurEtudiant;
    return moyenne;
}

//Implémentation du sous-programme rechercheEtudiant
int rechercheEtudiant(char* matriculeEtu){//Fonction prédicat
    int i = 0;
    int verification = 0;
    while((i<compteurEtudiant) && strcmp(G[i].matricule, matriculeEtu)!=0)
        /*Ici la condiction pour sortir de la boucle while est que:
        Soit on trouve le matricule
        soit on parcourt tout le groupe d'étudiant
        */
        i+=1;
    if(i < compteurEtudiant)//si est égale à la taille du groupe d'étudiant
        verification = 1;
    return verification;
}

//Implémentation du sous-programme afficheEudiant
void afficheEtudiant(Etudiant etu){
    printf("\n---------------------------------------------------------------------------------------------\n");
    printf("Nom : %s\t Prenom : %s\t Date et lieu de naissance : %d-%d-%d a %s\n",
            etu.nom, etu.prenom, etu.dateDeNaissance.jour, etu.dateDeNaissance.mois,
             etu.dateDeNaissance.annee, etu.lieu);
    printf("Matricule : %s\t Parcourt-Types : %s\t Niveau : %d\t Sexe : %s \n", etu.matricule,
            etu.parcourtTypes, etu.niveau, etu.sexe);
}
void afficheGroupeEtudiant(){
    printf("Voici les %d membres du groupe d'etudiant\n", compteurEtudiant);
    for(int i = 0; i<compteurEtudiant; i++)
    {
        afficheEtudiant(G[i]);//Appel de la fonction pour afficher un étudiant
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
        scanf("%d", &newStudent.dateDeNaissance.mois);
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
        G[compteurEtudiant]=newStudent;//ajout d'un etudiant dans le groupe d'étudiant
        compteurEtudiant++;//incrémentation du nombre d'étudiant présent dans le groupe après l'ajout
    }
    
    
}

//Implémentation du programme menu
void menu(){
    char option[3]="NON";
    while(strcmp(option, "OUI")!=0 && strcmp(option, "oui")!=0 )
        //while pour repéter le menu tant que l'utilisateur n'entre pas OUI ou oui au moment indiquer
    {
        int choixMenu;
        printf("\n\n  ==================  Menu ==================\n\n");
        printf("1 - Ajouter des etudiant dans le groupe.\n");
        printf("2 - Determiner le nombre de fiile dans le groupe.\n");
        printf("3 - Determiner le nombre de Garcon dans le groupe.\n");
        printf("4 - Rechercher un etudiant.\n");
        printf("5 - Determiner l'age moyenne du groupe.\n");
        printf("6 - Afficher les membres du groupe.\n");
        printf("Entrez votre choix ?  ");
        scanf("%d", &choixMenu);
        printf("\n");

        switch(choixMenu)
        {
            case 1:
                addNewStudent();
                printf("\nVoulez vous quitter (OUI ou NON) ? ");
                scanf("%s", option);
                break;
            case 2:
                printf("Dans le groupe d'etudiant il y'a : %d fille(s)\n", nombreFille());
               printf("\nVoulez vous quitter (OUI ou NON) ? ");
                scanf("%s", option);
                break;
            case 3:
                printf("Dans le groupe d'etudiant il y'a : %d Garcon(s)\n", nombreGarcon());
               printf("\nVoulez vous quitter (OUI ou NON) ? ");
                scanf("%s", option);
                break;
            case 4:
                printf("Entrez le matricule de l'etudiant que vous rechercher :");
                char matEtudiant[8];
                scanf("%s", matEtudiant);
                char* deci="NON";
                if(rechercheEtudiant(matEtudiant)==1)//pour afficher OUI ou NON comme resultat de la recherche
                    deci="OUI";
                printf("L'etudiant de matricule %s est-il present : %s\n", matEtudiant, deci);
               printf("\nVoulez vous quitter (OUI ou NON) ? ");
                scanf("%s", option);
                break;
            case 5:
                printf("Dans le groupe d'etudiant la moyenne d'age est : %d an(s)\n\n", ageMoyen());
                printf("\nVoulez vous quitter (OUI ou NON) ? ");
                scanf("%s", option);
                break;
            case 6:
                afficheGroupeEtudiant();
                printf("\nVoulez vous quitter (OUI ou NON) ? ");
                scanf("%s", option);
                break;
            default:
                printf("\nVoulez vous quitter (OUI ou NON) ? ");
                scanf("%s", option);
                break;

        }
    }
}
