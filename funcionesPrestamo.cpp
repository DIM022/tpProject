#include "funcionesPrestamo.h"
#include <sstream>

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
            validar = verificarExistenciaDniSocio(_dniSocio, vectorSocio);

            if(!validar){
                cout<< "DNI NO ENCONTRADO VERIFICAR SI ES CORRECTO Y/O EXISTENTE"<< endl;
            }
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
    vectorPrestamo.back().realizarPrestamo();

    //FECHA LIMITE DEL PRESTAMO
    cout<< "ESTABLECER FECHA DE DEVOLUCION: "<< endl;
    vectorPrestamo.back().establecerFechaPrestamo();

    cout<< "================"<< endl;
    cout<< "PRESTAMO ANIADIDO"<< endl;
    cout<< "================"<< endl;
    //TERMINAR
}

/**=====================================================================*/

void filtrarPrestamoTodo(vector <datoPrestamo>& vectorPrestamo){

    ///MUESTRA TOS LOS PRESTAMOS EXSTENES
    for(size_t i=0; i<vectorPrestamo.size(); i++){

        cout<< "--------------------------"<< endl;
        vectorPrestamo[i].mostrarPrestamo();
        cout<< "--------------------------"<< endl;
    }

    ///EN CASO DE QUE NO HALLA
    ///RETORNAMOS UN MENSAJE
    if(!vectorPrestamo.size()){

        cout<< "NO HAY PRESTAMOS HECHOS"<< endl;
    }
}

/**=====================================================================*/

void filtrarPrestamoLibro(vector <datoPrestamo>& vectorPrestamo){

    string _libroBusqueda;
    bool valido = true;

    ///VERIFICAMOS QUE EXISTA ALGUN PRESTAMO
    if(!vectorPrestamo.size()){

        cout<< "NO HAY PRESTAMOS HECHOS"<< endl;

    }else{

        ///EN CASO QUE EXISTA
        ///BUSCAMOS

        cout<< "INGRESE NOMBRE DEL LIBRO A FILTRAR: ";
        cin >> _libroBusqueda;

        for(size_t i=0; i<vectorPrestamo.size(); i++){

            if( _libroBusqueda == vectorPrestamo[i].getNombreLibro() ){

                cout<< "--------------------------"<< endl;
                vectorPrestamo[i].mostrarPrestamo();
                cout<< "--------------------------"<< endl;
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
}

/**=====================================================================*/

void filtrarPrestamoSocio(vector <datoPrestamo>& vectorPrestamo){

    string _dniBusqueda;
    bool valido = true;

    ///VERIFICAMOS QUE EXISTAN PRESTAMOS
    if(!vectorPrestamo.size()){

        cout<< "NO HAY PRESTAMOS HECHOS"<< endl;

    }else{

        ///EN CASO DE QUE HALLA
        ///BUSCAMOS

        cout<< "INGRESE DNI A FILTRAR: ";
        cin >> _dniBusqueda;

        ///RECORRE EL VECTOR
        for(size_t i=0; i<vectorPrestamo.size(); i++){

            ///SI CINCIDE ENTRA
            if( _dniBusqueda == vectorPrestamo[i].getDni() ){

                cout<< "--------------------------"<< endl;
                vectorPrestamo[i].mostrarPrestamo();
                cout<< "--------------------------"<< endl;
                i = vectorPrestamo.size();
                valido = false;
            }
        }

        ///EN CASO QUE NO COINCIDA NINGUNA BUSQUEDA
        ///RETORNAMOS UN MENSAJE
        if(valido){
            cout<< "=============================="<< endl;
            cout<< "NO SE ENCONTRO NINGUN PRESTAMO ASOCIADO A ESE DNI"<< endl;
            cout<< "=============================="<< endl;
        }

    }
}

/**=====================================================================*/

void filtrarPrestamoFecha(vector <datoPrestamo>& vectorPrestamo){

    tm fechaBusqueda = {};
    int _dia = 0, _mes = 0, _anio = 0;
    bool valido = true;

    ///VERIFICAMOS QUE EXISTAN PRESTAMOS
    if(!vectorPrestamo.size()){

        cout<< "NO HAY PRESTAMOS HECHOS"<< endl;

    }else{
        ///EN CASO DE QUE HAYA UN PRESTAMO
        ///BUSCAMOS

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

        ///RECORREMOS TODO EL VECTOE
        for(size_t i=0; i<vectorPrestamo.size(); i++){

            ///SI COINCIDE ENTR
            if(vectorPrestamo[i] == fechaBusqueda){

                cout<< "--------------------------"<< endl;
                vectorPrestamo[i].mostrarPrestamo();
                cout<< "--------------------------"<< endl;
                i = vectorPrestamo.size();
                valido = false;
            }
        }

        ///EN CASO DE HABER COINCIDENCIAS RETORNAMOS UN MENSAJE
        if(valido){

            cout<< "=============================="<< endl;
            cout<< "NO SE ENCONTRO NINGUN PRESTAMO ASOCIADO A ESA FECHA"<< endl;
            cout<< "=============================="<< endl;
        }
    }
}

/**=====================================================================*/
bool verificarExistenciaDniSocio(const string& dniBuscado, const vector<socio>& vectorSocio) {
    // Reutilizamos la función que ya existe para buscar por DNI.
    // La función buscarIndicePorDNI devuelve -1 si no encuentra el socio.
    // Si devuelve cualquier otro número (0 o más), significa que el socio existe.
    if (buscarIndicePorDNI(vectorSocio, dniBuscado) != -1) {
        return true; // El socio fue encontrado.
    } else {
        return false; // El socio NO fue encontrado.
    }
}

bool verificarExistenciaNombreLibro(string _nombreLibro, vector <libro>& vectorLibro){

    ///RECORRE TODO EL VECTOR
    for(size_t i=0; i<vectorLibro.size(); i++){

        ///SI ENCUENTRA EL QUE BUSCAMOS ENTRA
        if( _nombreLibro == vectorLibro[i].get_nombre() ){

            ///1 - TRUE ( DISPONIBLIE ) // 2 - FALSE ( NO DISPONIBLE )
            ///SI ENTRA AL IF = TRUE --- EL LIBRO ESTA DISPONIBLE
            if(vectorLibro[i].getEstadoSN()){

                ///MODIFICAMOS EL ESTADO DEL LIBRO
                ///COMO FALSE
                ///PARA QUE NO PUEDA SER ALQUILADO MULTIPLES VECES
                vectorLibro[i].setDato_estadoSN(false);
                i = vectorLibro.size();
                return false;

            }else{
                i = vectorLibro.size();
                cout<< "LIBRO NO DISPONIBLE YA ALQUILADO"<< endl;
                cout<< "INGRESE OTRO LIBRO Y/O TERMINE EL REGISTRO DE PRESTAMO"<< endl;
                return true;
            }

        }
    }

    cout<< "NO SE ENCONTRO EL NOMBRE INGRESADO CON NINGUN LIBRO"<< endl;
    return true;
}

/**=====================================================================*/

///ESTABLECE LOS PARAMETROS COMO UNA FECHA VALIDA
///PARA QUE PUEDA SER COMPARADO
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
/// ANiO : SUMA EL NUM INGRESADO + 1900 ( 2025 - 1900 = 125 + 1900 = 2025)
    mes = mes - 1;
    anio -= 1900;

///LE ASIGNAMOS LOS DATOS AL PBJETO
    fechaBusquda.tm_mday = dia;
    fechaBusquda.tm_mon = mes;
    fechaBusquda.tm_year = anio;

///LE ASIGNAMOS LOS TIEMPOS EN 0 PARA EVITAR ERRORES
    fechaBusquda.tm_sec = 0;
    fechaBusquda.tm_min = 0;
    fechaBusquda.tm_hour = 0;

    return fechaBusquda;
}
void subirCambiosPrestamos(const vector<datoPrestamo>& vectorPrestamo) {
    ofstream archivo("C:/Users/Urano/Documents/Final/prestamos.csv");
    if (!archivo.is_open()) return;

    archivo << "dni,libro,fecha_inicio,fecha_fin\n"; // Escribir cabecera
    for (const auto& prestamo : vectorPrestamo) {
        archivo << prestamo.stringFile() << "\n";
    }
    archivo.close();
}

tm parsearFecha(const string& fecha_str) {
    tm fecha_tm = {}; // Inicializa la estructura a ceros

    // Si la fecha está vacía o es la de por defecto, no hagas nada
    if (fecha_str.empty() || fecha_str == "0/1/1900") {
        return fecha_tm;
    }

    stringstream ss(fecha_str);
    string dia_str, mes_str, anio_str;

    // Extraemos día, mes y año usando '/' como delimitador
    getline(ss, dia_str, '/');
    getline(ss, mes_str, '/');
    getline(ss, anio_str);

    try {
        // Convertimos las partes a enteros y las asignamos
        fecha_tm.tm_mday = std::stoi(dia_str);
        fecha_tm.tm_mon = std::stoi(mes_str) - 1; // tm_mon va de 0 a 11
        fecha_tm.tm_year = std::stoi(anio_str) - 1900; // tm_year cuenta años desde 1900
    } catch (const std::exception& e) {
        // Si hay un error en la conversión, devuelve la fecha vacía
        std::cerr << "Error al parsear la fecha: " << fecha_str << std::endl;
        return {};
    }

    return fecha_tm;
}

vector<datoPrestamo> cargarPrestamos(const string& nombre_archivo) {
    vector<datoPrestamo> prestamos;
    ifstream archivo(nombre_archivo);
    if (!archivo.is_open()) {
        cout << "Error: No se pudo abrir el archivo de prestamos " << nombre_archivo << endl;
        return prestamos;
    }

    string linea;
    getline(archivo, linea); // Saltar la línea de la cabecera (header)

    while (getline(archivo, linea)) {
        if (linea.empty()) continue; // Ignorar líneas vacías

        stringstream stream(linea);
        string dni, libro, fecha_inicio_str, fecha_fin_str;

        getline(stream, dni, ',');
        getline(stream, libro, ',');
        getline(stream, fecha_inicio_str, ',');
        getline(stream, fecha_fin_str, ',');

        // Se crea el objeto préstamo con su constructor
        datoPrestamo p(libro, dni);

        // --- INICIO DE LA CORRECCIÓN ---
        // 1. Convertimos las fechas leídas (string) a estructuras tm
        tm fecha_inicio_tm = parsearFecha(fecha_inicio_str);
        tm fecha_fin_tm = parsearFecha(fecha_fin_str);

        // 2. Asignamos esas estructuras tm al objeto usando los setters
        p.setFechaInicio(fecha_inicio_tm);
        p.setFechaFinal(fecha_fin_tm);
        // --- FIN DE LA CORRECCIÓN ---

        // Añadimos el objeto ya completo al vector
        prestamos.push_back(p);
    }
    archivo.close();
    return prestamos;
}


