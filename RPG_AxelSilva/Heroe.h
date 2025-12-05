#ifndef HEROE_H
#define HEROE_H

#include "Personaje.h"
#include "Inventario.h"
#include <iostream>

using namespace std;

class Heroe : public Personaje
{
private:
    int nivel;
    int experienciaActual;
    int experienciaNecesaria;
    int bonusAtaque;
    int bonusDefensa;
    Inventario inventario;

public:
    Heroe(string nom, int atk, int def, int psMax);

    virtual ~Heroe();

    void setNivel(int niv);
    int getNivel();

    void setExp(int exp);
    int getExp();

    virtual void recibirDano(int cantidad) override; //Se usa override por que se le modifica el funcionamiento del metodo a como estaba en la clase personaje

    int getAtaqueTotal();

    int getDefensaTotal();

    void ganarExperiencia(int cantidad);

    void subirNivel();

    void agregarBonusAtaque(int cantidad);

    void agregarBonusDefensa(int cantidad);

    void abrirInventario();


    virtual void atacar(Personaje &objetivo);


    void resetBonos();
};



#endif