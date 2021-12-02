#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n,p,v,i,W; //Nombre d'objets, poids et valeur.
	int P[10],V[10]; // Tableau où on stocke les poids // Tableau où on stocke les valeurs
	float R[10]; // Tableau où on stocke le rapport
	float r; //Le rapport calculé

	// La saisie :
	printf("Veuillez entrer le nombre d'objets souhaité:");
	scanf("%d",&n);
	for(i=0;i<n;i++) {
	printf("Veuillez entrer l'objet %d\n",i);
	printf("Veuillez entrer le poids de l'objet %d :",i);
	scanf("%d",&p);
	printf("\n");
	P[i]=p;
	printf("Veuillez entrer la valeur de l'objet%d :",i);
	scanf("%d",&v);
	printf("\n");
	
	V[i]=v;
	r=(float)v/p; //Calcul du rapport
	printf("Le rapport de l'objet %d est %f:\n",i,r);
	R[i]=r;
	printf("\n");
	}
	
	//Affichage du poids, valeur et le rapport.
	for(i=0;i<n;i++)printf (" %d \t",P[i]);
	printf("\n");
	for(i=0;i<n;i++)printf (" %d \t",V[i]);
	printf("\n");
	for(i=0;i<n;i++)printf (" %f \t",R[i]);
	printf("\n");
	int PS=11; //Poids total du sac
	int tot=0;
	int max;
	for (i=0; i<n-1; i++) { //Boucle pour voir qui a le plus grand max selon le rapport donc on doit parcourir le tab des rapports.
	
		//* Recherche du maximum à droite de A[I] en triant les 3 tableaux.
		max=i;
		int j;
		for (j=i+1; j<n; j++)
		if (R[j]<R[max]) max=j;
		// Echange de A[I] avec le maximum
		float L=R[i];    // valeur qui permet de faire la permutation pour faire le tri selon les rapports.
		int A=V[i];      // valeur qui permet de faire la permutation pour faire le tri
		int K=P[i];      // valeur qui permet de faire la permutation pour faire le tri
		R[i]=R[max];
		V[i]=V[max];
		P[i]=P[max];
		R[max]=L;
		V[max]=A;
		P[max]=K;
	}
	//Affichage
	for(i=0;i<n;i++) printf (" %d \t",P[i]);
	printf("\n");
	for(i=0;i<n;i++) printf (" %d \t",V[i]);
	printf("\n");
	for(i=0;i<n;i++) printf (" %f \t",R[i]);
	printf("\n");
	
	for(i=n-1;i>=0;i--) {
		if(P[i]<W) {     // On fait des tests pour l'insertion des objets dans le sac
			printf("Element %d pris !\n",i+1); //Affichage
			tot+=V[i]; //Somme des valeurs
			W-=P[i];  //Pour avoir uniquement le poids du sac
		}
	}
	printf("La valeure totale = %d\n",tot);
	return 0;
}
