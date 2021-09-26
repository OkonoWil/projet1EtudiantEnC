#include "etudiant.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//D�claration des variable globale
int compteurEtudiant = 0;//variable contenant le nombre d'�tudiant pr�sent dans le groupe
GroupeEtudiant G;

//Impl�mentation du sous-programme nombreFille
int nombreFille(){
    int compteur = 0;//compteur initialis� � 0.
    for(int i = 0; i<compteurEtudiant; i++){ //la boucle for pour parcourire le groupe
        if(strcmp(G[i].sexe,"F")==0)//si le sexe de l'�tudiant est f�minin
            compteur++; //Le compteur est incr�ment� � chaque le if est v�rifi�
    }
    return compteur;
}

//Impl�mentation du sous-programme ageMoyenne
int ageMoyen(){
    int moyenne; //d�claration de la variable qui va contenir la moyenne
    int sommeAge = 0;//la variable interm�diare qui contiendra la somme d'�ge.
    for(int i = 0; i<compteurEtudiant; i++){
        sommeAge+=(2021-G[i].dateDeNaissance.annee);
    }
    if(compteurEtudiant==0)//Teste si la taille du tableau est vide
        moyenne=0;//dans ce cas de figure la moyenne est nul
    else
        moyenne=sommeAge/compteurEtudiant;
    return moyenne;
}

//Impl�mentation du sous-programme rechercheEtudiant
int rechercheEtudiant(char* matriculeEtu){//Fonction pr�dicat
    int i = 0;
    int verification = 0;
    while((i<compteurEtudiant) && strcmp(G[i].matricule, matriculeEtu)!=0)
        /*Ici la condiction pour sortir de la boucle while est que:
        Soit on trouve le matricule
        soit on parcourt tout le groupe d'�tudiant
        */
        i+=1;
    if(i < compteurEtudiant)//si est �gale � la taille du
        verification = 1;
    return verification;
}

//Impl�mentation du sous-programme afficheEudiant
void afficheEtudiant(Etudiant etu){
    printf("\n---------------------------------------------------------------------------------------------\n");
    printf("Nom : %s\t Prenom : %s\t Date de naissance : %d-%d-%d\t Sexe : %s\n",
            etu.nom, etu.prenom, etu.dateDeNaissance.jour, etu.dateDeNaissance.mois,
             etu.dateDeNaissance.annee, etu.sexe);
    printf("Matricule : %s\t Parcourt-Types : %s\t Niveau : %d \n", etu.matricule,
            etu.parcourtTypes, etu.niveau);
}
void afficheGroupeEtudiant(){
    printf("Voici les membres du groupe d'etudiant\n");
    for(int i = 0; i<compteurEtudiant; i++)
    {
        afficheEtudiant(G[i]);//Appel de la fonction pour afficher un �tudiant
    }
}

//Impl�mentation du sous-programme addNewStudent celle-ci permet de cr�er un nouveau etudiant
//Et de l'ajouter dans le groupe
void addNewStudent(){
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
    printf("Entrez son sexe (M ou F) : ");
    scanf("%s", newStudent.sexe);
    printf("Entrez son matricule : ");
    scanf("%s", newStudent.matricule);
    printf("Entrez son parcourt-types : ");
    scanf("%s", newStudent.parcourtTypes);
    printf("Entrez son niveau : ");
    scanf("%d", &newStudent.niveau);
    G[compteurEtudiant]=newStudent;//ajout d'un etudiant dans le groupe d'�tudiant
    compteurEtudiant++;//incr�mentation du nombre d'�tudiant pr�sent dans le groupe apr�s l'ajout
}

//Impl�mentation du programme menu
void menu(){
    char option[3]="NON";
    while(strcmp(option, "OUI")!=0 && strcmp(option, "oui")!=0 )
        //while pour rep�ter le menu tant que l'utilisateur n'entre pas OUI ou oui au moment indiquer
    {
        int choixMenu;
        printf("\n\n  ==================  Menu ==================\n\n");
        printf("1 - Ajouter un nouveau etudiant au groupe.\n");
        printf("2 - Determiner le nombre de fiile dans le groupe.\n");
        printf("3 - Rechercher un etudiant.\n");
        printf("4 - Determiner l'age moyenne du groupe.\n");
        printf("5 - Afficher les membres du groupe.\n");
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
            case 4:
                printf("Dans le groupe d'etudiant la moyenne d'age est : %d an(s)\n\n", ageMoyen());
                printf("\nVoulez vous quitter (OUI ou NON) ? ");
                scanf("%s", option);
                break;
            case 5:
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
