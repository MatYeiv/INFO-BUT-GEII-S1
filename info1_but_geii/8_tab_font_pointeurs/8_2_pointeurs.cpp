/* Mathieu GADENNE E13A */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int maximum(int tab[],int size);
void croissant(int tab[], int size);
void permute(int * A, int * B);
int rech_max(int tab[], int size, int* ptrindice);

int main()
{
   int tableau[] = {0,12,11,13,15,9,5,4,2,7,8,1,3,10,14};
   int longueur = sizeof(tableau)/sizeof(int);
   int indice;

   cout << "[" << tableau[0] << ", ";

   for(int n = 1; n <= longueur-2; n++)
   {
      cout << tableau[n] << ", " ;
   }

   cout << tableau[longueur-1] << "]" << endl << endl;

   cout << "Le maximum du tableau est : " << maximum(tableau, longueur) << "." << endl << endl;
   cout << "Le maximum du tableau est : "<< rech_max(tableau, longueur, &indice) << " et se trouve à l'indice : "<< indice << endl << endl;
   cout << "Le tableau dans l'ordre croissant donne : " << endl;
   croissant(tableau, longueur);
   cout << "Le maximum du tableau est : "<< rech_max(tableau, longueur, &indice) << " et se trouve à l'indice : "<< indice << endl << endl;


   return 0;
}

int maximum(int tab[], int size)
{
   /*
      Comme vu précedemment à l'exercice 7, la pyramide des âges
      Cette fonction permets de trouver le maximum d'une liste
   */

   int memory = 0;
   int n = 0;

   while (n < size)
   {
      if (memory <= tab[n])
      {
         memory = tab[n];
         n++;
      }
      else
      {
         n++;
      }
   }
   return memory;
}

void croissant(int tab[], int size)
{
   /*
      Fonction permettant de trier les valeurs d'un tableau,
      Le procédé a était expliquer lors des séances TD
   */

   for(int i = 0; i <= size-1; i++)
   {
      for(int j = i+1 ; j <= size-1; j++) // si l'on met j = 0 et > la liste est croissante
      {
         if(tab[j] < tab[i]) // si on change < en > la liste est rangé dans l'ordre décroissant
         permute( &tab[j], &tab[i]);
      }
   }

   // La partie ci-dessous permets l'affichage des valeurs du tableau

   cout << "[" << tab[0] << ", ";

   for(int n = 1; n <= size-2; n++)
   {
      cout << tab[n] << ", " ;
   }

   cout << tab[size-1] << "]" << endl << endl;

   return;
}

void permute(int * A, int * B)
{

   // Fonction qui permute deux nombres grâce à leurs adresses

   int temp;
   temp = *A;
   *A = *B;
   *B = temp;

   return;
}

int rech_max(int tab[], int size, int* ptrindice)
{
   /*
      Cette fonction est construit comme la fonction maxximum,
      Mais contient un pointeur permettant de renvoyer la valeur d'indice dans la fonction main
   */

   int memory = tab[0];
   int n = 1;

   while(n < size)
   {
      if (memory <= tab[n])
      {
         memory = tab[n];
         *ptrindice = n; // Le pointeur renvoie la valeur d'indice
         n++;
      }
      else
      { n++; }
   }

   return memory;
}
