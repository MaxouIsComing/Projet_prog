#include <vector>
#include <iostream>
#include <cmath>
#include "Vecteur3D.h"
using namespace std;

int main () {

// un vecteur en 3D :
Vecteur3D vect1(-2.0, -2.0, -2.0);
// un autre vecteur en 3D 
Vecteur3D vect2(6.0, 6.0, 6.0);
Vecteur3D vect3(vect1); // copie de V1
Vecteur3D vect4; //vecteur nul


cout << "Vecteur 1 : " << vect1 << endl;
cout << "Vecteur 2 : " << vect2 << endl;
cout << "Vecteur 3 : " << vect3 << endl;
cout << "Vecteur 4 : " << vect4 << endl;

cout << "Le vecteur 1 est "; 
    if (vect1 == vect2) {
       cout << "égal au";
   } else {
    cout << "différent du"; }
cout << " vecteur 2," << endl << "et est "; 
    if (vect1 != vect3) {
        cout << "différent du"; } 
    else {
       cout << "égal au";
   }
cout << " vecteur 3." << endl;
Vecteur3D bougie = vect2-vect1;
//test produit scalaire, produit vectoriel
double t = vect1.norme();
double t2 = vect1.norme2();
cout << t << " " << t2 << endl;

cout << "Bougie" ;
cout << bougie << endl;
cout << "Bougie norme " << endl;
cout << bougie.norme() << endl;

Vecteur3D vect5;
double resultat;
resultat = vect1*vect3;
vect5 = vect1^vect2;
cout << "produit scalaire de Vecteur 1 et Vecteur 3 : " << resultat <<endl;
cout << "produit vectoriel de Vecteur 1 et Vecteur 2 : " << vect5 <<endl;

//test multiplication par un scalaire

Vecteur3D vect6 (2.0,1.0,-4.0);
Vecteur3D vect7 (1,1,1);

Vecteur3D test = vect7-vect6;
cout << "Le vecteur test vaut : ";
cout << test << endl;

double scalaire = -2.0;

vect6 = vect6*scalaire;
vect7 = scalaire*vect7;

cout << "Vecteur 6 :" << vect6 << endl;
cout << "Vecteur 7 :"  << vect7 << endl;

// test soustraction, addition
Vecteur3D vect8;
Vecteur3D vect9;

vect8 = vect6 + vect7;
vect9 = vect6 - vect7;

cout << "Vecteur 8 :"  << vect8 << endl;
cout << "Vecteur 9 :" << vect9 << endl;

//test inverse et unitaire

vect9 = -vect9;
vect8 = ~vect8;

cout << "Vecteur 8 :"  << vect8 << endl;
cout << "Vecteur 9 :" << vect9 << endl;

    return 0;

}

