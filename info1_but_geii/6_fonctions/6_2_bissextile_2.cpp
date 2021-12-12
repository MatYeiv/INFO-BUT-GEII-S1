/* Mathieu GADENNE E13A */
#include <iostream>

using namespace std;

int isBissextile(int annee);

int main()
{
   int inUti;
   cout << "Entrez l'année désirée." << endl;
   cin >> inUti ;

   if(isBissextile(inUti) == 2) // comparaison avec le retour de la valeur entière pour effectuer le choix de l'affichage
   {
      cout << "L'année " << inUti << " est bissextile." << endl;
   }
   else if (isBissextile(inUti) == 1)
   {
      cout << "L'année " << inUti << " n'est pas bissextile." << endl;
   }
   else
   {
      cout << "Erreur" << endl;
   }

   return 0;
}

int isBissextile(int annee)
{
   if ( (annee % 4 == 0 && annee % 100 != 0) || annee % 400 == 0 ) // condition pour le retour de la valeur entière
   {
      return 2;
   }
   else
   {
      return 1;
   }
}
