#include <vector>
#include <iostream>
#include <cmath>
#include "Vecteur3D.h"
using namespace std;

int main () {
// un vecteur en 3D :
Vecteur3D vect1(3.0, 2.0, -0.1);
// un autre vecteur en 3D 
Vecteur3D vect2(2.6, 3.5, 4.1);
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
    return 0;
}

