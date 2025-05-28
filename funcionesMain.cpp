#include "funcionesMain.h"
#include "gestionVectorSocio.h"

using namespace std;

///FUNCION PARA VERIFICAR STRING DE SOLO CARACTERES
bool verificarCharString(string _string){

    bool valido =  false;

    for(size_t i=0; i<_string.size(); i++){

        if( (_string[i] >= 'a' && _string[i]<= 'z') || (_string[i] >= 'A' && _string[i]<= 'Z') || (_string[i] == ' ') ){

        }else{
            cout<< "NO PUEDE HABER NUMERO NUMERO / CARACTERES ESPECIALES"<<endl;
             ///LO IGUALAMOS PARA TERMINAR EL FOR
             i = _string.size();
            valido = true;
        }
    }
    if(valido){
        ///EL STRING TIENE UN NUMERO / CARACTER ESPECIAL
        ///RETORNAMOS < true >
        return true;
    }
    ///SI TODO ESTA BIEN RETORNAMOS < false >
    ///PARA TERMINE EL BUCLE WHILE
    return false;
}


bool verificarNumeroString(string _string){

  bool valido =  false;

    for(size_t i=0; i< _string.size(); i++){

        if(_string[i] >= '0' && _string[i] <= '9'){

        }else{
            cout<< "SOLO VALIDO NUMEROS";
            i = _string.size();
            valido = true;
        }

    }

    if(valido){
        ///EL STRING TIENE ALGO MAS QUE SOLO NUMERO
        ///RETORNAMOS < true >
        return true;
    }
    ///SI TODO ESTA BIEN RETORNAMOS < false >
    ///PARA TERMINE EL BUCLE WHILE
    return false;

}


void mostrar(vector<socio>& vector_Socio){

    cout<< "SOCIOS"<<endl;
    for(size_t i = 0; i<vector_Socio.size(); i++){
        cout<< "---------------"<< endl;
        cout<< "- ";
        vector_Socio[i].mostrarSocio();
    }
        cout<< "---------------"<< endl;
}





void subirCambios(vector <socio>& vector_Socio){

    fstream file;
    string aux;

/**COMENTADO : AGREGA DNI A LOS SOCIOS */
/*
    int cont = 0;

    for(size_t i=0; i<vector_Socio.size(); i++){

        if (i <= 50) {
            aux = "111" + std::to_string(cont);

        } else if (i > 50 && i <= 100) {
            aux = "222" + std::to_string(cont);

        } else if (i > 100 && i <= 150) {
            aux = "333" + std::to_string(cont);

        } else {
            aux = "444" + std::to_string(cont);

        }
        cont++;
        if(cont > 50){
            cont = 0;
        }
        vector_Socio[i].setDato(aux, 2);
    }
*/
    ///SOCIO
        ///OUT PARA ESCRIBIR Y TRUNC PARA ELIMINAR EL CONTENIDO ANTERIOIR DEL ARCHIVO
        file.open("lista de socios.csv", ios::out | ios::trunc);

        for(size_t i=0; i<vector_Socio.size(); i++){

            ///ALMACENAMOS EN ARCHIVO --- stringFile
            ///stringFile -- CONVIERTE LOS ATRIBUTOS DEL OBJETO EN UN STRING QUE RETORNA
            file << vector_Socio[i].stringFile()<<'\n';
        }
        file.close();

}




/// ABRE UN ARCHIVO VALIDO Y LO RETORNA
ifstream archivo_IO() {

    ifstream file;///ALMACENAMOS LA DIRECCION DEL ARCHIVO

    ///ABRIMOS EL ARCHIVO
    file.open("lista de socios.csv", ios::in);

        ///VERIFICAMOS SI NO HUBO ERROR
        if(file.fail()){

            cout<< "ERROR AL ABRIR EL ARCHIVO ( FUNCION )   ";
            cout<< "VERIFICAR QUE EL ARCHIVO EXISTA"<< endl;

            ///RETORNA EL ARCHIVO QUE ES NULL
            return file;
        }

    ///SI TODO SALE BIEN RETORNAMOS LA DIRECCION DEL ARCHIVO
    return file;
}
/*----------------------------------------------------------------*/

