#include "socioH.h"///DONDE ESTA LA CLASE SOCIO

using namespace std;

/**---------------------------------------------------------------------------------------------------*/

// getters
string socio::getapll() {
    return apellido;
}

/**---------------------------------------------------------------------------------------------------*/

string socio::getdni() {
    return dni;
}

/**---------------------------------------------------------------------------------------------------*/

string socio::getsex() {
    return sexo;
}

/**---------------------------------------------------------------------------------------------------*/

string socio::getdir() {
     return direccion;
}

/**---------------------------------------------------------------------------------------------------*/

string socio::getnum() {
     return num_telefonico;
}

/**---------------------------------------------------------------------------------------------------*/

string socio::getedad() {
     return edad;
}

/**---------------------------------------------------------------------------------------------------*/

string socio::getfechaN() {
     return fechaN;
}

/**---------------------------------------------------------------------------------------------------*/

string socio::getmail() {
    return mail;
}

/**---------------------------------------------------------------------------------------------------*/

void socio::mostrarSocio(){
    cout<<"--------------------"<<endl; //aplicamos quitar_tildes porque sino el cout no funciona bien para los caracteres con tilde
    cout<<"Apellido: "<<apellido <<endl;
    cout<<"DNI: "<<dni <<endl;
    cout<<"Sexo: "<<sexo <<endl;
    cout<<"Direccion: "<<direccion <<endl;
    cout<<"Numero: "<<num_telefonico <<endl;
    cout<<"Edad: "<<edad <<endl;
    cout<<"Fecha de Nacimiento: "<<fechaN <<endl;
    cout<<"Email: "<<mail <<endl;
     cout<<"--------------------"<<endl;
}

/**---------------------------------------------------------------------------------------------------*/

string socio::stringFile(){

    string _stringFile;///DONDE ALMACENAREMOS LOS ATRIBUTOS


    ///AGREGAR AL FINAL DEL ARCHIVO CADA ATRIBUTO
    ///PARA FORMA UNA LINEA COMPLETA
    ///PARECIDA A COMO LA TOMAMOS ORIGINALMENTE
    _stringFile.append(apellido);
    _stringFile +=',';
    _stringFile.append(dni);
    _stringFile +=',';
    _stringFile.append(sexo);
    _stringFile +=',';
    _stringFile.append(direccion);
    _stringFile +=',';
    _stringFile.append(num_telefonico);
    _stringFile +=',';
    _stringFile.append(edad);
    _stringFile +=',';
    _stringFile.append(fechaN);
    _stringFile +=',';
    _stringFile.append(mail);
    _stringFile +='\0';

    ///RETORNAMOS
    return _stringFile;
}

/**---------------------------------------------------------------------------------------------------*/

///MODIFICA LOS ATRIBUTOS DEL OBJETO
void socio::setDato(string nuevoValor, int posDato){

    switch(posDato){

    case 1 :
        apellido = nuevoValor;break;

    case 2 :
        dni = nuevoValor;
        break;

    case 3 :
        sexo = nuevoValor;break;

    case 4 :
        direccion = nuevoValor;break;

    case 5 :
        num_telefonico = nuevoValor;break;

    case 6 :
        edad = nuevoValor;break;

    case 7 :
        fechaN = nuevoValor;break;

    case 8 :
        mail = nuevoValor;break;

    default :
        cout<< "error"<<endl;break;
    }
}

/**---------------------------------------------------------------------------------------------------*/

///VALIDA SI EL STRING RECIBIDO ES IGUAL AL DEL OBJETO
///USADO EN LA FUNCION BUSQUEDA
int socio::validar(string socioDNIB){

    if(dni == socioDNIB){
        return 1;

    }else{
        return 0;

    }
}

/**---------------------------------------------------------------------------------------------------*/

///CONSTRUCTOR QUE INICIALIZA LOS ATRIBUTOS
socio::socio(string _apellido, string _dni, string _genero, string _direccion, string _numeroT, string _edad, string _fechaN, string _mail, int _posicionA){

    apellido = _apellido;
    dni = _dni;
    sexo = _genero;
    direccion = _direccion;
    num_telefonico = _numeroT;
    edad = _edad;
    fechaN = _fechaN;
    mail = _mail;
    posicionDato = _posicionA;
}

/**---------------------------------------------------------------------------------------------------*/

socio::socio(){
}

/**---------------------------------------------------------------------------------------------------*/

socio::~socio(){

    ///EN LA FUNCION DE TOMARLINEA CUANDO SALIDOS SE INVOCAN A TODOS LOS DESTRUCTORES
    //YA QUE SALE DEL AMBITO EN EL QUE FUERON CREADOS
    ///VER COMO SOLUCIONAR ESO

    //cout<< "llamada a destructor"<< endl;
}

/**---------------------------------------------------------------------------------------------------*/
