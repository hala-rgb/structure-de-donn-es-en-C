/*cellule.h*/ 
	 
typedef int typage; 
	 
struct _cellule { 
typage element; 
struct _cellule *suivant; 
}; 
	 
typedef struct _cellule* Cellule; 

