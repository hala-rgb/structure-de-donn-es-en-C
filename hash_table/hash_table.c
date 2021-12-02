#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "hash_table.h"



int hachage(TableHachage table, char *cle) {
int codeh = 0;//      
for (; *cle; cle++){

if( isupper(*cle)) {//tester si le lettre  en majuscule
//printf("hala1");
*cle = tolower(*cle);// la foction tolower transfére le lettre majuscule en minuscule
}
codeh += *cle;}
return (codeh % table->taille);
}


TableHachage cree_table_hachage(int taille) {
int i;
TableHachage table = (TableHachage)malloc(sizeof(Table_hachage));
table->taille = taille;
table->alveoles = (Liste*)malloc(table->taille * sizeof(Liste));
for (i = 0; i < table->taille; i++)
table->alveoles[i] = NULL;
return table;
}

 TableHachage insere(TableHachage table, char *cle) {
int codeh;
Liste liste = NULL;
codeh = hachage(table, cle);
liste = table->alveoles[codeh];
while (liste) {
if (!strcasecmp(liste->cle, cle)) {
	liste->valeur++;
	return table;
}
liste = liste->suivant;
}
if (liste == NULL) {
liste = (Liste)malloc(sizeof(Cellule));
strcpy(liste->cle, cle);
liste->valeur=1;
//strcpy(liste->valeur,valeur);
liste->suivant = table->alveoles[codeh];
table->alveoles[codeh] = liste;
return table;
}
}


/*int recherche(TableHachage table, char *cle){
Liste liste = table->alveoles[hachage(table, cle)];
for (; liste; liste = liste->suivant)
if (strcmp(valeur, liste->cle) == 0) {
//strcpy(valeur,liste->valeur);
return 1;
}
return 0;
}*/

void supprime(TableHachage table, char *cle) {
int codeh;
Liste liste, *precedent;
codeh = hachage(table, cle);
liste = table->alveoles[codeh];
precedent = &table->alveoles[codeh];
for (; liste; precedent = &liste->suivant, liste = liste->suivant)
if (strcmp(cle, liste->cle) == 0) {
*precedent = liste->suivant;
free(liste);
return;
}
}




void afficher(TableHachage table ){//cette fonction affiche les mot trier selon le plus grande par rapport au sommation du code ASCII
  
    int i;
    for(i=1;i<=table->taille;i++){
    	Liste liste = NULL;
	    liste = table->alveoles[i];
        
        for (; liste; liste = liste->suivant){
	    printf("%s %d ",liste->cle,liste->valeur);

        printf("\n");
        	}
         
 }

}
