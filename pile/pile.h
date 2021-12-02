#ifndef _PILE_CHINE_H
#define _PIlE_CHAINE_H
#include <stdbool.h>


typedef int Element;

typedef struct Cellule {
	Element valeur;
	struct Cellule *suivante;	
} Cellule;
typedef Cellule *Pile;

Pile pile_vide();
Pile empiler ( Pile p, Element e);
Pile depiler (Pile p);
Element sommet (Pile p);
void Afficher_pile(Pile p);
bool est_vide( Pile p);











#endif

