#ifndef GESTIONVECTORLIBRO_H_INCLUDED
#define GESTIONVECTORLIBRO_H_INCLUDED

using namespace std;

#include <vector>

#include "buscar_libros.h"
#include "cargar_libros.h"

#include "libroH.h"
#include "funcionesLibro.h"
#include "funcionesMain.h"

extern std::vector<libro> vector_Libro;
void agregarLibro(vector<libro>&);

bool validarNombre(string);
bool validarAutores(string);
bool validarUbicacion(int *, vector <libro>&);
void modificarLibro(int, vector<libro>&);
void subirCambiosLibro(vector <libro>&);

#endif // GESTIONVECTORLIBRO_H_INCLUDED
