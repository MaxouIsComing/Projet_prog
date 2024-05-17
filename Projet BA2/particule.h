#pragma once
#include <iostream>
#include <array>
#include <vector>
#include <cmath>
#include "Vecteur3D.h"
#include"Enceinte.h"
#include"Systeme.h"
#include<random>

class Particule {
    protected: 
        Vecteur3D position;
        Vecteur3D vitesse;
        double masse;
        static constexpr int EPSILON = 1;
        
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
        Vecteur3D getVitesse()const;
        Vecteur3D getPosition() const;
// ======================================================================================================================================
    // Setters
        void setPosition(const Vecteur3D& pos);
        void setVitesse( Vecteur3D& vit);
        void setMasse(double m);
        void setVitesse(int pos, double new_vit);
        void setPosition(int pos, double new_pos);
// ======================================================================================================================================
    //destructeur
     virtual ~Particule() = default;

// ======================================================================================================================================
   //surcharge d'opérateur interne
        virtual std::ostream& affiche(std::ostream& sortie) const;
// ======================================================================================================================================
 // methode pour l'evolution du systeme
    virtual void evolue(double dt);
    bool Rencontre (const Particule& p1);
    bool operator==(const Particule& other) const;
   };
// ======================================================================================================================================
    //surcharge d'opérateur externe 
    std::ostream& operator<<(std::ostream& sortie, Particule const& part);







