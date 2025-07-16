#ifndef SOCIO_H_INCLUDED
#define SOCIO_H_INCLUDED

#include<iostream>
#include<string>

using namespace std;

class socio{
    string apellido;
    string dni;
    string sexo;
    string direccion;
    string num_telefonico;
    string edad;
    string fechaN;
    string mail;
    int posicionDato; /// ELIMINAR

public :
    socio();
    socio(string, string, string, string, string, string, string, string, int);
    ~socio();

    int validar(string);///SIRVE PARA LA BUSQUEDA DEL SOCIO
    string stringFile()const;///CONVIERTE LOS ATRIBUTOS A UN STRING
    void mostrarSocio();

    //setters
    void setDato(string, int);///MODIFICA ALGUN ATRIBUTO DEL OBJETO

    //getters
    string getapll()const;
    string getdni()const;
    string getsex()const;
    string getdir()const;
    string getnum()const;
    string getedad()const;
    string getfechaN()const;
    string getmail()const;

};

#endif // SOCIO_H_INCLUDED
