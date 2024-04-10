#include <iostream>
#include <array>
#include <vector>
#include <cmath>
#include "particule.h"
using namespace std;

//surchage externe affichage 
std::ostream& operator<<(ostream& sortie, Particule const& part) {
    return part.affiche(sortie);
}
std::ostream& Particule::affiche(ostream& const sortie) const {
    sortie << "pos : ";
    for(auto const& element : position) {
        sortie << element << " ";
    }
    sortie << " ; " ;
    sortie << "v : "  ;

    for (auto const& element : vitesse) {
        sortie << element << " ";
    }
    sortie << " ; m : " << masse ;
    }


// getteurs avec Vecteur3d:: pour extérioriser les méthodes

array<double,3> Particule::get_Position() const {
    return position;
}
double Particule::get_Vitesse(unsigned int pos) const{
   return  vitesse[pos];
}