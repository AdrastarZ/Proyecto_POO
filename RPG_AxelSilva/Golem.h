#ifndef GOLEM_H
#define GOLEM_H

#include "Personaje.h"
#include <iostream>

using namespace std;

class Golem : public Personaje // Clase heredada de clase Personaje
{
private:
   int xpDrop;
public:
    Golem();
    
    virtual ~Golem();

    int getXP();
};

#endif


