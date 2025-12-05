#include "PocionDefensa.h"
#include "Objeto.h"
#include <iostream>
#include <cstdlib>
#include "Heroe.h"
#include <ctime>

using namespace std;
    
    PocionDefensa::PocionDefensa():Objeto("Poción defensiva", 1, "Poción que otorga entre 10 a 20 puntos de defensa temporalmente"){
        boostDefMin = 10; // Rango minimo de aumento de defensa
        boostDefMax = 20; // Rango maximo de aumento de defensa
    }
    PocionDefensa::~PocionDefensa(){}

    void PocionDefensa::usar(Heroe& h){
        
        int boost = (rand()%(boostDefMax-boostDefMin+1)) + boostDefMin; // Genera un valor aleatorio entre 10 a 20
        h.agregarBonusDefensa(boost); //Utiliza el metodo agregarBonusDefensa de la clase heroe para sumarle el valor de boost
        
        cout << "Tu defensa base aumento " << boost << " puntos temporalmente" << endl;
    }

