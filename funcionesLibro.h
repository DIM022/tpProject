#ifndef func_h //si no esta definido
#define func_h //definimos

#include "libroH.h"

#include <string>//13 - 20 << linea que los usa
#include <unordered_map>//13 - 20 << linea que los usa
#include <vector>//mostrar,
#include <fstream>
#include <array> // para retornar un array fijo en una funcion

using namespace std;

string a_minusculas(string text);
string borrar_comillas(string texto);
string borrar_ceros(string fecha);
string normalizar_anio(string fecha);
string borrar_espacios(string texto);
string quitar_tildes(string texto);
bool fecha_valida(string fecha);
bool es_entero_valido(string s);

string asignar_estado(int &contador);
string asignar_estadoSN(int &contador);
void asignar_ubicacion(int &contador, int ubicacionL[2]);
void asignar_estadosUbicacion(string nombre_archivo);
void cambiar_ubicacion(string ubicacion_string, int[2]);
int contar_campos(string linea);
bool es_ubicacion_valida(string);

#endif //cierra condicion del ifndef
