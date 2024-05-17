#pragma once
#include <iostream>
#include<random>

class GenerateurAleatoire {
         public:
    GenerateurAleatoire(unsigned int graine = std::random_device()() ) 
    : generateur(graine){}

    double uniforme(double min, double max);
        private:
    std::default_random_engine generateur ; 
    std::uniform_real_distribution<double> distribution_uniforme ;

};
