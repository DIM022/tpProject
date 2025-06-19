#include "funcionesMain.h"

#include "gestionVectorSocio.h"

using namespace std;

/**---------------------------------------------------------------------------------------------------*/

//ASEGURA QUE SE ENTRE UNA SOLA VEZ PARA EVITAR SOBRE ESCRITURAS
int inicioAperturaSocio(vector<socio>& vectorSocio, ifstream& file, int& contRepeS){


    //SOLO SE ABRE EL ARCHIVO 1 VEZ
    //YA QUE SI SELECIONACMOS PARA ACCEDER A SOCIO SIN AVER GUARDAO LAS MODIFICACIONES
    //SE PIERDEN ESAS MODIFICACIONES Y TIENE EL VECTOR ORIGINAL DE NUEVO
    if(!contRepeS ){

        //ABRIMOS EL ARCHIVO
        file = archivo_IO();

        //VERIFICAMOS QUE SE ASIGNO
        if(file.fail()){
            //SI NO, IMPRIMOS Y RETORNAMOS
            cout<< "ERROR AL ABRIR EL ARCHIVO ( MAIN )"<< endl;
            cout<< "CERRANDO PROGRAMA"<< endl;
            return 1;
        }

        //TOMA LOS DATOS DEL ARCHIVO Y CIERRA ARCHIVO
        lecturaLinea(vectorSocio, file);

        contRepeS++;
    }
    return 0;
}

/**---------------------------------------------------------------------------------------------------*/

void eliminarSocio(vector <socio>& vector_Socio, int flagDNI){

    //.begin -- apunta al primer elemento del vector
    //.erase -- se desplaza desde la posicion indicada ( begin ), tantas veces como se especifique el segundo argumento
    //         elimina esa posicion reducion el vector sin dejar un espacio en blanco
    vector_Socio.erase(vector_Socio.begin() + flagDNI);

    cout<< "SOCIO ELIMINADO.."<< endl;
}

/**---------------------------------------------------------------------------------------------------*/

void agregarSocio(vector <socio>& vectorSocio){

    int _posicionA = 0, tam_bytes = 0, contEdad = 0, posChar = 0;

    string _apellido, _dni, _genero, _direccion, _numeroT, _edad, _fechaC, _mail;
    string numCalle, nombreCalle;//VARIABLE AUXILIAR --- LINEA 142

   bool salir = true;

    cout<< "-------------------------"<< endl;
    cout<< "INGRESO DE NUEVO SOCIO"<< endl;

    //NOMBRE
    //NO DEBE HABER NUMERO / SIGNOS
    do{

        cout<< "NOMBRE: ";
        getline(cin, _apellido);

        //VERIFICAMOS
        //RETORNA 1 SI HAY UN NUMERO Y 0 SI NO LO HAY
        salir = verificarCharString(_apellido);

    }while(salir);

/**--   SOLO NUMERO     -----*/

    do{
        cout<< "DNI: ";
        getline(cin, _dni);

        //VERIFIACAMOS SOLO NUMEROS
        //TRUE - HAY MAS QUE SOLO NUMEROS
        //FALSE - SOLO NUMEROS
        //----
        //VERIFICAMOS QUE NO HALLA UN DNI EXISTENTE
        //TRUE - EXISTE
        //FALSE NO EXISTE
        salir = verificarNumeroString(_dni);

        if(!salir){
            //VERIFICAMOS QUE NO HALLA UN DNI EXISTENTE PARA EVITAR ERRORES
            salir = verificarExistenciaDniSocio(_dni, vectorSocio);

            if(salir){
                cout<< "DNI YA EXISTENTE INGRESAR UN DNI VALIDO"<< endl;
            }
        }

    }while(salir);

/**----    female O male   ----*/

     //female O male
     //NO DEBE HABER NUMERO / SIGNOS
    do{

        cout<< "GENERO ( MALE O FEMALE ): ";
        cin >> _genero;
        cin.ignore();

        //VERIFICAMOS QUE SOLO HAYA LETRAS VALIDAS ( a - z && A - Z)
        //FALSE SI SOLO HAY CHARES VALIDOS
        salir = verificarCharString(_genero);

        //PASAMOS EL STRING A MINUSCULA POR LAS DUDAS
        _genero = a_minusculas(_genero);

        //TIENE QUE SER UNO DE LOS DOS PARA ENTRAR
        if(_genero != "female" && _genero != "male"){
            cout<< "SOLO INGRESAR FEMALE OR MALE"<< endl;
            salir = true;

        }

    }while(salir);

/**-------  LUGAR + NUM --------*/


    cout<< "DIRECCION"<< endl;
    do{
        salir = false;

        //SE INGRESA LA DIRECCION
        cout<< "CALLE : ";
        getline(cin, nombreCalle);

        salir = verificarCharString(nombreCalle);

        //SI EL STRING ES SOLO CHAR VALIDO RETORNA FALSE PARA TERMINAR EL BUCLE
        //LO NEGAMOS SI ENTRA ES PORQUE ES SOLO CHAR VALIDO
        //Y AHORA PEDIMOS LA DIRECCION ( NUMERO )
        if(!salir){

            do{
                cout<< "INGRESE EL NUMERO DE CALLE: "<< endl;
                cin >> numCalle;
                cin.ignore();

                salir = verificarNumeroString(numCalle);

            //SI ES FALSE NO ITERA MAS
            }while(salir);

        }else{
            //SE INGRESO UN CARACTER NO VAIDO EN CALLE
            cout<< "SOLO SE PERMITE CARACTERES VALIDOS"<< endl;
            salir = true;
        }

    }while(salir);
        _direccion = (nombreCalle + ' ' + numCalle);

/**--------   NUMERO TELEFONICO  ------*/

    // xxx xxx xxx
    do{
        cout<< "NUMERO TELEFONICO ( 9 DIGITOS && SIN ESPACIOS ): ";
        getline(cin, _numeroT);

        tam_bytes = _numeroT.size();

        //VERIFICAMOS QUE SOLO SE HALLA INGRESAO ) DIGITOS
        if(tam_bytes == 9){

            salir = verificarNumeroString(_numeroT);

            //TRUE --> NO HAY SOLO NUMEROS
            //FALSE --> SOLO NUMEROS
            if(salir){
                cout<< "SOLO ESTA PERMITIDO NUMERO"<< endl;
                salir = true;

            }else{
                //SALIR = FALSE
                //SI ES VERDADERO
                //xxx xxx xxx
                //xxx xxx xxx
                //CON ESTO SEPARAMOS DE 3 EN 3 EL STRING
                _numeroT.insert(3, " ");
                _numeroT.insert(7, " ");


            }

        }else{
            cout<< "INGRESAR 9 NUMEROS 0 - 9 SIN ESPACIOS !"<< endl;
            salir = true;

        }

    }while(salir);

/**-------  EDAD    ----*/
    // > 0 && < 120
    do{
        cout<< "EDAD: ";
        getline(cin, _edad);

        if(!verificarNumeroString(_edad)){

            //CONVERTIMOS LA EDAD DE STRIING A NUMERO PARA VERIFICAR
            contEdad = stoi(_edad);

            if(contEdad > 0 && contEdad <= 120){
                //EDAD VALIDA
                salir = false;

            }else{
                cout<< "EDAD INVALIDA"<< endl;
                salir = true;
            }
        }

    }while(salir);

/**----- FECHA NACIMIENTO   ------*/

    //xx/xx/xxxx
    cout<< "FECHA NACIMIENTO: ";
    getline(cin, _fechaC);

/**-------*/
    //xxxxxx@xxx
    do{
        //INGRESO DEL MAIL
        cout<< "MAIL: ";
        getline(cin, _mail);

        //SE INGRESA EL MAIL
        //LEEMOS HASTA EL ARROBA Y VERIFICAMOS SOLO LETRAS Y/O NUMEROS
        posChar = _mail.find("@");

        if(_mail[posChar] == '@'){

            for(int i=0; i<posChar; i++){

                if( (_mail[i] >= 'a' && _mail[i] <= 'z' ) || (_mail[i] >= 'A' && _mail[i] <= 'Z' ) || (_mail[i] >= '0' && _mail[i] <= '9' ) ){
                    salir = false;

                }else{
                    cout<< "SOLO CARACTERES VALIDOS PARA EL USUARIO ( XXXXXX@ ) "<< endl;
                    i = posChar;
                    salir = true;
                }
            }

        }else{
            cout<< "FALTA EL '@'"<< endl;
            salir = true;
        }

    }while(salir);
/**-----*/

    //LE ASIGNAMOS LA POSICION IDENTIFICATORIA AL SOCIO
    _posicionA = vectorSocio.size();

    //LE PASAMOS TODOS ESOS DATOS A VECTOR QUE DE FORMA DINAMICA ALMACENA A LO ULTIMO EL NUEVO OBJETO SOCIO
    vectorSocio.push_back(socio(_apellido, _dni, _genero, _direccion, _numeroT, _edad, _fechaC, _mail, _posicionA) );


}

/**---------------------------------------------------------------------------------------------------*/

//MODIFICA EL VECTOR Y EN LA FUNCION < subirCambios > SOBREESCRIBIMOS EL ARCHIVO CON EL VECTOR

void modificarSocio(vector <socio>& vector_Socio, int flagDNI){

    string nuevoValor;//ALMACENA EL NUEVO VALOR
    int posDato = 0;
    bool salir = true;

    do{
        cout<< "QUE CAMPO QUIERE MODIFICAR : "
            << "1-APELLIDO  2-DNI   3-SEXO   4-DIRECCION    "
            << "5-TELEFONO  6-EDAD  7-FECHA NACIMIENTO  8-MAIL   9-SALIR>> ";
        cin >> posDato;

        //IGNORA EL ENTER PARA EVITAR LEERLO
        cin.ignore();

        if(posDato == 9){
            salir = false;

        }else if(posDato >= 1 && posDato <= 8){

            cout<< "INGRESE EL NUEVO VALOR : ";
            getline(cin, nuevoValor);

            //PARAMETROS : EL VALOR NUEVO, Y LA OPCION DEL DATO A CAMBIAR
            vector_Socio[flagDNI].setDato(nuevoValor, posDato);

        }else{
            cout<< "OPCION INVALIDA < MENU MODIFCAR ( FUNCION ) >"<< endl;
        }

    }while(salir);
}

/**---------------------------------------------------------------------------------------------------*/

//TOMA LA LINEA DEL ARCHIVO Y LO PLASMA EN VARIABLES
void lecturaLinea(vector <socio>& vector_Socio, ifstream& file){

    int _posicionA = 0;//INDICA EN QUE POSICION ( LINEA ) DEL ARCHIVO SE ENCUENTRA
    int contDato = 1;//PARA IDENTIFICAR EN QUE TIPO DE DATO ESTAMOS
    int indice = 0;

    string lineaDato;//es donde guardaremos los datos tomados del archivo
    string _apellido, _dni, _genero, _direccion, _numeroT, _edad, _fechaC, _mail;

    //TOMA LA LINEA DE DATOS HASTA QUE FINALIZA Y DEVULVE FALSE
     while(getline(file, lineaDato)){

        //ITERAMOS HASTA EL FINAL DEL STRING ( LINEA )
        while(lineaDato[indice] != '\0'){

            //SI ENCEUNTRA UNA < , > LO SALTEA
            if(lineaDato[indice] == ','){

                //PASAMOS AL SIGUITE DATO
                contDato++;

                //PASAMOS AL SIGUIETE INDICE
                indice++;

            //SALTEAMOS LAS COMILLAS
            }else if(lineaDato[indice] == '"'){
                indice++;

            }else{

                //RECORREMOS CADA DATO GUARDANDO CHAR X CHAR HASTA TERMINAR DE RECORRERLO
                if(contDato == 1){

                    _apellido += lineaDato[indice];
                    indice++;

                }else if(contDato == 2){
                    _dni += lineaDato[indice];
                    indice++;

                }else if(contDato == 3){
                    _genero += lineaDato[indice];
                    indice++;

                }else if(contDato == 4){
                    _direccion += lineaDato[indice];
                    indice++;

                }else if(contDato == 5){
                    _numeroT += lineaDato[indice];
                    indice++;

                }else if(contDato == 6){
                    _edad += lineaDato[indice];
                    indice++;

                }else if(contDato == 7){
                    _fechaC += lineaDato[indice];
                    indice++;

                }else if(contDato == 8){
                    _mail += lineaDato[indice];
                    indice++;
                }
            }

        }//FIN WHILE QUE RECORRE HASTA UN ' \0 '

        //SE AGREGA DE FORMA DINAMICA UN NUEVO ESPACIO DE VECTOR CON LO QUE INICILIAZAMOS ESOS VALORES TOMADOS
        vector_Socio.push_back(socio(_apellido, _dni, _genero, _direccion, _numeroT, _edad, _fechaC, _mail, _posicionA));

        //LIMPIAMOS LOS STRING PARA EVITAR SOBREESCRIBIR LOS DATOS UNOS SOBRE OTROS
        lineaDato.clear();
        _apellido.clear();
        _dni.clear();
        _genero.clear();
        _direccion.clear();
        _numeroT.clear();
        _edad.clear();
        _fechaC.clear();
        _mail.clear();

        //MODIFICAMOS VARIABLES PARA CADA LINEA NUEVA
        indice=0;
        contDato = 1;
        _posicionA++;
     }

     //CERRAMOS EL ARACHIVO
     file.close();
}

/**---------------------------------------------------------------------------------------------------*/

bool verificarExistenciaDniSocio(string _string, vector <socio>& vectorSocio){

    //RECORRE TODO EL VECTOR SOCIO
    for(size_t i=0; i<vectorSocio.size(); i++){

        //SI ENCUENTRA UNA COINCIDENCIA ENTRA
        if(_string == vectorSocio[i].getdni() ){
            i = vectorSocio.size();
            return true;
        }
    }

    //EN CASO DE ENCNTRAR NADA RETORNAMOS FALSE
    return false;
}

/**---------------------------------------------------------------------------------------------------*/
