/*
 * Date : 02/10/2021
 *
 * Auteur : Emile METRAL 
 * 
 * Description : Le programme permet de convertir un decimal / binaire / hexadecimal en un decimal / binaire / hexadecimal avec plusieurs methode
*/

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
	do
	{
		choix = 0;
		while ( choix < 1|| choix > 8)
		{
			afficheMenu();
			scanf("%d", &choix);
		}
		
		// Partie du traitement du choix :
		traiterChoix(choix, valeur);
		
	} while (choix != 8);
	
	printf("Thank you :D Goodbye !\n");

    return 0;
}



