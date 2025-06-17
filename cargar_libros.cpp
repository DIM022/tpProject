#include "cargar_libros.h"

///FUNCION QUE RETORNA UN VECTOS < LIBRO >
vector<libro> cargarLibro(string nombre_archivo){

    ifstream archivoLibros;
    string linea;
    char limitador = ',';
    int contador_estado = 0;
    int contador_disponibilidad = 0;
    int contador_ubicacion = 0;
    
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
    int cantidad_campos = contar_campos(linea);
    string nombre, area, subarea, autores, editorial, anio_de_publicacion;

    string estado, estadoSN_string, ubicacion_string; //los atributos q agregamos
    ///PARAMETROS :
    ///STREAM : DONDE SE ENCUETRAN LOS DATOS
    // NOMBRE : STRING DONDE SE ALMACENA
    // LIMITADOR : INDICA HASTA QUE PUNTO LEERA

    ///LEE HASTA DONDE SE DEJO Y CONTINUA DESDE AHI
    ///POR ESO NOS PERMITE ALMACENAR SUS DATOS EN VARIBALES
    //separamos la ubicacion para el array


    ///CREAMOS UN OBJETO DE TIPO LIBRO LLAMADO < objetoLibro>
    if(cantidad_campos <= 6){
        getline(stream, nombre, limitador);

         nombre = borrar_comillas(nombre);

        getline(stream, area, limitador);

        area = quitar_tildes(area);
        getline(stream, subarea, limitador);
        subarea = borrar_comillas(subarea);
        getline(stream, estado, limitador);
        getline(stream, ubicacion_string, limitador);
        getline(stream, estadoSN_string);
        int ubicacion[2];
        cambiar_ubicacion(ubicacion_string, ubicacion);

         bool estadoSN = ( estadoSN_string == "si");//si es "si" da true, caso contrario false

        libro objetoLibroCorto(nombre, area, subarea, estado, ubicacion, estadoSN);//creamos el libro

        libros.push_back(objetoLibroCorto);//Lo mandamos al final
    }else{
    getline(stream, nombre, limitador);

    nombre = borrar_comillas(nombre);

    getline(stream, area, limitador);

    area = quitar_tildes(area);

    getline(stream, subarea, limitador);

    subarea = borrar_comillas(subarea);

    getline(stream, autores, limitador);

    getline(stream, editorial, limitador);

    getline(stream, anio_de_publicacion, limitador);
    anio_de_publicacion = borrar_comillas(anio_de_publicacion);

    getline(stream, estado, limitador);
    getline(stream, ubicacion_string, limitador);
    getline(stream, estadoSN_string);
    int ubicacion[2];
    cambiar_ubicacion(ubicacion_string, ubicacion);
     bool estadoSN = ( estadoSN_string == "si");//si es "si" da true, caso contrario false
     
    libro objetoLibro(nombre, area, subarea, autores, editorial, anio_de_publicacion, estado, ubicacion, estadoSN);
    libros.push_back(objetoLibro);
    }
    }

    ///CERRAMOS EL ARCHIVO
    //YA QUE NO LO USAMOS MAS
    archivoLibros.close();

    return libros;
}
