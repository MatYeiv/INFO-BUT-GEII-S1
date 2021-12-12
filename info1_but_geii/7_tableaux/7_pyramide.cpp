/* Mathieu GADENNE E13A */
#include <iostream>
#include <stdlib.h> // bibliothèques permettant de faire l'allocation dynamique

using namespace std;

int PluGndNbr(int pop[], int l);
float AgeMoyen(int pop[], int ann[], int l);
void tableau(int pop[], int longpop, int ptrtab[], int l);
void affiche(int tableau[], int length);

// prototypes des fonctions

int main()
{
   int annee[]={2019,2018,2017,2016,2015,2014,2013,2012,2011,2010,2009,2008,2007,2006,2005,2004,2003,2002,2001,2000,1999,1998,1997,1996,1995,1994,1993,1992,1991,1990,1989,1988,1987,1986,1985,1984,1983,1982,1981,1980,1979,1978,1977,1976,1975,1974,1973,1972,1971,1970,1969,1968,1967,1966,1965,1964,1963,1962,1961,1960,1959,1958,1957,1956,1955,1954,1953,1952,1951,1950,1949,1948,1947,1946,1945,1944,1943,1942,1941,1940,1939,1938,1937,1936,1935,1934,1933,1932,1931,1930,1929,1928,1927,1926,1925,1924,1923,1922,1921,1920,1919};
   int femme[]={346324,350503,357304,366607,377204,391501,392202,399227,404030,413625,408398,411043,407591,414777,404430,404036,402977,401250,403919,404371,379795,376479,364363,368533,365901,357004,358110,378321,386191,399020,408207,414023,417174,425827,424654,421184,416829,441409,444590,448557,425335,413726,412954,403860,414578,434834,458834,467783,464142,454621,449572,446380,443790,454330,455939,461505,456383,440637,441038,440968,438821,431486,427710,425002,421955,419167,409584,414522,403062,416115,409011,405651,395417,373675,282822,274365,265820,245327,217897,225603,234771,226815,219891,217005,206227,202703,186398,181628,164968,152444,128482,113470,95551,82108,67040,53442,41649,32000,23516,16396,18309};
   int homme[]={360058,365656,371835,382535,393693,403548,409134,419746,420236,430787,428212,430731,425893,432473,424444,424188,422558,422993,426940,427764,398800,390940,373892,372960,365819,352810,352119,369044,376549,384258,385549,391686,392288,398561,398500,396432,392284,418774,423924,427805,405284,398834,402575,391152,403928,424573,446674,458045,456949,445768,439368,431757,429154,437583,437857,439911,432906,417223,417146,411659,407015,395560,390560,384101,377452,375899,366489,369758,357936,367412,357423,353971,343786,319209,236133,228151,218015,198121,171413,171850,173240,163237,152718,145045,130057,122635,107243,98622,85287,73609,57533,47092,36852,28358,22290,16359,11552,7728,5514,3639,3551};

   int longueurf = sizeof(femme)/sizeof(int);
   int longueurh = sizeof(homme)/sizeof(int);
   int longueurAn = sizeof(annee)/sizeof(int);

   // déclarations des variables indiquant la longueur des listes

   int * cinqtab = NULL; // Déclaration du pointeur permettant de faire l'allocation dynamique pour le tableau 5 par 5
   int taille = 0;

   // Condition indiquant le nombre de case à créer dans le tableau 5 par 5

   if(longueurAn%5 != 0)
   { taille = (longueurAn/5) + 1; }
   else
   { taille = (longueurAn/5); }

   cinqtab = (int*)calloc(taille, sizeof(int));

   if(cinqtab == NULL){ return -1; } // protection de la mémoire

   cout << "L'age le plus represente chez les femmes est " << 2021 - annee[PluGndNbr(femme, longueurf)] << " ans avec une population de : "<< femme[PluGndNbr(femme, longueurf)] << "." << endl;
   cout << "L'age moyen chez les femmes est de " << AgeMoyen(femme, annee, longueurf) << " ans" << endl << endl;

   cout << "L'age le plus represente chez les hommes est " << 2021 - annee[PluGndNbr(homme, longueurh)] << " ans avec une population de : "<< homme[PluGndNbr(homme, longueurh)] << "." << endl;
   cout << "L'age moyen chez les hommes est de " << AgeMoyen(homme, annee, longueurh) << " ans." << endl << endl;

   // affichage des différents résultats

   cout << "Le tableau 5 par 5  des hommes s'organise de la maniere suivante : " << endl ;
   tableau(homme, longueurh, cinqtab, taille-1);
   affiche(cinqtab, taille-1); // appel des fonctions avec la taille-1, autrement les fonction ne s'executerais pas correctement

   cout << "Le tableau 5 par 5  des femmes s'organise de la maniere suivante : " << endl ;
   tableau(femme, longueurf, cinqtab, taille-1);
   affiche(cinqtab, taille-1);

   return 0;
}

int PluGndNbr(int pop[], int l)
{
   /*
      Fonction permettant de trouver le maximum dans un tableau
   */
   long valeurfin = 0;
   int compteur = 0;
   int n= 0;

   while (n <= l)
   {
      if (valeurfin < pop[n]) // si la valeur de pop[n] est plus grande que la précedanete alors on la sauvegarde à la place de la précédente
      {
         valeurfin = pop[n];
         compteur = n;
      }
      n++;
   }
   return compteur;
}

float AgeMoyen(int pop[], int ann[], int l)
{
   /*
      Fonction permmettant de trouver l'age moyen a partir d'un tableau de population ainsi que d'un tableau d'année
      C'est deux tableaux doivent avoir des indices qui coïncident
   */

   float moy = 0;
   float moyenne = 0;
   int n = 0;
   float temp = 0, massetemp = 0 , massemoy = 0;

   while(n < l)
   {
      temp = pop[n];
      massetemp = massetemp + temp; // somme de toute la population du tableau

      moy = temp * (2021 - ann[n]); // on calcule le nombre de personne pour un age donné et on somme
      massemoy = massemoy + moy;

      n++;
   }

   moyenne = massemoy / massetemp;

   return moyenne;
}

void tableau(int pop[], int longpop, int ptrtab[], int l)
{
   /*
      Fonction permettant le remplissage d'un tableau 5 par 5 à partir d'un autre tableau
   */
   int j = 0;

   for(int i = 0; i < 5*l; i = i+5)
    {
      ptrtab[j] = pop[i] + pop[i+1] + pop[i+2] + pop[i+3] + pop[i+4] ; // somme des cases du tableau de population
      j++; // incrémentation du compteur d'indice pour le tableau 5 par 5
   }

   int compteur = longpop % 5; // Condition pour le "switch statement"

   switch(compteur)
   /*
      Structure permettant de réalisé la somme de la case finale du tableau 5 par 5,
      dépendant du nombre de case restante à sommer
   */
   {
   case 1 :
      ptrtab[l] = pop[longpop-1];
      break;
   case 2 :
      ptrtab[l] = pop[longpop-1] + pop[longpop-2];
      break;
   case 3 :
      ptrtab[l] = pop[longpop-1] + pop[longpop-2] + pop[longpop-3];
      break;
   case 4 :
      ptrtab[l] = pop[longpop-1] + pop[longpop-2] + pop[longpop-3] + pop[longpop-4];
      break;
   default :
      break;
   }
   return;
}

void affiche(int tableau[], int length)
{
   /*
      Fonction permettant de faire l'affichage d'un tableau,
      quand lui sont données en paramètres le tableau ainsi que la longueur-1
   */
   cout << "["  << tableau[0] << ", " ;
   for(int j = 1; j <= length-1; j++)
   {
      cout << tableau[j] << ", " ;
   }
   cout << tableau[length] << "]" << endl << endl;

   return;
}
