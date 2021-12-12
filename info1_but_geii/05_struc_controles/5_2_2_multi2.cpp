/* Mathieu GADENNE E13A */
#include <iostream>

using namespace std;

int main()
{
    int nbr, val, condition = 0;

    cout << "Entrez un nombre entier entre 1 et 10." << endl;
    cin >> nbr;

    while (condition == 0) // Boucle permettant de répéter la demande du nombre si celui-ci ne réponds pas aux conditions imposées
    {
        if (1 <= nbr && nbr <= 10)
        {
            for( int i=1; i<11; i++)
            {
               val = nbr * i; // calcul

               cout << nbr << " x " << i << " = " << val << endl; // affichage
               condition++; // changement d'état de la variable afin de stopper la boucle
            }
        }
        else if (nbr < 1) // réponse du programme si le nombre ne réponds pas aux conditions
        {
            cout << "Erreur le nompbre est trop petit." << endl;
            cout << "Veuillez rentrer un nombre entre 1 et 10 : " << endl;
            cin >> nbr;
        }
        else if (10 < nbr )
        {
            cout << "Erreur le nombre est trop grand." << endl;
            cout << "Veuillez rentrer un nombre entre 1 et 10 : " << endl;
            cin >> nbr;
        }
        else
        {
            cout << "Erreur." << endl;
        }
}

    return 0;
}
