#include<stdio.h>
#include<math.h>>


const int MAX = 100;


int Max(int M[][MAX], int lignes, int millieu, int * max)
{
	int max_indice = 0;
	int i;
	for (i = 0; i <lignes; i++) {
		if (*max < M[i][millieu]) {
			*max = M[i][millieu];
			max_indice = i;
		}
	}
	return max_indice;
}

int PeakMatrice(int M[][MAX], int lignes, int colones,
				int millieu)
{
	int max = 0;
	int max_index = Max(M, lignes, millieu, &max);


	if (millieu == 0 || millieu == colones - 1)
		return max;


	if (max >= M[max_index][millieu - 1] && max >= M[max_index][millieu + 1])
		return max;


	if (max < M[max_index][millieu - 1])
		return PeakMatrice(M,lignes, colones, millieu - ceil((double)millieu / 2));


	return PeakMatrice(M, lignes, colones, millieu + ceil((double)millieu / 2));
}


int main()
{
	int M[MAX][MAX] ;
	M[0][0]= 10;
	M[0][1]= 7;
	M[0][2]=10;
	M[0][3]=10;
	  
	M[1][0]= 11;
	M[1][1]= 17;
	M[1][2]=12;
	M[1][3]=11;
	  
	M[2][0]= 15;
	M[2][1]= 9;
	M[2][2]=11;
	M[2][3]=18;
	  
	M[3][0]= 16;
	M[3][1]= 37;
	M[3][2]=19;
	M[3][3]=20;
	
	
	// 10	7	10	10
	// 11	17	12	11
	// 15	9	11	18
	// 16	37	19	20
					
					


	int lignes = 4, colones = 4;
	int c =PeakMatrice(M, lignes, colones,colones/2);
	printf("Le pic est : %d ");
	return 0;
}

