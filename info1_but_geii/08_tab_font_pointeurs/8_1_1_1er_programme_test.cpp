/* Mathieu GADENNE E13A */
#include <iostream>

using namespace std;

void affiche(int t[ ], int);

int main()
{
    int tab1[ ]={1,2,6,5};
    int tab2[ ]={9,8,7,6,5,4};

    cout << endl << "tout le tableau 1 :" << endl;
    affiche(tab1,1);

    cout << endl << "tout le tableau 2 :" << endl;
    affiche(tab2,6);

    cout << endl << "les 3 premiers elements du tableau 2:" << endl;
    affiche(tab2,3);

    return 0;
}

void affiche(int tab[], int size)
{
   /*
      Fonction modifié afin de répondre au cas particulier ou size = 1
   */
   if(size == 1)
   { cout << "[" << tab[0] << "]" << endl; }
   else
   {
   int i;

   cout << "[" << tab[0];

   for(i=1;i<size-1;i++)
   {
      cout << "," << tab[i];
   }

   cout << "," << tab[size-1] << "]" << endl;
   }
}
