
using namespace std;

#include "Inventario.h"
#include "Heroe.h"
#include <iostream>


    Inventario::Inventario(){} //Se deja el constructor vacio ya que todo lo requerido ya fue instanciado en otras clases
    Inventario::~Inventario(){} // Destructor

    int Inventario::mostrarMenu(){ //Menu de opciones que puede hacer el jugador en su turno
        int opcion = 0; 

        while (opcion <= 0 || opcion > 4)
        {
            cout << "Inventario: " << endl;
            cout << "1. Pocion de regeneración" << endl;
            cout << "2. Pocion Ofensiva" << endl;
            cout << "3. Pocion Defensiva" << endl;
            cout << "4. Volver" << endl << endl;

            cout << "Selecciona un número para continuar: ";
            cin >> opcion;

            if(opcion <= 0 || opcion > 4){
                cout << "Esa no es una opcion valida. Intente de nuevo" << endl;
            }
        }

        return opcion;
        
    }

    void Inventario::usarObjeto(int opcion, Heroe& h){ //Dependiendo de la opcion usada se usa uno de los casos con sus clases
        switch (opcion)
        {
        case 1:
            pocionVida.usar(h); //Clase llamada en .h , esta usando su metod para usar en direccion a la clase Heroe referenciada
            break;
        case 2:
            pocionAtaque.usar(h); //Clase llamada en .h , esta usando su metod para usar en direccion a la clase Heroe referenciada
            break;
        case 3:
            pocionDefensa.usar(h);//Clase llamada en .h , esta usando su metod para usar en direccion a la clase Heroe referenciada
            break;
        case 4:
            break;
        
        default:
            break;
        }
    }

