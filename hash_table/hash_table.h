#ifndef _HASH_TABLE_H
#define _HASH_TABLEH_H
#include <stdbool.h>


typedef struct cellule {
char cle[15]; // la clé
int valeur; // infos
struct cellule *suivant;
} Cellule;
typedef Cellule * Liste; // type Liste
typedef struct table_hachage {
int taille; // taille table
Liste *alveoles; // tableau de listes
} Table_hachage;
// type TableHacage
typedef Table_hachage *TableHachage;

int hachage(TableHachage table, char *cle);
TableHachage cree_table_hachage(int taille);
TableHachage table_vide();
TableHachage insere(TableHachage table, char *cle);
int recherche(TableHachage table, char *cle);
void supprime(TableHachage table, char *cle);
void afficher(TableHachage table);



#endif
