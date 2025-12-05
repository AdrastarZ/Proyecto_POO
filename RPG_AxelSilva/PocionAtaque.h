#ifndef POCIONATAQUE_H
#define POCIONATAQUE_H

#include "Objeto.h"
#include <iostream>

using namespace std;

class PocionAtaque : public Objeto //Clase heredada de la clase Objeto
{
protected:
    int boostAtkMin;
    int boostAtkMax;

public:
    PocionAtaque();
    virtual ~PocionAtaque();
 
    virtual void usar(Heroe& h);// Referencia a la clase Heroe por que es con quien va a ser usada
};

#endif