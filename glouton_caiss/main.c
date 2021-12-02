#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	//déclaration des variables
	int nb_pieces_200,
		nb_pieces_100,
		nb_pieces_50,
		nb_pieces_20,
		nb_pieces_10,
		nb_pieces_5,
		nb_pieces_2,
		nb_pieces_1,
		rendu;
	// la somme de la monnaie
	printf("Veuillez entrer la somme du rendu\n");
	scanf("%d", &rendu);
	
	//les calculs
	nb_pieces_200 = rendu/200;
	rendu = rendu%200;
	nb_pieces_100 = rendu/100;
	rendu = rendu%100;
	nb_pieces_50 = rendu/50;
	rendu = rendu%50;
	nb_pieces_20 = rendu/20;
	rendu = rendu%20;
	nb_pieces_10 = rendu/10;
	rendu = rendu%10;
	nb_pieces_5 = rendu/5;
	rendu = rendu%5;
	nb_pieces_2 = rendu/2;
	rendu = rendu%2;
	nb_pieces_1 = rendu;
	
	//Test et Affichage des résultats
	if(nb_pieces_200>1)
	printf("Il faut %d pièces de monnaie de 200 dhs\n", nb_pieces_200);
	if(nb_pieces_200==1)
	printf("Il faut %d pièce de monnaie  de 200 dhs\n", nb_pieces_200);
	if(nb_pieces_100>1)
	printf("Il faut %d pièces de monnaie de 100 dhs\n", nb_pieces_100);
	if(nb_pieces_100==1)
	printf("Il faut %d pièce de monnaie  de 100 dhs\n", nb_pieces_100);
	if(nb_pieces_50>1)
	printf("Il faut %d pièces de monnaie de 50 dhs\n", nb_pieces_50);
	if(nb_pieces_50==1)
	printf("Il faut %d pièce de monnaie  de 50 dhs\n", nb_pieces_50);
	if(nb_pieces_20>1)
	printf("Il faut %d pièces de monnaie de 20 dhs\n", nb_pieces_20);
	if(nb_pieces_20==1)
	printf("Il faut %d pièce de monnaie  de 20 dhs\n", nb_pieces_20);
	if(nb_pieces_10>1)
	printf("Il faut %d pièces de monnaie de 10 dhs\n", nb_pieces_10);
	if(nb_pieces_10==1)
	printf("Il faut %d pièce de monnaie  de 10 dhs\n", nb_pieces_10);
	if(nb_pieces_5>1)
	printf("Il faut %d pièces de monnaie de 5 dhs\n", nb_pieces_5);
	if(nb_pieces_5==1)
	printf("Il faut %d pièce de monnaie  de 5 dhs\n", nb_pieces_5);
	if(nb_pieces_2>1)
	printf("Il faut %d pièces de 2 dhs\n", nb_pieces_2);
	if(nb_pieces_2==1)
	printf("Il faut %d pièce de 2 dhs\n", nb_pieces_2);
	if(nb_pieces_1>1)
	printf("Il faut %d pièces de 1 dhs\n", nb_pieces_1);
	if(nb_pieces_1==1)
	printf("Il faut %d pièce de 1 dhs\n", nb_pieces_1);

	system ("pause");
	return 0;
}
