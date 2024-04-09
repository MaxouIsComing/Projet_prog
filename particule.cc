#include <iostream>
#include <array>
#include <vector>
#include <cmath>
#include "particule.h"
using namespace std;

//surchage externe affichage 
ostream& operator<<(ostream& sortie, Particule const& part) {
    return part.affiche(sortie)
}
void Particule::affiche(ostream& const sortie) {
    cout << "pos : " << position[0] << position[1] << vitesse << 
}

// getteurs avec Vecteur3d:: pour extérioriser les méthodes

array<double,3> Particule::get_Position() const {
    return position;
}
double Particule::get_Masse() const{
    return masse;
}