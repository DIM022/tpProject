#include "libroH.h"
#include <string>

using namespace std;

/**---------------------------------------------------------------------------------------------------*/

//constructor
libro::libro(string n, string a , string s, string aut, string edi, string ani){
    nombre = n;
    area = a;
    sub_area = s;
    autores = aut;
    editorial = edi;
    anio_P = ani;
}

/**---------------------------------------------------------------------------------------------------*/

libro::libro(string n, string a , string s, string aut, string edi, string ani,int* _ubi,bool _estadoSN){

    nombre = n;
    area = a;
    sub_area = s;
    autores = aut;
    editorial = edi;
    anio_P = ani;

    if (_ubi != nullptr) {
        ubicacionL[0] = _ubi[0]; // Columna
        ubicacionL[1] = _ubi[1]; // Fila
    }
    estadoSN = _estadoSN;
}




/**---------------------------------------------------------------------------------------------------*/

//setters
void libro::setDato(string nuevoValor, int posDato){

    switch(posDato){

        case 1 :
            nombre = nuevoValor;break;

        case 2 :
            area = nuevoValor;break;
            break;

        case 3 :
            sub_area = nuevoValor;break;

        case 4 :
            autores = nuevoValor;break;

        case 5 :
            editorial = nuevoValor;break;

        case 6 :
            anio_P = nuevoValor;break;

        case 7 :
            estado = nuevoValor;break;
    }
}

/**---------------------------------------------------------------------------------------------------*/

void libro::setDato_UBI(int colu, int fila){

    ubicacionL[0] = colu;
    ubicacionL[1] = fila;
}

/**---------------------------------------------------------------------------------------------------*/

void libro::setDato_estadoSN(bool _est){

    estadoSN = _est;
}

/**---------------------------------------------------------------------------------------------------*/

//getters
string libro::get_nombre() const{
    return nombre;
}

/**---------------------------------------------------------------------------------------------------*/

string libro::get_area() const{
    return area;
}

/**---------------------------------------------------------------------------------------------------*/

string libro::get_sub_area() const{
    return sub_area;
}

/**---------------------------------------------------------------------------------------------------*/

string libro::get_autores()const  {
    return autores;
}

/**---------------------------------------------------------------------------------------------------*/

string libro::get_editorial()const  {
    return editorial;
}

/**---------------------------------------------------------------------------------------------------*/

string libro::get_anio_P() const {
    return anio_P;
}

/**---------------------------------------------------------------------------------------------------*/

string libro::getEstado()const{

    return estado;
}

/**---------------------------------------------------------------------------------------------------*/

bool libro::getEstadoSN()const {

    return estadoSN;
}

/**---------------------------------------------------------------------------------------------------*/

int libro::getColumna()const {

    return ubicacionL[0];
}

/**---------------------------------------------------------------------------------------------------*/

int libro::getFila()const {

    return ubicacionL[1];
}

/**---------------------------------------------------------------------------------------------------*/

void libro:: mostrarLibro(){

        cout<< "-----------------------"<<endl;
        cout<<"Nombre: "<<quitar_tildes(nombre)<<endl;
        cout<<"Area: "<<quitar_tildes(area)<<endl;
        cout<<"Sub Area: "<<quitar_tildes(sub_area)<<endl;
        cout<<"Autores: "<<quitar_tildes(autores)<<endl;
        cout<<"Editorial:"<<quitar_tildes(editorial)<<endl;
        cout<<"Anio de Publicacion: "<<quitar_tildes(anio_P)<<endl;
}

/**---------------------------------------------------------------------------------------------------*/

string libro::generar_barras()const{

    string cod_Barras; // aca se guarda el codigo de barra

    //codifio la ubicación (Columna y Fila) ---
    for (int i = 0; i <= 1; i++) {

        for (int j = ubicacionL[i]; j > 0; j--) {
            cod_Barras.append("|");
        }
        cod_Barras.append("/"); // separador
    }

    //Disponibilidad (estadoSN)
    if (estadoSN) { // Si es true (disponible)
        cod_Barras.append("||");
    } else { // Si es false (no disponible)
        cod_Barras.append("|");
    }
    cod_Barras.append("/"); // Separador
/**---------------------------------------------------------------------------------------------------*/
    //NOTA: ESTO NO SE VE EN EL CODIGO DE BARRA PORQUE NO PUDE HACER FUNCIONAR EL ESTADO FISICO DEL LIBRO
    if (!estado.empty()) {
        char primer_char = tolower(estado.front());

        if (primer_char == 'b') {
            cod_Barras.append("|");
        } else if (primer_char == 'r') {
            cod_Barras.append("||");
        } else if (primer_char == 'm') {
            cod_Barras.append("|||");
        } else if (primer_char == 'd') {
            cod_Barras.append("||||");
        }
    }

    return cod_Barras;
}

/**---------------------------------------------------------------------------------------------------*/

string libro::stringFile()const{

    string _stringFile;


    _stringFile.append(nombre);
    _stringFile +=',';
    _stringFile.append(area);
    _stringFile +=',';
    _stringFile.append(sub_area);
    _stringFile +=',';
    _stringFile.append(autores);
    _stringFile +=',';
    _stringFile.append(editorial);
    _stringFile +=',';
    _stringFile.append(anio_P);
    _stringFile +=',';
    _stringFile.append(estado);
    _stringFile +=',';

    _stringFile.append(std::to_string(ubicacionL[0])); // Columna
    _stringFile += ',';
    _stringFile.append(std::to_string(ubicacionL[1])); // Fila
    _stringFile += ',';


    if(estadoSN){
        _stringFile.append("1");
    }else{
        _stringFile.append("0");
    }



    return _stringFile;
}
