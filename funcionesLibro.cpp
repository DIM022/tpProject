#include "funcionesLibro.h"

using namespace std;

///RETORNA EL STIRNG A MIINUSCULAS
string a_minusculas(string texto){

    //size() devuelve un unsigned long, o size_t y size_t segun el entorno de ejecucion puede ser uns long,
    //un int, un long long
    for( size_t i = 0;i<texto.size(); i++){

        //la pos 0 ej:C va a ser =  c
        texto[i] = tolower(texto[i]);
    }
    return texto ;
}


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
string normalizar_anio(string fecha){
    int len = fecha.length();

    //si es xx/xx/xx - 3 me da / o si es x/x/xx tambien
    if(len>=6 && fecha[len -3 ] == '/' ){

        //substr saca una parte del string, desde donde(len-2) y cuantos caracteres queremos(2)
        string ult_dos = fecha.substr(len - 2, 2);

        //stoi = string to int

        int an_ingresado = stoi(ult_dos);

        //si es 26 = 1926 si es 25 = 2025
        string insertar = (an_ingresado>=26) ? "19" : "20";

         //xx/xx/"insertar(19/20)"xx
        fecha.insert(len - 2, insertar);

    }
    return fecha;
}

string borrar_espacios(string texto){
    string salida = "";

    for(unsigned long i = 0; i< texto.length(); i++){//recorre el texto c por c(char)

        if(texto[i] != ' '){//si  es distinto de un espacio

           salida += texto[i];//le vamos ingresando c por c a la salida
        }
    }
    return salida;
}
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
