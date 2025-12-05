#ifndef OBJETO_H
#define OBJETO_H

#include <iostream>

using namespace std;
class Heroe; //Llamada con anterioridad debido a que los objetos depende de la existencia del heroe
class Objeto // Clase Base
{
protected:
    string nombre;
    int cantidad;
    string descripcion;
    
public:
    Objeto(string nom, int cantidadObjetos, string des);
    virtual ~Objeto();
    virtual void usar(Heroe& h) = 0; //Crea un metodo virtua puro (abstracto), este no lo ocupa para las clases hijas estan obligadas a hacerlo
};// Se uso para generalizar su funcion ya que no tiene una funcionalidad concreta hasta que este con una de las clases hija

#endif