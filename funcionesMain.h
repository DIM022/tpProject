#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include<string>
#include<fstream>
#include<vector>

///DONDE SE ENCUENTRAN LAS CLASES
#include "socioH.h"
#include "gestionVectorSocio.h"

using namespace std;

ifstream archivo_IO();///FUNCION PARA ABRIR EL ARCHIVO EN MODO ESCRITURA O LECTURA

void subirCambios(vector <socio>&);///TOMA EL VECTOR Y LO COPIA EN EL ARCHIVO
void mostrar(vector<socio>&);///RECORRE EL VECTOR
bool verificarNumeroString(string);
bool verificarCharString(string);

#endif // FUNCIONES_H_INCLUDED
