#include "prestamoFormato.h"

/**=====================================================================*/

///ESTABLECE LA FECHA DE DEVOLUCION DEL PRESTAMO
void datoPrestamo::establecerFechaPrestamo(){

    int dia = 0, mes = 0, anio = 0;
    bool valido = false;

///VERIFICAMOS EL INGRESO DE VALORESVALIDO PARA UNA FECHA
    do{
        valido = false;
        cout<< "INGRESE DIA:  ";
        cin >> dia;
        cin.ignore();

        if(dia <= 0 || dia > 31){

            cout<< "EL DIA DEBE SER MAYOR A 0 Y MENOR A 31"<< endl;
            valido = true;
        }
    }while(valido);

    do{
        valido = false;
        cout<< "INGRESE MES:  ";
        cin >> mes;
        cin.ignore();

        if(mes <= 0 || mes > 12){

            cout<< "EL MES DEBE SER MAYOR A 0 Y MENOR A 12"<< endl;
            valido = true;
        }
    }while(valido);

    do{
        valido = false;
        cout<< "INGRESE AÑO:  ";
        cin >> anio;
        cin.ignore();

        if( anio < fechaInicio.tm_year+1900){

            cout<< "INGRESE UN ANIO MAYOR A 2025"<< endl;
            valido = true;
        }

    }while(valido);

///MODIFICAMOS EL VALOR YA QUE
/// MES : EMPIEZA DESDE 0 ( 0 - ENERO && 11 - DICIEMBRE
/// AÑO : SUMA EL NUM INGRESADO + 1900 ( 2025 - 1900 = 125 + 1900 = 2025)
    mes = mes - 1;
    anio -= 1900;

///VERIFICAMOS / VALIDAMOS LA FECHA VALIDA
    do{
        valido = false;

        if(anio == fechaInicio.tm_year){

            if(mes < fechaInicio.tm_mon){

                valido = true;
                cout<< "INGRESE UN MES VALIDO"<< endl;
                cout<< "INGRESE UN MES:  ";
                cin >> mes;
                cin.ignore();
                mes -=1;

            }else if(mes == fechaInicio.tm_mon){

                if(dia <= fechaInicio.tm_mday){

                    valido = true;
                    cout<< "INGRESE UN DIA VALIDO"<< endl;
                    cout<< "INGRESE UN DIA:  ";
                    cin >> dia;
                    cin.ignore();
                }
            }
        }
    }while(valido);

///LE ASIGNAMOS LOS DATOS AL PBJETO
    fechaFinal.tm_mday = dia;
    fechaFinal.tm_mon = mes;
    fechaFinal.tm_year = anio;
}

/**=====================================================================*/

///ESTABLECEMOS LA FECHA EN LA QUE SE ESTA
///PRESTANDO EL LIBRO
void datoPrestamo::realizarPrestamo(){

    time_t timeS = time(nullptr);
    tm* timeT = localtime(&timeS);

    fechaInicio = *timeT;

    getFechaInicio();
}

/**=====================================================================*/

///SIRVE PARA CONSULTAR LOS DIAS FALTANTES HASTA LA DEVOLUCION
void datoPrestamo::getDevolucion(){

    double segu = 0;
    int diasDevolucion = 0;

    ///GUARDAMOS EN SEGUNDOS DESDE 1900 - ACTUALIDAD
    time_t seg = time(nullptr);

    ///GUARDAMOS EL TIEMPO DEL MOMENTO EN EL QUE SE REVISA EL VENCIMIENTO
    tm* ahora = localtime(&seg);

///ESTABLECEMOS LOS HORARIOS EN 0 PARA QUE NO ALTENREN LOS DATS
    ahora->tm_sec = 0;
    ahora->tm_min = 0;
    ahora->tm_hour = 0;

    fechaFinal.tm_sec = 0;
    fechaFinal.tm_min = 0;
    fechaFinal.tm_hour = 0;

///PASAMOS ESOS DIAS A SEUNDOS
    time_t fechaF = mktime(&fechaFinal);
    time_t fechaI = mktime(ahora);

///GUARDAMOS ESA DIFERENCIA DE SEGUNDOS
    segu = difftime(fechaF, fechaI);

///Y LA CONVERTIMOS EN DIAS
    diasDevolucion = segu / (60 * 60 * 24);

    if(diasDevolucion){

        cout<< "DIAS HASTA LA DEVOLUCION: "<< diasDevolucion<< endl;
        getFechaFinal();
    }else{

        cout<< "YA PASO LA FECHA DE DEVOLUCION: ";
        getFechaFinal();
    }

}

/**=====================================================================*/

void datoPrestamo::getFechaInicio(){

    cout<< endl<< "FECHA DEL PRESTAMO"<< endl;
    cout<< fechaInicio.tm_mday<< "/"<< fechaInicio.tm_mon+1<< "/"<< fechaInicio.tm_year+1900<< endl;
}

/**=====================================================================*/

void datoPrestamo::getFechaFinal(){

    cout<< endl<< "FECHA DE DEVOLUCION"<< endl;
    cout<< fechaFinal.tm_mday<< "/"<< fechaFinal.tm_mon+1<< "/"<< fechaFinal.tm_year+1900<< endl;
}

/**=====================================================================*/

string datoPrestamo::getDni(){

    return dniSocio;
}

/**=====================================================================*/

string datoPrestamo::getNombreLibro(){

    return nombreLibro;
}

/**=====================================================================*/

void datoPrestamo::mostrarPrestamo(){

    cout<< "DNI: "<< dniSocio<< endl
        << "LIBRO: "<< nombreLibro<< endl;
        getFechaInicio();
        getFechaFinal();
}

/**=====================================================================*/

datoPrestamo::datoPrestamo(string _nombrelibro, string nombreSocio): nombreLibro(_nombrelibro), dniSocio(nombreSocio) {
    fechaInicio = {};
    fechaFinal = {};
}

/**=====================================================================*/

datoPrestamo::~datoPrestamo(){

}

/**=====================================================================*/

bool datoPrestamo::operator==(tm& otro){

    if( (fechaFinal.tm_mday == otro.tm_mday) && (fechaFinal.tm_mon == otro.tm_mon) && (fechaFinal.tm_year == otro.tm_year) ){

        return true;
    }
    return false;
}

/**=====================================================================*/
