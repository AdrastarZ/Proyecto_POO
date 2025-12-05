#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "Personaje.h"
#include <iostream>

using namespace std;

class Zombie : public Personaje //Clase heredada de Clase Personaje
{
private:
   int xpDrop;
public:
    Zombie();
    
    virtual ~Zombie();

    int getXP();
};

#endif


