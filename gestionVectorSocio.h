#ifndef GESTIONVECTORSOCIO_H_INCLUDED
#define GESTIONVECTORSOCIO_H_INCLUDED

#include "funcionesMain.h"
#include "funcionesLibro.h"

using namespace std;

int inicioAperturaSocio(vector<socio>&, ifstream&, int&);
void eliminarSocio(vector <socio>&, int);
void agregarSocio(vector <socio>&);
void modificarSocio(vector <socio>&, int);//MODIFICA EL VECTOR
void lecturaLinea(vector <socio>&, ifstream&);//TOMA EL ARCHIVO Y LE EXTRAE LOS DATOS LINEA X LINEA Y LO ENSAMBLA EN UN VECTOR

bool verificarExistenciaDniSocio(string, vector <socio>&);

#endif // GESTIONVECTORSOCIO_H_INCLUDED
