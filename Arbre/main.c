#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Arbre.h"
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char * nouveau_string(char * mot){
	char * c = (char *)malloc(sizeof(mot));
	strcpy(c, mot);
	return c;
}

int main(int argc, char *argv[]) {
	char c;
	FILE* f = fopen("text.txt", "r");
	FILE* file = fopen("text.txt", "r");
	char mot[20];
	Arbre a = arbre_vide() ;
	while((c=fgetc(file))!=EOF){
        printf("%c",c);
    }
	printf("\n \nMots : Occurence \n");
	printf("---------------------------------------------------------- \n");
	while (!feof(f)) {
    	fscanf(f, "%s", mot);
   		a= insere(a, nouveau_string(mot));
	}

	afficher(a);
	supprimerElement(a,"laha");
	printf("2eme affichage\n");
	afficher(a);
}
