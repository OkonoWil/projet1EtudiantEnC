#ifndef ETUDIANT_H_INCLUDED
#define ETUDIANT_H_INCLUDED
#include <stdio.h>
#include <string.h>
#define TAILLE 100//D�claration de la constante TAILLE : la taille du tableau groupeEtudiant

//D�claration du type structur� Date
typedef struct {
    unsigned int jour;
    unsigned int mois;
    unsigned int annee;
}Date;

//D�claration du type structur� Etudiant
typedef struct {
    char nom[25];
    char prenom[25];
    char parcourtTypes[25];
    char matricule[10];
    unsigned int niveau;
    char sexe[10];
    Date dateDeNaissance;
}Etudiant;

//D�claration du type structur� GroupeEtudiant
typedef Etudiant GroupeEtudiant[TAILLE];

//Prototype du Sous-programme qui d�termine le nombre de filles du groupe
int nombreFille();

//Prototype du Sous-programme qui d�termine l'�ge moyen du groupe
int ageMoyen();

//Prototype du Sous-programme qui recherche si un �tudiant de matricule M donn� est pr�sent
int rechercheEtudiant(char* matriculeEtu);

//Prototype du sous-programme d'affichage permettant d'afficher un �tudiant
void afficheEtudiant(Etudiant etu);

//Prototype du sous-programme d'affichage permettant d'afficher le groupe d'�tudiant
void afficheGroupeEtudiant();

//Prototype du sous-programme permettant de cr�er un nouveau �tudiant et de l'ajouter dans le groupe
void addNewStudent();

//Prototype du sous-programme permettant de faire interagi le programme avec un utilisateur.
void menu();

#endif // ETUDIANT_H_INCLUDED
