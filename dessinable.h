#include <iostream>
#include <vector>
#pragma once
#include "SupportAdessin.h"

class Dessinable{
    public:
    virtual void dessine_sur(SupportADessin& support) override 
    // devra être recopié (masquage) dans chaque sous-classe (au lieu d'être hérité, pour des raisons techniques)
    {support.dessine(*this);}
};
