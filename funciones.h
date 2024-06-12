#ifndef FUNCION_H_INCLUDED
#define FUNCION_H_INCLUDED

int tirarDado();
void generarTirada(int v[], int tam);
void mostrarTirada(int v[], int tam);
int SumarTirada (int v[], int tam);
bool compararVectoresEnMismaPosicion(int vec1[], int vec2[], int tam);
bool existeNumeroVector(int vec[], int tam, int num);
void ordenarVector(int vec[], int tam);
int contarNumerosRepetidos(int vec[], int tam, int num);
bool verificarTodosRepetidos(int vec[], int tam);

/// Diseño
void PressEnter();

#endif // FUNCION_H_INCLUDED
