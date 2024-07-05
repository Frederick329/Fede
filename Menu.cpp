#include <iostream>
#include "juegos.h"
#include "funciones.h"
#include "menu.h"

using namespace std;

    string nombEst;
    int PuntEst=0;

void menu()
{
    int opcion;

    do
    {
        system("cls");
        cout << "------------------------------------------------------------------------------------------------------------------------";
        cout << "                                                 BIENVENIDO A" <<endl;
        cout << "                                                CIEN O ESCALERA" << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "1 - JUGAR           " << endl;
        cout << "2 - PUNTAJES MAXIMOS" << endl;
        cout << "3 - CREDITOS        " << endl;
        cout << "4 - MODO SIMULADO   " << endl;
        cout << "5 - REGLAS DEL JUEGO" << endl;
        cout << "0 - PARA SALIR      " << endl;
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
            ElejirJugadores(PuntEst, nombEst);
            break;
        case 2:
            PuntajesMaximos(PuntEst, nombEst);
            break;
        case 3:
            Creditos();
            break;
        case 4:
            ModoSimuldado();
            break;
        case 5:
            Reglas();
            break;
        }
    }
    while(true);

}

void ElejirJugadores(int &PuntEst, string &nombEst)
{
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

    if (jugador==1)
    {
        ModoUnJugador(PuntEst, nombEst);
    }
    else{
        ModoDosJugadores(PuntEst, nombEst);
    }
}

void ModoSimuldado()
{
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

    if (jugador==1)
    {
        ModoUnJugadorSimulado(PuntEst, nombEst);
    }
    else{
        ModoDosJugadoresSimulado(PuntEst, nombEst);
    }

}

void Creditos()
{

    system("cls");
    cout << "||====================================================================================||" << endl;
    cout << "||                                                                                    ||" <<endl;
    cout << "||                      Fede                                                          ||" << endl;
    cout << "||                                                                                    ||" <<endl;
    cout << "||                      Kevin                                                         ||"<< endl;
    cout << "||                                                                                    ||" <<endl;
    cout << "||                                                                 GRACIAS POR JUGAR! ||" <<endl;
    cout << "||                                                                                    ||" <<endl;
    cout << "||====================================================================================||" << endl;

    system("pause");
}

void Reglas()
{
    system("cls");
    cout << "                                              REGLAMENTO DEL JUEGO"<<endl;
    cout << " " <<endl;
    cout << " " <<endl;
    cout << "El objetivo del juego es obtener al menos 100 puntos en la menor cantidad posible de  rondas, o sacar una escalera"<<endl;
    cout << "en un lanzamiento" << endl;
    cout << "Una ronda esta compuesta por 3 lanzamientos. Un lanzamiento consiste en tirar seis dados y evaluar sus valores para"<<endl;
    cout << "determinar el puntaje."<<endl;
    cout << "El puntaje de un lanzamiento esta determinado por una serie de reglas que figuran en la seccion Combinaciones con"<<endl;
    cout << "puntos."<<endl;
    cout << "El puntaje final de la ronda sera el valor maximo de los puntos obtenidos en los 3 lanzamientos (no la suma de los" <<endl;
    cout << "tres, sino el mas alto), con las siguientes excepciones: "<<endl;
    cout << "Si en un lanzamiento se obtiene escalera el jugador GANA EL PARTIDO en ese momento. "<<endl;
    cout << "Si en un lanzamiento se obtiene una combinacion de 6 dados con valor 6, el puntaje total de la persona se resetea a 0. "<<endl;
    cout << "Para el caso de la opcion para 2 jugadores, cada jugador debe completar una ronda (3 lanzamientos) alternativamente. "<<endl;
    cout << " " <<endl;
    cout << " " <<endl;
    cout << "                                            COMBINACIONES CON PUNTOS"<<endl;
    cout << "                      +------------------------------------------------------------------------+" <<endl;
    cout << "                      |      Combinacion        |  Nombre jugada  |      Puntaje otorgado      |" <<endl;
    cout << "                      |-------------------------|-----------------|----------------------------|" <<endl;
    cout << "                      | Menos de 6 dados con    |                 | Suma de los valores de     |" <<endl;
    cout << "                      | valores iguales         |  Suma de dados  | todos los dados            |" <<endl;
    cout << "                      | Ejemplo: 6,5,5,2,2,1    |                 | Ejemplo: 6+5+5+2+2+1=21    |" <<endl;
    cout << "                      |-------------------------|-----------------|----------------------------|" <<endl;
    cout << "                      | 6 dados iguales(menos   |  Sexteto X (X   | X*10 puntos                |" <<endl;
    cout << "                      | para el numero 6)       |  es el numero   |                            |" <<endl;
    cout << "                      |                         |  del dado)      |                            |" <<endl;
    cout << "                      |-------------------------|-----------------|----------------------------|" <<endl;
    cout << "                      | Escalera en cualquier   |  ESCALERA       | Gana la partida en esa     |" <<endl;
    cout << "                      | orden (1, 2, 3, 4, 5, 6)|                 | ronda                      |" <<endl;
    cout << "                      |-------------------------|-----------------|----------------------------|" <<endl;
    cout << "                      | Seis 6                  |  SEXTETO de 6   | Resetea el puntaje total   |" <<endl;
    cout << "                      |                         |                 | a 0                        |" <<endl;
    cout << "                      +------------------------------------------------------------------------+" <<endl;
    cout << " " <<endl;
    cout << " " <<endl;
    system("pause");
}

void PuntajesMaximos(int PuntEst, string nombEst){

    system("cls");
    cout << "el puntaje maximo es: " << PuntEst << " de el jugador: " << nombEst << endl;
    system("pause");
}
