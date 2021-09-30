#include <stdlib.h>
#include <stdio.h>

void afficheMenu();
int obtenirTaille(char *tab);
void traiterChoix(int choix, char *val);
int bintodec(char *val);
int hexatodec(char *val);
char *dectohexa(unsigned int val);
char *dectobin_v1(unsigned int val);
char *dectobin_v2(unsigned int val);
char *dectobin_v3(unsigned int val);
char *dectohexa_v2(unsigned int val);

int main(int argc, char const *argv[])
{
    // Partie des declarations des variables:
    char *valeur;
    int resultat = 0, choix = 0;
    // Partie du choix de la conversion :
    while ( choix < 1|| choix > 7)
    {
        afficheMenu();
        scanf("%d", &choix);
    }
    
    // Partie du traitement du choix :
    traiterChoix(choix, valeur);

    return 0;
}

void afficheMenu(){
    printf("Choissisez une conversion :\n");
    for (size_t i = 1; i < 8; i++)
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
            printf("%ld. Décimal → Binaire en utilisant le decalage de bits et les opérateurs bit a bit\n",i );
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
            scanf("%d", &nombreDecimal);

            val = dectohexa(nombreDecimal);

            printf("Valeur en hexadecimal : %s\n", val);

            break;
        
        case 4:
            printf("Décimal → Binaire en utilisant la methode par soustraction\n" );
            printf("Décimal → Hexadécimal\n" );
            printf("Entrez le nombre en decimal : " );
            scanf("%d", &nombreDecimal);

            val = dectobin_v1(nombreDecimal);

            printf("Valeur en binaire : %s\n", val);
            break;
        
        case 5:
            printf("Décimal → Binaire en utilisant la methode par division\n" );
            break;
        
        case 6:
            printf("Décimal → Binaire en utilisant le decalage de bits et les opérateurs bit a bit\n" );
            break;
        
        case 7:
            printf("Décimal → Binaire en utilisant le decalage de bits et les opérateurs bit a bit\n" );
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

int bintodec(char *val){
    //printf("debut fonction\n");
    int taille = obtenirTaille(val), conversion = 0, puissance = 1 ;
    //printf("taille : %d\n", taille);
    for (int i = taille-1; i >= 0; i--)
    {
        conversion += ( (int)val[i]-48 ) * puissance;
        //printf("conversion : %d\n puissance av : %d\n",conversion, puissance);
        puissance *= 2;
        //printf("puissance av : %d\n", puissance);
    }
    
    return conversion;
}

int hexatodec(char *val){
    //printf("debut fonction\n");
    int taille = obtenirTaille(val), conversion = 0, puissance = 1 ;
    //printf("taille : %d\n", taille);
    for (int i = taille-1; i >= 0; i--)
    {
        // Si la valeur est entre 0 et 9
        if ( ((int)val[i]-48) >= 0 &&  ((int)val[i]-48) < 10)
        {
            conversion += ( (int)val[i]-48 ) * puissance;
        }
        // Si la valeur est entre A et F :
        else{
            // Si la valeur est pas une majuscule
            if ((int)val[i] >= 97)
            {
                val[i] = val[i] - 32;
            }
            conversion += ( (int)val[i]-55 ) * puissance;
        }
        
        //printf("conversion : %d\n puissance av : %d\n",conversion, puissance);
        puissance *= 16;
        //printf("puissance av : %d\n", puissance);
    }
    
    return conversion;
}

char *dectohexa(unsigned int val){
    char *resultat = NULL, *inversionResultat =  NULL;
    char tempVal3;
    int tempVal1 = val, taille = 0, tempVal2 = 0, puissance = 1, i = 0;

    // Nombre de chiffre dans le nombre : 
    if (tempVal1 >= 10)
    {
        while(tempVal1 > 0){
            taille ++;
            tempVal1 = tempVal1 / 10 ;
        }
    }
    else {
        taille = 1;
    }
    //printf("Taille : %d\n", taille);
    
    resultat = malloc(taille * sizeof(char));
    inversionResultat = malloc(taille * sizeof(char));

    if (resultat == NULL || inversionResultat == NULL) // On vérifie si l'allocation a marché ou non
    {
        exit(0); // On arrête tout
    }

    while (val >= 16)
    {   
        tempVal2 = val % 16;
        val = val / 16 ;
        //printf("val : %d\ntempVal2 : %d\n", val, tempVal2);
        if (tempVal2 >= 10)
        {
            switch (tempVal2)
            {
            case 10:
                resultat[i] = 'A' ;
                break;
            case 11:
                resultat[i] = 'B' ;
                break;
            case 12:
                resultat[i] = 'C' ;
                break;
            case 13:
                resultat[i] = 'D' ;
                break;
            case 14:
                resultat[i] = 'E' ;
                break;
            case 15:
                resultat[i] = 'F' ;
                break;             
            default:
                break;
            }
        }
        else
        {
            resultat[i] = tempVal2 + '0' ;
        }
        i++;
    }
    if (val >= 10)
        {
            switch (val)
            {
            case 10:
                resultat[i] = 'A' ;
                break;
            case 11:
                resultat[i] = 'B' ;
                break;
            case 12:
                resultat[i] = 'C' ;
                break;
            case 13:
                resultat[i] = 'D' ;
                break;
            case 14:
                resultat[i] = 'E' ;
                break;
            case 15:
                resultat[i] = 'F' ;
                break;             
            default:
                break;
            }
        }
    else
    {
        resultat[i] = val + '0' ;
    }

    // inversion
    int p = 0;
    for (int n = i; n >= 0; n--)
    {
        inversionResultat[p] = resultat[n];
        p++;
        
    }
    

    //printf("Resultat : %s\nInversion Resultat : %s\n",resultat, inversionResultat);

    
    return inversionResultat;
    free(resultat);
    free(inversionResultat);
}

char *dectobin_v1(unsigned int val){
    char *resultat = NULL;
    int puissance = 1, taille = 0, tempVal1 = val, nombrePuissance = 0, n = 0;

    
    // Nombre de chiffre dans le nombre : 
    if (tempVal1 >= 10)
    {
        while(tempVal1 > 0){
            taille ++;
            tempVal1 = tempVal1 / 10 ;
        }
    }
    else {
        taille = 1;
    }
    //printf("Taille : %d\n", taille);

    resultat = malloc((taille * 4) * sizeof(char));

    if (resultat == NULL) // On vérifie si l'allocation a marché ou non
    {
        exit(0); // On arrête tout
    }

    while (val - puissance >= puissance)
    {
        puissance *= 2;
        nombrePuissance ++;
    }
    //printf("nbr de puissance : %d \npuissance : %d\n", nombrePuissance, puissance);

    while (nombrePuissance >= 0)
    {   
        puissance = 1;
        for (int i = 0; i < nombrePuissance; i++)
        {
            puissance *= 2;
        }
        //printf("nbr de puissance : %d \npuissance : %d\n", nombrePuissance, puissance);
        if(val >= puissance){
            resultat[n] = '1';
            val = val - puissance;
            nombrePuissance--;
            n++;
        }
        else
        {
            resultat[n] = '0';
            nombrePuissance--;
            n ++;
        }
        
    }
    
    
    //printf("Resultat : %s\n",resultat, );

    return resultat;
    free(resultat);
}


