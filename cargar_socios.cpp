#include "cargar_socios.h"

///DEVULVE UN VECTOR SOCIO
///PARAMETRO : NOMBRE DEL ARCHIVO
vector<socio> cargarSocio(string nombre_archivo) {

    ifstream archivoSocios;
    string linea;
    char limitador = ',';

    ///ABRIMOS EL ARCHIVO
    archivoSocios.open(nombre_archivo);

    if (!archivoSocios.is_open()) {
        cout << "No se pudo abrir el archivo." << endl;
    }

    // array dinamico del objeto de la clase socio(<socio>) llamado socios
    vector<socio> socios;

    getline(archivoSocios, linea); // primera linea (parametros)

    while (getline(archivoSocios, linea)) { // todas las lineas
        stringstream stream(linea); // operaciones de I/O en cadenas de texto

        string apellido, dni, sexo, direccion, numero_telefono, mail, fechaN, edad;
        int posicionA = 0;

        getline(stream, apellido, limitador);
        getline(stream, dni, limitador);
<<<<<<< HEAD
    
        while (!dni.empty() && isspace(dni.back())) {//isspace devuelve true si es ' ', \n, \t, \r
        dni.pop_back();//elimina el ultimo caracter
    }
        while (!dni.empty() && isspace(dni.front())) {
        dni.erase(dni.begin());//begin, el primer elemento, lo borramos con erase
}

=======
>>>>>>> MenuPrestamos
        getline(stream, sexo, limitador);
        getline(stream, direccion, limitador);
        direccion = borrar_comillas(direccion);
        getline(stream, numero_telefono, limitador);
        numero_telefono = borrar_comillas(numero_telefono);
        getline(stream, edad, limitador);
        getline(stream, fechaN, limitador);
        getline(stream, mail, limitador);

        posicionA++;

        socio socioo(apellido, dni, sexo, direccion, numero_telefono, edad, fechaN, mail, posicionA);

        socios.push_back(socioo); // lo mandamos al final del vector socios
    }

    archivoSocios.close();

    ///DEVUELVE EL VECTOR SOCIO
    return socios;
}
