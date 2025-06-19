#include "funcionesLibro.h"

using namespace std;

/**---------------------------------------------------------------------------------------------------*/

//RETORNA EL STIRNG A MIINUSCULAS
string a_minusculas(string texto){

    //size() devuelve un unsigned long, o size_t y size_t segun el entorno de ejecucion puede ser uns long,
    //un int, un long long
    for( size_t i = 0;i<texto.size(); i++){

        //la pos 0 ej:C va a ser =  c
        texto[i] = tolower(texto[i]);
    }
    return texto ;
}

/**---------------------------------------------------------------------------------------------------*/

string borrar_comillas(string texto){

    string salida = "";

    //recorre el texto c por c(char)
    for(char c : texto){

        //si c es distinto de "
        if(c != '"'){

            //le vamos ingresando c por c a la salida
           salida += c;
        }
    }

    //devolvemos el text sin "
    return salida;
}

/**---------------------------------------------------------------------------------------------------*/

string borrar_ceros(string fecha){

    string salida = "";

    //recorre el texto char x char --- xx/xx/xxxx
    for(unsigned long i = 0;i < fecha.length(); i++){

        // si en las posiciones 0 o 3 hay un 0, no se almacena
        if((i == 0 || i == 3) && fecha[i] == '0'){

        //si la fecha es ej:02/02/1966 se borran los 0 en las posiciones 0 y 3
        }else{
            salida += fecha[i];
        }
    }

    return salida;
}

/**---------------------------------------------------------------------------------------------------*/

bool fecha_valida(string fecha){

    int longitud = fecha.length();

    //si  es xx/xx/xxxx
    if(longitud >= 10 && fecha[2] == '/' && fecha[5] == '/'){
        return true;

    //si es x/x/xxxx
    }else if(longitud >= 8 && fecha[1] == '/' && fecha[3] == '/'){
        return true;

    // x/xx/xxxx
    }else if(longitud >= 9 && fecha[1] == '/' && fecha[4] == '/'){
        return true;

    // xx/x/xxxx
    }else if(longitud >= 9 && fecha[2] == '/' && fecha[4] == '/'){
        return true;

    // x/x/xx
    }else if(longitud >= 6){
        return true;

    }
    else{
        return false;

    }
}

/**---------------------------------------------------------------------------------------------------*/

string normalizar_anio(string fecha){
    int len = fecha.length();

    //si es xx/xx/xx - 3 me da / o si es x/x/xx tambien
    if(len>=6 && fecha[len -3 ] == '/' ){

        //substr saca una parte del string, desde donde(len-2) y cuantos caracteres queremos(2)
        string ult_dos = fecha.substr(len - 2, 2);
        int an_ingresado = 0;
        //stoi = string to int
        if(es_entero_valido(ult_dos)){
        an_ingresado = stoi(ult_dos);
        }


        //stoi = string to int

        an_ingresado = stoi(ult_dos);


        //si es 26 = 1926 si es 25 = 2025
        string insertar = (an_ingresado>=26) ? "19" : "20";

         //xx/xx/"insertar(19/20)"xx
        fecha.insert(len - 2, insertar);

    }
    return fecha;
}

/**---------------------------------------------------------------------------------------------------*/

string borrar_espacios(string texto){
    string salida = "";

    for(unsigned long i = 0; i< texto.length(); i++){//recorre el texto c por c(char)

        if(texto[i] != ' '){//si  es distinto de un espacio

           salida += texto[i];//le vamos ingresando c por c a la salida
        }
    }
    return salida;
}

/**---------------------------------------------------------------------------------------------------*/

string quitar_tildes(string texto) {

    unordered_map<string, char> reemplazos = {//las tildes van con string porque ocupan mas de un char
        {"á", 'a'}, {"é", 'e'}, {"í", 'i'}, {"ó", 'o'}, {"ú", 'u'},//clave = á , valor = a;
        {"Á", 'A'}, {"É", 'E'}, {"Í", 'I'}, {"Ó", 'O'}, {"Ú", 'U'},
        {"ñ", 'n'}, {"Ñ", 'N'}, {"ü", 'u'}, {"Ü", 'U'}
    };

    string resultado = "";

    for (size_t i = 0; i < texto.length();) { //recorremos el texto char por char

        if ((unsigned char)texto[i] >= 194) {//si es mas de 194 ; las letras con acento empiezan en 0xc2(194) o mas.
            //se castea unsigned char porque un char normal nunca va a ser mayor a 127 y ademas puede ser negativo entonces 127>194 no tiene sentido(unsigned char va de 0 a 255)

            string letra = texto.substr(i, 2);//le sacamos los 2 bytes si es un acento y lo guardamos en letra(desde i, 2 posiciones);

            if (reemplazos.count(letra)) { //devuelve true si letra existe o false si no existe en el mapa
                //si la letra(clave) encontrada y sacada con substr esta en el mapa se cambia por el valor del mapa
                resultado += reemplazos[letra]; //reemplazos[letra] devuelve el valor asociado a la clave, ej á = a ;

            } else {
                resultado += letra;//si no esta en el map, se guarda como esta

            }
            i += 2; //como es tilde avanzamos 2 bytes

        } else {
            resultado += texto[i]; //le sumamos la letra normal en la posicion
            i++; //letra normal, de 1 en 1
        }
    }

    return resultado;
}

/**---------------------------------------------------------------------------------------------------*/

bool es_entero_valido(string s) {

    if (s.empty()) {
        return false; // si no tiene nada

    }
        for (char c : s) { //caracter por caracter del string
        if (!isdigit(c)) {
            return false; //si un caracter no es un digito
        }
    }
    return true;
}

/**---------------------------------------------------------------------------------------------------*/




string asignar_estado( int &contador){

    string estados[4] = {
        "bueno", "regular", "malo", "destruido"
    };
    string estado = estados[contador % 4];//al hacer modulo de 4 siempre va a ir en 0, 1 , 2, 3 y repite
    contador++;
    return estado;
}
/**------------------------------------------------------------------------------------------------- */
string asignar_estadoSN(int &contador){
    string disponibilidad[2] = {"si", "no"};
    contador++;
    return disponibilidad[contador % 2]; //esto va a alternar entre las posiciones 0 y 1
}
/**------------------------------------------------------------------------------------------------- */
void asignar_ubicacion(int &contador, int ubicacionL[2]){
    int columnas_por_fila = 5;//5 columnas por fila

    ubicacionL[0] = (contador % columnas_por_fila) + 1;//columnas
    ubicacionL[1] = (contador / columnas_por_fila) + 1;//fila

    contador++;
}
/**------------------------------------------------------------------------------------------------- */

void asignar_estadosUbicacion(string nombre_archivo){

    ifstream archivo_entrada(nombre_archivo);

    if (!archivo_entrada.is_open()){

        cout<<"no se pudo abrir el archivo."<<endl;
    }


    vector<string> lineas_nuevas;

    string linea;

    int contador_estado = 0;

    int contador_estadoSN = 0;

    int contador_ubicacion = 0;

    //leemos el encabezado y le agregamos los otros parametros

    getline(archivo_entrada, linea);
    if((linea.find("ESTADO") != string::npos) && (linea.find("ESTADOSN") != string::npos) && (linea.find("UBICACION") != string::npos)){
        cout<<"El encabezado ya fue actualizado."<<endl;
        archivo_entrada.close();
        return; //salimos
    }

    linea += ",ESTADO,ESTADOSN,UBICACION";
    lineas_nuevas.push_back(linea);
    //leemos y modificamos las otras lineas
    while(getline(archivo_entrada, linea)){

        string estado = asignar_estado(contador_estado);

        string estadoSN = asignar_estadoSN(contador_estadoSN);

        int ubicacionL[2];

        asignar_ubicacion(contador_ubicacion, ubicacionL);

        string ubicacionstring = to_string(ubicacionL[0]) + "-" + to_string(ubicacionL[1]); //quedaria 1-2 por ej

        string nueva_linea = linea + "," + estado + "," + ubicacionstring + "," + estadoSN; //la nueva linea seria los datos anteriores sumando los estados

        lineas_nuevas.push_back(nueva_linea);
    }
    archivo_entrada.close();

    //escribimos todo
    ofstream archivo_salida(nombre_archivo);

    if (!archivo_salida.is_open()){

        cout<<"no se pudo abrir el archivo."<<endl;
    }
    for (string l : lineas_nuevas){//por cada string en lineas_nuevas

        archivo_salida << l <<endl; //escribimos el contenido de l
    }

    archivo_salida.close();

    cout<<"El archivo se actualizo correctamente."<<endl;
}

/**------------------------------------------------------------------------------------------------- */

int contar_campos(string linea) {
    int cantidad = 1; // al menos un campo aunque no haya comas
    for (char c : linea) {
        if (c == ',') {
            cantidad++;
        }
    }
    return cantidad;
}
/**------------------------------------------------------------------------------------------------- */
void cambiar_ubicacion(string ubicacion_string, int ubicacion[2]){
    size_t guion = ubicacion_string.find('-');//buscamos el guion .find devuelve la pos, ej 2, sino devuelve string::npos(no encontrado)
    if( guion != string::npos){ //si el guion se encontro(distinto de no encontrado)
    if(es_ubicacion_valida(ubicacion_string)){
    ubicacion[0] = stoi(ubicacion_string.substr(0, guion));//hacemos un string to int y substraemos de la ubicacion desde 0, tamaño de substring va a ser = guion
    ubicacion[1] = stoi(ubicacion_string.substr(guion + 1));//y aca desde guion + 1, osea las filas
    }
    } else{
    ubicacion[0] = 0;
    ubicacion[1] = 0;
    }
}
/**------------------------------------------------------------------------------------------------- */
bool es_ubicacion_valida(string ubicacion_string) {
    size_t guion = ubicacion_string.find('-');
    // Verificamos que el guion este y que no este al inicio ni final
    if (guion == string::npos || guion == 0 || guion == ubicacion_string.length() - 1) {
        return false;
    }
    string parte1 = ubicacion_string.substr(0, guion);
    string parte2 = ubicacion_string.substr(guion + 1);

    // Verificamos que ambas partes sean enteros positivos
    for (char c : parte1) {
        if (!isdigit(c)) return false;
    }
    for (char c : parte2) {
        if (!isdigit(c)) return false;
    }

    return true;
}
/**------------------------------------------------------------------------------------------------ */
