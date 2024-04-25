#include <iostream>
#include <array>
#include <vector>
#include "Systeme.h"
#include"particule.h"
#include "Vecteur3D.h"

using namespace std;

int main() {

// Création d'une instance de système
Systeme systeme;

 // Création d'instances de particules
Particule* helium = new Particule({1, 1, 1}, {0, 0, 0}, 4.002602);
Particule* neon = new Neon({1, 18.5, 1}, {0, 0.2, 0}, 20.1797);
Particule* argon = new Argon({1, 1, 3.1}, {0, 0, -0.5}, 39.948);


 // Ajout des particules au système

    systeme.ajouter_particule(helium);
    systeme.ajouter_particule(neon);
    systeme.ajouter_particule(argon);

cout << systeme << endl;
    return 0;
}