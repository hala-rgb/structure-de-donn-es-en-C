#include<stdio.h>


#define MAX 999999

int MultiplicationMatrices(int d[], int n)
{
    
    int m[n + 1][n + 1];
 	int i;
 	int len, k;
    for (i = 1; i <= n; i++) {
        m[i][i] = 0;
    }
 
    for (len = 2; len <= n; len++)        
    {
        for (i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1;
            m[i][j] = MAX;
 
            for (k = i; j < n && k <= j - 1; k++)
            {
                int cout = m[i][k] + m[k + 1][j] + d[i - 1] * d[k] * d[j];
                if (cout < m[i][j]) {
                    m[i][j] = cout;
                }
            }
        }
    }
    return m[1][n - 1];
}
 

int main()
{	
    int d[4];
    d[0] = 10;
    d[1] = 20;
    d[2] = 30;
    d[3] = 40;
    int n = sizeof(d) / sizeof(d[0]);
 
    printf( "Le cout minimal est : %d ", MultiplicationMatrices(d, n));
 
    return 0;
}
