#pragma once
#include <iostream>
#include "particule.h"
#include "Vecteur3D.h"
#include "Enceinte.h"

typedef std::unique_ptr<Particule> ParticulePtr; //plus lisible

class Systeme {
    private:
    std::vector<ParticulePtr> collection;
    Enceinte E;

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
    void ajouter_particule(Particule* const& p);
    void vider_particules(Particule* const& p);
    Systeme(Systeme const&) = delete; 
    Systeme operator=(Systeme const&) = delete; 
// ======================================================================================================================================
 // methode pour l'evolution du systeme

void evolue(double dt) {
    

}

    


};

class GenerateurAleatoire {
         public:
    GenerateurAleatoire(unsigned int graine = std::random_device()() ) 
    : generateur(graine){}

    double uniforme(double min, double max) 
    { return distribution_uniforme(generateur, std::uniform_real_distribution<double>::param_type{min});}
        private:
    std::default_random_engine generateur ; 
    std::uniform_real_distribution<double> distribution_uniforme ;

};
// ======================================================================================================================================
//surcharge affichage externe 
std::ostream& operator<<(std::ostream& output, Systeme const& sys);
