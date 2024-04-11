#include <iostream>
#include <array>
#include <vector>
#include <cmath>
#include "Vecteur3D.h"

class Particule {
    private:
        Vecteur3D position;
        Vecteur3D vitesse;
        double masse;
    public:
 // ======================================================================================================================================
    //constructeur par défaut/ copie/ initialisation
        Particule() : position(), vitesse(), masse(0.0) {}
        Particule(const Vecteur3D& pos, const Vecteur3D& vit, double m) : position(pos), vitesse(vit), masse(m) {}
        Particule(const Particule& autre) : position(autre.position), vitesse(autre.vitesse), masse(autre.masse) {}
// ======================================================================================================================================
    // Guetters
        Vecteur3D getPosition() const;
        Vecteur3D getVitesse() const ;
        double getMasse() const;
// ======================================================================================================================================
    // Setters
        void setPosition(const Vecteur3D& pos);
        void setVitesse(const Vecteur3D& vit);
        void setMasse(double m);
// ======================================================================================================================================
   //surcharge d'opérateur interne
    std::ostream& affiche(std::ostream& sortie) const;
};
// ======================================================================================================================================
    //surcharge d'opérateur externe 
    std::ostream& operator<<(std::ostream& sortie, Particule const& part);

