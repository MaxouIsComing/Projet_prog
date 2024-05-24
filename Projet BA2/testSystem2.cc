#include <iostream>
#include <vector>
#include "Systeme.h"
#include"particule.h"
#include "Neon.h"
#include "Argon.h"
#include "Helium.h"
#include "Vecteur3D.h"

using namespace std;

int main() {

// Création d'une instance de système
Systeme systeme(20,20,20);

 // Création d'instances de particules
systeme.InitialiseSysteme(300,300,400);

cout << "Le systeme est composé "<<systeme.getTaille()<< "  particules " << endl;
cout << systeme << endl;

cout << "Lancement de la simulation" << endl;
cout << "============-------"<<endl;

int i(0);
double dt = 1;

while (i < 2) {
    
    systeme.evolue(dt);
    cout << systeme << endl;
    cout << "============-------"<<endl;
    ++i;

}
    return 0;
}