#include <iostream>
#include<cstdlib>
#include "funciones.h"

using namespace std;

void ModoUnJugador(){
    const int TAM = 6;
    int tirada[TAM];
    int ronda = 1;
    int PuntosAct = 0;
    string nombre;
    cout << "Ingrese su nombre de jugador: ";
    cin.ignore();
    getline(cin, nombre);
    cout << " " <<endl;
    cout << "------------------------------------------------------------------------------------------------------------------------";
    cout << "                                               COMIENZA LA RONDA #" << ronda <<endl;
    cout << "------------------------------------------------------------------------------------------------------------------------";

    while (PuntosAct <= 100){
    for (int i = 0; i < 3; i++){
    cout << "TURNO DE " << nombre << "     |    RONDA #" << ronda << "    |     PUNTAJE TOTAL: " << PuntosAct << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------";
    generarTirada(tirada, TAM);
    mostrarTirada(tirada, TAM);
    int puntos = SumaDeDados (tirada, TAM);
    PuntosAct = PuntosAct += puntos;
    cout << "LA TIRDADA SUMA: " << puntos << " PUNTOS" <<endl;
    PressEnter();
    if (PuntosAct > 100){
        i = 4;
    }
    }

    if (PuntosAct < 100){
    cout << " " <<endl;
    cout << " " <<endl;
    cout << "                                           LA PUNTUACION DE LA RONDA # " << ronda << " es: " << PuntosAct<< endl;
    cout << " " <<endl;
    cout << " " <<endl;
    cout << "------------------------------------------------------------------------------------------------------------------------";
    ronda++;
    }
    }

    cout << "                           FELICIDADES HA GANADO!!! =)" <<endl;
    cout << "                           SU PUNTUACION ES: " << PuntosAct <<endl;

}

void ModoDosJugadores(){
}