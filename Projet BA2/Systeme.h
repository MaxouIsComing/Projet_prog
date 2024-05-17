#pragma once
#include <iostream>
#include "Vecteur3D.h"
#include "Enceinte.h"
#include"GenerateurAleatoire.h"

class Particule;

class Systeme {
    private:
    std::vector<std::unique_ptr<Particule>> collection;
    Enceinte E;
    GenerateurAleatoire tirage=123456;


// ======================================================================================================================================
    //constructeur par défaut/ initialisation
    public:
    Systeme () 
        :  collection(), E()    {} 

    Systeme ( double Hauteur, double Profondeur, double Largeur)
    : collection(), E(Hauteur,Profondeur,Largeur)
    {}
// ======================================================================================================================================
    //surcharge affichage interne 
    std::ostream& affiche(std::ostream& output) const;

// ======================================================================================================================================
//ajout,suppression de particule
    void ajouter_particule(Particule*  p);
    void vider_particules(Particule* const& p);
    Systeme(Systeme const&) = delete; 
    Systeme operator=(Systeme const&) = delete; 
// ======================================================================================================================================
 // methode pour l'evolution du systeme
    void BounceWall(const Enceinte& e,  Particule* p);
    virtual void Collision(double dt);
    void VitesseApresChoc( Particule& p1,  Particule& p2);
    Vecteur3D TirageDeVo (const Particule& p1, Vecteur3D Vg);
    int indice( Particule& p) const ;
    void evolue(double dt);
};

// ======================================================================================================================================
//surcharge affichage externe 
std::ostream& operator<<(std::ostream& output, Systeme const& sys);
