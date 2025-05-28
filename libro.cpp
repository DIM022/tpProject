#include "libroH.h"

using namespace std;

//constructor
libro::libro(string n, string a , string s, string aut, string edi, string ani){
    nombre = n;
    area = a;
    sub_area = s;
    autores = aut;
    editorial = edi;
    anio_P = ani;
}

libro::libro(string n, string a , string s, string aut, string edi, string ani, int* _ubi,bool _estadoSN){

    nombre = n;
    area = a;
    sub_area = s;
    autores = aut;
    editorial = edi;
    anio_P = ani;
    ubicacionL[0] = _ubi[0];
    ubicacionL[1] = _ubi[1];
    estadoSN = _estadoSN;

}
//getters
string libro::get_nombre() {
    return nombre;
}

string libro::get_area() {
    return area;
}

string libro::get_sub_area() {
    return sub_area;
}

string libro::get_autores()  {
    return autores;
}

string libro::get_editorial()  {
    return editorial;
}

string libro::get_anio_P()  {
    return anio_P;
}

string libro::getEstado(){

    return estado;
}

bool libro::getEstadoSN(){

    return estadoSN;
}

int libro::getColumna(){

    return ubicacionL[0];
}

int libro::getFila(){

    return ubicacionL[1];
}

void libro:: mostrarLibro(){

        cout<< "-----------------------"<<endl;
        cout<<"Nombre: "<<quitar_tildes(nombre)<<endl;
        cout<<"Area: "<<quitar_tildes(area)<<endl;
        cout<<"Sub Area: "<<quitar_tildes(sub_area)<<endl;
        cout<<"Autores: "<<quitar_tildes(autores)<<endl;
        cout<<"Editorial:"<<quitar_tildes(editorial)<<endl;
        cout<<"Anio de Publicacion: "<<quitar_tildes(anio_P)<<endl;
}

void libro::generar_barras(){

    ///LOS DATOS SERAN REPRESENTADO POR  > |
    ///LOS SEPARAMOS CON > /
   int columna=0; //COLUMNA DONDE ESTA EL LIBRO
   int fila=0; //FILA DONDE ESTA EL LIBRO
   int stateSN=0;// ESTADO DISPONIBLE SI / NO
   int stateLibro=0; // ESTADO FISICO DEL LIBRO ( BUENO, REGULAR, MALO, DESTRIDO )
   int i=0, salir = 0;

    int indice = 0;
    string cod_Barras;///DONDE GUARDAMOS EL CODIGO DE BARRAS

///FILA Y COLUMNA
///LEE LA COLUMNA ( PRIMER DATO ) Y LUEGO LA FILA ( SEGUNDO DATO )

    for(int i=0; i<=1 ; i++){

        ///TOMA EL VALOR DE LA FILA/COLUMNA
        ///E IMPRIME TANTAS VECES ITERE
        for(int j = ubicacionL[i]; j>0; j--){
            cod_Barras.append("|");
            cout<< '|';
        }

        ///SEPARA COLUMNA DE FILA
        cod_Barras.append( "/");
        cout<< '/';
    }

///ESTADO DISPONIBLE O NO >> 1 SI // 0 NO
    if(estadoSN){//SI
        cod_Barras.append( "||");
        cout<< "||";

    }else{//NO
        cod_Barras.append( "|");
        cout<< '|';

    }

    cod_Barras.append( "/");///SEPARADOR
    cout<< '/';

///LEE EL PRIMER BYTE Y EN BACE A ESO LE ASIGNAMOS CIERTA LETRA
/// B > BUENO // R > REGULAR // M > MALO // D > DESTRUIDO
///CADA LETRA INDICA CIERTA CANTIDAD DE BARRAS
    if(estado.front() == 'b' || estado.front() == 'B'){
        cod_Barras.append( "|");
        cout<< '|';

    }else if(estado.front() == 'r' || estado.front() == 'R'){
        cod_Barras.append( "||");
        cout<< "||";

    }else if(estado.front() == 'm' || estado.front() == 'M'){
        cod_Barras.append( "|||");
        cout<< "|||";

    }else if(estado.front() == 'd' || estado.front() == 'D'){
        cod_Barras.append( "||||");
        cout<< "||||";
    }
     cod_Barras.append( "/");
    cout<<  endl;

///IMPRIME EL CODIGO DE BARRAS
    cout<< "string cod_Barras : "<< cod_Barras<< endl;


///LEEEMOS LA BARRA PARA DECODIFICARLO
    while(!salir){

        if(cod_Barras[i] == '/'){///SI ENCUENTRA UN SEPARADOR AUMENTA AL SIGUIENTE TIPO  Y AUMENTAMOS INDICE
            indice++;
            i++;
        }

        if(indice == 0){
            columna++;

        }else if(indice == 1){
            fila++;

        }else if(indice == 2){
            stateSN++;

        }else if(indice == 3){
            stateLibro++;

        }else{
            salir = 1;

        }
        i++;
    }

///IMPRIMIMOS EL CODIGO DE BARRAS
    cout<< "el libro se escuentra :"<< endl
        << "columna: "<<columna<< " en la fila: "<< fila<< endl;

        if(stateSN){
            cout<<"estado : disponible"<<endl;
        }else{
            cout<<"estado : no disponible"<<endl;
        }

    cout<< "estado: ";
        if(stateLibro == 1){
            cout<< "bueno"<< endl;

        }else if(stateLibro == 2){
            cout<< "regular"<< endl;

        }else if(stateLibro == 3){
            cout<< "malo"<< endl;

        }else if(stateLibro == 4){
            cout<< "destruido"<< endl;

        }
}
