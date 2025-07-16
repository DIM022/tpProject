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

tm parsearFecha(const string& fecha_str);
void registrarPrestamo(vector <datoPrestamo>&, vector <socio>&, vector <libro>&);
bool verificarExistenciaDniSocio(const string& dniBuscado, const vector<socio>& vectorSocio);
bool verificarExistenciaNombreLibro(string, vector <libro>&);
tm establecerFechaFuncion(int, int, int);

void filtrarPrestamoTodo(vector <datoPrestamo>&);
void filtrarPrestamoSocio(vector <datoPrestamo>&);
void filtrarPrestamoLibro(vector <datoPrestamo>&);
void filtrarPrestamoFecha(vector <datoPrestamo>&);
void subirCambiosPrestamos(const vector<datoPrestamo>& vectorPrestamo);
vector<datoPrestamo> cargarPrestamos(const string& nombre_archivo);

#endif // FUNCIONESPRESTAMO_H_INCLUDED
