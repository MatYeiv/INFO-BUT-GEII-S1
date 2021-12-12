/* Mathieu GADENNE E13A */
#include <iostream>
#include <math.h>
// importation de la bibliothèques math.h nécessaire à l'utilisation de la fonction sqrt()

using namespace std;

int main()
{
   float a,b,c;
   double X, X1, X2, delta, racdelta;

   // déclarations des variables

   cout << "Entrer a, b et c de votre polynône du second degré." << endl;

   cin >> a; cin >> b; cin >> c;

   // saisie utilisateur

   delta = (b*b) - 4*(a)*(c);

   // calcul de la condition

   if (delta > 0)
   {
      racdelta = sqrt(delta);
      X1 = (-b-racdelta)/(2*a);
      X2 = (-b+racdelta)/(2*a);

      // calcul

      cout << "X1 vaut : " << X1 << " et X2 vaut : " << X2 << endl; // affichage
   }
   else if (delta == 0)
   {
      X = (-b)/(2*a);

      cout << "X vaut : " << X << endl;
   }
   else if (delta < 0)
   {
      X = (-b)/(2*a); // calcul de la partie réel
      racdelta = sqrt(-delta);
      X1 = (racdelta)/(2*a);
      X2 = (-racdelta)/(2*a);

      // calcul de la partie imaginaire

      cout << "Z1 vaut : " << X << " + (" << X1 << "j) et" << "Z2 vaut : " << X << " + (" << X2 << "j)" << endl;

      // affichage

   }
   else
   {
      cout << "Error" << endl;
   }

   return 0;
}
