#include <iostream>
#include <vector>
#pragma once
#include "particule.h"

class SupportADessin{
    public:
    virtual ~SupportADessin() = default;

    // on suppose ici que les supports ne seront ni copiés ni déplacés 
    virtual void dessine(Neon const&) = 0;
    virtual void dessine(Argon const&) = 0;
    virtual void dessine(Enceinte const&) = 0;
    virtual void dessine(Systeme const&) = 0;
    // autres choses à dessiner?



};

class TextViewer : public SupportADessin {
    private:
    std::ostream& flot;
    public:
    TextViewer(std::ostream& flot)
    : flot(flot)
    {}
    virtual ~TextViewer() = default;
    // on copie pas les TextViewer
    TextViewer(TextViewer const& ) = delete; // on supprime le choix d'ajouter des constructeurs de copie
    TextViewer& operator=(TextViewer const&) = delete;
    // mais on peut les déplacer
    TextViewer(TextViewer&&) = default; // constructeur par défaut
    TextViewer& operator=(TextViewer&&) = default;

    virtual void dessine(Contenu const& a_dessiner) override; // il faudra ajouter la classe contenu plus tard 



};

