#ifndef GESTIONVECTORLIBRO_H_INCLUDED
#define GESTIONVECTORLIBRO_H_INCLUDED


#define ARCHIVO_LIBROS "lista_libros.csv"

using namespace std;

#include <vector>

#include "buscar_libros.h"
#include "cargar_libros.h"

#include "libroH.h"
#include "funcionesLibro.h"
#include "funcionesMain.h"

bool validarNombre(string);
bool validarAutores(string);
bool validarUbicacion(int *, vector <libro>&);

void inicioAperturaLibro(vector <libro>&, int&);
void agregarLibro(vector<libro>&);
void modificarLibro(int, vector<libro>&);
void subirCambiosLibro(vector <libro>&);

#endif // GESTIONVECTORLIBRO_H_INCLUDED
