#ifndef func_h //si no esta definido
#define func_h //definimos

#include "libroH.h"


#include <string>//13 - 20 << linea que los usa
#include <unordered_map>//13 - 20 << linea que los usa
#include <vector>//mostrar,

using namespace std;

string a_minusculas(string text);
string borrar_comillas(string texto);
string borrar_ceros(string fecha);
bool fecha_valida(string fecha);
string normalizar_anio(string fecha);
string borrar_espacios(string texto);
string quitar_tildes(string texto);
bool es_entero_valido(string s);
bool es_entero_valido(string s);
string asignar_estado(int &contador);
string asignar_estadoSN(int &contador);
void asignar_ubicacion(int &contador, int ubicacionL[2]);
void asignar_estadosUbicacion(string nombre_archivo);
int contar_campos(string linea);
void cambiar_ubicacion(string ubicacion_string, int[2]);
bool es_ubicacion_valida(string);

#endif //cierra condicion del ifndef
