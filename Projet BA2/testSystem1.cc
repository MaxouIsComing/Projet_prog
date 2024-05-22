#include <iostream>
#include <array>
#include <vector>
#include "Systeme.h"
#include"particule.h"
#include "Neon.h"
#include "Vecteur3D.h"
#include "Argon.h"
#include "Helium.h"

using namespace std;

int main() {

// Création d'une instance de système
Systeme systeme(20,20,20);

 // Création d'instances de particules
Particule* helium = new Helium({1, 1, 1}, {0, 0, 0}, 4.002602);
Neon* neon = new Neon ({1, 18.5, 1}, {0, 0.2, 0}, 20.1797);
Argon* argon = new Argon({1, 1, 3.1}, {0, 0, -0.5}, 39.948);

 // Ajout des particules au système

    systeme.ajouter_particule(helium);
    systeme.ajouter_particule(neon);
    systeme.ajouter_particule(argon);

cout << "Le systeme est composé de  3 particules " << endl;
cout << systeme << endl;

cout << "Lancement de la simulation" << endl;
cout << "============-------"<<endl;

int i(0);
double dt = 1;

while (i<8) {
    
    systeme.evolue(dt);
    cout << systeme << endl;
    cout << "============-------"<<endl;
    ++i;

}
    return 0;
}