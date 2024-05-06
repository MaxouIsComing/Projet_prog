#include <iostream>
#include <vector>
#include "particule.h"
#include "Vecteur3D.h"
#include "Systeme.h"

using namespace std;

// ======================================================================================================================================
  std::ostream& Systeme::affiche(std::ostream& output) const { 
    cout << "Le système est composé de " << collection.size() << " particules " << endl;
        for(auto const& p : collection) {
            p->affiche(output);
        }
    }
// ======================================================================================================================================
    void Systeme:: ajouter_particule(Particule* const& p){
        if(p!=nullptr) {collection.push_back(unique_ptr<Particule>(p)); }
    }
// ======================================================================================================================================
    void Systeme:: vider_particules(Particule* const& p){collection.clear();}
// ======================================================================================================================================
    std::ostream& operator<<(std::ostream& output, Systeme const& sys) {return sys.affiche(output);}
