#ifndef INVENTARIO_H
#define INVENTARIO_H

using namespace std;

#include "PocionAtaque.h"
#include "PocionVida.h"
#include "PocionDefensa.h"
#include <iostream>

class Heroe; //Llamada con anterioridad de vido a los objetos depende de la existencia del heroe
class Inventario //clase Base
{
private:
    PocionVida pocionVida;
    PocionAtaque pocionAtaque;
    PocionDefensa pocionDefensa;

public:
    Inventario();
    ~Inventario();

    int mostrarMenu();

    void usarObjeto(int opcion, Heroe& h);
};

#endif