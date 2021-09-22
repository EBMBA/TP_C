#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isPremier(int nbr){
    int reste = 0;
    bool premier = true; 

    for (int i = 2; i < 50000; i++)
    {
        if( i != nbr ){
            reste = nbr % i ;

            if(reste == 0 ){
                return false;
                break;
            }
        }
        

    }
    if ( premier == true )
    {
        return true;
    }
}

void printTab(const int *tab, int longueur){
    for (int i = 0; i < longueur; i++)
    {
        printf("%d\n", tab[i]);
    }    
}

void initTab(int *tab, int longueur){
    for (int i = 0; i < longueur; i++)
    {
        tab[i]=0; 
           
    }    
}


void addTab(int *tab, int longueur, int nbr){
    for (int i = 0; i < longueur; i++)
    {
        if( tab[i] == 0 ){
            tab[i]=nbr; 
            break;
        }
    }    
}


void ex1(){
    int nbr = 0, reste = 0;
    bool premier = true; 
    printf("Entrez le nombre naturel à tester : ");
    scanf("%d", &nbr);
    
    

    for (int i = 2; i < 50000; i++)
    {
        if( i != nbr ){
            reste = nbr % i ;

            if(reste == 0 ){
                printf("%d n'est pas un nombre premier : il est divisible par %d.\n",nbr, i);
                premier = false;
                break;
            }
        }
        

    }
    if ( premier == true )
    {
        printf("%d est un nombre premier.\n", nbr);
    }
    
}

void ex2(){
    int nbr = 0, reste = 0;
    bool premier = true; 
    printf("Entrez le nombre naturel à tester : ");
    scanf("%d", &nbr);
    
    for (int p = 1; p <= nbr; p++)
    {
        premier = isPremier(p);

        if ( premier == true )
        {
            printf("%d est un nombre premier.\n", p);
        }

    }
}

void ex3(){
    int nbr = 0, reste = 0;
    int *nbrPremier = NULL;
    bool premier = true; 

    printf("Entrez le nombre naturel à tester : ");
    scanf("%d", &nbr);
    
    nbrPremier = malloc(  nbr * sizeof(int));

    if (nbrPremier == NULL) // On vérifie si l'allocation a marché ou non
    {
            exit(0); // On arrête tout
    }

    initTab(nbrPremier, nbr);

    for (int p = 1; p <= nbr; p++)
    {
        premier = isPremier(p);

        if ( premier == true )
        {
            printf("%d est un nombre premier.\n", p);
            addTab(nbrPremier, nbr, p);
        }

    }
    printTab(nbrPremier, nbr); 

    free(nbrPremier);
}

void ex7(){
    int nbr = 0, reste = 0, taille = 0;
    int *nbrPremier = NULL;
    bool premier = true; 

    printf("Entrez le nombre naturel à tester : ");
    scanf("%d", &nbr);

    taille = nbr / 2;
    
    nbrPremier = malloc(  taille * sizeof(int));

    if (nbrPremier == NULL) // On vérifie si l'allocation a marché ou non
    {
            exit(0); // On arrête tout
    }

    initTab(nbrPremier, taille);

    for (int p = 1; p <= nbr; p++)
    {
        premier = isPremier(p);

        if ( premier == true )
        {
            printf("%d est un nombre premier.\n", p);
            addTab(nbrPremier, taille, p);
        }

    }
    printTab(nbrPremier, taille); 

    free(nbrPremier);
}

int main(int argc, char const *argv[])
{
    //ex1();
    //ex2();
    //ex3();
    ex7();
    return 0;
}
