
#include "Zombie.h"
#include <iostream>

using namespace std;

    Zombie::Zombie():Personaje("Zombie", 15, 10, 100){ //Establece las estadisticas fijas del enemigo Zombie
         
        xpDrop = 50; // La experiencia que deja el Enemigo
    }
    
    Zombie::~Zombie(){}

    int Zombie::getXP(){
        return xpDrop;
    }





