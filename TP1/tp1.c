#include <stdio.h>

void ex1(){
    char c;
    // Caractere par caractere avec présision c = getc(stdin);
    // Sans précision du flux : 
    c = getchar();

    // Print en précisant le flux de sortie : putc(c, stdout)
    // Sans précision du flux de sortie :
    putchar(c);
}

void ex2(){
    char c = getchar();
    char d = getchar();

    // Print en précisant le flux de sortie : putc(c, stdout)
    // Sans précision du flux de sortie :
    putchar(c);
    putchar('\n');
    putchar(d);
    putchar('\n');
}

void ex3(){
    double x1, x2, x3, x4, x5;
    x1=1.2345;
    x2=123.45; 
    x3=0.000012345; 
    x4=1e-10;
    x5=-123.4568e15;

    printf("%f    %f\n%f     %f\n%f",x1, x2, x3, x4, x5);
    printf("%e    %e\n%e     %e\n%e\n",x1, x2, x3, x4, x5);
}

void ex4(){
    double x1, x2, x3, x4, x5, x6;
    x1=12.34567;
    x2=1.234567; 
    x3=1234567; 
    x4=123456.7;
    x5=0.1234567;
    x6=1234.567;
    
    printf("%.2f    %.2f\n%.2f     %.2f\n%.2f    %.2f\n",x1, x2, x3, x4, x5, x6);
}

void ex5(){
    float x = 1234.56789;
    printf("%f\n",x);
    printf("%d\n",x);
    printf("%e\n",x);
}

void ex6(){
    int i = 0; 

    scanf("%d",&i);

    printf("%d\n",i*3); 

}

void ex7(){
    int h, m, s;
    printf("Entrez l’heure (hh:mm:ss) : ");
    scanf("%d",&h);
    printf("Entrez l’heure (hh:mm:ss) : %d:", h);
    scanf("%d",&m);
    printf("Entrez l’heure (hh:mm:ss) : %d:%d:", h,m);
    scanf("%d",&s);
    printf("Entrez l’heure (hh:mm:ss) : %d:%d:%d", h,m,s);
    printf("\n");

    printf("%d heure(s)\n%d minute(s)\n%d seconde(s)\n",h,m,s);

}

void ex7bis(){
    int h,m,s; 
    printf("Entrez l’heure (hh:mm:ss) : ");
    scanf("%d:%d:%d",&h,&m,&s);
    printf("%d heure(s)\n%d minute(s)\n%d seconde(s)\n",h,m,s);
}


int main(int argc, char const *argv[])
{
    // ex1();
    //ex2();
    //ex3();
    //ex4();
    //ex5();
    //ex6();
    ex7bis(); 

    return 0;
}
