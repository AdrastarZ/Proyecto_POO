
#include "Heroe.h"
#include <iostream>

using namespace std;

    Heroe::Heroe(string nom, int atk, int def, int psMax):Personaje(nom, atk, def, psMax)
    {
        nivel = 1;
        experienciaActual = 0;
        experienciaNecesaria = nivel*100;
        bonusAtaque = 0;
        bonusDefensa = 0;

    }

    Heroe::~Heroe(){};

    void Heroe::setNivel(int niv){ //setter de nivel
        nivel = niv; 
    }
    int Heroe::getNivel(){ // getter de nivel
        return nivel;
    }

    void Heroe::setExp(int exp){ //setter de experiencia
        experienciaActual = exp;
    }
    int Heroe::getExp(){ //setter de experiencia
        return experienciaActual;
    }

    void Heroe::ganarExperiencia(int cantidad){ //Se encarga de recolectar la experiencai de los enemigos
        experienciaActual += cantidad;
        cout << "+ " << cantidad << " de Exp" << endl;

        if(experienciaActual >= experienciaNecesaria){ //Si la experiencia que se tiene actualmente sobrepasa la necesaria, se convoca a la funcion subir de nivel 
            subirNivel();
        
            cout << "Subiste a nivel: "<< nivel << " !!!"<< endl;
        }
    }

    void Heroe::subirNivel(){ //Sube el nivel, utiliza los getter y setters de la clase personaje para aumentar en 5 las estadisticas base del heroe
        nivel++;
        setVidaMaxima(getVidaMaxima() + 5);
        setAtaque(getAtaque() + 5);
        setDefensa(getDefensa() + 5);
        experienciaActual = 0;
        experienciaNecesaria = nivel*100; // Al subir de nivel, se aumenta el requerimiento de exp necesaria
    }

    void Heroe::agregarBonusAtaque(int cantidad){ //Dependiendo de la pocion se le aumentara una cantidad al bonusAtaque
        bonusAtaque += cantidad;
    }

    int Heroe::getAtaqueTotal(){ //Esto ayuda a sumar el bonus de ataque con el ataque base 
        int atk = getAtaque();
        return atk+bonusAtaque;
    }

    void Heroe::agregarBonusDefensa(int cantidad){//Dependiendo de la pocion se le aumentara una cantidad al bonusDefensa
        bonusDefensa += cantidad; 
    }

    int Heroe::getDefensaTotal(){ //Esto ayuda a sumar el bonus de defensa con la defensa base 
        int def = getDefensa();
        return def+bonusDefensa;
    }
    void Heroe::recibirDano(int cantidad){ //Utilizando getDefensaTotal, ayuda asumir como si se le hubiera añadido un bonusDefensa aunque este sea 0
        int defensaReal = getDefensaTotal();
        int danoReal = cantidad - defensaReal; //Cantida hace referencia al ataque, al restarle la defensaReal te da el daño Real 
        if(danoReal<=0){ // Si el ataque llega a ser tan bajo que al restar la defensa da numero negativo, este se igualara a 0
            danoReal = 0;
        }
        int vida = getVidaActual()-danoReal; //La vida actual del enemigo es restada por el daño real ya calculado
        if(vida <= 0){ // Si el dano real llegara a ser mayor que la vida restante entonces la vida actual seria negativa, de ser asi se iguala la vida a 0
            vida = 0;
        }
        setVidaActual(vida); //la vida es actualizada 
        cout << "Recibiste " << danoReal << " de daño!!!" << endl;  
    }

    void Heroe::atacar(Personaje &objetivo) {   
        objetivo.recibirDano(getAtaqueTotal()); //Utilizando getAtaqueTotal, ayuda asumir como si se le hubiera añadido un bonusAtaque aunque este sea 0
        cout <<getNombre() << " ha atacado a " << objetivo.getNombre() << endl;
        cout << "¡Le hiciste " << getAtaqueTotal() << " puntos de daño!" << endl;
    } 
    
    void Heroe::abrirInventario(){
        int opcion = inventario.mostrarMenu(); //Llama a la clase invetario y utiliza su metod mostrarMenu
        inventario.usarObjeto(opcion, *this);  //Llama a la clase invetario y utiliza su metodo usarObjeto, y señala al mismo parametro de la clase
    }

    void Heroe::resetBonos(){ //Devuelve los valores de bonus de Ataque y Defensa a 0, ya que estos boosts son temporales
        bonusAtaque = 0;
        bonusDefensa = 0;
    }