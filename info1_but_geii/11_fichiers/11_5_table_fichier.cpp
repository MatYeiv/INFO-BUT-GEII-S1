/* Mathieu GADENNE E13A */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
   FILE * tableX = NULL;
   char * nom = NULL;
   char nom1[] = {"table"};
   char nom2[256]; // ici la valeur de l'entrée utilisateur étant inconnue on viendra la modifié plus tard dans le programme
   char nom3[] = {".txt"};

   int num = 0, resultat = 0, taille = 0;

   printf("Veuillez indiquer le numéro de la table à calculer : \t");
   scanf("%9d", &num);
   printf("Fin\n");

   sprintf(nom2, "%d", num); //Conversion int en str

   taille = strlen(nom1) + 1 + strlen(nom2) + 1 + strlen(nom3) + 1;

   nom = (char*)malloc(taille * sizeof(char));
   if(nom == NULL){return -1;} // protection de la mémoire

   strcat(nom, nom1);
   strcat(nom, nom2);
   strcat(nom, nom3);

   // concaténation des troix chaines permettant d'obtenir le nom du fichier même si la valeur saisie est supérieur à 9

   tableX = fopen(nom, "w"); // ouverture du fichier
   if(tableX == NULL){return -1;} // vérification de l'ouverture du fichier

   fprintf(tableX, "Table de %d\n", num);

   for(int i = 1; i <= 10; i++)
   {
      resultat = i * num;
      fprintf(tableX, "%d x %d = %d\n", i, num, resultat); // écriture dans le fichier
   }

   fclose(tableX); // fermeture du fichier

   return 0;
}
