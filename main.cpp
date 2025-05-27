#include<iostream>
#include<string>
#include<fstream>
#include<vector>

#include "buscar_libros.h"
#include "cargar_libros.h"
#include "funcionesLibro.h"

#include "buscar_socios.h"///FUNCION BUSQUEDA SOCIO -- LINEA 80

#include "funcionesMain.h"///ACCEDE A ALGUNAS FUNCIONES NORMALES DEL MAIN
#include "gestionVectorSocio.h"///ACCEDE A LAS FUNCIONES QUE MANIPULA AL VECTOR SOCIO


#define ARCHIVO_SOCIOS "lista de socios.csv"
#define ARCHIVO_LIBROS "lista_libros.csv"

using namespace std;

int main()
{
    int contRepe = 0;
    int flagDNI = 0;///INDICA LA POSICION DEL SOCIO BUSCADO

    char menuP = 0;
    char menuSL = 0;
    char menuBS = 0;///MENU BUSQUEDA SOCIO -- linea 52

    vector < socio > vector_Socio;
    vector < libro > vector_Libro;

    ifstream file;///


    while(menuP != 'S' && menuP != 's'){

        cout<< "<< MENU >>"<< endl;
        cout<< "1/SOCIO   2/LIBRO   'S'/SALIR"<<endl;
        cin >> menuP;
        cin.ignore();

        switch(menuP){

            case '1' :

                ///SOLO SE ABRE EL ARCHIVO 1 VEZ
                ///YA QUE SI SELECIONACMOS PARA ACCEDER A SOCIO SIN AVER GUARDAO LAS MODIFICACIONES
                ///SE PIERDEN ESAS MODIFICACIONES Y TIENE EL VECTOR ORIGINAL DENUEVO
                if(!contRepe){
                    ///ABRIMOS EL ARCHIVO
                    file = archivo_IO();

                    ///VERIFICAMOS QUE SE ASIGNO
                    if(file.fail()){
                        ///SI NO, IMPRIMOS Y RETORNAMOS
                        cout<< "ERROR AL ABRIR EL ARCHIVO ( MAIN )"<< endl;
                        return 1;
                    }

                    ///TOMA LOS DATOS DEL ARCHIVO Y CIERRA ARCHIVO
                    lecturaLinea(vector_Socio, file);

                    contRepe++;
                }

                do{
                    cout<< "<< MENU SOCIO ( MAIN ) >>"<<endl;
                    cout<< "1/VER SOCIOS    2/BUSCAR SOCIO    3/AGREGAR USUARIO    'S'/SALIR"<<endl;
                    cin >> menuSL;
                    cin.ignore();

                    switch(menuSL){
                        case '1' :
                            mostrar(vector_Socio);break;

                        case '2' :
                            ///GUARDAMOS EL DNI DEL SOCIO BUSCADO
                             flagDNI = busqueda_socios(vector_Socio);

                             ///SI ES MAYOR O IGUAL A < 0 > SE ENCONTRO UN SOCIO
                             ///SI NO RETORNA A < MENU SOCIO >
                            if(flagDNI != -1){

                                ///MUESTRA EL MENU BS( BUSQUEDA )
                                 cout<< "1/MODIFICAR SOCIO    2/ELIMINAR SOCIO    'S'/SALIR"<<endl;
                                 cin >> menuBS;
                                 cin.ignore();

                                 if(menuBS == '1'){
                                    modificar_Socio(vector_Socio, flagDNI);

                                 }else if(menuBS == '2'){
                                    eliminarSocio(vector_Socio, flagDNI);

                                 }else if(menuBS == 's' || menuBS == 'S'){

                                    cout<< "SALIENDO DE < MENU BUSQUEDA >"<< endl;
                                    ///RETORNA AL < MENU SOCIO >
                                 }
                            }
                            break;

                        case '3' :
                            agregarSocio(vector_Socio);
                            cout<< "SOCIO AGREGADO"<< endl;

                            break;

                        case 's' | 'S' :
                            cout<< "SALIENDO AL MENU PRINCIPAL..."<< endl;
                            break;

                        default :
                            cout<< "OPCION INCORRECTA ( MENU SOCIO )"<< endl;
                            break;
                    }

                }while(menuSL != 'S' && menuSL != 's');

                break;

            case '2' :

                //ABRE Y RETORNA UN VECTOR DE LIBRO
                vector_Libro = cargarLibro(ARCHIVO_LIBROS);


                cout<< " MENU LIBRO ( MAIN )"<< endl;
                cout<< "1/ VER LIBRO    2/BUSCAR LIBRO     3/AGREGAR LIBRO"<< endl;
                cin >> menuSL;

                switch(menuSL){

                    case '1' :
                        /**VER LIBRO
                                - MUESTRA TODOS LOS LIBROS*/

                        mostrarL(vector_Libro);

                        break;

                    case '2' :
                        /**BUSCAR LIBRO
                                - BUSCAR POR CIERA CARACTERISTICAS
                                        MUESTRA TODOS SUS DATOS
                                                - NOMBRE, ETC, SI ESTA PRESTADO/DEVUELTO, ETC
                        */
                        busqueda_libros(vector_Libro);
                        break;

                    case '3' :
                        /**AGREGAR LIBRO
                                -AGREGAR LIBRO
                        */
                    default :
                        cout<< "OPCION INCORRECTA ( MENU LIBRO )"<< endl;
                }

            /*
                /
                cout<<"Buscar libro."<<endl;//unica opcion por ahora
                busqueda_libros(vector_Libro);
                break;
            */
            case 'S' |  's' :

                ///SUBIR CAMBIO SOCIO
                subirCambios(vector_Socio);
                break;
        }

    }

    return 0;
}
