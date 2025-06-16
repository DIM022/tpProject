#ifndef PRESTAMOFORMATO_H_INCLUDED
#define PRESTAMOFORMATO_H_INCLUDED

#include <iostream>
#include <ctime>
#include <string>

using namespace std;

class datoPrestamo{

private :
    string dniSocio;
    string nombreLibro;
    tm fechaInicio;
    tm fechaFinal;

public :

    datoPrestamo(string, string);
    ~datoPrestamo() = default;
    void realizarPrestamo();
    void establecerFechaPrestamo();
    void mostrarPrestamo();///MUESTRA LOS DATOS DE LAS PROPIEDADES
    bool operator==(datoPrestamo&);

    ///GETTERS
    void getDevolucion();///DEVUELVE LOS DIAS DESDE L PRESTAMO HASTA LA FECHA MAXIMA
    void getFechaFinal();///DEVUELVE LA FECHA INDICADA DE DEVOLUCION
    void getFechaInicio();///DEVUELVE CUANDO SE REALIZO EL PRESTAMO
    string getDni();
    string getNombreLibro();
};

#endif // PRESTAMOFORMATO_H_INCLUDED
