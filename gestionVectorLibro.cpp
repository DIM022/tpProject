#include "gestionVectorLibro.h"

void agregarLibro(vector<libro>& vectorLibro){

    bool valido = true;
    string _nombre, _area, _subArea, _autores, _editorial, _anioP;
    int _ubi[2];
    bool estadoSN;

        cout<< "-------------------------"<< endl;
        cout<< "INGRESO DE NUEVO LIBRO"<< endl;

        ///NOMBRE
        do{
            cout<< "INGRESE NOMBRE DEL LIBRO: ";
            getline(cin, _nombre);

            valido = validarNombre(_nombre);

        }while(valido);

        ///AREA
        do{
            cout<< "INGRESE AREA: ";
            getline(cin, _area);

            ///USAMOS UNA FUNCION DE <funcionesMain> YA QUE NOS SIRVE EN ESTE CASO
            valido = verificarCharString(_area);

        }while(valido);

        ///SUBAREA
        do{
            cout<< "INGRESE SUBAREA: ";
            getline(cin, _subArea);

            ///USAMOS UNA FUNCION DE < funcionesMain > YA QUE NOS SIRVE EN ESTE CASO
            valido = verificarCharString(_subArea);

        }while(valido);

        ///AUTORES
        do{
            cout<< "INGRESE NOMBRE DE AUTOR/ES ( EN FORMATO : AUTOR1-AUTOR2, etc): ";
            getline(cin, _autores);

            valido = validarAutores(_autores);

        }while(valido);

        ///EDITORIAL
        do{
            cout<< "INGRESE EDITORIAL: ";
            getline(cin, _editorial);

            ///USAMOS < validarAutores > YA QUE TIENE LAS MISMAS CARACTERESTICAS DE INGRESO
            valido = validarAutores(_editorial);

        }while(valido);

        ///ANIO PUBLICACION
        do{
            cout<< "INGRESE AÑO DE PUBLICACION: ";
            cin >> _anioP;

            ///USAMOS UNA FUNCION DE < funcionesMain > YA QUE TIENE LAS MISMAS CARACTERISTICAS DE INGRESO
            valido = verificarNumeroString(_anioP);

        }while(valido);

        ///UBICACION
        do{
            cout<< "INGRESE COLUMNA DE DONDE SE ENCUENTRA EL LIBRO: ";
            cin >> _ubi[0];
            cin.ignore();

            cout<< "INGRESE FILA DE DONDE SE ENCUENTRA EL LIBRO: ";
            cin >> _ubi[1];
            cin.ignore();

            valido = validarUbicacion(_ubi, vectorLibro);

        }while(valido);


    vectorLibro.push_back(libro(_nombre, _area, _subArea, _autores, _editorial, _anioP, _ubi, true) );
}

/**---------------------------------------------------------------------------------------------------*/

bool validarNombre(string _string){
    ///EL NOMBRE DEL LIBRO PUEDE INCLUIR LETRAS NUMERO Y > : < signo
    bool valido = false;

    ///PERMITIMOS EL INGGRESO DE MULTIPLES CARACTERES EXCEPTO LA COMA ','
    for(size_t i=0; i<_string.size(); i++){

        if(_string[i] == ','){
            cout<< "SOLO PERMITIDO CARACTES VALIDOS, la coma < , > ES UN CARACTER RESERVADO"<< endl;
            i = _string.size();
            valido = true;
        }
    }
    return valido;
}

/**---------------------------------------------------------------------------------------------------*/

bool validarAutores(string _string){

    bool valido = false;

    ///SE PERMITE EL INGRESO DE MAYUS- MINUS - '.'
     for(size_t i=0; i<_string.size(); i++){

        if( (_string[i] >= 'a' && _string[i] <= 'z') || ( _string[i] >= 'a' && _string[i] <= 'z') ||(_string[i] == ' ') || (_string[i] == '.') ){

        }else{
            cout<< "SOLO PERMITIDO CARACTES VALIDOS"<< endl;
            i = _string.size();
            valido = true;
        }
    }
    return valido;
}

/**---------------------------------------------------------------------------------------------------*/

bool validarUbicacion(int* ubi, vector <libro>& vectorLibro){

    bool valido = false;

    for(size_t i=0; i<vectorLibro.size(); i++){

        if(vectorLibro[i].getColumna() == ubi[0] && vectorLibro[i].getFila() == ubi[1]){
            cout<< "FILA Y COLUMNA YA ESTABLECIDA EN OTRO LIBRO"<< endl;
            i = vectorLibro.size();
            valido = true;
        }
    }
    return valido;
}

/**---------------------------------------------------------------------------------------------------*/
