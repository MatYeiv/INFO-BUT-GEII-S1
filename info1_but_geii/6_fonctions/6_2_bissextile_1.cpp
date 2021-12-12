/* Mathieu GADENNE E13A */
#include <iostream>

using namespace std;

void afficheSiBissextile( int annee); // prototype de la fonction

int main()
{
   int entreUti = 0;
   cout << "Entrez l'année désirée." << endl;
   cin >> entreUti; // saisie utilisateur

   afficheSiBissextile(entreUti);

   return 0;
}
void afficheSiBissextile (int annee)
{
   if ( (annee % 4 == 0 && annee % 100 != 0) || annee % 400 == 0) // condition pour choix de l'affichage
   {
      cout << "L'année est bixestile." << endl;
   }
   else
   {
      cout << "L'année n'est pas bissextile." << endl;
   }
}
