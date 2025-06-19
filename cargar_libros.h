#ifndef cargar_libros_h//si no esta definido
#define cargar_libros_h//definimos

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

#include "libroH.h"

#include "funcionesLibro.h"
#include "gestionVectorLibro.h"

///TOMA LOS DATOS DEL ARCHIVO LIBRO
vector<libro> cargarLibro(string);

#endif//fin del if
