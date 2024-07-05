#include <iostream>
#include "funciones.h"
#include "rlutil.h"

using namespace std;

int tirarDado()
{
    return rand()% 6 + 1;
}

void generarTirada(int v[], int tam)
{
    for (int i= 0; i < tam; i++)
    {
        v[i] = tirarDado();
    }
}
void escribirTirada(int v[], int tam)
{
    for (int i= 0; i < tam; i++)
    {
        cout << "Dado #" << i+1 << ": ";
        cin >> v[i];

    }
}
void mostrarTirada(int v[], int tam)
{
    for (int i= 0; i < tam; i++)
    {
        cout << "Dado #" << i+1 << ":" << v[i] << endl;
    }
    cout << "------------------------------------------------------------------------------------------------------------------------";
}

void DibujarCuadrados(int PosX, int PosY){

    int y, x;
    rlutil::setColor(rlutil::WHITE);
    for(PosX;PosX<60;PosX+=10){
    SombraDados(PosX, PosY);
      for(x=PosX; x<=PosX+6; x++){
        for(y=PosY; y<=PosY+2; y++){
            rlutil::locate(x, y);
            cout<<(char)219;
        }
    }
    }
}

void DibujaDados(int dados[], int PosX, int PosY){

    rlutil::hidecursor();
    DibujarCuadrados(PosX, PosY);
    rlutil::saveDefaultColor();
    for (int i=0;i<6;i++){
    PosX=3;
    PosX+=(i*10);
    rlutil::setColor(rlutil::BLACK);
    rlutil::setBackgroundColor(rlutil::WHITE);
        switch (dados[i])
        {
        case 1:
            rlutil::locate(PosX+3, PosY+1);
            cout<<(char)254;
            break;
        case 2:
            rlutil::locate(PosX+1, PosY);
            cout<<(char)254;
            rlutil::locate(PosX+5, PosY+2);
            cout<<(char)254;
            break;
        case 3:
            rlutil::locate(PosX+1, PosY);
            cout<<(char)254;
            rlutil::locate(PosX+5, PosY+2);
            cout<<(char)254;
            rlutil::locate(PosX+3, PosY+1);
            cout<<(char)254;
            break;
        case 4:
            rlutil::locate(PosX+1, PosY);
            cout<<(char)254;
            rlutil::locate(PosX+5, PosY+2);
            cout<<(char)254;
            rlutil::locate(PosX+5, PosY);
            cout<<(char)254;
            rlutil::locate(PosX+1, PosY+2);
            cout<<(char)254;
            break;
        case 5:
            rlutil::locate(PosX+1, PosY);
            cout<<(char)254;
            rlutil::locate(PosX+5, PosY+2);
            cout<<(char)254;
            rlutil::locate(PosX+5, PosY);
            cout<<(char)254;
            rlutil::locate(PosX+1, PosY+2);
            cout<<(char)254;
            rlutil::locate(PosX+3, PosY+1);
            cout<<(char)254;
            break;
        case 6:
            rlutil::locate(PosX+1, PosY);
            cout<<(char)254;
            rlutil::locate(PosX+5, PosY+2);
            cout<<(char)254;
            rlutil::locate(PosX+5, PosY);
            cout<<(char)254;
            rlutil::locate(PosX+1, PosY+2);
            cout<<(char)254;
            rlutil::locate(PosX+1, PosY+1);
            cout<<(char)254;
            rlutil::locate(PosX+5, PosY+1);
            cout<<(char)254;
            break;
        }
        rlutil::resetColor();

    }
}

void SombraDados(int PosX, int PosY){
        rlutil::saveDefaultColor();
        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::setColor(rlutil::GREY);
        for (int y=PosY;y<=PosY+2;y++){
            rlutil::locate(PosX+7,y);
            if(y==PosY){
                cout<<(char)220;
            }else{
                cout<<(char)219;
            }
        }

        for (int x=PosX+1;x<=PosX+7;x++){
            rlutil::locate(x,PosY+3);
            cout<<(char)223;
        }
        rlutil::resetColor();
}

int SumaDeDados (int v[], int tam)
{
    int contador=0;
    for (int i = 0; i < tam; i++)
    {
        contador += v[i];
    }

    return contador;
}

void ordenarVector(int vec[], int tam)
{
    int aux;
    for(int i = 0; i < tam-1; i++)
    {
        for(int j = i+1; j < tam; j++)
        {
            if(vec[j]<vec[i])
            {
                aux = vec[j];
                vec[j]=vec[i];
                vec[i]=aux;
            }
        }
    }
}

void Estadistica (int vec[], int punt)
{
    int aux;
    for(int i = 0; i < 3-1; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(vec[j]<vec[i])
            {
                aux = vec[j];
                vec[j]=vec[i];
                vec[i]=aux;
            }
        }
    }


}

bool Escalera (int v[], int tam)
{
    int cont = 0;
    for(int i = 0; i < tam-1 ; i++)
    {
        if (v[i] < v[i+1])
        {
            cont++;
        }
        if (cont == tam-1)
        {
            return true;
        }

    }
    return false;
}
bool Sexteto (int v[], int tam)
{
    int cont = 0;
    for (int i = 0; i < tam; i++)
    {
        if (v[i] == tam)
        {
            cont++;
        }
    }
    if (cont == tam)
    {
        return true;
    }
    return false;

}
bool SextetodeX (int v[], int tam)
{
    int cont = 0;
    for (int i = 0; i < tam; i++)
    {
        if (v[i] == v[0] && v[0] != tam)
        {
            cont++;
        }
    }

    if (cont == tam)
    {
        return true;
    }
    return false;
}
void PressEnter()
{

    system("pause");
    cout << "------------------------------------------------------------------------------------------------------------------------";
}
