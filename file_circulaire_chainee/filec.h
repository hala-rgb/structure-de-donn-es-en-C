#ifndef file_c
#define filec_c
#include <stdbool.h>


typedef int Element ;

typedef struct Cellule {
	Element valeur;
	struct Cellule *suivant;	
}Cellule;

typedef struct file{
    Cellule *tete;
    Cellule *queue;
}file;

typedef file* File;

void init_file(File f);
File Enfiler(File f, Element e);
File Defiler(File f);
bool est_vide( File f);
void test();

void afficher_file(File f);

#endif
 
