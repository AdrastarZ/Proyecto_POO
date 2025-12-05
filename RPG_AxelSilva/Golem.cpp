
#include "Golem.h"
#include <iostream>

using namespace std;

    Golem::Golem():Personaje("Golem", 25, 30, 250){ //Establece las estadisticas fijas del enemigo Golem
         
        xpDrop = 150; // La experiencia que deja el Golem
    }
    
    Golem::~Golem(){}

    int Golem::getXP(){
        return xpDrop;
    }