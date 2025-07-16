#ifndef LIBRO_H_INCLUDED
#define LIBRO_H_INCLUDED

#include<iostream>
#include<string>

#include "funcionesMain.h"

using namespace std;

class libro{
    string nombre;
    string area;
    string sub_area;
    string autores;
    string editorial;
    string anio_P;
    string estado;

///atributos agregados
    int ubicacionL[2];// 4( columna )  _  3( fila )
    bool estadoSN;//1 ( DISPONIBLE ) / 0 ( NO DISPONIBLE )

public :
    libro(string, string, string, string, string, string);
    libro(string, string, string, string, string, string,int*,bool);
    //~libro();
    string stringFile() const;
    string generar_barras()const;
    void mostrarLibro();

    //getters
    string get_nombre()const;
    string get_area()const ;
    string get_sub_area()const;
    string get_autores()const ;
    string get_editorial()const;
    string get_anio_P()const;
    string getEstado()const;
    bool   getEstadoSN()const;
    int    getColumna()const;
    int    getFila()const ;

    //setters
    void setDato(string, int);
    void setDato_UBI(int, int);
    void setDato_estadoSN(bool);
};

#endif // LIBRO_H_INCLUDED
