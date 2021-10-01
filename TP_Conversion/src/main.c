#include <stdlib.h>
#include <stdio.h>
#include "../include/conversion.h"
#include "../include/fonctionSupplementaire.h"


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



