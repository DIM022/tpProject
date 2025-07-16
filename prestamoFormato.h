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
    ~datoPrestamo();

    void realizarPrestamo();///INICIA FECHA INCIO CON LA FECHA EN EL MOMENTO QUE SE INICIA UN NUEVO PRESTAMO
    void establecerFechaPrestamo();///SE INICIALIZA LA FECHA MAXIMA DEL PRESTAMO
    void mostrarPrestamo();///MUESTRA LOS DATOS DE LAS PROPIEDADES

    bool operator==(tm&);///SOBRECARGA PARA COMPRAR DOS FECHAS
    void setFechaInicio(const tm& fecha);
    void setFechaFinal(const tm& fecha);

    ///GETTERS
    void getDevolucion();///DEVUELVE LOS DIAS DESDE L PRESTAMO HASTA LA FECHA MAXIMA
    string getFechaFinal()const;///DEVUELVE LA FECHA INDICADA DE DEVOLUCION
    string getFechaInicio()const;///DEVUELVE CUANDO SE REALIZO EL PRESTAMO
    string getDni()const;
    string getNombreLibro()const;
    string stringFile() const;
};

#endif // PRESTAMOFORMATO_H_INCLUDED
