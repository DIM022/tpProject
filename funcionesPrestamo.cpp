#include "funcionesPrestamo.h"

/**=====================================================================*/

void registrarPrestamo(vector <datoPrestamo>& vectorPrestamo, vector <socio>& vectorSocio, vector <libro>& vectorLibro){

    string _dniSocio;
    string _nombreLibro;
    bool validar = false;

    cout<< "========================="<<endl;
    cout<< "INGRESO DE NUEVO PRESTAMO"<< endl;
    cout<< "========================="<<endl;

//TOMAMOS LOS DATOS NECESARIOS
    do{
        cout<< "DNI DEL SOCIO: ";
        cin >> _dniSocio;
        cin.ignore();

        //USAMOS ALGUBAS FUBCUIBES DEL < FUNCIONES MAIN >
        validar = verificarNumeroString(_dniSocio);

        //SI EL INGRESO ES CORRECTO = false
        //ENTONVES VALIDAMOS SU EXISTENCIA COMPARANDOLO CON VECTOR SOCIO
        if(!validar){
            validar = verificarExistenciaNombreSocio(_dniSocio, vectorSocio);
        }

    }while(validar);

    do{
        cout<< "NOMBRE DEL LIBRO: ";
        cin >> _nombreLibro;
        cin.ignore();

        //USAMOS ALGUBAS FUBCUIBES DEL < gestionVectorLibro >
        validar = validarNombre(_nombreLibro);

        if(!validar){
            validar = verificarExistenciaNombreLibro(_nombreLibro, vectorLibro);
        }

    }while(validar);

    //COLOCAMOS LOS DATOS EN EL CONSTRUCTOR Y
    //SE CREA AGREGA UN OBJETO EN LA UTIMA POSICION DEL VECTOR
    vectorPrestamo.push_back(datoPrestamo(_nombreLibro, _dniSocio));

    //LLAMOS A ESA ULTIMA CLASE Y ESTABLECEMOS LAS FECHAS

    //FECHA DE INICIO PRESTAMO
    vectorPrestamo.back().realizarPrestamo();///GUARDAMOS LA FECHA ACTUAL DE PRESTAMO

    //FECHA MAXIMA DEL PRESTAMO
    vectorPrestamo.back().establecerFechaPrestamo();///ESTABLECER LA FECHA LIMITE DEL PRESTAMO

    cout<< "================"<< endl;
    cout<< "PRESTAMO AÑADIDO"<< endl;
    cout<< "================"<< endl;
    //TERMINAR
}

/**=====================================================================*/

void filtrarPrestamoLibro(vector <datoPrestamo>& vectorPrestamo){

    string _libroBusqueda;
    bool valido = true;

    cout<< "INGRESE NOMBRE DEL LIBRO A FILTRAR: ";
    cin >> _libroBusqueda;

    for(size_t i=0; i<vectorPrestamo.size(); i++){

        if( _libroBusqueda == vectorPrestamo[i].getNombreLibro() ){

            vectorPrestamo[i].mostrarPrestamo();
            i = vectorPrestamo.size();
            valido = false;
        }
    }

      if(valido){

        cout<< "=============================="<< endl;
        cout<< "NO SE ENCONTRO NINGUN PRESTAMO ASOCIADO A ESE LIBRO"<< endl;
        cout<< "=============================="<< endl;
    }
}

/**=====================================================================*/

void filtrarPrestamoSocio(vector <datoPrestamo>& vectorPrestamo){

    string _dniBusqueda;
    bool valido = true;

    cout<< "INGRESE DNI A FILTRAR: ";
    cin >> _dniBusqueda;

    for(size_t i=0; i<vectorPrestamo.size(); i++){

        if( _dniBusqueda == vectorPrestamo[i].getDni() ){

            vectorPrestamo[i].mostrarPrestamo();
            i = vectorPrestamo.size();
            valido = false;
        }
    }

      if(valido){
        cout<< "=============================="<< endl;
        cout<< "NO SE ENCONTRO NINGUN PRESTAMO ASOCIADO A ESE DNI"<< endl;
        cout<< "=============================="<< endl;
    }

}

/**=====================================================================*/

bool verificarExistenciaNombreSocio(string _string, vector <socio>& vectorSocio){

    for(size_t i=0; i<vectorSocio.size(); i++){

        if(_string == vectorSocio[i].getdni() ){

            i = vectorSocio.size();
            return false;
        }
    }

    cout<< "NO SE ENCONTRO EL DNI INGRESADO CON NINGUN SOCIO"<< endl;
    return true;
}

/**=====================================================================*/

bool verificarExistenciaNombreLibro(string _nombreLibro, vector <libro>& vectorLibro){

    for(size_t i=0; i<vectorLibro.size(); i++){

        if( _nombreLibro == vectorLibro[i].get_nombre() ){

            i = vectorLibro.size();
            return false;
        }
    }

    cout<< "NO SE ENCONTRO EL NOMBRE INGRESADO CON NINGUN LIBRO"<< endl;
    return true;
}

/**=====================================================================*/

void filtrarPrestamoFecha(vector <datoPrestamo>& vectorPrestamo){

    tm fechaBusqueda = {};
    int _dia = 0, _mes = 0, _anio = 0;
    bool valido = true;

    cout<< "INGRESE LA FECHA A BUSCAR: "<< endl;
    cout<< "DIA";
    cin >> _dia;
    cin.ignore();

    cout<< "MES";
    cin >> _mes;
    cin.ignore();

    cout<< "ANIO";
    cin >> _anio;
    cin.ignore();

    ///LLAMAMOS A FUNCION QUE VALIDE Y ESTABLESCA LA FECHA
    fechaBusqueda = establecerFechaFuncion(_dia, _mes, _anio);

    ///LLAMAMOS AL OPERADOR SOBRECARGADO

    for(size_t i=0; i<vectorPrestamo.size(); i++){

        if(vectorPrestamo[i] == fechaBusqueda){

            i = vectorPrestamo.size();
            vectorPrestamo[i].mostrarPrestamo();
            valido = false;
        }
    }
    if(valido){

        cout<< "=============================="<< endl;
        cout<< "NO SE ENCONTRO NINGUN PRESTAMO ASOCIADO A ESA FECHA"<< endl;
        cout<< "=============================="<< endl;
    }
}

/**=====================================================================*/

tm establecerFechaFuncion(int dia, int mes, int anio){

    bool validar = false;

    tm fechaBusquda = {};
///VERIFICAMOS EL INGRESO DE VALORESVALIDO PARA UNA FECHA
    do{
        validar = false;
        if(dia <= 0 || dia > 31){

            cout<< "EL DIA DEBE SER MAYOR A 0 Y MENOR A 31"<< endl;
            validar = true;

            cout<< "INGRESE DIA: ";
            cin >> dia;
            cin.ignore();
        }
    }while(validar);

    do{
        validar = false;
        if(mes <= 0 || mes > 12){

            cout<< "EL MES DEBE SER MAYOR A 0 Y MENOR A 12"<< endl;
            validar = true;

            cout<< "INGRESE MES: ";
            cin >> mes;
            cin.ignore();
        }
    }while(validar);

///MODIFICAMOS EL VALOR YA QUE
/// MES : EMPIEZA DESDE 0 ( 0 - ENERO && 11 - DICIEMBRE
/// AÑO : SUMA EL NUM INGRESADO + 1900 ( 2025 - 1900 = 125 + 1900 = 2025)
    mes = mes - 1;
    anio -= 1900;

///LE ASIGNAMOS LOS DATOS AL PBJETO
    fechaBusquda.tm_mday = dia;
    fechaBusquda.tm_mon = mes;
    fechaBusquda.tm_year = anio;

    fechaBusquda.tm_sec = 0;
    fechaBusquda.tm_min = 0;
    fechaBusquda.tm_hour = 0;

    return fechaBusquda;
}
