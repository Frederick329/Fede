#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

using namespace std;

void menu();
void ElejirJugadores(int &PuntEst, std::string &nombEst);
void Creditos();
void Reglas();
void PuntajesMaximos(int, std::string);
void ModoSimuldado();

#endif // MENU_H_INCLUDED

/*
 if (PuntosAct > PuntEst)
        {
            PuntEst = PuntosAct;
            nombEst = nombre;

        }
        int PuntEst=0;
        string nombEst;

        escribirTirada(tirada, TAM);

*/
