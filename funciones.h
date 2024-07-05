#ifndef FUNCION_H_INCLUDED
#define FUNCION_H_INCLUDED

int tirarDado();
void escribirTirada (int v[], int tam);
void generarTirada(int v[], int tam);
void mostrarTirada(int v[], int tam);
void DibujarCuadrados(int PosY, int PosX);
void SombraDados(int PosX, int PosY);
void DibujaDados(int dados[], int PosY,int PosX);

int SumaDeDados (int v[], int tam);
bool SextetodeX (int v[], int tam);
bool Sexteto (int v[], int tam);
bool Escalera (int v[], int tam);

void ordenarVector(int vec[], int tam);
void Estadistica (int vec[], int tam);

void PressEnter();

#endif // FUNCION_H_INCLUDED
