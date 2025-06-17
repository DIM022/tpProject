#include "funcionesPrestamo.h"

void registrarPrestamo(vector <datoPrestamo>& vectorPrestamo, vector <socio>& vectorSocio, vector <libro>& vectorLibro){

    string _dniSocio;
    string _nombreLibro;
    int intTam = 0;
    bool validar = false;
    bool valido = false;

    cout<< "========================="<<endl;
    cout<< "INGRESO DE NUEVO PRESTAMO"<< endl;
    cout<< "========================="<<endl;

    do{
        cout<< "DNI DEL SOCIO: ";
        getline(cin, _dniSocio);
        cin.ignore();

        validar = verificarNumeroString(_dniSocio);

        if(!validar){
            validar = verificarExistenciaNombreSocio(_dniSocio, vectorSocio);
        }

    }while(validar);

    do{
        cout<< "NOMBRE DEL LIBRO: ";
        cin >> _nombreLibro;
        cin.ignore();

        valido = validarNombre(_nombreLibro);

        if(!valido){
             valido = verificarExistenciaNombreLibro(_nombreLibro, vectorLibro);
        }

    }while(valido);

    vectorPrestamo.push_back(datoPrestamo(_nombreLibro, _dniSocio));

    vectorPrestamo.back().realizarPrestamo();///GUARDAMOS LA FECHA ACTUAL DE PRESTAMO
    vectorPrestamo.back().establecerFechaPrestamo();///ESTABLECER LA FECHA LIMITE DEL PRESTAMO

    cout<< "================"<< endl;
    cout<< "PRESTAMO A�ADIDO"<< endl;
    cout<< "================"<< endl;

}

bool verificarExistenciaNombreLibro(string _nombreLibro, vector <libro>& vectorLibro){

    for(size_t j=0; j<vectorLibro.size(); j++){

        if( _nombreLibro == vectorLibro[j].get_nombre() ){

            j = vectorLibro.size();
            return false;
        }
    }

    cout<< "NO SE ENCONTRO EL NOMBRE INGRESADO CON NINGUN LIBRO"<< endl;
    return true;
}

bool verificarExistenciaNombreSocio(string _string, vector <socio>& vectorSocio){

    for(size_t i=0; i<vectorSocio.size(); i++){
        cout << "conparando con: "<<vectorSocio[i].getdni()<<endl;
        if(_string == vectorSocio[i].getdni()){

            i = vectorSocio.size();
            return false;
        }
    }

    cout<< "NO SE ENCONTRO EL DNI INGRESADO CON NINGUN SOCIO"<< endl;
    return true;
}
