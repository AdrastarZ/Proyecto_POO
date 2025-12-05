#include <iostream>
#include "Combate.h"
#include "Heroe.h"
#include "Zombie.h"
#include "Golem.h"
#include "Dragon.h"
#include <cstdlib>
#include <ctime>

using namespace std;


void iniciarCombate(Heroe& heroe, Personaje& enemigo)
{
    cout << "\n¡COMBATE CONTRA " << enemigo.getNombre() << "!\n\n";

    while (heroe.estaVivo() && enemigo.estaVivo()) //Verifica que ambos esten vivos
    {
        // --- Turno del héroe ---
        cout << endl << "--- Tu turno ---" << endl;
        cout << "1. Atacar" << endl;
        cout << "2. Usar objeto"<< endl;
        cout << "3. Ver estado"<< endl;
        cout << "4. Rendirse"<< endl;
        cout << "Elige: ";

        int opcion;
        cin >> opcion;
        cout << endl;
        if (opcion == 1)
        {
            heroe.atacar(enemigo); //Utilizando el metodo atacar heredado el heroe ataca al enemigo
        }
        else if (opcion == 2)
        {
            heroe.abrirInventario();//El heroe utiliza el metod abrir inventario
        }
        else if (opcion == 3) //Utilizando getters, se leen las estadisticas del enemigo y Heroe
        {
            cout << "\n--- ESTADO ---\n";
            cout << heroe.getNombre() << " → " << heroe.getVidaActual()
                 << "/" << heroe.getVidaMaxima()
                 << "  ATK: " << heroe.getAtaqueTotal()
                 << "  DEF: " << heroe.getDefensaTotal() << endl;

            cout << enemigo.getNombre() << " -> " << enemigo.getVidaActual()
                 << "/" << enemigo.getVidaMaxima() << endl << endl;

            continue; // NO consume turno, vuelve al menú del héroe
        }
        else if (opcion == 4)
        {
            cout << "Huiste del combate..." << endl;
            return;
        }
        else
        {
            cout << "Opción inválida." << endl;
            continue;
        }

        // Si el enemigo muere, termina el combate
        if (!enemigo.estaVivo())
            break;

        // --- Turno del enemigo ---
        cout << endl << "--- Turno del enemigo ---" << endl;
        enemigo.atacar(heroe); //Utilizando el metodo atacar heredado el enemigo ataca al heroe

        if (!heroe.estaVivo())
            break;
    }

    // --- Resultado del combate --- // Dependiendo de si el heroe esta vivo o no se muesta un mensaje de derrota o victoria
    if (heroe.estaVivo()) 
    {
        cout << endl << "¡HAS GANADO EL COMBATE!" << endl;
       
        heroe.ganarExperiencia(enemigo.getXP());
    }
    else
    {
        cout << "\nHas sido derrotado..." << endl;
    }

    heroe.resetBonos(); //Reinicia los valores bonus del heroe
}

int main() {
    // Crear al héroe
    srand(time(NULL));// Inicia semilla para valores aleatorios 
    Heroe heroe("Axel", 20, 10, 100); //Nombre, ataque, defensa, Vida

    // Crea enemigos con identificadores
    Zombie z;
    Golem g;
    Dragon d;

    int opcion = 0;

    while (opcion != 4) {
        cout << "\n=== SELECCIONA CONTRINCANTE ===\n";
        cout << "1. Zombie\n";
        cout << "2. Golem\n";
        cout << "3. Dragon\n";
        cout << "4. Salir\n";
        cout << "Opción: ";
        cin >> opcion;

        if (opcion == 1) {
            cout << "\n Peleas contra un Zombie!\n";
            iniciarCombate(heroe, z);
        }
        else if (opcion == 2) {
            cout << "\n Peleas contra un Golem!\n";
            iniciarCombate(heroe, g);
        }
        else if (opcion == 3) {
            cout << "\n Peleas contra un Dragon!\n";
            iniciarCombate(heroe, d);
        }
        else if (opcion != 4) {
            cout << "Opción inválida.\n";
        }

        // Restaurar vida del héroe tras cada combate
        heroe.setVidaActual(heroe.getVidaMaxima());
        heroe.resetBonos();
    }

    cout << endl << "Saliendo del juego..." << endl;
    return 0;
}

