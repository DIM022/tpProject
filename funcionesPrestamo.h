#ifndef FUNCIONESPRESTAMO_H_INCLUDED
#define FUNCIONESPRESTAMO_H_INCLUDED

#include <vector>
#include <string>

#include "socioH.h"
#include "libroH.h"
#include "prestamoFormato.h"

#include "gestionVectorLibro.h"
#include "gestionVectorSocio.h"
#include "funcionesMain.h"

void registrarPrestamo(vector <datoPrestamo>&, vector <socio>&, vector <libro>&);

bool verificarExistenciaNombreSocio(string, vector <socio>&);
bool verificarExistenciaNombreLibro(string, vector <libro>&);
tm establecerFechaFuncion(int, int, int);

void filtrarPrestamoSocio(vector <datoPrestamo>&);
void filtrarPrestamoLibro(vector <datoPrestamo>&);
void filtrarPrestamoFecha(vector <datoPrestamo>&);

#endif // FUNCIONESPRESTAMO_H_INCLUDED
