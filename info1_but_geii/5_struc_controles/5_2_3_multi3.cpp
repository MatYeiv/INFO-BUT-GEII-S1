/* Mathieu GADENNE E13A */
#include <iostream>
using namespace std;

int main()
{
   int nbr, val, uti;
   int cons = 0;
   int erreur = 0;

   while(cons != 1) // garde-fou empêchant l'utilisateur de saisir une valeur ne répondant pas aux conditions
   {
      cout << "Entrez une valeur entre 1 et 10." << endl;
      cin >> nbr;

      if(1 <= nbr && nbr <= 10)
      {
         cons = 1;
      }
      else if(nbr < 1)
      {
         cout << "Le nombre est trop petit." << endl;
      }
      else if(10 < nbr)
      {
         cout << "Le nombre est trop grand." << endl;
      }
      else
      {
         cout << "Erreur." << endl;
      }
   }
   for (int i=1; i<=10; i++)
   {
      val = nbr * i;
      cout << nbr << " x " << i << " = ";
      cin >> uti;

      while (val != uti && i <= 10) // boucle imposant à l'utilisateur de saisir la réponse attendue
      {
         cout << "Erreur !!" << endl;
         cout << nbr << " x " << i << " = ";
         erreur = erreur + 1 ; // compteur d'erreur
         cin >> uti;
      }
   }

   cout << "Vous avez fait " << erreur << " erreur au cours de cette execution." << endl; // affichage du nombre d'erreur

   return 0;
}
