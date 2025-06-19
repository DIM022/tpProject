#include<iostream>
#include<string>
#include<fstream>
#include<vector>

#include "gestionVectorLibro.h"

#include "buscar_socios.h"

//ACCEDE A ALGUNAS FUNCIONES NORMALES DEL MAIN
#include "funcionesMain.h"
//ACCEDE A LAS FUNCIONES QUE MANIPULA AL VECTOR SOCIO
#include "gestionVectorSocio.h"
//ACCEDE A LAS FUNCIONES QUE ACCEDEN Y MANIPULAN PRESTAMOS
#include "funcionesPrestamo.h"

using namespace std;

int main(){

    int contRepeS = 0, contRepeL = 0;
    int flagDNI = 0;///INDICA LA POSICION DEL SOCIO BUSCADO
    int flagL = 0;

    char menuP = 0;
    char menuSL = 0;
    char menuL = 0;
    char menuPS = 0;
    char menuSUBPS = 0;

    vector < socio > vectorSocio;
    vector < libro > vectorLibro;
    vector < datoPrestamo > vectorPrestamo;

    ifstream file;///


    while(menuP != 'S' && menuP != 's'){

        cout<< "==============================================="<< endl;
        cout<< "==============================================="<< endl;
        cout<< "\t<< MENU >>"<< endl;
        cout<< "\t1/SOCIO   2/LIBRO   3/PRESTAMO    'S'/SALIR"<<endl << ">";
        cin >> menuP;
        cin.ignore();

        switch(menuP){

            case '1' :

                if(inicioAperturaSocio(vectorSocio, file, contRepeS) ){

                    return 1;
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
                                 cin >> menuSL;
                                 cin.ignore();

                                ///PASAMOS COMO ARGUMENTO
                                ///EL VECTOR PARA SER MODIFCADO
                                ///Y LA POSICION DEL SOCIO ( flagDNI )
                                 if(menuSL == '1'){
                                    modificarSocio(vectorSocio, flagDNI);

                                 }else if(menuSL == '2'){
                                    eliminarSocio(vectorSocio, flagDNI);

                                 }else if(menuSL == 's' || menuSL == 'S'){

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

                inicioAperturaLibro(vectorLibro, contRepeL);
                do{
                    cout<< "-----------------------------------------------"<< endl;
                    cout<< " MENU LIBRO ( MAIN )"<< endl;
                    cout<< "1/ VER LIBRO    2/BUSCAR LIBRO     3/AGREGAR LIBRO      'S'/SALIR"<< endl<< ">";
                    cin >> menuL;
                    cin.ignore();

                    switch(menuL){

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
                                cin >> menuL;
                                cin.ignore();

                                if(menuL == '1'){
                                    modificarLibro(flagL, vectorLibro);

                                }else if(menuL == '2'){

                                }else if(menuL == 's' || menuL == 'S'){
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

                }while(menuL != 'S' && menuL != 's');
                break;

            case '3' :

                do{
                    cout<< "-----------------------------------------------"<< endl;
                    cout<< "MENU PRESTAMO ( MAIN )"<< endl;
                    cout<< "1/VER PRESTAMOS    2/REALIZAR PRESTAMO    'S'/SALIR"<< endl;
                    cin >> menuPS;

                    switch(menuPS){
                        case '1' :

                            do{
                                cout<< "-----------------------------------------------"<< endl;
                                cout<< "MENU PRESTAMO BUSQUEDA"<< endl;
                                cout<< "1/SOCIO    2/LIBRO    3/FECHA   4/TODO  'S'/SALIR"<< endl;
                                cin >> menuSUBPS;

                                if(menuSUBPS == '1'){
                                    filtrarPrestamoSocio(vectorPrestamo);

                                }else if(menuSUBPS == '2'){
                                    filtrarPrestamoLibro(vectorPrestamo);

                                }else if(menuSUBPS == '3'){
                                    filtrarPrestamoFecha(vectorPrestamo);

                                }else if(menuSUBPS == '4'){
                                    filtrarPrestamoTodo(vectorPrestamo);

                                }else if(menuSUBPS == 's' || menuSUBPS == 'S'){
                                    cout<< "SALIENDO AL MENU ( MAIN )"<< endl;

                                }else{
                                    cout<< "SELECCIONE UNA OPCION VALIDA"<< endl;
                                }

                            }while(menuSUBPS != 's' && menuSUBPS != 'S');

                            break;

                        case '2' :

                            inicioAperturaSocio(vectorSocio, file, contRepeS);
                            inicioAperturaLibro(vectorLibro, contRepeL);

                            registrarPrestamo(vectorPrestamo, vectorSocio, vectorLibro);

                            break;

                        case 's' | 'S' :
                            cout<< "SALIENDO AL MENU < MAIN >"<< endl;

                        default :
                            cout<< endl<< "======================"<< endl;
                            cout<< "OPCION INCORRECTA ( MENU MAIN )"<< endl;
                            cout<< endl<< "======================"<< endl;
                            break;
                    }
                }while(menuPS != 's' && menuPS != 'S');
                break;

            case 'S' |  's' :

                ///SI NO SE ABRE NUNCA A SOCIO ESTO TRUNCA A SOCIOS ES DECIR QUE BORRA EL CONTENIDO
                ///Y SUBE LO DE VECTOR PERO COMO EN VECTOR NO HAY NADA YA QUE NUNCA SE ABRIO
                ///QUEDA VACIO

                ///SUBIR CAMBIO SOCIO
                if(contRepeS){
                    subirCambios(vectorSocio);
                    vectorSocio.clear();
                    vectorSocio[1].mostrarSocio();
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
