#ifndef FUNCION_H_INCLUDED
#define FUNCION_H_INCLUDED

int tirarDado();
void generarTirada(int v[], int tam);
void mostrarTirada(int v[], int tam);

///PUNTUACION
int SumaDeDados (int v[], int tam);
int Sexteto (int v[], int tam);
int Escalera (int v[], int tam);

///GUIAS
bool compararVectoresEnMismaPosicion(int vec1[], int vec2[], int tam);
bool existeNumeroVector(int vec[], int tam, int num);
void ordenarVector(int vec[], int tam);
int contarNumerosRepetidos(int vec[], int tam, int num);
bool verificarTodosRepetidos(int vec[], int tam);

///DISEÑO
void PressEnter();

///MENU
bool MENU();
void ModoUnJugador();
void ModoDosJugadores();

#endif // FUNCION_H_INCLUDED
