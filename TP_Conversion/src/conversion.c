#include <stdlib.h>
#include <stdio.h>
#include "../include/fonctionSupplementaire.h"

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
    int tempVal1 = val, taille = 0, tempVal2 = 0, i = 0;

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

char *dectobin_v2(unsigned int val){
    char *resultat = NULL, *inversionResultat = NULL;
    int taille = 0, tempValTaille1 = val, reste = 0, i = 0;

    
    // Nombre de chiffre dans le nombre : 
    if (tempValTaille1 >= 10)
    {
        while(tempValTaille1 > 0){
            taille ++;
            tempValTaille1 = tempValTaille1 / 10 ;
        }
    }
    else {
        taille = 1;
    }
    //printf("Taille : %d\n", taille);

    resultat = malloc((taille * 4) * sizeof(char));
    inversionResultat = malloc((taille * 4) * sizeof(char));

    if (resultat == NULL || inversionResultat == NULL) // On vérifie si l'allocation a marché ou non
    {
        exit(0); // On arrête tout
    }

    while (val > 0)
    {   
        reste = val % 2;
        val = val / 2 ;
        //printf("val : %d\ntempVal2 : %d\n", val, reste);
        
        resultat[i] = reste + '0' ;
        //printf("ici\n"); 
        //printf("Resultat : %s\n",resultat);

        i++;
        //printf("Resultat : %s\n",resultat);
    }

    inversionResultat = inverserTab(resultat);
    //printf("Resultat : %s\nInversion Resultat : %s\n",resultat, inversionResultat);

    
    return inversionResultat;
    free(resultat);
    free(inversionResultat);
}

char *dectobin_v3(unsigned int val){
    char *resultat, *inversionResultat = NULL; 
    unsigned bit = 0 ;
	unsigned mask = 1 ;

    resultat =  malloc(sizeof(val)*4 * sizeof(char));
    inversionResultat = malloc(sizeof(val)*4  * sizeof(char));

	for (int i = 0 ; i < (sizeof(val)*4 ); ++i)
	{
		bit = (val&mask) >> i ;
		resultat[i] = bit + '0' ;
		mask <<= 1 ;
	}
    //printf("Resultat : %s\n",resultat);

    inversionResultat = inverserTab(resultat);
    
    return inversionResultat;
    free(inversionResultat);
    free(resultat);
}

char *dectohexa_v2(unsigned int val){
    char *resultat, *inversionResultat = NULL; 
    char tempValBit; 
    unsigned bit = 0 ;
	unsigned mask = 15 ; // Nombre de F le max sur un hexa
    int p = 0, taille = 0; 
    unsigned int tempValTaille1 = val; 
    // Nombre de chiffre dans le nombre : 
    if (tempValTaille1 >= 10)
    {
        while(tempValTaille1 > 0){
            taille ++;
            tempValTaille1 = tempValTaille1 / 10 ;
        }
    }
    else {
        taille = 1;
    }
    //printf("Taille : %ld\n",sizeof(val));

    resultat =  malloc((taille+1) * sizeof(char));
    inversionResultat = malloc((taille+1 )* sizeof(char));
    

	for (int i = 0 ; i < (taille*4+1); i+=4) // decalage de 4bits par 4bits 
	{
		bit = (val & mask) >> i ;
        //printf("bit : %d\n",bit);
        tempValBit = bit + '0';
        //printf("bit char : %c\n",tempValBit);

        // Passage en lettre : 
        if (tempValBit >= 58 && tempValBit<=63)
        {
            tempValBit+= (65-58); // ascii : 'A' - ':'
        }
		resultat[p] =  tempValBit;
        //printf("Resultat : %s\n",resultat);
		mask <<= 4 ;
        p ++;
	}
    //printf("Resultat : %s\n",resultat);

    inversionResultat = inverserTab(resultat);
    
    return inversionResultat;
    free(inversionResultat);
    free(resultat);
}

