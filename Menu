#include <iostream>
#include "menu.h"
#include "juegos.h"
using namespace std;

void menu(){
int opcion;

    do
    {
        system("cls");
        cout << "------------------------------------------------------------------------------------------------------------------------";
        cout << "                                                CIEN O ESCALERA" << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "1 - JUGAR          " << endl;
        cout << "2 - ESTADISTICAS   " << endl;
        cout << "3 - CREDITOS       " << endl;
        cout << "0 - PARA SALIR     " << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------";
        cout << endl;
        cout << "                                                   OPCION: ";
        cin >> opcion;

        switch(opcion)
        {
        case 0:
            return;
            break;
        case 1:
            ElejirJugadores();
            break;
        case 2:

            break;
        case 3:

            break;
        }

    }
    while(true);

}

void ElejirJugadores(){
    system("cls");
    int jugador;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << " " <<endl;
    cout << "Ingrese (1) para un solo jugador                                                         Ingrese (2) para dos jugadores " << endl;
    cout << " " <<endl;
    cout << "------------------------------------------------------------------------------------------------------------------------";
    cout << "                                                   OPCION: ";
    cin >> jugador;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

    if (jugador==1){
        ModoUnJugador();
    }
}
