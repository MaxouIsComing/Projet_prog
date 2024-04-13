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

    //surcharge affichage interne 
    std::ostream& affiche(std::ostream& output) const;

    void ajouter_particule(Particule* const& p){
        collection.push_back(p); //garder la définition dans le .h et mettre le corps dans le .cc
    }
    void vider_particules(Particule* const& p){
        collection.clear(); //.h et .cc

    }
    Systeme(Systeme const&) = delete; // on supprime le choix de mettre des constr. de copie
    Systeme operator=(Systeme const&) = delete; // on supprime le choix d'affecter systeme

 
    

};

//surcharge affichage externe 
std::ostream& operator<<(std::ostream& output, Systeme const& sys);