#include "gestionVectorLibro.h"


void inicioAperturaLibro(vector <libro>& vectorLibro, int& contRepeL){

    ///ASEGURA QUE SE CARGUE EL LIBRO UNA SOLA VEZ PARA EVITAR
    ///ACTUALIZACIONES NO BUSCADAS
    if(!contRepeL){
        //ABRE Y RETORNA UN VECTOR DE LIBRO
        vectorLibro = cargarLibro(ARCHIVO_LIBROS);

        contRepeL++;
    }

}

/**---------------------------------------------------------------------------------------------------*/

void agregarLibro(vector<libro>& vectorLibro){

    bool valido = true;
    string _nombre, _area, _subArea, _autores, _editorial, _anioP;
    int _ubi[2];

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

            valido = fecha_valida(_anioP);

            ///NEGAMOS VALIDO YA QUE LA FUNCION FECHA_VALIDA DELVUELDE TRUE SI ES CORRECTO EL INGRESO
        }while(!valido);

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

void modificarLibro(int flagDNI, vector<libro>& vectoLibro){

    string nuevoValor;///ALMACENA EL NUEVO VALOR
    int posDato = 0, colu = 0, fila = 0;
    int _ubi[2];
    bool valido = true;
    bool est;

    do{
        cout<< "-----------------------------------------------"<< endl;
        cout<< "QUE CAMPO QUIERE MODIFICAR: "<< endl
            << "1-NOMBRE  2-AREA   3-SUBAREA   4-AUTORES "
            << "5-EDITORIA  6-AÑO DE PUBLICACION\n 7-UBICACION  8-ESTADO (DISPOPNIBLE / NO DISPONIBLE )  9-SALIR"<< endl;
        cout<< "------"<< endl<< ">";
        cin >> posDato;

        ///IGNORA EL ENTER PARA EVITAR LEERLO
        cin.ignore();

        if(posDato == 9){
            valido = false;

        }else if(posDato >= 1 && posDato <= 6){

            cout<< "INGRESE EL NUEVO VALOR : ";
            getline(cin, nuevoValor);

            ///PARAMETROS : EL VALOR NUEVO, Y LA OPCION DEL DATO A CAMBIAR
            vectoLibro[flagDNI].setDato(nuevoValor, posDato);

        }else if(posDato == 7){

            do{
                cout<< "INGRESE COLUMNA DONDE SE UBICARA EL LIBRO: ";
                cin >> colu;
                cin.ignore();

                cout<< "INGRESE FILA DONDE UBICARA EL LIBRO: ";
                cin >> fila;
                cin.ignore();

                _ubi[0] = colu;
                _ubi[1] = fila;
                ///VERIFICAMOS QUE NO ESTE EN USO ESA FILA Y COLUMNA
                valido = validarUbicacion(_ubi, vectoLibro);

                if(valido){
                    cout<< "COLUMNA Y FILA YA UTILIZADOS.."<<endl;
                }

            }while(valido);

                vectoLibro[flagDNI].setDato_UBI(colu, fila);

        }else if(posDato == 8){

                cout<< "1/DISPONIBLE   2/NO DISPONIBLE";
                cin >>posDato;
                cin.ignore();

                if(posDato == 1){
                    est = true;
                    vectoLibro[flagDNI].setDato_estadoSN(est);

                }else if(posDato == 2){
                    est = false;
                    vectoLibro[flagDNI].setDato_estadoSN(est);

                }else{
                    cout<< "OPCION INCORRECTA"<< endl;
                }

        }else{
            cout<< endl<< "======================"<< endl;
            cout<< "OPCION INVALIDA < MENU MODIFCAR ( FUNCION ) >"<< endl;
            cout<< endl<< "======================"<< endl;
        }

    }while(valido);
}

/**---------------------------------------------------------------------------------------------------*/

void subirCambiosLibro(vector <libro>& vectorLibro){

    fstream file;
        ///LIBRO
        ///OUT PARA ESCRIBIR Y TRUNC PARA ELIMINAR EL CONTENIDO ANTERIOIR DEL ARCHIVO
        file.open("lista_libros.csv", ios::out | ios::trunc);

        for(size_t i=0; i<vectorLibro.size(); i++){

            ///ALMACENAMOS EN ARCHIVO --- stringFile
            ///stringFile -- CONVIERTE LOS ATRIBUTOS DEL OBJETO EN UN STRING QUE RETORNA
            file << vectorLibro[i].stringFile()<<'\n';
        }

        file.close();
}
