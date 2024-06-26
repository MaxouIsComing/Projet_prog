#pragma once
#include <vector>
#include <array>
#include <cmath>
#include <iostream>

class Enceinte {

    private:
        double Hauteur;
        double Profondeur;
        double Largeur;
        
    public :

Enceinte (double H = 20.0, double P=20.0, double L=20.0)
: Hauteur(H), Profondeur(P), Largeur(L) {}

     // Getters pour les dimensions de l'enceinte
    double getHauteur() const { return Hauteur; }
    double getProfondeur() const { return Profondeur; }
    double getLargeur() const { return Largeur; }
};