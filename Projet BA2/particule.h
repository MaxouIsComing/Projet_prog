#pragma once
#include <iostream>
#include <array>
#include <vector>
#include <cmath>
#include "Vecteur3D.h"
#include"Enceinte.h"

class Particule {
    protected: // ne pas oublier le destructeur!!!!
        Vecteur3D position;
        Vecteur3D vitesse;
        double masse;
    public:
 // ======================================================================================================================================
    //constructeur par défaut/ copie/ initialisation
        Particule() : position(), vitesse(), masse(0.0) {}
        Particule( Vecteur3D pos, Vecteur3D vit, double m) : position(pos), vitesse(vit), masse(m) {}
        Particule(const Particule& autre) : position(autre.position), vitesse(autre.vitesse), masse(autre.masse) {}
// ======================================================================================================================================
    // Getters
        double getPosition(int pos) const;
        double getVitesse(int pos) const ;
        double getMasse() const;
// ======================================================================================================================================
    // Setters
        void setPosition(const Vecteur3D& pos);
        void setVitesse(const Vecteur3D& vit);
        void setMasse(double m);
// ======================================================================================================================================
   //surcharge d'opérateur interne
   virtual std::ostream& affiche(std::ostream& sortie) const;
// ======================================================================================================================================
 // methode pour l'evolution du systeme
    virtual void evolue(double dt) {
        double x;
        double y;
        double z;

        x = dt*getVitesse(0);
        y = dt*getVitesse(1);
        z = dt*getVitesse(2); 
        setPosition({x,y,z});
    }
    virtual void BounceWall(const Enceinte& e) {
        double x_min = 0.0;
        double x_max = e.getLargeur();
        double y_min = 0.0;
        double y_max = e.getProfondeur();
        double z_min = 0.0;
        double z_max = e.getHauteur();


        // Vérifier si la particule a atteint ou dépassé les limites de l'enceinte sur chaque axe
        if (getPosition(0) <= x_min || getPosition(0) >= x_max) {
            // Inverser la composante de vitesse correspondante
            vitesse.set_coord(0 ,-getVitesse(0));
        }

        if (getPosition(1) <= y_min || getPosition(1) >= y_max) {
            // Inverser la composante de vitesse correspondante
           vitesse.set_coord(1 ,-getVitesse(1));
        }

        if (getPosition(2) <= z_min || getPosition(2) >= z_max) {
            // Inverser la composante de vitesse correspondante
            vitesse.set_coord(2 ,-getVitesse(2));
        }
    }
};
   
// pour voir si deux particules se sont rencontrer et calcul des vitesses voir descriptif projet et utiliser loi de proba :::



    


// ======================================================================================================================================
    //surcharge d'opérateur externe 
    std::ostream& operator<<(std::ostream& sortie, Particule const& part);

class Neon : public Particule {
    public:
    Neon (Vecteur3D pos, Vecteur3D vit, double m)
    : Particule(pos, vit, m)  {}
    
    std::ostream& affiche(std::ostream& sortie)const;
};
std::ostream& operator<<(std::ostream& sortie, Neon const& part);



class Argon : public Particule {
    public:
    Argon (Vecteur3D pos, Vecteur3D vit, double m)
    : Particule (pos,vit,m){}

     std::ostream& affiche(std::ostream& sortie) const;
};
 std::ostream& operator<<(std::ostream& sortie, Argon const& part);

 class Helium : public Particule {
    public:
    Helium (Vecteur3D pos, Vecteur3D vit, double m)
    : Particule (pos,vit,m){}

     std::ostream& affiche(std::ostream& sortie) const;
};
 std::ostream& operator<<(std::ostream& sortie, Helium const& part);