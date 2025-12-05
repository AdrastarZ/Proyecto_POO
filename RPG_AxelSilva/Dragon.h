#ifndef DRAGON_H
#define DRAGON_H

#include "Personaje.h"
#include <iostream>

using namespace std;

class Dragon : public Personaje // Clase heredada de clase Personaje
{
private:
   int xpDrop;
public:
    Dragon();
    
    virtual ~Dragon();

    int getXP();
};

#endif