
#include <iostream>
#include "Objeto.h"

using namespace std;

    Objeto::Objeto(string nom, int cantidadObjetos, string des){
        nombre = nom;
        cantidad = cantidadObjetos;
        descripcion = des;

    }
    Objeto::~Objeto(){}
