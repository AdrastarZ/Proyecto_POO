#include "PocionVida.h"
#include "Objeto.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Heroe.h"

using namespace std;
    
    PocionVida::PocionVida():Objeto("Pocion de Curación", 1, "Poción que recupera entre 10 a 40 puntos de salud"){
        curacionMax = 40; // Rango maximo de curacion
        curacionMin = 10; // Rango minimo de curacion
    }
    PocionVida::~PocionVida(){}

    void PocionVida::usar(Heroe& h){
        
        int curaReal = (rand()%(curacionMax-curacionMin+1)) + curacionMin; // Genera un valor aleatorio entre 10 a 40
        int vidaActual = h.getVidaActual(); //Utiliza el metodo getVidaActual de la clase heroe para obtener la vida acutal
        int vidaMax = h.getVidaMaxima(); //Utiliza el metodo getVidaMax de la clase heroe para obtener la vida Maxima
        int vidaFinal = vidaActual + curaReal; //Utilizando la vida actual le suma el valor aleatorio a esta para que sea el nuevo valor de vida actual
        int curacionEfectiva = vidaFinal - vidaActual; //Utilizando la vida actual anterior esta se le resta de la vida actual nueva para saber cuanta vida se le añadio
        if(vidaFinal > vidaMax) //Si la vida actual nueva llegase a exceder el limite de vida de vidaMax, esta seria igual a ese mismo valor
            vidaFinal = vidaMax;
        
        h.setVidaActual(vidaFinal); //El heroe referenciado utiliza el metodo setVidaActual para actualizar su vida a la vida actual nueva
        cout << "Te regeneraste " << curacionEfectiva << " PS" << endl;
    }

