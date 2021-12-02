#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "pile.h"



Pile pile_vide(){
	return NULL;
}

Pile empiler ( Pile p, Element e){
	
	Pile C = (Pile)malloc(sizeof(Cellule));
	if ( C==NULL ) {
		printf("mémoire insufisante");
	    exit(-1);
		} 
	C->valeur=e;
	C->suivante=p;
	p=C;
	return p ;
	
}


Pile depiler (Pile p){
	
	if (est_vide (p)){
		printf("Erreur:pile vide !\n");
		exit(-1);
		
	}
    Pile tmpc=p;
    p=p->suivante;
    free(tmpc);
    return p ;
	
}

Element sommet (Pile p){
	return p->valeur;
}

bool est_vide(Pile p){
	if (p==NULL) return true ;
	return false;
}


void Afficher_pile(Pile p){
 
    if (est_vide(p)){
    	printf("pile vide !!\n");
    	exit(0);
	}	
	else {
		Pile tmp = p;
		while(tmp!=NULL){
			
			printf("%d\n",(tmp->valeur));
			tmp =tmp->suivante;
		}
	}
}









