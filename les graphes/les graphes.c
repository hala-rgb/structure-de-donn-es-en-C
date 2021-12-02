#include "les graphes.h" 
#include "fifo.h" 
	 
pSommet* CreerGraphe(int taille){ 
pSommet* Newgraphe = (pSommet*)malloc(taille*sizeof(pSommet)); 
int i; 
for(i=0;i<taille;i++){ 
    Newgraphe[i]=(pSommet)malloc(sizeof(struct Sommet)); 
    Newgraphe[i]->valeur=i; 
    Newgraphe[i]->arc=NULL; 
} 
return Newgraphe; 
} 
	 
/**************************************************/ 
pSommet* CreerArete(pSommet* graphe,int s1,int s2,int valeur){ 
if(graphe[s1]->arc==NULL){ 
    pArc Newarc=(pArc)malloc(sizeof(struct Arc)); 
    Newarc->valeur=valeur; 
    Newarc->sommet=s2; 
    Newarc->arc_suivant=NULL; 
    graphe[s1]->arc=Newarc; 
return graphe; 
} 
	 
else{ 
    pArc temp=graphe[s1]->arc; 
    while( !(temp->arc_suivant==NULL)){ 
        temp=temp->arc_suivant; 
   } 
    pArc Newarc=(pArc)malloc(sizeof(struct Arc)); 
    Newarc->valeur=valeur; 
    Newarc->sommet=s2; 
    Newarc->arc_suivant=NULL; 
	 
    if(temp->sommet>s2){ //trier les sommet de méme niveaux
        Newarc->arc_suivant=temp->arc_suivant; 
        Newarc->sommet=temp->sommet; 
        temp->sommet=s2; 
        temp->arc_suivant=Newarc; 
        return graphe; 
    } 

    temp->arc_suivant=Newarc; 
    return graphe; 
    } 
} 
	 
/**************************************************/ 
void affiche(pSommet* graphe, int taille){ 
int i,j; 
pArc temp; 
	 
for(i=0;i<taille;i++){ 
    printf("le sommet %d ",graphe[i]->valeur); 
    if(!(graphe[i]->arc==NULL)){ 
    printf("lie a  %d",graphe[i]->arc->sommet); 
    temp=graphe[i]->arc; 
    while(!(temp->arc_suivant==NULL)){ 
        temp=temp->arc_suivant; 
        printf(",%d",temp->sommet); 
    } 
    } 
    printf("\n"); 
} 
} 
 
/**************************************************/ 
void InitialParcourLongueur(pSommet* graphe, int taille){ 
/*Initialisation de la couleur des sommets*/ 
 /*N=Noir, deja vu.  B=Blanc a voir*/ 
printf("\n***PARCOURS EN PROFONDEUR***\n"); 
int i; 
  for(i=0;i<taille;i++){ 
    graphe[i]->couleur='B'; 
} 
  for(i=0;i<taille;i++){ 
    if(graphe[i]->couleur=='B'){ 
        printf("%d,",graphe[i]->valeur); 
        graphe[i]->couleur='N'; 
        pArc Temparc=graphe[i]->arc; 
        while(!(Temparc==NULL)){ 
            ParcourLongueur(graphe,Temparc->sommet,taille); 
            Temparc=Temparc->arc_suivant; 
       } 
   } 
} 
return; 
} 
/****************************************************/ 
void ParcourLongueur(pSommet* graphe,int s, int taille){ 
if(graphe[s]->couleur=='B'){ 
    printf("%d,",graphe[s]->valeur); 
    graphe[s]->couleur='N'; 
    pArc Temparc=graphe[s]->arc; 
    while(!(Temparc==NULL)){ 
        ParcourLongueur(graphe,Temparc->sommet,taille); 
        Temparc=Temparc->arc_suivant; 
   } 
} 
 return; 
} 
 
/**************************************************/ 
void InitialParcourLargeur(pSommet* graphe, int taille){ 
/*Initialisation de la couleur des sommets*/ 
/*N=Noir, deja vu.  B=Blanc a voir*/ 
 printf("\n***PARCOURS EN LARGEUR***\n"); 
int i=0; 
File file = fileVide(); 
   for(i=0;i<taille;i++){ 
        graphe[i]->couleur='B'; 
   } 
   enfiler(file,0); 
   while(longueur(file)){ 
        i=defilement(file); 
        if(graphe[i]->couleur=='B'){ 
        pArc Temparc=graphe[i]->arc; 
         if(Temparc!=NULL){ 
            enfiler(file,Temparc->sommet); 
                while(Temparc->arc_suivant!=NULL){ 
                    Temparc=Temparc->arc_suivant; 
                    enfiler(file,Temparc->sommet); 
	           } 
         } 
       printf("%d",graphe[i]->valeur); 
	       graphe[i]->couleur='N'; 
	       } 
	     } 
printf("\n"); 
	} 


void intcycle(pSommet* graphe,int taille){ //cette fonction ne marche pas 
//Initialisation de la couleur des sommets 

int i; 
  for(i=0;i<taille;i++){ 
    graphe[i]->couleur='B'; 
} 

       } 
int estcycle(pSommet* graphe,int s, int taille){
File file = fileVide();

  intcycle( graphe, taille);
    enfiler(file,s); 
     while(longueur(file)){ 
       s= defilement(file);
         
       
       pSommet tempsomet=graphe[s];
       pArc Temparc=tempsomet->arc;
      while(!(Temparc==NULL)){ 
                    
                  if(tempsomet->couleur!=N){//si il est différent de noir c'est a dire n'est pas marqer
				  
				  enfiler(file,Temparc->sommet);//alors en va le enfiler 
				  }
					  Temparc=Temparc->arc_suivant; 
					 tempsomet=graphe[s]->arc;
					  
	           } 
  	   
  	 
	
	if(graphe[s]->couleur=='N'){
	
	printf("oui");
	return 1;
     	}
		 
   		graphe[s]->couleur='N';
	   }
         printf("non");
       return 0;  
}

/*
 int verificoleur(pSommet* graphe,int s){
 	printf("dans3");
 	if (  graphe[s]->couleur=='N') {
 		printf("dans5");
	 return 0;}
 	else return 1;
 }
 */
 
 

