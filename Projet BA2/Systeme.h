#include <iostream>
#pragma once
#include "particule.h"
#include "Vecteur3D.h"
#include "Enceinte.h"

class Systeme{
    private:
    std::vector<Particule*> collection;
    double h;
    double p;
    double l;
    public:
    Systeme (std::vector<Particule*> collection={}) {Enceinte e;} // constr. par défaut , à quoi sert l'enceinte?

    Systeme (std::vector<Particule*> collection={}, double Hauteur, double Profondeur, double Largeur)
    : h(Hauteur), p(Profondeur), l(Largeur)
    {} // comment initialiser l'enceinte?
 
    

    



};