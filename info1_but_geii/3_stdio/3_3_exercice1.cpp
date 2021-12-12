/* Mathieu GADENNE E13A */
#include <iostream>

using namespace std;

int main()
{
   long secondes;
   long heures, minutes, sec;

   // déclarations des variables

   cout << "Saisir le nombres de secondes" << endl;
   cin >> secondes ;

   // saisie de l'utilisateur

   heures = secondes / 3600;
   minutes = (secondes % 3600) / 60;
   sec = secondes %  60;

   // calcul des valeurs

   cout << secondes << " secondes correspondents a ";
   cout << heures <<"h, "<< minutes << "min et ";
   cout << sec << "secondes." << endl;

   // affichage des resultats

   return 0;
}
