/* Mathieu GADENNE E13A */
#include <iostream>

using namespace std;

int main()
{
    int nbr, val;

    cout << "Entrez un nombre entier." << endl;
    cin >> nbr; // saisie

    for(int i=1; i<11; i++)
    {
        val = nbr * i; // calcul

        cout << nbr << " x " << i << " = " << val << endl; // affichage

    }


    return 0;
}
