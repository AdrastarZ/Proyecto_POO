
#include "Dragon.h"
#include <iostream>

using namespace std;

    Dragon::Dragon():Personaje("Dragón", 50, 50, 500){ //Establece las estadisticas fijas del enemigo Dragon
         
        xpDrop = 300; // La experiencia que deja el Golem
    }
    
    Dragon::~Dragon(){}

    int Dragon::getXP(){
        return xpDrop;
    }