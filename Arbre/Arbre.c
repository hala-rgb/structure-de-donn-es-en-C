#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Arbre.h"

// crer arbre vide
Arbre arbre_vide() {
	return NULL;
}
	
//tester si l'arbre est vide
bool est_vide(Arbre a) {
	return a == NULL ;
}

// créer neouveux noeud
Noeud * nouveau_noeud(Element e) {
	Noeud * p = (Noeud *) malloc(sizeof(Noeud));
	if (p == NULL) {
		printf("memoire sature");
		exit(-1);
	}
	p->mot =e;
	p->fils_gauche = NULL;
	p->fils_droite = NULL;
	p->occurence=1;
	return p;
}

// construire un arbre
Arbre construire_arbre(Noeud *r,Arbre G,Arbre D) {
	r->fils_gauche = G;
	r->fils_droite = D;
	return r ;
}

// retoutre de la racine
Noeud racine(Arbre A) {
	// précondition : A est non vide !
	if (est_vide(A)) {
		printf("Erreur : Arbre vide !\n");
		return (*A);
	}
}
// arbre droite de l'arbre
Arbre droite(Arbre A) {
	if (est_vide(A)) {
		printf("Erreur : Arbre vide !\n");
		exit(-1);
	}
	return A->fils_droite; 
}

// arbre gauche de l'arbre
Arbre Gauche(Arbre A) {
	// précondition : A est non vide !
	if (est_vide(A)) {
		printf("Erreur : Arbre vide !\n");
		exit(-1);
	}
	return A->fils_gauche; 
}

//inserer element dans l'arbre
Arbre insere (Arbre arbre, Element val) {
	Noeud *  N = nouveau_noeud(val);
	if (est_vide(arbre)) {
	  	arbre = construire_arbre(N,NULL,NULL); 
	} else if (!strcasecmp(arbre->mot,N->mot)) {
		arbre->occurence++;
	} else if (strcasecmp(arbre->mot,N->mot)>0) {
		arbre->fils_gauche= insere ( arbre->fils_gauche ,  val );
	} else if (strcasecmp(arbre->mot,N->mot)<0) {
		arbre->fils_droite = insere ( arbre->fils_droite ,  val );
	}
	return arbre;	
}

void afficher (Arbre arbre) {
	if (est_vide(arbre)) {
		return;
	} else {
		afficher (arbre->fils_gauche);
		printf("%s : %d \n" , arbre->mot, arbre->occurence);
		afficher (arbre->fils_droite);
	}
}

Arbre Max(Arbre a){
	if (est_vide(a->fils_droite)) {
		return a;
	}
	else{
		return Max(a->fils_droite);
	}
}


Arbre supprimerMax(Arbre a){
	if (est_vide(a->fils_droite)) {
		return a->fils_gauche;
	}
	else{
		return construire_arbre(a,a->fils_gauche,supprimerMax(a->fils_droite));
	}
}


Arbre trouve(Arbre a , Element val ) {
   if (est_vide(a)) {
        printf("Erreur : Arbre vide1 !\n");
        exit(-1);
}
    if (!stricmp(a->mot,val))
       return a ;
    if (stricmp(a->mot,val)>0) 
       return trouve(a->fils_gauche, val) ;
    else 
       return trouve(a->fils_droite , val) ;
}

Arbre supprimerElement(Arbre a, Element val){ 

if (est_vide(a)) {
printf("Erreur : Arbre vide !\n");
exit(-1);
}
Arbre N ;
N = trouve(a ,val);


if( stricmp(a->mot,val)<0 ){
	
	
    a=construire_arbre(a,a->fils_gauche,supprimerElement(a->fils_droite,val));
    
    }
    else {
    	if( stricmp(a->mot,val)>0 )
    	{
    		a=construire_arbre(a,supprimerElement(a->fils_gauche,val),a->fils_droite);
		}
		else {
			if (est_vide(a->fils_droite)) {
			a=a->fils_gauche ;
			}
			else{
				if (est_vide(a->fils_gauche)) {
			       a=a->fils_droite ;
			    }
			     else{
				a=construire_arbre(Max(a->fils_gauche), supprimerMax(a->fils_gauche), a->fils_droite);
			    }
			} 
		}
	}
	free(N);
	return a;


}

