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

//atributos agregados
    int ubicacionL[2];// 4( columna )  _  3( fila )
    bool estadoSN;//1 ( DISPONIBLE ) / 0 ( NO DISPONIBLE )

public :
    libro(string, string, string, string, string, string);
    libro(string, string, string, string, string, string, int*,bool);
    libro(string, string, string, string, int[2], bool);//sobrecargo el constructor para el ultimo libro del csv
    libro(string, string, string, string, string, string, string, int[2], bool);

    //~libro();
    string stringFile();
    void generar_barras();
    void mostrarLibro();

    //getters
    string get_nombre();
    string get_area() ;
    string get_sub_area();
    string get_autores() ;
    string get_editorial();
    string get_anio_P();
    string getEstado();
    bool   getEstadoSN();
    int    getColumna();
    int    getFila();

    //setters
    void setDato(string, int);
    void setDato_UBI(int, int);
    void setDato_estadoSN(bool);
};

#endif // LIBRO_H_INCLUDED
