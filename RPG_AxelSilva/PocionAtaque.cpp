#include "PocionAtaque.h"
#include "Objeto.h"
#include "Heroe.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
    
    PocionAtaque::PocionAtaque():Objeto("Poción ofensiva", 1, "Poción que otorga entre 10 a 20 puntos de ataque temporalmente"){
        
        boostAtkMin = 10; // Rango minimo de aumento de ataque
        boostAtkMax = 20; // Rango maximo de aumento de ataque
    }
    PocionAtaque::~PocionAtaque(){}

    void PocionAtaque::usar(Heroe& h){
        
        int boost = (rand()%(boostAtkMax-boostAtkMin+1)) + boostAtkMin; // Genera un valor aleatorio entre 10 a 20
        h.agregarBonusAtaque(boost); //Utiliza el metodo agregarBonusAtaque de la clase heroe para sumarle el valor de boost
        
        cout << "Tu ataque base aumento " << boost << " puntos temporalmente" << endl;
    }

