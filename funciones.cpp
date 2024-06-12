#include <iostream>
#include<cstdlib>
#include "funciones.h"

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

void mostrarTirada(int v[], int tam)
{
    for (int i= 0; i < tam; i++)
    {
        cout << "Dado #" << i+1 << " :" << v[i] << endl;
    }

}

int SumarTirada (int v[], int tam)
{
    int contador=0;
    for (int i = 0; i < tam; i++)
    {
        contador += v[i];
    }

    return contador;
}

bool compararVectoresEnMismaPosicion(int vec1[], int vec2[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        if(vec1[i] != vec2[i])
        {
            return false;
        }
    }
    return true;
}

bool existeNumeroVector(int vec[], int tam, int num)
{
    for(int i = 0; i < tam; i++)
    {
        if(vec[i] == num)
        {
            return true;
        }
    }
    return false;
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
/// Cuando todos los numeros son iguales, se suma la puntuacion de X*2, menos cuando es un sexteto, se resetean los puntos
int contarNumerosRepetidos(int vec[], int tam, int num)
{
    int cant = 0;
    for(int i = 0; i < tam; i++)
    {
        if(vec[i] == num)
        {
            cant++;
        }
    }
    return cant;
}

bool verificarTodosRepetidos(int vec[], int tam)
{
    int cantidadRepetidos;
    cantidadRepetidos = contarNumerosRepetidos(vec, tam, vec[0]);
    if(cantidadRepetidos == tam)
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
