// Reemplaza la función entera en Final/cargar_libros.cpp

#include "cargar_libros.h"
#include <vector>
#include <string>
#include "funcionesMain.h"
#include "funcionesLibro.h"

vector<libro> cargarLibro(string nombre_archivo) {
    ifstream archivoLibros(nombre_archivo);
    vector<libro> libros;
    string linea;
    char limitador = ',';

    if (!archivoLibros.is_open()) {
        cerr << "No se pudo abrir el archivo." << endl;
        return {};
    }

    getline(archivoLibros, linea); // Saltar encabezado

    while (getline(archivoLibros, linea)) {
        stringstream stream(linea);
        string nombre, area, subarea, autores, editorial, anio_de_publicacion, estado;

        // --- NUEVAS VARIABLES PARA LEER LOS DATOS ADICIONALES ---
        string columnaStr, filaStr, estadoSN_str;
        int columna = 0, fila = 0;
        bool estadoSN = false;


        getline(stream, nombre, limitador);
        nombre = borrar_comillas(nombre);

        getline(stream, area, limitador);
        area = quitar_tildes(area);

        getline(stream, subarea, limitador);
        getline(stream, autores, limitador);
        getline(stream, editorial, limitador);

        getline(stream, anio_de_publicacion, limitador);
        anio_de_publicacion = borrar_comillas(anio_de_publicacion);

        getline(stream, estado, limitador); // Leer el estado (Bueno, Malo, etc.)

        // --- NUEVO: LEER COLUMNA, FILA Y DISPONIBILIDAD ---
        getline(stream, columnaStr, limitador);
        getline(stream, filaStr, limitador);
        getline(stream, estadoSN_str, limitador);

        // Convertir la ubicación de string a int
        if (es_entero_valido(columnaStr)) {
            columna = stoi(columnaStr);
        }
        if (es_entero_valido(filaStr)) {
            fila = stoi(filaStr);
        }

        // Convertir la disponibilidad de string a bool
        if(estadoSN_str == "1"){
            estadoSN = true;
        }

        // --- CREACIÓN DEL OBJETO Y ASIGNACIÓN DE DATOS ---
        // Se crea el objeto libro con el constructor original
        libro objetoLibro(nombre, area, subarea, autores, editorial, anio_de_publicacion);

        // Se usan los setters para asignar los datos adicionales
        objetoLibro.setDato(estado, 7);
        objetoLibro.setDato_UBI(columna, fila);
        objetoLibro.setDato_estadoSN(estadoSN);


        libros.push_back(objetoLibro);
    }

    archivoLibros.close();
    return libros;
}
/**---------------------------------------------------------------------------------------------------*/
