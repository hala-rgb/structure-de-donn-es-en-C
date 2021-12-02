#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "CFile.h"



/*******est vide*************/
bool est_vide ( File f ){
	if (f==NULL) return true;
	return false;
}
/*******File vide***************/
File file_vide (){
 return NULL;
}
/***********Enfiler************************/
File enfiler ( File f, Element e ){
	File tf = f;
	Cellule *nc = (Cellule *)malloc(sizeof(Cellule));
	if(nc ==NULL  ) 
	{
	printf("Defaut de memoire.");
	exit (-1);
	}
	
	nc-> valeur = e;
	nc-> suivant =NULL;
	//nc-> precedent =NULL;
	if(est_vide(f))
	{
	tf = (File)malloc(sizeof(file));
	if(tf ==NULL  ) 
	{
	printf("Defaut de memoire.");
	exit (-1);
	}
	tf->queue = nc;
	tf->tete=nc;
	}
	
	else {
	
		tf ->queue->suivant = nc;
		//nc->precedent = tf->queue;
		tf->queue =nc;
	}
	
	f=tf;
	return f;
}
/****************Defiler*******************/
File defiler ( File f ){
	
	if(est_vide(f))
	{
		printf("Erreur : File vide !");
		exit(-1);
	}
	Cellule * tmp =f->tete;
	f->tete= tmp->suivant;
	free(tmp);
	return f;
}


/***********tete****************************/
Element tete ( File f ){
	if (est_vide(f))
	{
		printf(" Erreur : File vide.\n");
		exit(-1);
	}
	return f->tete->valeur;
}

/************Queue**************************/
Element queue ( File f ){
	if (est_vide(f))
	{
		printf(" Erreur : File vide.\n");
		exit(-1);
	}
	return f->queue->valeur;
}
 /**************************************afficher***************/
void Afficher_file(File f){
	 if(est_vide(f)) printf("File vide !\n");
	Cellule *temp=f->tete;
	printf(" Les elements de la file :  !\n");

	while (temp)
	{
		printf("%d\t",temp->valeur);
		temp=temp->suivant;
	}
	
	printf("\n");
}


