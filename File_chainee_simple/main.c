#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "CFile.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


 

int main(int argc, char *argv[]) {
	 File f= file_vide();

	
  f=enfiler(f,1);
  printf("la tete : %d\n",tete(f));
   printf("la queue : %d\n",queue(f));
	f=enfiler(f,2);
	printf("la tete : %d\n",tete(f));
		printf("la queue : %d\n",queue(f));
	f=enfiler(f,3);
	
		
		f=defiler (  f );
	Afficher_file( f);
	printf("la tete : %d\n",tete(f));
		printf("la queue : %d",queue(f));

	return 0;
}
