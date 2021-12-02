#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "hash_table.h"
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char * nouveau_string(char * mot){
	char * c = (char *)malloc(sizeof(mot));
	strcpy(c,mot);
	return c;
	
}

int main(int argc, char *argv[]) {
	
	FILE* f= fopen("f.txt","r+");
	
		char mot[20];
	     TableHachage T = cree_table_hachage(20);
		while(!feof(f)){
			fscanf(f,"%s",mot);
			T=insere(T,nouveau_string(mot));
		}
		
		
//	printf("apres la suppression du mot hala");	
//	supprime(T, "hala");
	afficher(T);
	

	
	
	
}
