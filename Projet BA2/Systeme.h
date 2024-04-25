#include <iostream>
#pragma once
#include "particule.h"
#include "Vecteur3D.h"
#include "Enceinte.h"

typedef std::unique_ptr<Particule> ParticulePtr; //plus lisible


class Systeme{
    private:
    std::vector<ParticulePtr> collection;
    Enceinte E;

// ======================================================================================================================================
    //constructeur par défaut/ initialisation
    public:
    Systeme (std::vector<ParticulePtr> c={}) 
        :  collection(c), E()    {} 

    Systeme (std::vector<ParticulePtr> c={}, double Hauteur, double Profondeur, double Largeur)
    : collection(c), E(Hauteur,Profondeur,Largeur)
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
};
// ======================================================================================================================================
//surcharge affichage externe 
std::ostream& operator<<(std::ostream& output, Systeme const& sys)
 {return sys.affiche(output);}