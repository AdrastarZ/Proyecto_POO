#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <iostream>

using namespace std;

class Personaje //Clase Base
{
private:
    string nombre;
    int vidaMaxima;
    int vidaActual;
    int ataque;
    int defensa;
    
public:
    Personaje(string nom, int atk, int def, int psMax);
    
    virtual ~Personaje();

    void setNombre(string nom);
    string getNombre();

    void setVidaActual(int psRestante); //Vida cambia conforme subes de nivel o te golpean      
    int getVidaActual();

    void setVidaMaxima(int psMax);   
    int getVidaMaxima();

    void setAtaque(int atk);
    int getAtaque();

    void setDefensa(int def);
   int getDefensa();

    void atacar(Personaje &objetivo);
    virtual void recibirDano(int cantidad);
    virtual int getXP() { return 0; }
    bool estaVivo();

};

#endif


