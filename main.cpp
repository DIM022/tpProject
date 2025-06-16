#include<iostream>
#include<string>
#include<fstream>
#include<vector>

#include "buscar_libros.h"
#include "cargar_libros.h"
#include "funcionesLibro.h"
#include "gestionVectorLibro.h"

///FUNCION BUSQUEDA SOCIO -- LINEA 80
#include "buscar_socios.h"

#include "funcionesMain.h"///ACCEDE A ALGUNAS FUNCIONES NORMALES DEL MAIN
#include "gestionVectorSocio.h"///ACCEDE A LAS FUNCIONES QUE MANIPULA AL VECTOR SOCIO

#include "funcionesPrestamo.h"

#define ARCHIVO_SOCIOS "lista de socios.csv"
#define ARCHIVO_LIBROS "lista_libros.csv"

using namespace std;

int main(){

    int contRepeS = 0, contRepeL = 0;
    int flagDNI = 0;///INDICA LA POSICION DEL SOCIO BUSCADO
    int flagL = 0;

    char menuP = 0;
    char menuSL = 0;
    char menuBS = 0;///MENU BUSQUEDA SOCIO -- linea 52

    vector < socio > vectorSocio;
    vector < libro > vectorLibro;
    vector < datoPrestamo > vectorPrestamo;

    ifstream file;///


    while(menuP != 'S' && menuP != 's'){

        cout<< "================================================================================="<< endl;
        cout<< "\t\t<< MENU >>"<< endl;
        cout<< "\t\t1/SOCIO   2/LIBRO   3/PRESTAMO    'S'/SALIR"<<endl << ">";
        cin >> menuP;
        cin.ignore();

        switch(menuP){

            case '1' :

                ///SOLO SE ABRE EL ARCHIVO 1 VEZ
                ///YA QUE SI SELECIONACMOS PARA ACCEDER A SOCIO SIN AVER GUARDAO LAS MODIFICACIONES
                ///SE PIERDEN ESAS MODIFICACIONES Y TIENE EL VECTOR ORIGINAL DENUEVO
                if(!contRepeS){
                    ///ABRIMOS EL ARCHIVO
                    file = archivo_IO();

                    ///VERIFICAMOS QUE SE ASIGNO
                    if(file.fail()){
                        ///SI NO, IMPRIMOS Y RETORNAMOS
                        cout<< "ERROR AL ABRIR EL ARCHIVO ( MAIN )"<< endl;
                        return 1;
                    }

                    ///TOMA LOS DATOS DEL ARCHIVO Y CIERRA ARCHIVO
                    lecturaLinea(vectorSocio, file);

                    contRepeS++;
                }

                do{
                    cout<< "-----------------------------------------------"<< endl;
                    cout<< "<< MENU SOCIO ( MAIN ) >>"<< endl;
                    cout<< "1/VER SOCIOS    2/BUSCAR SOCIO    3/AGREGAR USUARIO    'S'/SALIR"<< endl<< ">";
                    cin >> menuSL;
                    cin.ignore();

                    switch(menuSL){
                        case '1' :
                            mostrar(vectorSocio);
                            break;

                        case '2' :
                            ///GUARDAMOS EL DNI DEL SOCIO BUSCADO
                             flagDNI = busquedaSocios(vectorSocio);

                             ///SI ES MAYOR O IGUAL A < 0 > SE ENCONTRO UN SOCIO
                             ///SI NO RETORNA A < MENU SOCIO >
                            if(flagDNI != -1){

                                ///MUESTRA EL MENU BS( BUSQUEDA )
                                 cout<< "1/MODIFICAR SOCIO    2/ELIMINAR SOCIO    'S'/SALIR"<< endl<< ">";
                                 cin >> menuBS;
                                 cin.ignore();

                                 if(menuBS == '1'){
                                    modificar_Socio(vectorSocio, flagDNI);

                                 }else if(menuBS == '2'){
                                    eliminarSocio(vectorSocio, flagDNI);

                                 }else if(menuBS == 's' || menuBS == 'S'){

                                    cout<< "SALIENDO DE < MENU BUSQUEDA >"<< endl;
                                    ///RETORNA AL < MENU SOCIO >
                                 }
                            }
                            break;

                        case '3' :
                            agregarSocio(vectorSocio);
                            cout<< "<<< SOCIO AGREGADO >>"<< endl;

                            break;

                        case 's' | 'S' :
                            cout<< "<<< SALIENDO AL MENU PRINCIPAL... >>"<< endl;
                            break;

                        default :
                            cout<< endl<< "======================"<< endl;
                            cout<< "OPCION INCORRECTA ( MENU SOCIO )"<< endl;
                            cout<< endl<< "======================"<< endl;
                            break;
                    }

                }while(menuSL != 'S' && menuSL != 's');

                break;

            case '2' :

                ///ASEGURA QUE SE CARGUE EL LIBRO UNA SOLA VEZ PARA EVITAR
                ///ACTUALIZACIONES NO BUSCADAS
                if(!contRepeL){
                    //ABRE Y RETORNA UN VECTOR DE LIBRO
                    vectorLibro = cargarLibro(ARCHIVO_LIBROS);

                    contRepeL++;
                }


                do{
                    cout<< "-----------------------------------------------"<< endl;
                    cout<< " MENU LIBRO ( MAIN )"<< endl;
                    cout<< "1/ VER LIBRO    2/BUSCAR LIBRO     3/AGREGAR LIBRO      'S'/SALIR"<< endl<< ">";
                    cin >> menuSL;
                    cin.ignore();

                    switch(menuSL){

                    case '1' :
                            mostrarL(vectorLibro);
                            break;

                        case '2' :
                            ///RETORNA EL INDICE DEL LIBRO BUSCADO -- SOLO SI SE BUSCA EL NOMBRE
                            flagL = busqueda_libros(vectorLibro);

                            ///SI ENTRA ES PORQUE ENCONTRO UN LIBRO ESPECIFICO
                            ///Y QUEREMOS MODIFICARLO
                            if(flagL != -1){

                                cout<< "1-MODIFICAR LIBRO      2-ELIMINAR     'S'/SALIR"<< endl;
                                cin >> menuSL;
                                cin.ignore();

                                if(menuSL == '1'){
                                    modificarLibro(flagL, vectorLibro);

                                }else if(menuSL == '2'){

                                }else if(menuSL == 's' || menuSL == 'S'){
                                        cout<< "SALIENDO DEL < MENU BUSQUEDA >"<< endl;
                                }

                            }
                            break;

                        case '3' :
                            agregarLibro(vectorLibro);
                            break;

                        case 's' | 'S' :
                            cout<< "SALIENDO AL MENU PRINCIPAL..."<< endl;
                            break;

                        default :
                            cout<< endl<< "======================"<< endl;
                            cout<< "OPCION INCORRECTA ( MENU LIBRO )"<< endl;
                            cout<< endl<< "======================"<< endl;
                            break;
                    }

                }while(menuSL != 'S' && menuSL != 's');

            case '3' :

                cout<< "-----------------------------------------------"<< endl;
                cout<< "MENU PRESTAMO ( MAIN )"<< endl;
                cout<< "1/VER PRESTAMOS    2/REALIZAR PRESTAMO"<< endl;
                cin >> menuSL;

                switch(menuSL){
                    case '1' :
                        cout<< "-----------------------------------------------"<< endl;
                        cout<< "MENU PRESTAMO BUSQUEDA"<< endl;
                        cout<< "1/SOCIO    2/LIBRO    3/FECHA"<< endl;
                        cin >> menuSL;

                        if(menuSL == '1'){
//                            filtrarPrestamoSocio(vectorPrestamo);

                        }else if(menuSL == '2'){
//                            filtrarPrestamoLibro(vectorPrestamo);

                        }else if(menuSL == '3'){
//                            filtrarPrestamoFecha(vectorPrestamo);
                        }
                        break;

                    case '2' :
//                        registrarPrestamo(vectorPrestamo, vectorSocio, vectorLibro);

                        break;

                    default :
                        cout<< endl<< "======================"<< endl;
                        cout<< "OPCION INCORRECTA ( MENU MAIN )"<< endl;
                        cout<< endl<< "======================"<< endl;
                        break;
                }
                break;

            case 'S' |  's' :

                ///SI NO SE ABRE NUNCA A SOCIO ESTO TRUNCA A SOCIOS ES DECIR QUE BORRA EL CONTENIDO
                ///Y SUBE LO DE VECTOR PERO COMO EN VECTOR NO HAY NADA YA QUE NUNCA SE ABRIO
                ///QUEDA VACIO

                ///SUBIR CAMBIO SOCIO
                if(contRepeS){
                    subirCambios(vectorSocio);
                }

                if(contRepeL){
                    subirCambiosLibro(vectorLibro);
                }
                break;

            default :
                cout<< endl<< "======================"<< endl;
                cout<< "OPCION INCORRECTA ( MENU MAIN )"<< endl;
                cout<< endl<< "======================"<< endl;
                break;
        }

    }

    return 0;
}
