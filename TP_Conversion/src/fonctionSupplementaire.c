#include <stdlib.h>
#include <stdio.h>
#include "../include/conversion.h"

void afficheMenu(){
    printf("Choissisez une conversion :\n");
    for (size_t i = 1; i < 9; i++)
    {
        switch (i)
        {
        case 1:
            printf("%ld. Binaire → Décimal\n",i );
            break;

        case 2:
            printf("%ld. Hexadécimal → Décimal\n",i );
            break;
        
        case 3:
            printf("%ld. Décimal → Hexadécimal\n",i );
            break;
        
        case 4:
            printf("%ld. Décimal → Binaire en utilisant la methode par soustraction\n",i );
            break;
        
        case 5:
            printf("%ld. Décimal → Binaire en utilisant la methode par division\n",i );
            break;
        
        case 6:
            printf("%ld. Décimal → Binaire en utilisant le decalage de bits et les opérateurs bit a bit\n",i );
            break;
        
        case 7:
            printf("%ld. Décimal → Hexadécimal en utilisant le decalage de bits et les opérateurs bit a bit\n",i );
            break;
        
        case 8:
            printf("%ld. Quitter\n",i );
            break;
        
        default:
            break;
        }
    }
    printf(" : ");
    
}

void traiterChoix(int choix, char *val){
    int taille = 0, resultat = 0;
    //char *valeurHexadecimal;
    unsigned int nombreDecimal = 0;
    switch (choix)
        {
        case 1:
            printf("Binaire → Décimal\n" );

            printf("Entrez le nombre de bit : " );
            scanf("%d", &taille);

            val = malloc( taille * sizeof(char));

            if (val == NULL) // On vérifie si l'allocation a marché ou non
            {
                    exit(0); // On arrête tout
            }

            printf("Entrez le nombre en binaire : " );
            scanf("%s", val);

            resultat = bintodec(val);
            printf("Le nombre en base 10 est : %d\n", resultat);

            free(val);
            break;

        case 2:
            printf("Hexadécimal → Décimal\n" );

            printf("Entrez le nombre de chiffres/lettres : " );
            scanf("%d", &taille);

            val = malloc( taille * sizeof(char));

            if (val == NULL) // On vérifie si l'allocation a marché ou non
            {
                    exit(0); // On arrête tout
            }

            printf("Entrez le nombre en hexadecimal : " );
            scanf("%s", val);

            resultat = hexatodec(val);
            printf("Le nombre en base 10 est : %d\n", resultat);

            free(val);
            break;
        
        case 3:
            printf("Décimal → Hexadécimal\n" );
            printf("Entrez le nombre en decimal : " );
            scanf("%u", &nombreDecimal);

            val = dectohexa(nombreDecimal);

            printf("Valeur en hexadecimal : %s\n", val);

            break;
        
        case 4:
            printf("Décimal → Binaire en utilisant la methode par soustraction\n" );
            printf("Entrez le nombre en decimal : " );
            scanf("%u", &nombreDecimal);

            val = dectobin_v1(nombreDecimal);

            printf("Valeur en binaire : %s\n", val);
            break;
        
        case 5:
            printf("Décimal → Binaire en utilisant la methode par division\n" );
            printf("Entrez le nombre en decimal : " );
            scanf("%u", &nombreDecimal);

            val = dectobin_v2(nombreDecimal);

            printf("Valeur en binaire : %s\n", val);
            break;
        
        case 6:
            printf("Décimal → Binaire en utilisant le decalage de bits et les opérateurs bit a bit\n" );
            printf("Entrez le nombre en decimal : " );
            scanf("%u", &nombreDecimal);

            val = dectobin_v3(nombreDecimal);
            printf("Valeur en binaire par decalage de bits: %s\n", val);
            
            break;
        
        case 7:
            printf("Décimal → Hexadécimal en utilisant le decalage de bits et les opérateurs bit a bit\n" );
            printf("Entrez le nombre en decimal : " );
            scanf("%u", &nombreDecimal);

            val = dectohexa_v2(nombreDecimal);
            printf("Valeur en hexadecimal par decalage de bits: %s\n", val);
            break;
        
        default:
            break;
    }
}

int obtenirTaille(char *tab){
    int taille = 0;

    while (tab[taille] != '\0')
    {
        taille ++;
    }
    
    return taille;
}

char *inverserTab(char *Tab){
    char *tableauInverser = NULL;
    unsigned int i = obtenirTaille(Tab);
    //printf("%d", i);
    tableauInverser = malloc(i * sizeof(char));

    // inversion
    i--;
    unsigned int p = i;
    for (unsigned int n = 0; n <= p; n++)
    {
        tableauInverser[n] = Tab[i];
        //printf("Resultat : %s\nInversion Resultat : %s\n",Tab, tableauInverser);
        i--; 
    }

    return tableauInverser;
}