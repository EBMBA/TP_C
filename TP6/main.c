#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void ex1(){
    char chaineCaract[100];
    int longueur = 0;
    printf("Entrez une chaine de caracteres : ");
    scanf("%s", chaineCaract);

    while (chaineCaract[longueur] != '\0'){
        longueur ++;
    }
    
    printf("Il y a %d caracteres dans la chaine \"%s\".\n",longueur ,chaineCaract);

}

void ex2(){
    char chaineCaract[100], chaine2[100];
    int longueur = 0;
    printf("Entrez une chaine de caracteres : ");
    scanf("%s", chaineCaract);

    while (chaineCaract[longueur] != '\0'){
        chaine2[longueur] = chaineCaract[longueur];
        longueur ++;
    }
    
    printf("La chaine 2 est : %s.\n", chaine2);
}

void ex3(){
    char chaineCaract[5], chaine2[5], chaine3[9];
    int longueur = 0, longueur2 = 0;
    printf("Entrez une chaine de caracteres : ");
    scanf("%s", chaineCaract);
    printf("Entrez une chaine de caracteres : ");
    scanf("%s", chaine2);
    //printf("%s\n", chaine2);

    while (chaineCaract[longueur] != '\0'){
        chaine3[longueur] = chaineCaract[longueur];
        longueur ++;
    }
    
    while ( chaine2[longueur2] != '\0'){
        chaine3[longueur] = chaine2[longueur2];
        longueur ++; longueur2 ++;
    }

    printf("La chaine 3 est leur concatenation : %s.\n", chaine3);
}

void ex4(){
    char chaineCaract[5], chaine2[5];
    int longueur = 0, longueur2 = 0, i = 0;
    printf("Entrez une chaine de caracteres : ");
    scanf("%s", chaineCaract);
    printf("Entrez une chaine de caracteres : ");
    scanf("%s", chaine2);
    //printf("%s\n", chaine2);

    while (chaineCaract[i] != '\0'){
        longueur += chaineCaract[longueur];
        i++;
    }
    
    i = 0;

    while ( chaine2[i] != '\0'){
        longueur2 += chaine2[longueur2];
        i++;
    }

    if ( longueur < longueur2 )
    {
        printf("Resultat %s < %s\n",chaineCaract ,chaine2);
    }
    else 
    {
        printf("Resultat %s > %s\n",chaineCaract ,chaine2);
    } 
}

void ex5(){
    srand(time(0));
    
    char chaineCaract[5], chaine2[5];
    int longueur = 0, longueur2 = 0;
    
    //printf("%s\n", chaine2);

    for (int p = 0; p < 5; p++)
    {
        int num = ( rand() % ( 122 - 97  + 1 ) ) + 97;
        chaineCaract[p] = num;
    }
    
    printf("La chaine 1  est : %s\n", chaineCaract);
    
    int n = 4;

    for (int i = 0; i < 5; i++)
    {
        
        chaine2[i] = chaineCaract[n] ;
        n -- ;
        
    }
    
    printf("La chaine 2  est son inversion: %s\n", chaine2);

}

void ex6(){
    srand(time(0));
    
    char chaineCaract[5], chaine2[5];
    int longueur = 0, longueur2 = 0;
    
    //printf("%s\n", chaine2);

    for (int p = 0; p < 5; p++)
    {
        int num = ( rand() % ( 122 - 97  + 1 ) ) + 97;
        chaineCaract[p] = num;
    }
    
    printf("La chaine 1  est : %s\n", chaineCaract);
    
    int n = 4;
    char temp;

    for (int i = 0; i < 2; i++)
    {
        
        temp = chaineCaract[i] ;
        chaineCaract[i] = chaineCaract[n] ;
        chaineCaract[n] = temp ;
        n -- ;
        /*
            mot : asdfg
            temp = a
            0 = g
            4 = a
            
            mot : gsdfa
            temp = s
            1 = f
            3 = s
        */
    }
    
    printf("La chaine 2  est son inversion: %s\n", chaineCaract);

}

int main(int argc, char const *argv[])
{
    ex6();
    return 0;
}

