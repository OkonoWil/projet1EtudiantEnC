#ifndef ETUDIANT_H_INCLUDED
#define ETUDIANT_H_INCLUDED
#include <stdio.h>
#include <string.h>
#define TAILLE 100//Déclaration de la constante TAILLE : la taille du tableau groupeEtudiant

//Déclaration du type structuré Date
typedef struct {
    unsigned int jour;
    char mois[15];
    unsigned int annee;
}Date;

//Déclaration du type structuré Etudiant
typedef struct {
    char nom[25];
    char prenom[25];
    char parcourtTypes[25];
    char matricule[10];
    char lieu[25];
    unsigned int niveau;
    char sexe[10];
    Date dateDeNaissance;
}Etudiant;

//Prototype du Sous-programme qui détermine le nombre de filles du groupe
int nombreFille();

//Prototype du Sous-programme qui détermine le nombre de garçons du groupe
int nombreGarcon();

//Prototype du Sous-programme qui détermine l'âge moyen du groupe
int ageMoyen(int nbrEtudiant);

//Prototype du Sous-programme qui recherche si un étudiant de matricule M donné est présent
int rechercheEtudiant(char* matriculeEtu,  int nbrEtudiant);

//Prototype du sous-programme d'affichage permettant d'afficher un étudiant
void afficheEtudiant(Etudiant etu);

//Prototype du sous-programme permettant de créer un nouveau étudiant et de l'ajouter dans le groupe
void addNewStudent();

//Prototype du sous-programme permettant de faire interagi le programme avec un utilisateur.
void menu();

void decision(char *pointeurOpt);
void decision2(char *pointeurOpt);

void saveStudent(Etudiant etud);

void readFileStudent();

#endif // ETUDIANT_H_INCLUDED
