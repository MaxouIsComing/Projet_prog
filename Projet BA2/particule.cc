#include <iostream>
#include <vector>
#include "particule.h"
#include "Vecteur3D.h"
using namespace std;


// ======================================================================================================================================
    // Guetters
    Vecteur3D Particule::getPosition() const { return position; }
    Vecteur3D Particule::getVitesse() const { return vitesse; }
    double Particule::getMasse() const  { return masse; }


// ======================================================================================================================================
    // Setters
    void Particule::setPosition(const Vecteur3D& pos) { position = pos; }
    void Particule::setVitesse(const Vecteur3D& vit) { vitesse = vit; }
    void Particule::setMasse(double m) { masse = m; }

// ======================================================================================================================================
 //surcharge affichage
    std :: ostream& Particule::affiche(std::ostream& sortie) const {
    sortie << "pos : " << position << " ; \"v\" : " << vitesse << " ; \"m\" : " << masse; 
    return sortie;
        }
    std::ostream& operator<<(std::ostream& sortie, Particule const& part) { 
    return part.affiche(sortie);
        }