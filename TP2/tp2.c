#include <stdio.h>
#include <math.h>

void ex1(){
    // char c = ' '; 
    unsigned char c = ' ';

    printf("Entrez un caractere : ");
    scanf("%c",&c);

    int lettreSuiv = c + 1;

    printf("Le code ASCII de \'%2c\' est %d\nLe caractere suivant dans la table ASCII est \'%c\'\n",c,c,lettreSuiv);

}

void ex2(){
    int codeASCII = 0;
    printf("Entrez le code ASCII : ");
    scanf("%d", &codeASCII);

    printf("Le caractere correspondant au code ASCII %d est \'%c\'\n", codeASCII, codeASCII);
}

void ex3(){
    signed int v1 = 12;
    signed int v2 = 4294967284;

    unsigned int v1bis = 12;
    unsigned int v2bis = 4294967284;

    printf("%d    %d\n%u    %u\n",v1,v2,v1bis,v2bis);
    printf("%x    %x\n%u    %u\n%d    %d\n",12,4294967284,12,4294967284,12,4294967284);
    /*
        12 = 0000 1100 => 1 octet 
        4294967284 = 1111 1111 1111 1111 1111 1111 1111 0100 => 4 octets 
    */
}

void ex4(){
    printf("Decimal : %d\nOctal : %o\nHexadecimal : %x\nDecimal : %d\nOctal : %o\nHexadecimal : %x\n ", 4,4,4,-4,-4,-4);
}

void ex5(){
    int tailleShort = sizeof(short)*8;
    short int var1 = 0;
    short int var2 = 0;

    /* 
        18000:19000 = 37000 // La taille d'un short est de 16 bits avec une etendu −32 767 ; +32 767 or 37000 est superieur 
        -28536
        56:-33333
        32259
    */
    scanf("%i:%i",&var1,&var2);
    short vars3 = var1+var2;
    printf("%i\nLa taille d'un short est de %d bits\n", vars3, tailleShort);
}

void ex6(){
    const float constF = 0.1;
    printf("%.1f\n", constF);
    printf("%.10f\n", constF);
    /* 
        0.1
        0.1000000015 => recupere des chiffre en memoire 
    */
}

void ex7(){
    double c1 = (1*exp(-9)+1*exp(9))-1*exp(9);
    double c2 = 1*exp(-9)+(1*exp(9)-1*exp(9));

    printf("%010f\n", c1);
    printf("%010f\n", c2);
}

int main(int argc, char const *argv[])
{
    //ex1();
    //ex2();
    //ex3();
    //ex4();
    //ex5();
    //ex6();
    ex7();
    return 0;
}
