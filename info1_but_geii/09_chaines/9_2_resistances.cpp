/* Mathieu GADENNE E13A */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void affichage(char tab[][7]);
int isTrue(char tab[][7], char text[]);
void troisAnneaux(char tab[][7], char _1Ann[], char _2Ann[], char _3Ann[], int E12[]);

int main(void)
{
   char tabcodecoul[][7] = {"noir", "marron", "rouge", "orange", "jaune", "vert", "bleu", "violet", "gris", "blanc"};
   int tabvalE12[] = {10, 12, 15, 18, 22, 27, 33, 39, 47, 56, 68, 82};
   char ent1Ann[256], ent2Ann[256], ent3Ann[256];

   affichage(tabcodecoul);
   printf("\n");
   troisAnneaux(tabcodecoul, ent1Ann, ent2Ann, ent3Ann, tabvalE12);

   return 0;
}

void affichage(char tab[][7])
{
   /*
      Fonction d'affichage du tableau comme dans la consigne
   */

   for(int i = 0; i <= 9; i++)
   { printf("Couleurs %d : %s\n", i, tab[i]); }
}

int isTrue(char tab[][7], char text[])
{
   /*
      Fonction vérifiant si la string saisie par l'utilisateur correspond à l'une des srting du tabcodecoul
   */

   int comparaison = 0;

   for(int i = 0; i <= 9; i++)
   {
      if(strcmp(tab[i], text) == 0) // comparaison des 2 strings afin de savoir si elle coresspondent entre elles
      { comparaison++; }
      else
      { comparaison = comparaison; }
   }
   if(comparaison == 1)
   { return 1; }
   else
   { return 0; }
}

void troisAnneaux(char tab[][7], char _1Ann[], char _2Ann[], char _3Ann[], int E12[])
{
   int defo1, defo2, defo3, defosaisie, defop = 0;
   int val1Ann, val2Ann, val3Ann;
   int taille, correspondance;
   long valAnn1_2 = 0;
   char st1Ann[256], st2Ann[256], answer[256];
   char * Ann1_2 = NULL;

   char * end;

   while(defop == 0) // Cette boucle nous permet de demander à l'utilisateur si il veut de nouveau utiliser le programme
   {
      defo1 = 0; defo2 = 0; defo3 = 0, defosaisie = 0;
      val1Ann = 0; val2Ann = 0; val3Ann = 0;
      taille = 0; correspondance = 0;

      while(defo1 == 0) // garde-fou qui oblige l'utilisateur a rentré une string correspondant à une string du tabcodecoul
      {
         printf("Indiquez la couleur du premier anneau : \t");
         fgets(_1Ann, 256, stdin);
         _1Ann[strlen(_1Ann)-1] = 0; // Enlève ""\n".

         if (isTrue(tab, _1Ann) == 1)
         { defo1 = 1; } // variable de defaut permettant de sortir de la boucle
      }

      for(int i = 0; i <= 9; i++)
      {
         if(strcmp(tab[i], _1Ann) == 0) // on compare les deux strings et si elle sont égale alors la valeur renvoyé sera 0.
         { val1Ann = i; }
      }

      sprintf(st1Ann, "%d", val1Ann); // conversion d'entier en string à l'aide de la fonction sprintf

      while(defo2 == 0)
      {
         printf("Indiquez la couleur du deuxième anneau : \t");
         fgets(_2Ann, 256, stdin);
         _2Ann[strlen(_2Ann)-1] = 0;

         if (isTrue(tab, _2Ann) == 1)
         { defo2 = 1; }
      }

      for(int i = 0; i <= 9; i++)
      {
         if(strcmp(tab[i], _2Ann) == 0)
         { val2Ann = i; }
      }

      sprintf(st2Ann, "%d", val2Ann);

      while(defo3 == 0)
      {
         printf("Indiquez la couleur du troisième anneau : \t");
         fgets(_3Ann, 256, stdin);
         _3Ann[strlen(_3Ann)-1] = 0; // Enlève \n.

         if (isTrue(tab, _3Ann) == 1)
         { defo3 = 1; }
      }

      for(int i = 0; i <= 9; i++)
      {
         if(strcmp(tab[i], _3Ann) == 0) // on compare les deux strings et si elle sont égale alors la valeur renvoyé sera 0.
         { val3Ann = i; }
      }

      taille = strlen(st1Ann) + 1 + strlen(st2Ann) + 1;

      Ann1_2 = (char*)malloc(taille * sizeof(char));
      if(Ann1_2 == NULL){exit(EXIT_FAILURE);} // Sortie du programme en cas de mauvaise allocation de la mémoire

      strcpy(Ann1_2, st1Ann); // On copie la deuxième string dans la première.
      strcat(Ann1_2, st2Ann); // Concaténation de 2 string.

      valAnn1_2 = strtol(Ann1_2, &end, 10); // Conversion d'une string en entier
      // 1.String / 2.Pointeur sur le premier caractère / 3.Base

      for(int i = 0 ; i < 12; i++) // test de la correspondance avec une valeur de la série E12
      {
         if(E12[i] == valAnn1_2)
         { correspondance = 1; }
         else
         { correspondance = correspondance; }
      }

      if(correspondance == 1)
      { printf("\nLa resistance a une valeur de %ld x 10^%d ohms et se trouve dans la serie E12.\n", valAnn1_2, val3Ann); }
      else
      { printf("\nLa resistance a une valeur de %ld x 10^%d ohms et ne se trouve pas dans la serie E12.\n", valAnn1_2, val3Ann); }

      while(defosaisie == 0) // boucle obligeant l'utilisateur à saisir une réponse correct afin de continuer
      {
         printf("\nVoulez vous recommencer ? oui/non\n"); // Permet à l'utilisateur de réutiliser le programme sans le relancer
         fgets(answer, 256, stdin);
         answer[strlen(answer)-1] = 0;

         if(strcmp(answer, "oui") == 0) // test de la validité de la réponse
         {
            defop = 0; printf("\n\n");
            defosaisie++;
         }
         else if(strcmp(answer, "non") == 0)
         {
            defop = 1;
            defosaisie++;
         }
         else
         {
            defosaisie = defosaisie;
         }
      }
   }
}
