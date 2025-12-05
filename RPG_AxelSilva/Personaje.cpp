#include "Personaje.h"
#include <iostream>

using namespace std;

    Personaje::Personaje(string nom, int atk, int def, int psMax){
        nombre = nom; 
        vidaMaxima = psMax;
        vidaActual = vidaMaxima;
        ataque = atk;
        defensa = def;
    }
    Personaje:: ~Personaje(){}

    void Personaje::setNombre(string nom){ //setter de Nombre
        nombre = nom;
    }
    string Personaje::getNombre(){ //getter de nombre
        return nombre;
    }

    void Personaje::setVidaActual(int psRestante){ //setter de vida
        vidaActual = psRestante; 
    }
    int Personaje::getVidaActual(){ //getter de vide
        return vidaActual;
    }

    //setter de vida Maxima
    void Personaje::setVidaMaxima(int psMax){ //Vida cambia conforme subes de nivel o te golpean
        vidaMaxima = psMax; 
    }
    int Personaje::getVidaMaxima(){ //getter de vida Maxima
        return vidaMaxima;
    }

    void Personaje::setAtaque(int atk){ //setter de Ataque
        ataque = atk; 
    }
    int Personaje::getAtaque(){ //getter de Ataque
        return ataque;
    }

    void Personaje::setDefensa(int def){ //setter de Defensa
        defensa = def; 
    }
   int Personaje::getDefensa(){ //getter de Defensa
        return defensa;
    }

    void Personaje::recibirDano(int cantidad){ //Solo aplicable para los enemigos, debido a que se hizo override para la clase Heroe
        int danoReal = cantidad-defensa; //Cantida hace referencia al ataque, al restarle la defensa te da el daño Real
        if(danoReal<=0){ // Si el ataque llega a ser tan bajo que al restar la defensa da numero negativo, este se igualara a 0
            danoReal = 0;
        }
        vidaActual = vidaActual-danoReal; //La vida actual del enemigo es restada por el daño real ya calculado
        if(vidaActual <= 0){ // Si el dano real llegara a ser mayor que la vida restante entonces la vida actual seria negativa, de ser asi se iguala la vida a 0
            vidaActual = 0;
        }
    }

    void Personaje::atacar(Personaje &objetivo){ //Este metodo se encarga de que el daño hecho se transifiera a un objetivo referenciado, en este caso uno de los 3 enemigos
        objetivo.recibirDano(ataque); 
        cout << "El " <<nombre << " ha atacado a " << objetivo.getNombre() << endl;
    }
    
    bool Personaje::estaVivo(){
        return vidaActual > 0; 
        //Si la vidaActual es mayor a 0, devuelve 1, significa que sigue vivo
        //Si devuelve 0, ya no esta vivo
    }




