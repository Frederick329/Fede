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
            cout << "TURNO DE " << nombre << "     |     TIRADA # " << lanzamiento << "    |     PUNTAJE ACTUAL: " << puntos << endl;
            cout << "------------------------------------------------------------------------------------------------------------------------";

            generarTirada(tirada, TAM);
            mostrarTirada(tirada, TAM);
            ordenarVector(tirada, TAM);
            Escalera (tirada, TAM);
            Sexteto(tirada, TAM);
            SextetodeX(tirada, TAM);
            if (Escalera(tirada, TAM) == true)
            {

                {
                    DibujaDados(tirada, 3, 18);
                    rlutil::anykey();
                    system("cls");
                }
                puntos = 100;
                rlutil::anykey();
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
                {
                    DibujaDados(tirada, 3, 18);

                    rlutil::anykey();
                    system("cls");

                }
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
                {
                    DibujaDados(tirada, 3, 18);

                    rlutil::anykey();
                    system("cls");

                }
                system("pause");
            }
            if (SextetodeX(tirada, TAM) == false && Sexteto(tirada, TAM) == false)
            {
                PuntosProv = SumaDeDados (tirada, TAM);

                cout << "LA TIRADA SUMA: " << PuntosProv << " PUNTOS" <<endl;

                cout << "MAXIMO PUNTAJE DE LA RONDA: " << PuntosMax << endl;
                cout << "PUNTAJE DE ESTA TIRADA: " << PuntosProv << endl;
                cout << "------------------------------------------------------------------------------------------------------------------------"<<endl;
                {
                    DibujaDados(tirada, 3, 18);

                    rlutil::anykey();
                    system("cls");

                }
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
            if (puntos > 100)
            {
                /*rlutil::anykey();*/
            }
            lanzamiento++;

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
        PuntosMax1 = 0;
        primerJugada=true;
        for (int i = 0; i < 3; i++)
        {
            cout << "------------------------------------------------------------------------------------------------------------------------";
            cout << "TURNO DE " << nombre1 << "     |    LANZAMIENTO # " << lanzamiento << "    |     PUNTAJE ACTUAL: " << puntos1 << endl;
            cout << "------------------------------------------------------------------------------------------------------------------------";
            generarTirada(tirada, TAM);
            mostrarTirada(tirada, TAM);
            ordenarVector(tirada, TAM);
            Escalera (tirada, TAM);
            SumaDeDados (tirada,TAM);
            Sexteto(tirada, TAM);
            SextetodeX(tirada, TAM);
            if (Escalera(tirada, TAM) == true)
            {
                {
                    DibujaDados(tirada, 3, 18);
                    rlutil::anykey();
                    system("cls");
                }
                puntos1 = 100;
                system("pause");
                system("cls");
                cout << "------------------------------------------------------------------------------------------------------------------------";
                cout << "" <<endl;
                cout << "                                                    ESCALERA GANASTE!" << endl;
                cout << "                                                       FELICIDAES " << nombre1 <<endl;
                cout << "" <<endl;
                cout << "------------------------------------------------------------------------------------------------------------------------";
                system("pause");
                menu();
            }
            if (SextetodeX(tirada, TAM) == true)
            {
                PuntosProv1 = tirada[0] * 10;
                cout << "LA TIRADA SUMA: " << PuntosProv1 << " PUNTOS" <<endl;
                cout << "MAXIMO PUNTAJE DE LA RONDA: " << PuntosMax1 << endl;
                cout << "PUNTAJE DE ESTA TIRADA: " << PuntosProv1 << endl;
                cout << "------------------------------------------------------------------------------------------------------------------------"<<endl;
                {
                    DibujaDados(tirada, 3, 18);
                    rlutil::anykey();
                    system("cls");
                }

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
                {
                    DibujaDados(tirada, 3, 18);
                    rlutil::anykey();
                    system("cls");
                }
            }
            if (SextetodeX(tirada, TAM) == false && Sexteto(tirada, TAM) == false)
            {
                PuntosProv1 = SumaDeDados (tirada, TAM);
                cout << "LA TIRADA SUMA: " << PuntosProv1 << " PUNTOS" <<endl;
                cout << "MAXIMO PUNTAJE DE LA RONDA: " << PuntosMax1 << endl;
                cout << "PUNTAJE DE ESTA TIRADA: " << PuntosProv1 << endl;
                cout << "------------------------------------------------------------------------------------------------------------------------"<<endl;
                {
                    DibujaDados(tirada, 3, 18);
                    rlutil::anykey();
                    system("cls");
                }
            }
            if (primerJugada == true)
            {
                PuntosMax1 = PuntosProv1;
                primerJugada = false;
            }
            else if (PuntosMax1 < PuntosProv2)
            {
                PuntosMax1 = PuntosProv1;
            }

            if (puntos1 > 100 )
            {
                system("cls");
                cout << " PUNTAJE DE " << nombre1 << "es: " << puntos1 << "EN LA TIRADA # " << lanzamiento << endl;
                system("pause");
                break;
            }
            lanzamiento++;
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
        PuntosMax2 = 0;
        primerJugada=true;
        for (int i = 0; i < 3; i++)
        {


            cout << "------------------------------------------------------------------------------------------------------------------------";
            cout << "TURNO DE " << nombre2 << "     |    LANZAMIENTO # " << lanzamiento << "    |     PUNTAJE ACTUAL: " << puntos2 << endl;
            cout << "------------------------------------------------------------------------------------------------------------------------";
            generarTirada(tirada, TAM);
            mostrarTirada(tirada, TAM);
            ordenarVector(tirada, TAM);
            Escalera (tirada, TAM);
            SumaDeDados (tirada,TAM);
            Sexteto(tirada, TAM);
            SextetodeX(tirada, TAM);
            if (Escalera(tirada, TAM) == true)
            {
                puntos2 = 100;
                system("cls");
                cout << "------------------------------------------------------------------------------------------------------------------------";
                cout << "" <<endl;
                cout << "                                                    ESCALERA GANASTE!" << endl;
                cout << "                                                       FELICIDAES" << nombre2 <<endl;
                cout << "" <<endl;
                cout << "------------------------------------------------------------------------------------------------------------------------";
                system("pause");
                menu();
            }
            if (SextetodeX(tirada, TAM) == true)
            {
                PuntosProv2 = tirada[0] * 10;
                cout << "SEXTETO DE " << tirada[0] << " =D!!!" <<endl;
                cout << "LA TIRADA SUMA: " << PuntosProv2 << " PUNTOS" <<endl;
                cout << "MAXIMO PUNTAJE DE LA RONDA: " << PuntosMax2 << endl;
                cout << "PUNTAJE DE ESTA TIRADA: " << PuntosProv2 << endl;
                cout << "------------------------------------------------------------------------------------------------------------------------"<<endl;
                {
                    DibujaDados(tirada, 3, 18);
                    rlutil::anykey();
                    system("cls");
                }
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
                {
                    DibujaDados(tirada, 3, 18);
                    rlutil::anykey();
                    system("cls");
                }
            }
            if (SextetodeX(tirada, TAM) == false && Sexteto(tirada, TAM) == false)
            {
                PuntosProv2 = SumaDeDados (tirada, TAM);
                cout << "LA TIRADA SUMA: " << PuntosProv2 << " PUNTOS" <<endl;
                  cout << "MAXIMO PUNTAJE DE LA RONDA: " << PuntosMax2 << endl;
                cout << "PUNTAJE DE ESTA TIRADA: " << PuntosProv2 << endl;
                cout << "------------------------------------------------------------------------------------------------------------------------"<<endl;
                {
                    DibujaDados(tirada, 3, 18);
                    rlutil::anykey();
                    system("cls");
                }
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
            if (puntos2 > 100 )
            {

                system("cls");
                cout << " PUNTAJE DE " << nombre2 << "es: " << puntos2 << "EN EL LANZAMIENTO # " << lanzamiento << endl;
                system("pause");
                break;
            }
            lanzamiento++;
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
