#include "filec.h"
#include <stdio.h>
#include <stdlib.h>



void init_file(File f){
    f->tete=NULL;
	f->queue=NULL;
	
	
}


bool est_vide( File f){
	if(f->queue==NULL && f->tete==NULL ) return true;
	return false;
	
}


File Enfiler ( File f, Element e){
//printf("hala1");
	Cellule* C = (Cellule*)malloc(sizeof(Cellule));//retourne une adresse c'est pour ca en mets Cellule*
	if (C == NULL){
	 	printf("mémoire insufisante");
	    exit (-1);
	}
//	printf("hala2");
	C->valeur=e;
	C->suivant=NULL;
	if (est_vide(f)){
		f->tete=C;
		f->queue=C;
		
	}
	else{
		f->queue->suivant=C;
		f->queue=C;
	}
	f->queue->suivant=f->tete;

	return f;
}


File Defiler ( File f){
	if(est_vide(f)){
		printf("file vide");
		exit(-1);
	}
   Cellule*	C =f->tete;
   f->tete=f->tete->suivant;
   f->queue->suivant=f->tete;//circulaire
   free(C);
   return f;
   	
}

void afficher_file(File f){

	if(est_vide(f)){
		printf("file vide");
	}
	else{

		 Cellule* cpt= f->tete;
		 while(cpt->suivant!=f->tete){
		 	printf("%d\t",cpt->valeur);
		 	cpt=cpt->suivant;
		 
		 }
		 if(cpt->suivant==f->tete){
		 	printf("%d\t",cpt->valeur);
		 }
	}
  printf("\n");
	
}
