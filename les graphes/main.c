#include <stdio.h> 
#include <stdlib.h> 
#include "les graphes.h" 
	 
	 
int N=10; 
	 
	 
int main(int argc, char *argv[]) 
{ 
pSommet* graphe=NULL; 
graphe=CreerGraphe(N); 
graphe=CreerArete(graphe,0,1,10); 
graphe=CreerArete(graphe,1,4,10); 
graphe=CreerArete(graphe,1,3,10); 
graphe=CreerArete(graphe,1,9,10); 
graphe=CreerArete(graphe,1,8,10); 
graphe=CreerArete(graphe,3,2,10); 
graphe=CreerArete(graphe,2,7,10); 
graphe=CreerArete(graphe,7,4,10); 
	 
	 
affiche(graphe,N); 
InitialParcourLongueur(graphe,N); 
printf("\n"); 
InitialParcourLargeur(graphe,N); 
 estcycle(graphe,0, 10);
system("PAUSE"); 
return 0; 
} 

