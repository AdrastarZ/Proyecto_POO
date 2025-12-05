#ifndef POCIONVIDA_H
#define POCIONVIDA_H

#include "Objeto.h"
#include <iostream>


using namespace std;

class PocionVida : public Objeto //Clase heredada de la clase Objeto
{
protected:
    int cantidad;
    int curacionMin;
    int curacionMax;

public:
    PocionVida();
    virtual ~PocionVida();

    virtual void usar(Heroe& h); // Referencia a la clase Heroe por que es con quien va a ser usada 
};

#endif