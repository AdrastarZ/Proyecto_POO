#ifndef POCIONDEFENSA_H
#define POCIONDEFENSA_H

#include "Objeto.h"
#include <iostream>

using namespace std;

class PocionDefensa : public Objeto //Clase heredada de la clase Objeto
{
protected:
    int boostDefMin;
    int boostDefMax;

public:
    PocionDefensa();
    virtual ~PocionDefensa();

    virtual void usar(Heroe& h); // Referencia a la clase Heroe por que es con quien va a ser usada 
};

#endif