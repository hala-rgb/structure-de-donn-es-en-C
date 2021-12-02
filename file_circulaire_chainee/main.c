#include <stdio.h>
#include <stdlib.h>
#include "filec.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() 
{
 //test();
	File f=(File)malloc(sizeof(file));
	
	init_file( f);
//	afficher_file(f);
	f=Enfiler(f,1);
    f=Enfiler(f,2);
    f=Enfiler(f,3);
    f=Enfiler(f,4);
    f=Enfiler(f,5);
    f=Enfiler(f,6);
    f=Enfiler(f,7);
    f=Enfiler(f,8);
     afficher_file(f);
    f=Defiler(f);
    printf("aprés la défilement\n");
   afficher_file(f);
    
    
	return 0;
}
