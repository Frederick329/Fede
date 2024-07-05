#include <iostream>
#include "juegos.h"
#include "funciones.h"
#include "menu.h"
#include "rlutil.h"

using namespace std;

void ModoUnJugador(int &PuntEst, string &nombEst)
{
    int PuntosMax = 0;
    int PuntosProv = 0;
    const int TAM = 6;
    int tirada[TAM];
    int ronda = 1;
    int puntos = 0;
    int lanzamiento = 1;
    string nombre;
    bool primerJugada=true;

    cout << "INGRESE NOMBRE DE JUGADOR: ";
    cin.ignore();

    getline(cin, nombre);
    cout << " " <<endl;

    system("cls");
    cout << "------------------------------------------------------------------------------------------------------------------------";
    cout << " " <<endl;
    cout << " " <<endl;
    cout << "                                                   COMIENZA LA RONDA #" << ronda << endl;
    cout << " " <<endl;
    cout << " " <<endl;
    cout << "------------------------------------------------------------------------------------------------------------------------";
    system("pause");
    system("cls");

    while (puntos <= 100)
    {
        PuntosMax = 0;
        primerJugada=true;
        for (int i = 0; i < 3; i++)
        {
            cout << "------------------------------------------------------------------------------------------------------------------------";
            cout << "TURNO DE " << nombre << "     |     RONDA #" << ronda << "   |   TIRADA # " << lanzamiento << "    |     PUNTAJE ACTUAL: " << puntos << endl;
            cout << "------------------------------------------------------------------------------------------------------------------------";
            generarTirada(tirada, TAM);
            DibujaDados(tirada, 3, 5);
            cout << "" <<endl;
            cout << "" <<endl;
            cout << "" <<endl;
            ordenarVector(tirada, TAM);
            Escalera (tirada, TAM);
            Sexteto(tirada, TAM);
            SextetodeX(tirada, TAM);
            if (Escalera(tirada, TAM) == true)
            {
                system("cls");
                cout << "------------------------------------------------------------------------------------------------------------------------";
                cout << "" <<endl;
                cout << "                                                    ESCALERA GANASTE!" << endl;
                cout << "" <<endl;
                cout << "------------------------------------------------------------------------------------------------------------------------";
                system("pause");
                menu();
            }
            if (Sexteto(tirada, TAM) == true)
            {
                puntos = 0;
                PuntosProv = 0;
                cout << "SEXTETO DE SEIS! SE REINICIA EL PUNTAJE!"<<endl;
                cout << "LA TIRADA SUMA: " << PuntosProv << " PUNTOS" <<endl;
                cout << "MAXIMO PUNTAJE DE LA RONDA: " << PuntosMax << endl;
                cout << "PUNTAJE DE ESTA TIRADA: " << PuntosProv << endl;
                cout << "------------------------------------------------------------------------------------------------------------------------"<<endl;
                system("pause");
            }
            if (SextetodeX(tirada, TAM) == true)
            {
                PuntosProv = tirada[0] * 10;
                cout << "SEXTETO DE " << tirada[0] << " =D!!!" <<endl;
                cout << "LA TIRADA SUMA: " << PuntosProv << " PUNTOS" <<endl;
                cout << "MAXIMO PUNTAJE DE LA RONDA: " << PuntosMax << endl;
                cout << "PUNTAJE DE ESTA TIRADA: " << PuntosProv << endl;
                cout << "------------------------------------------------------------------------------------------------------------------------"<<endl;
                system("pause");
            }
            if (SextetodeX(tirada, TAM) == false && Sexteto(tirada, TAM) == false)
            {
                PuntosProv = SumaDeDados (tirada, TAM);
                cout << "SUMA DE DADOS!" <<endl;
                cout << "LA TIRADA SUMA: " << PuntosProv << " PUNTOS" <<endl;
                cout << "MAXIMO PUNTAJE DE LA RONDA: " << PuntosMax << endl;
                cout << "PUNTAJE DE ESTA TIRADA: " << PuntosProv << endl;
                cout << "------------------------------------------------------------------------------------------------------------------------"<<endl;
            }
            if (primerJugada == true)
            {
                PuntosMax = PuntosProv;
                primerJugada = false;
            }
            else if (PuntosMax < PuntosProv)
            {
                PuntosMax = PuntosProv;
            }
            if (puntos >= 100)
            {
                break;
            }
            lanzamiento++;
            system("pause");
            system("cls");
        }
        puntos += PuntosMax;
        lanzamiento = 1;
        system("cls");
        if (puntos < 100)
        {
            cout << "------------------------------------------------------------------------------------------------------------------------";
            cout << " " <<endl;
            cout << " " <<endl;
            cout << "                                           LA PUNTUACION DE LA RONDA # " << ronda << " es: " << puntos<< endl;
            cout << " " <<endl;
            cout << " " <<endl;
            cout << "------------------------------------------------------------------------------------------------------------------------";
            ronda++;
            system("pause");
            system("cls");
            cout << "------------------------------------------------------------------------------------------------------------------------";
            cout << " " <<endl;
            cout << " " <<endl;
            cout << "                                                   COMIENZA LA RONDA #" << ronda << endl;
            cout << " " <<endl;
            cout << " " <<endl;
            cout << "------------------------------------------------------------------------------------------------------------------------";
            system("pause");
            system("cls");

        }
        if (puntos > PuntEst)
        {
            PuntEst = puntos;
            nombEst = nombre;
        }

    }
    cout << "------------------------------------------------------------------------------------------------------------------------";
    cout << " " <<endl;
    cout << " " <<endl;
    cout << "                           FELICIDADES " << nombre <<  " GANASTE!!! =)" <<endl;
    cout << "                           SU PUNTUACION ES: " << puntos <<endl;
    cout << " " <<endl;
    cout << " " <<endl;
    cout << "------------------------------------------------------------------------------------------------------------------------";
    system("pause");
}

void ModoDosJugadores(int &PuntEst, string &nombEst)
{

    int PuntosMax1 = 0;
    int PuntosProv1 = 0;
    int puntos1 = 0;
    int PuntosMax2 = 0;
    int PuntosProv2 = 0;
    int puntos2 = 0;
    const int TAM = 6;
    int tirada[TAM];
    int ronda = 1;
    int lanzamiento = 1;
    string nombre1;
    string nombre2;
    bool primerJugada=true;

    cout << "INGRESE NOMBRE DE JUGADOR #1 : ";
    cin.ignore();
    getline(cin, nombre1);
    cout << " " <<endl;
    cout << "INGRESE NOMBRE DE JUGADOR #2 : ";
    getline(cin, nombre2);
    cout << "" <<endl;
    system("pause");
    system("cls");

    cout << "------------------------------------------------------------------------------------------------------------------------";
    cout << " " <<endl;
    cout << " " <<endl;
    cout << "      COMIENZA LA RONDA #" << ronda << ", " << nombre1 << " COMIENZA CON EL JUEGO!" << endl;
    cout << " " <<endl;
    cout << " " <<endl;
    cout << "------------------------------------------------------------------------------------------------------------------------";
    system("pause");
    system("cls");
    while ( puntos1 < 100 || puntos2 < 100)
    {
        primerJugada=true;
        for (int i = 0; i < 3; i++)
        {
            cout << "------------------------------------------------------------------------------------------------------------------------";
            cout << "TURNO DE " << nombre1 << "     |     RONDA #" << ronda << "   |   TIRADA # " << lanzamiento << "    |     PUNTAJE ACTUAL: " << puntos1 << endl;
            cout << "------------------------------------------------------------------------------------------------------------------------";
            generarTirada(tirada, TAM);
            DibujaDados(tirada, 3, 5);
            cout << "" <<endl;
            cout << "" <<endl;
            cout << "" <<endl;
            ordenarVector(tirada, TAM);
            Escalera (tirada, TAM);
            Sexteto(tirada, TAM);
            SextetodeX(tirada, TAM);
            if (Escalera(tirada, TAM) == true)
            {
                system("cls");
                cout << "------------------------------------------------------------------------------------------------------------------------";
                cout << "" <<endl;
                cout << "                                                    ESCALERA GANASTE!" << endl;
                cout << "" <<endl;
                cout << "------------------------------------------------------------------------------------------------------------------------";
                system("pause");
                menu();
            }
            if (Sexteto(tirada, TAM) == true)
            {
                puntos1 = 0;
                PuntosProv1 = 0;
                cout << "SEXTETO DE SEIS! SE REINICIA EL PUNTAJE!"<<endl;
                cout << "LA TIRADA SUMA: " << PuntosProv1 << " PUNTOS" <<endl;
                cout << "MAXIMO PUNTAJE DE LA RONDA: " << PuntosMax1 << endl;
                cout << "PUNTAJE DE ESTA TIRADA: " << PuntosProv1 << endl;
                cout << "------------------------------------------------------------------------------------------------------------------------"<<endl;
                system("pause");
            }
            if (SextetodeX(tirada, TAM) == true)
            {
                PuntosProv1 = tirada[0] * 10;
                cout << "SEXTETO DE " << tirada[0] << " =D!!!" <<endl;
                cout << "LA TIRADA SUMA: " << PuntosProv1 << " PUNTOS" <<endl;
                cout << "MAXIMO PUNTAJE DE LA RONDA: " << PuntosMax1 << endl;
                cout << "PUNTAJE DE ESTA TIRADA: " << PuntosProv1 << endl;
                cout << "------------------------------------------------------------------------------------------------------------------------"<<endl;
                system("pause");
            }
            if (SextetodeX(tirada, TAM) == false && Sexteto(tirada, TAM) == false)
            {
                PuntosProv1 = SumaDeDados (tirada, TAM);
                cout << "SUMA DE DADOS!" <<endl;
                cout << "LA TIRADA SUMA: " << PuntosProv1 << " PUNTOS" <<endl;
                cout << "MAXIMO PUNTAJE DE LA RONDA: " << PuntosMax1 << endl;
                cout << "PUNTAJE DE ESTA TIRADA: " << PuntosProv1 << endl;
                cout << "------------------------------------------------------------------------------------------------------------------------"<<endl;
            }
            if (primerJugada == true)
            {
                PuntosMax1 = PuntosProv1;
                primerJugada = false;
            }
            else if (PuntosMax1 < PuntosProv1)
            {
                PuntosMax1 = PuntosProv1;
            }
            if (puntos1 >= 100)
            {
                break;
            }
            lanzamiento++;
            system("pause");
            system("cls");
        }
        puntos1 += PuntosMax1;

        lanzamiento = 1;
        system("cls");
        if (puntos1 < 100)
        {
            cout << "------------------------------------------------------------------------------------------------------------------------";
            cout << " " <<endl;
            cout << "                                                   RONDA # " << ronda <<endl;
            cout << "                                              PROXIMO TURNO: " << nombre2 <<endl;
            cout << " " <<endl;
            cout << " " <<endl;
            cout << "                                             PUNTAJE " << nombre1 << ": " << puntos1 << " PUNTOS" <<endl;
            cout << "                                             PUNTAJE " << nombre2 << ": " << puntos2 << " PUNTOS" <<endl;
            cout << "------------------------------------------------------------------------------------------------------------------------";
            system("pause");
            system("cls");
        }
        primerJugada=true;
        for (int i = 0; i < 3; i++)
        {
            cout << "------------------------------------------------------------------------------------------------------------------------";
            cout << "TURNO DE " << nombre2 << "     |     RONDA #" << ronda << "   |   TIRADA # " << lanzamiento << "    |     PUNTAJE ACTUAL: " << puntos2 << endl;
            cout << "------------------------------------------------------------------------------------------------------------------------";
            generarTirada(tirada, TAM);
            DibujaDados(tirada, 3, 5);
            cout << "" <<endl;
            cout << "" <<endl;
            cout << "" <<endl;
            ordenarVector(tirada, TAM);
            Escalera (tirada, TAM);
            Sexteto(tirada, TAM);
            SextetodeX(tirada, TAM);
            if (Escalera(tirada, TAM) == true)
            {
                system("cls");
                cout << "------------------------------------------------------------------------------------------------------------------------";
                cout << "" <<endl;
                cout << "                                                    ESCALERA GANASTE!" << endl;
                cout << "" <<endl;
                cout << "------------------------------------------------------------------------------------------------------------------------";
                system("pause");
                menu();
            }
            if (Sexteto(tirada, TAM) == true)
            {
                puntos2 = 0;
                PuntosProv2 = 0;
                cout << "SEXTETO DE SEIS! SE REINICIA EL PUNTAJE!"<<endl;
                cout << "LA TIRADA SUMA: " << PuntosProv2 << " PUNTOS" <<endl;
                cout << "MAXIMO PUNTAJE DE LA RONDA: " << PuntosMax2 << endl;
                cout << "PUNTAJE DE ESTA TIRADA: " << PuntosProv2 << endl;
                cout << "------------------------------------------------------------------------------------------------------------------------"<<endl;
                system("pause");
            }
            if (SextetodeX(tirada, TAM) == true)
            {
                PuntosProv2 = tirada[0] * 10;
                cout << "SEXTETO DE " << tirada[0] << " =D!!!" <<endl;
                cout << "LA TIRADA SUMA: " << PuntosProv2 << " PUNTOS" <<endl;
                cout << "MAXIMO PUNTAJE DE LA RONDA: " << PuntosMax2 << endl;
                cout << "PUNTAJE DE ESTA TIRADA: " << PuntosProv2 << endl;
                cout << "------------------------------------------------------------------------------------------------------------------------"<<endl;
                system("pause");
            }
            if (SextetodeX(tirada, TAM) == false && Sexteto(tirada, TAM) == false)
            {
                PuntosProv2 = SumaDeDados (tirada, TAM);
                cout << "SUMA DE DADOS!" <<endl;
                cout << "LA TIRADA SUMA: " << PuntosProv2 << " PUNTOS" <<endl;
                cout << "MAXIMO PUNTAJE DE LA RONDA: " << PuntosMax2 << endl;
                cout << "PUNTAJE DE ESTA TIRADA: " << PuntosProv2 << endl;
                cout << "------------------------------------------------------------------------------------------------------------------------"<<endl;
            }
            if (primerJugada == true)
            {
                PuntosMax2 = PuntosProv2;
                primerJugada = false;
            }
            else if (PuntosMax2 < PuntosProv2)
            {
                PuntosMax2 = PuntosProv2;
            }
            if (puntos2 >= 100)
            {
                break;
            }
            lanzamiento++;
            system("pause");
            system("cls");
        }
        puntos2 += PuntosMax2;

        lanzamiento = 1;
        system("cls");
        cout << "------------------------------------------------------------------------------------------------------------------------";
        cout << " " <<endl;
        cout << "                                                   RONDA # " << ronda <<endl;
        cout << "                                              PROXIMO TURNO: " << nombre1 <<endl;
        cout << " " <<endl;
        cout << " " <<endl;
        cout << "                                             PUNTAJE " << nombre1 << ": " << puntos1 << " PUNTOS" <<endl;
        cout << "                                             PUNTAJE " << nombre2 << ": " << puntos2 << " PUNTOS" <<endl;
        cout << "------------------------------------------------------------------------------------------------------------------------";
        system("pause");
        system("cls");
        ronda++;
        if (puntos2 < 100)
        {
            cout << "------------------------------------------------------------------------------------------------------------------------";
            cout << " " <<endl;
            cout << " " <<endl;
            cout << "                                             COMIENZA LA RONDA # " << ronda << endl;
            cout << " " <<endl;
            cout << " " <<endl;
            cout << "------------------------------------------------------------------------------------------------------------------------";
            system("pause");
            system("cls");
        }
    }
    if (puntos1 > puntos2)
    {
        if (puntos1 > PuntEst)
        {
            PuntEst = puntos1;
            nombEst = nombre1;
        }
        cout << "------------------------------------------------------------------------------------------------------------------------";
        cout << " " <<endl;
        cout << " " <<endl;
        cout << "                           FELICIDADES " <<  nombre1 << " GANASTE"<<endl;
        cout << "                           SU PUNTUACION ES: " << puntos1 <<endl;
        cout << " " <<endl;
        cout << " " <<endl;
        cout << "------------------------------------------------------------------------------------------------------------------------";
        system("pause");
    }
    else
    {
        if (puntos2 > PuntEst)
        {
            PuntEst = puntos2;
            nombEst = nombre2;
        }
        cout << "------------------------------------------------------------------------------------------------------------------------";
        cout << " " <<endl;
        cout << " " <<endl;
        cout << "                           FELICIDADES " <<  nombre2 << " GANASTE"<<endl;
        cout << "                           SU PUNTUACION ES: " << puntos2 <<endl;
        cout << " " <<endl;
        cout << " " <<endl;
        cout << "------------------------------------------------------------------------------------------------------------------------";
        system("pause");
    }
}
