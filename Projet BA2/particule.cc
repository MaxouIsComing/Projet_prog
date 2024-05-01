#include <iostream>
#include <vector>
#include "particule.h"
#include "Vecteur3D.h"
using namespace std;


// ======================================================================================================================================
    // Getters
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
   std::ostream& Particule:: affiche(std::ostream& sortie) const {
     sortie << "Particule " << "position : " << position << ", vitesse : " << vitesse << ", masse : " << masse << endl; 
     return sortie;
    }   
    std::ostream& Argon::affiche(std::ostream& sortie) const {
     sortie << "particule  Argon : " << "position : " << position << ", vitesse : " << vitesse << ", masse : " << masse << endl; 
     return sortie;
    }   
     std::ostream& Neon::affiche(std::ostream& sortie) const {
     sortie << "particule  Neon :" << "position : " << position << ", vitesse : " << vitesse << ", masse : " << masse << endl; 
     return sortie;
    }   
     std::ostream& Helium::affiche(std::ostream& sortie) const {
     sortie << "particule  Helium :" << "position : " << position << ", vitesse : " << vitesse << ", masse : " << masse << endl; 
     return sortie;
    }   

    std::ostream& operator<<(std::ostream& sortie, Particule const& part) 
            { return part.affiche(sortie); }

    std::ostream& operator<<(std::ostream& sortie, Argon const& part) 
            { return part.affiche(sortie); }

    std::ostream& operator<<(std::ostream& sortie, Neon const& part) 
            { return part.affiche(sortie); }

    std::ostream& operator<<(std::ostream& sortie, Helium const& part) 
            { return part.affiche(sortie); }

        

