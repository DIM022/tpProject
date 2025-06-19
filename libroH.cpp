#include "libroH.h"

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

/**---------------------------------------------------------------------------------------------------*/

libro::libro(string n, string a , string s, string aut, string edi, string ani, string estado_, int ubicacion_[2], bool estadoSN_){
    nombre = n;
    area = a;
    sub_area = s;
    autores = aut;
    editorial = edi;
    anio_P = ani;
    estado = estado_;
    ubicacionL[0] = ubicacion_[0];
    ubicacionL[1] = ubicacion_[1];
    estadoSN = estadoSN_;
}

/**---------------------------------------------------------------------------------------------------*/

libro::libro(string nombre_, string area_, string sub_area_, string estado_, int ubicacion_[2], bool estadoSN_)//sobrecargo el constructor para el ultimo libro del csv
{
    nombre = nombre_;
    area = area_;
    sub_area = sub_area_;
    autores = "Desconocido";
    editorial = "Desconocido";
    anio_P = "Desconocido";
    estado = estado_;
    ubicacionL[0] = ubicacion_[0];
    ubicacionL[1] = ubicacion_[1];
    estadoSN = estadoSN_;
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
string libro::get_nombre() {
    return nombre;
}

/**---------------------------------------------------------------------------------------------------*/

string libro::get_area() {
    return area;
}

/**---------------------------------------------------------------------------------------------------*/

string libro::get_sub_area() {
    return sub_area;
}

/**---------------------------------------------------------------------------------------------------*/

string libro::get_autores()  {
    return autores;
}

/**---------------------------------------------------------------------------------------------------*/

string libro::get_editorial()  {
    return editorial;
}

/**---------------------------------------------------------------------------------------------------*/

string libro::get_anio_P()  {
    return anio_P;
}

/**---------------------------------------------------------------------------------------------------*/

string libro::getEstado(){

    return estado;
}

/**---------------------------------------------------------------------------------------------------*/

bool libro::getEstadoSN(){

    return estadoSN;
}

/**---------------------------------------------------------------------------------------------------*/

int libro::getColumna(){

    return ubicacionL[0];
}

/**---------------------------------------------------------------------------------------------------*/

int libro::getFila(){

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
        cout<< "Estado: "<< ( estadoSN ? "disponible" : "no disponible ")<< endl;
}

/**---------------------------------------------------------------------------------------------------*/

void libro::generar_barras(){

    //LOS DATOS SERAN REPRESENTADO POR  > |
    //LOS SEPARAMOS CON > /
   int columna=0; //COLUMNA DONDE ESTA EL LIBRO
   int fila=0; //FILA DONDE ESTA EL LIBRO
   int stateSN=0;// ESTADO DISPONIBLE SI / NO
   int stateLibro=0; // ESTADO FISICO DEL LIBRO ( BUENO, REGULAR, MALO, DESTRIDO )
   int i=0, salir = 0;

    int indice = 0;
    string cod_Barras;//DONDE GUARDAMOS EL CODIGO DE BARRAS

//FILA Y COLUMNA
//LEE LA COLUMNA ( PRIMER DATO ) Y LUEGO LA FILA ( SEGUNDO DATO )

    for(int i=0; i<=1 ; i++){

        //TOMA EL VALOR DE LA FILA/COLUMNA
        //E IMPRIME TANTAS VECES ITERE
        for(int j = ubicacionL[i]; j>0; j--){
            cod_Barras.append("|");
            cout<< '|';
        }

        //SEPARA COLUMNA DE FILA
        cod_Barras.append( "/");
        cout<< '/';
    }

//ESTADO DISPONIBLE O NO >> 1 SI // 0 NO
    if(estadoSN){//SI
        cod_Barras.append( "||");
        cout<< "||";

    }else{//NO
        cod_Barras.append( "|");
        cout<< '|';

    }

    cod_Barras.append( "/");//SEPARADOR
    cout<< '/';

//LEE EL PRIMER BYTE Y EN BACE A ESO LE ASIGNAMOS CIERTA LETRA
// B > BUENO // R > REGULAR // M > MALO // D > DESTRUIDO
//CADA LETRA INDICA CIERTA CANTIDAD DE BARRAS
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

//IMPRIME EL CODIGO DE BARRAS
    cout<< "string cod_Barras : "<< cod_Barras<< endl;


//LEEEMOS LA BARRA PARA DECODIFICARLO
    while(!salir){

        if(cod_Barras[i] == '/'){//SI ENCUENTRA UN SEPARADOR AUMENTA AL SIGUIENTE TIPO  Y AUMENTAMOS INDICE
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

//IMPRIMIMOS EL CODIGO DE BARRAS
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

/**---------------------------------------------------------------------------------------------------*/

string libro::stringFile(){

    string _stringFile;//DONDE ALMACENAREMOS LOS ATRIBUTOS
    string _aux;


    //AGREGAR AL FINAL DEL ARCHIVO CADA ATRIBUTO
    //PARA FORMA UNA LINEA COMPLETA
    //PARECIDA A COMO LA TOMAMOS ORIGINALMENTE
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

    _stringFile += ubicacionL[0];
    _stringFile +='-';
    _stringFile += ubicacionL[1];

    _stringFile +=',';

    //SI BOOL ESTA DISPONIBLE LO REGISTRAMOS COMO UN 1 EN EL ARCHIVO
    //SI NO COMO UN < 0 >
    if(estadoSN){
        _stringFile.append("si");
    }else{
         _stringFile.append("no");
    }
    _stringFile +='\0';

    //RETORNAMOS
    return _stringFile;
}
