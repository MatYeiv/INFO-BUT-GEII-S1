/* Mathieu GADENNE E13A */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   char prenom[10];

   printf("Entrez votre prenom : \t");

   fgets(prenom, 10, stdin); // on utilise la fonction fgets afin de pouvoir récupérer des chaines de caractères contenant des espaces
   prenom[strlen(prenom) - 1] = 0; // on efface le caractères d'échappement "\n" de la string

   printf("\nVotre prenom est : %s\n", prenom);

   return 0;
}
