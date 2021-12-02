#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Ctype.h>
#include "pile.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */



void postfix(){
	char exp[30];
	int i=0;
	Pile p = pile_vide();
	printf("entrez une expression arethmetique poste fixe : \n  ");
	scanf("%s",exp);
	while (exp[i]!='\0'){
		if ( isdigit(exp[i])){
			  int c = exp[i] - '0';
			  p = empiler(p,c);		         
	   }
	    else{
	   	int val1 =0,  val2 =0 ;
	   	val1=sommet(p); p=depiler(p);
	    val2=sommet(p); p=depiler(p);
	      switch (exp[i]){
	    	case '+':{
	    		p=empiler(p,val1+val2);
				break;
			}
			case '-':{
				p=empiler(p,val2-val1);
				break;
			}
			case '*':{
				p=empiler(p,val2*val1);
				break;
			}
			
			case '/':{
				if (val1!=0){
					p=empiler(p,val2/val1);
				}
				else { 
				  printf("interdi division sur 0 \n");
				  exit(-1);
				}
				
				break;
			}
		}
		
		
		}
	   	
		 i++;
		 }	 
			printf(" Le resultat est :");
	   	Afficher_pile(p);
		
	
	
}


int main (){
	postfix();
	return 0;
}
