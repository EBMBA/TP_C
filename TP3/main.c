#include <stdio.h>
#include <ctype.h>

// Variables globales
short a,b,c ;


void ex1(){
    short d,e,f;

    printf("&a : %p\n&b : %p\n&c : %p\n&d : %p\n&e : %p\n&f : %p\n",a,b,c,d,e,f);
    /*  &a : (nil) = 0x00000000
        &b : (nil) = 0x00000000
        &c : (nil) = 0x00000000
        &d : (nil) = 0x00000000
        &e : 0x5627 
        &f : 0x349f
    */
}

void ex2(){
    short g,h,i;

    printf("&g : %p\n&h : %p\n&i : %p\n",g,h,i);

    /*
        &a : (nil)
        &b : (nil)
        &c : (nil)
        &d : (nil)
        &e : 0x5612
        &f : 0xffff8f81
        &g : (nil)
        &h : 0x5612
        &i : 0xffff8f81
        &g : (nil)
        &h : (nil)
        &i : (nil)
    */
}

void ex3(){
    char caractere;
    printf("Entrez le caractere a traiter : ");
    caractere = getchar();

    if (caractere < 'a')
    {
        caractere = tolower(caractere);
    }
    else{
        caractere = toupper(caractere);
    }

    printf("Caractere apres le traitement : %c\n", caractere);
}

void ex4(){
    int op1, op2;
    printf("Entrez le premier operande : ");
    scanf("%d",&op1);

    printf("Entrez le second operande : ");
    scanf("%d",&op2);

    int div = op1/op2;
    int reste = op1 % op2;

    printf("%d = %d * %d + %d\n", op1, op2, div, reste);
}

void ex5(){
    int op1 = 0, op2 = 0;
    printf("Entrez le premier operande : ");
    scanf("%d",&op1);

    printf("Entrez le second operande : ");
    scanf("%d",&op2);

    float div = (float) op1/op2;

    printf("%d / %d = %f\n", op1, op2, div);
}

void ex6(){
    float op1 = 0.0;
    printf("Entrez le nombre reel : ");
    scanf("%f",&op1);

    op1 = op1 * 100;
    int temp = (int) op1 ;
    op1 = (float) temp / 100;

    printf("Resultat de la troncature : %f\n", op1);
}

void ex7(){
    int x=5,y=15;
    float u=2.1,v=5.0;
    printf("x==x : %d\n",x==x); // Vrai
    printf("x==y : %d\n",x==y); // Faux
    printf("x==u : %d\n",x==u); // Faux
    printf("x==v : %d\n",x==v); // Vrai
    printf("x>4 || x<3 : %d\n",x>4 || x<3); // Vrai
    printf("x>4 && x<3 : %d\n",x>4 && x<3); // Faux
    if(x) // Vrai
    printf("(x) : vrai\n");
    else
    printf("(x) : faux\n");
    printf("x=7 : %d\n",x=7); // Change la valeur de x
    printf("x : %d\n",x); // x = 7 maintenant 
    printf("x=(7!=8) : %d\n",x=(7!=8)); // x = 1 car la condition est vrai
    printf("x : %d\n",x);  // x = 1
    printf("(float)x : %d\n",(float)x); // Erreur car %d affiche un entier 
    /* 
        Resultat :
            x==x : 1
            x==y : 0
            x==u : 0
            x==v : 1
            x>4 || x<3 : 1
            x>4 && x<3 : 0
            (x) : vrai
            x=7 : 7
            x : 7
            x=(7!=8) : 1
            x : 1
            (float)x : -1330355552 
    */
}

int main(int argc, char const *argv[])
{
    //ex1();
    //ex2();
    /*
        short g,h,i;
        printf("&g : %p\n&h : %p\n&i : %p\n",g,h,i);
    */
    
    //ex3();
    //ex4();
    //ex5();
    //ex6();
    ex7();
    return 0;
}


/* 
Schema memoire :
    0x00000000 : a b c d 
    0xffff8f81 : i f
    0x5612 : e h
Commentaire : La memoire peut etre adresse deux fois 
*/