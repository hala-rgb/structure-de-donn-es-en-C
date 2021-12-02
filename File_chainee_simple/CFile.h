#ifndef _FILE_D_CHAINEE
#define _FILE_D_CHAINEE

typedef int Element; /* les éléments sont des int */
typedef struct cellule *Place; /* la place = adresse cellule */
typedef struct cellule {
Element valeur; // un éléments de la liste
struct cellule *suivant;
//struct cellule *precedent; // adresse cellule suivante
} Cellule;
typedef struct fILE
{
	Cellule *tete;
	Cellule *queue;
}file;
typedef file* File;
// Déclaration des fonctions gérant la liste
File file_vide ();
File enfiler ( File f, Element e );
File defiler ( File f );
Element tete ( File f );
Element queue ( File f );
void Afficher_file(File f);
bool est_vide ( File f );
#endif
