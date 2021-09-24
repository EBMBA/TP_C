#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void ex1(){
    int n = 4,q = 2,p = 3;
    short m[n][p][q];

    for (int i = 0; i < n; i++)
    {
        for (int u = 0; u < p; u++)
        {
            for (int j = 0; j < q; j++)
            {
                printf("%p\n", m[i][u][j]);
                printf("%d\n", &m[i][u][j]);
            }
            
        }
        
    }

    /* Resultat
        0x1eb8
        0xffffeac0
        0x7ffe
        (nil)
        (nil)
        0x90
        (nil)
        (nil)
        (nil)
        0x4
        (nil)
        (nil)
        0xffffb084
        0x7767
        0x7ff5
        (nil)
        (nil)
        (nil)
        (nil)
        (nil)
        0xffff8000
        (nil)
        (nil)
        (nil)
    */
    
}

void ex4(){
    const int n = 4, p = 4;
    short m[n][p];
    
    srand(time(0));

    for (int h = 0; h < n; h++)
    {
        for (int t = 0; t < p; t++)
        {
            int num = ( rand() % ( 99 - 1  + 1 ) );
            m[h][t] = num;
        }
    }

    for (int u = 0; u < n; u++)
    {
        for (int j = 0; j < p; j++)
        {
            printf("%d ", m[u][j]);
        }
        printf("\n"); 
    }
    

}

void ex5(){
    const int n = 4, p = 4;
    short m[n][p], res[n][p];
    int var = 0;
    
    srand(time(0));

    for (int h = 0; h < n; h++)
    {
        for (int t = 0; t < p; t++)
        {
            int num = ( rand() % ( 99 - 1  + 1 ) );
            m[h][t] = num;
        }
    }

    for (int u = 0; u < n; u++)
    {
        for (int j = 0; j < p; j++)
        {
            printf("%d ", m[u][j]);
        }
        printf("\n"); 
    }
    
    printf("Entrez la valeur par laquelle il faut multiplier la matrice : ");
    scanf("%d",&var);

    for (int u = 0; u < n; u++)
    {
        for (int j = 0; j < p; j++)
        {
            res[u][j] = var * m[u][j];
            printf("%d ", res[u][j]);
        }
        printf("\n"); 
    }

}



int main(int argc, char const *argv[])
{
    ex5();
    return 0;
}
