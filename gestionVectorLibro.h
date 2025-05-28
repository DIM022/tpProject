#ifndef GESTIONVECTORLIBRO_H_INCLUDED
#define GESTIONVECTORLIBRO_H_INCLUDED

using namespace std;

#include <vector>

#include "libroH.h"
#include "funcionesLibro.h"
#include "funcionesMain.h"

void agregarLibro(vector<libro> &);

bool validarNombre(string);
bool validarAutores(string);
bool validarUbicacion(int *, vector <libro>&);

#endif // GESTIONVECTORLIBRO_H_INCLUDED
