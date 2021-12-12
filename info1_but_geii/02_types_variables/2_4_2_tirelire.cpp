/* Mathieu GADENNE E13A */
#include <iostream>

using namespace std;

int main()
{
   int Nbp_2E = 2;
   int Nbp_1E = 12;
   int Nbp_50C = 3;
   int Nbp_10C = 10;

   //on initialise le nombre de pièces

   float resultat, resultat_us, resultat_uk;

   float ch_us, ch_uk;

   ch_uk = 0.89021;
   ch_us = 1.08925;

   // on assigne les valeurs de changes

   resultat = 2*Nbp_2E + 1*Nbp_1E + 0.5*Nbp_50C + 0.1*Nbp_10C;
   resultat_uk = resultat * ch_uk;
   resultat_us = resultat * ch_us;

   // on calcule les différents résultats

   cout << "Total dans la tirelire = " << resultat << "€" << endl;
   cout << "Total dans la tirelire = " << resultat_uk << "£" << endl;
   cout << "Total dans la tirelire = " << resultat_us << "$" << endl;

   // on affiche les résultats

   return 0;
}
