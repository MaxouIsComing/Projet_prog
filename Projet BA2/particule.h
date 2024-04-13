#pragma once
#include <iostream>
#include <array>
#include <vector>
#include <cmath>
#include "Vecteur3D.h"

class Particule {
    protected:
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

class Neon : public Particule {
    private:
    Vecteur3D pos;
    Vecteur3D vit;
    Vecteur3D m;
    public:
    Neon() : pos(),vit(),m(0.0) {}
    Neon (Vecteur3D pos, Vecteur3D vit, double m) : Particule (pos, vit,m){}
    Neon (const Neon& autre) : pos(autre.pos), vit(autre.vit), m(autre.m) {}
    
};

class Argon : public Particule {
    protected:
    Vecteur3D pos;
    Vecteur3D vit;
    Vecteur3D m;
    public:
    //constructeur par défaut, initialisation, copie
    Argon() : pos(),vit(),m(0.0) {}
    Argon (Vecteur3D pos, Vecteur3D vit, double m) : Particule (pos, vit,m){}
    Argon (const Argon& autre) : pos(autre.pos), vit(autre.vit), m(autre.m) {}
    

};