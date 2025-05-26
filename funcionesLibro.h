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

void mostrar(vector<libro>&);

#endif //cierra condicion del ifndef
