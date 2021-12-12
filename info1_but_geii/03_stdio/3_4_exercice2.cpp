/* Mathieu GADENNE E13A */
#include <iostream>

using namespace std;

int main()
{
   int r;
   const float pi = 3.141592; // déclaration de la constantes pi
   double surface, volume;

   cout << "Saisir r = ";
   cin >> r; // Saisie utilisateur
   cout << endl;

   surface = 4*pi*r*r;
   volume = (4.0/3)*pi*r*r*r;

   // calcul

   cout << "Surface d'une sphère de rayon, " << r << " est de : " << surface << "m2." << endl;
   cout << "Volume d'une sphère de rayon, " << r << " est de : " << volume << "m3." << endl;

   // affichage des résultats

   return 0;
}
