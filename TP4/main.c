#include <stdio.h>
#include <math.h>
#include <time.h>
/* 
    Compilation : gcc main.c -o main -lm
    https://stackoverflow.com/questions/10409032/why-am-i-getting-undefined-reference-to-sqrt-error-even-though-i-include-math

*/

void ex1(){
    int a,b,c;
    int plusGrandNbr;
    printf("Entrez les valeurs de a, b et c (sous la forme a:b:c) : ");
    scanf("%d:%d:%d",&a,&b,&c);
    if ( a < b && c < b)
    {
        printf("Le plus grand des entiers est %d\n", b);
    }
    else if ( a > b && c < a)
    {
        printf("Le plus grand des entiers est %d\n", a);
    }
    else if ( a < c && c > b)
    {
        printf("Le plus grand des entiers est %d\n", c);
    }
    
}

void ex2(){
    double a= 0.0,b= 0.0,c= 0.0,x1= 0.0,x2= 0.0, delta = 0.0;
    printf("Entrez les valeurs des coefficients a, b et c du trinome (a doit etre non-nul).\na = ");
    scanf("%le",&a);
    printf("b = ");
    scanf("%le",&b);
    printf("c = ");
    scanf("%le",&c);

    while(a == 0){
        printf("Entrez les valeurs des coefficients a, b et c du trinome (a doit etre non-nul).\na = ");
        scanf("%le",&a);
        printf("b = ");
        scanf("%le",&b);
        printf("c = ");
        scanf("%le",&c);
    }

    delta = b*b - 4*a*c;

    if ( delta > 0)
    {
        x1 = (-b - sqrt(delta)) / (2*a);
        x2 = (-b + sqrt(delta)) / (2*a);
        printf("L'equation %.2fx^2 + %.2fx + %.2f = 0 admet deux solutions :\n   x1 = %f  et  x2 = %f\n", a,b,c,x1,x2);
    }
    else if ( delta == 0)
    {
        x1 = -b  / (2*a);
        printf("L'equation %.2fx^2 + %.2fx + %.2f = 0 admet exactment une solution :\n   x = %f\n", a,b,c,x1);
    }
    else
    {
        printf("L'equation %.2fx^2 + %.2fx + %.2f = 0 n'admet pas de solution.\n", a,b,c);
    }
    
}

void ex3(){
    int a =0 ,b=0 ,c=0;
    printf("Entrez l’entier a renverser : ");
    scanf("%d",&a);
    
    if (a >= 10)
    {
        while(a >= 10){
            c = a % 10;
            if (b == 0)
            {
                b += c;
            }
            else {
                b = b * 10 + c;
            }
            a = a / 10 ;
        }
        b = b * 10 + a;
    }
    else {
        b = a;
    }
    
    printf("Resultat : %d\n",b); 
    // Tableau de sitiuation ??
}

void ex5(){
    int somme = 1;

    for (int i = 2; i <= 10; i++)
    {
        somme += i;
        for (int p = 1; p <= i; p++)
        {
            if (p == i)
            {
                printf("%d = %d\n", p, somme) ;
            }
            else {
                printf("%d + ", p) ;
            }
            
        }
        
        
    }
    
}

void ex6(){
    int somme = 1, n = 1;
    do
    {
        printf("Entrez n ou une valeur <=0 pour terminer : ");
        scanf("%d", &n);


        
        for (int i = 2; i <= n; i++)
        {
            somme += i;
            for (int p = 1; p <= i; p++)
            {
                if (p == i)
                {
                    printf("%d = %d\n", p, somme) ;
                }
                else {
                    printf("%d + ", p) ;
                }
                
            }
            
            
        }
    } while (n > 0);
    
}

void ex7(){
    int somme = 1, n = 2, n1 = 1, n2 = 0;
    
    printf("Entrez la valeur de n : ");
    scanf("%d", &n);

    printf("u%d = %d\n", n2, n2) ;
    printf("u%d = %d\n", n1, n1) ;

        
    for (int i = 2; i <= n; i++)
    {
        somme = n1 + n2;
            
        printf("u%d = %d\n", i, somme) ;

        n2 = n1;
        n1 = somme;
            
    }
}

void ex8(){
    int somme = 1, n = 2, n1 = 1, n2 = 0;
    double div = 0.0;
    
    printf("Entrez la valeur de n : ");
    scanf("%d", &n);

    printf("u%d = %d\n", n2, n2) ;
    printf("u%d = %d\n", n1, n1) ;

        
    for (int i = 2; i <= n; i++)
    {
        somme = n1 + n2;
        div = (double) somme / n1;
            
        printf("u%d = %d\n   u%d/u%d=%.15le\n", i, somme, i, i-1, div) ;

        n2 = n1;
        n1 = somme;
            
    }
}

void ex9(){
    int somme = 1, n = 2, n1 = 1, n2 = 0;
    double div = 0.0, diff = 0.0, nbrOr = 1.61180339887498948482045868343656;
    
    printf("Entrez la valeur de n : ");
    scanf("%d", &n);

    printf("u%d = %d\n", n2, n2) ;
    printf("u%d = %d\n", n1, n1) ;

        
    for (int i = 2; i <= n; i++)
    {
        somme = n1 + n2;
        div = (double) somme / n1;
        diff = div - nbrOr;
            
        printf("u%d = %d\n   u%d/u%d=%f\n   erreur : %.10f\n", i, somme, i, i-1, div, diff) ;

        if (diff < pow(10,-10) && diff > 0 || diff > pow(10,-10) && diff < 0)
        {
            printf("%d est le rang a partir du quel le nombre d'or est estime a 10^-10\n", i);
            break;
        }
        

        n2 = n1;
        n1 = somme;
            
    }
}

void devinette(){
    int nbrTentative = 1, nbrUtil = -1;
    srand(time(NULL));
    int nbrMystere = 1 + rand() % 100; 
    printf("J’ai tiré un nombre au hasard : essayez de le deviner !\n"); 

    do
    {
        if (nbrTentative == 1)
        {
            printf("Premiere tentative ? ");
            scanf("%d", &nbrUtil); 
        }
        else{
            printf("Tentative %d ? ", nbrTentative);
            scanf("%d", &nbrUtil); 
        }
        if (nbrUtil < nbrMystere)
        {
            printf("La valeur %d est trop petite.\n", nbrUtil);
        }
        else if (nbrUtil > nbrMystere)
        {
            printf("La valeur %d est trop grande.\n", nbrUtil);
        }
        
        nbrTentative ++;
        
    } while (nbrUtil != nbrMystere);
    
    printf("Oui, c’est bien ca (%d) ! Bravo, vous avez gagne !\n Votre score est : %d\n", nbrMystere, nbrTentative);
}
int main(int argc, char const *argv[])
{
    //ex1();
    //ex2();
    //ex3();
    //ex5();
    //ex6();
    //ex7();
    //ex8();
    //ex9();
    devinette(); // À votre avis, quelle stratégie le joueur doit-il adopter pour obtenir le meilleur score ? Par dicothomie 
    return 0;
}
