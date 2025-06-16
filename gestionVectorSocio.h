#ifndef GESTIONVECTORSOCIO_H_INCLUDED
#define GESTIONVECTORSOCIO_H_INCLUDED

#include "funcionesMain.h"
#include "funcionesLibro.h"

using namespace std;

void eliminarSocio(vector <socio>&, int);
void agregarSocio(vector <socio>&);
void modificar_Socio(vector <socio>&, int);///MODIFICA EL VECTOR
void lecturaLinea(vector <socio>&, ifstream&);///TOMA EL ARCHIVO Y LE EXTRAE LOS DATOS LINEA X LINEA Y LO ENSAMBLA EN UN VECTOR

#endif // GESTIONVECTORSOCIO_H_INCLUDED
