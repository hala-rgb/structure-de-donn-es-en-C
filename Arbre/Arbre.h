#ifndef ARBRE
#define ARBRE


typedef char* Element;
typedef struct {
	Element mot;
	int occurence;
	struct noeud * fils_gauche;
	struct noeud * fils_droite;

} Noeud;

typedef Noeud * Arbre;


Arbre arbre_vide();
















#endif
