#include "cargar_libros.h"

///FUNCION QUE RETORNA UN VECTOS < LIBRO >
vector<libro> cargarLibro(string nombre_archivo){

    ifstream archivoLibros;
    string linea;
    char limitador = ',';

    archivoLibros.open(nombre_archivo);

    if(!archivoLibros.is_open()){
        cout<<"No se pudo abrir el archivo."<<endl;
    }

    //ARRAY DINAMICO
    vector<libro> libros;

    getline(archivoLibros, linea);//TOMA LA PRIMERA LINEA QUE NO NECESITAMOS

    ///LEE TODAS LAS LINEAS
    while(getline(archivoLibros, linea)){

    stringstream stream(linea);

    string nombre, area, subarea, autores, editorial, anio_de_publicacion;

    ///PARAMETROS :
    ///STREAM : DONDE SE ENCUETRAN LOS DATOS
    // NOMBRE : STRING DONDE SE ALMACENA
    // LIMITADOR : INDICA HASTA QUE PUNTO LEERA

    ///LEE HASTA DONDE SE DEJO Y CONTINUA DESDE AHI
    ///POR ESO NOS PERMITE ALMACENAR SUS DATOS EN VARIBALES
    getline(stream, nombre, limitador);
    ///LLAMAMOS A LA FUNCION
    nombre = borrar_comillas(nombre);

    getline(stream, area, limitador);
    area = quitar_tildes(area);

    getline(stream, subarea, limitador);
    getline(stream, autores, limitador);
    getline(stream, editorial, limitador);

    getline(stream, anio_de_publicacion, limitador);
    anio_de_publicacion = borrar_comillas(anio_de_publicacion);

    ///CREAMOS UN OBJETO DE TIPO LIBRO LLAMADO < objetoLibro>
    libro objetoLibro(nombre, area, subarea, autores, editorial, anio_de_publicacion);

    libros.push_back(objetoLibro);

    }

    ///CERRAMOS EL ARCHIVO
    //YA QUE NO LO USAMOS MAS
    archivoLibros.close();

    return libros;
}
