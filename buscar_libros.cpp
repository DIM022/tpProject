#include "buscar_libros.h"
#include "funcionesLibro.h"

/**---------------------------------------------------------------------------------------------------*/

int busqueda_libros(vector<libro> libros) {

    int columnaB = 0, filaB = 0;
    int opcionCase7 = 0;
    string busquedaEstado = "";
    char eleccion = 0;
    int flagID = -1;

	do {
		cout<<"Seleccione una opcion de busqueda y filtrado de libros: "<<endl;
		cout<<" 1.Nombre\n 2.Area\n 3.Sub Area\n 4.Autores\n 5.Editorial\n 6.Anio de Publicacion\n"
            << "7.Estado ( Disponible / No Disponible )\n 8.Ubicacion\n 9.Estado(Bueno - Regular - Malo - Destruido)\n"
            << " 'S'/Salir"<< endl;
		cin>> eleccion;
		cin.ignore();

	} while(eleccion != '1' && eleccion != '2' && eleccion != '3' && eleccion != '4' && eleccion != '5' && eleccion != '6' && eleccion != '7' && eleccion != '8' && eleccion != '9' && eleccion != 'S' && eleccion != 's' );


	switch(eleccion) {
    	case  '1' : {

    		bool band;
    		string nombre_busc;

    		do {

    			band = 0;
    			cout<<"Ingrese el nombre del libro a buscar(E para salir): "<<endl;
    			getline(cin, nombre_busc);
    			nombre_busc = a_minusculas(quitar_tildes(nombre_busc));
    			for(unsigned long i = 0; i<libros.size(); i++) {
    				if(borrar_espacios(nombre_busc) == borrar_espacios(a_minusculas(quitar_tildes(libros[i].get_nombre())))) {
    					libros[i].mostrarLibro();
    					band = 1;
    					flagID = i;
    				}
    			}
    		} while(!band && nombre_busc != "E" && nombre_busc != "e");
    		break;
    	}
    	case '2' : {
    		string area_busc;
    		bool exist = false;

    		do {
    			exist = false;
    			cout<<"Ingrese el Area a buscar y filtrar(E para salir): "<<endl;
    			getline(cin, area_busc);
    			area_busc = a_minusculas(borrar_espacios(quitar_tildes(area_busc)));
    			for(unsigned long i = 0; i < libros.size(); i++) {
    				string area_libro = a_minusculas(borrar_espacios(quitar_tildes(libros[i].get_area())));
    				if(area_busc == a_minusculas(borrar_espacios(quitar_tildes(libros[i].get_area())))) {
    					libros[i].mostrarLibro();
    					//exist = true;
    				}
    			}
    			//if(!exist){
                //cout<<"El Area no existe."<<endl;
    			//}
    		} while(/*!exist &&*/ area_busc != "E" && area_busc != "e");
    		break;
    	}
    	case '3' : {
    		//limpiar buffer
    		bool encontrado;
    		string subarea_busc;
    		do {
    			encontrado = 0;
    			cout<<"Ingrese el Sub Area a buscar y filtrar(E para salir): "<<endl;
    			getline(cin, subarea_busc);
    			subarea_busc = quitar_tildes(subarea_busc);
    			for(unsigned long i = 0; i < libros.size(); i++) {
    				if(a_minusculas(borrar_espacios(subarea_busc)) == a_minusculas(borrar_espacios(quitar_tildes(libros[i].get_sub_area())))) {
    					libros[i].mostrarLibro();
    					encontrado = 1;
    				}
    			}

    		} while(!encontrado && subarea_busc != "E" && subarea_busc != "e");
    		break;
    	}

    	case '4' : {
    		bool band;
    		string autor_busc;

    		do {
    			band = 0;
    			cout<<"Ingrese el Autor a buscar(E para salir): "<<endl;
    			getline(cin, autor_busc);
    			autor_busc = quitar_tildes(autor_busc);
    			for(unsigned long i = 0; i < libros.size(); i++) {
    				if(a_minusculas(borrar_espacios(autor_busc)) == a_minusculas(borrar_espacios(quitar_tildes(libros[i].get_autores())))) {
    					libros[i].mostrarLibro();
    					band = 1;
    				}
    			}

    		} while(!band && autor_busc != "E" && autor_busc != "e");
    		break;
    	}
    	case '5' : {
    		bool band;
    		string edi_busc;

    		do {
    			band = false;
    			cout<<"Ingrese la Editorial a buscar y filtrar(E para salir): "<<endl;
    			getline(cin, edi_busc);
    			edi_busc = a_minusculas(quitar_tildes(edi_busc));
    			for(unsigned long i = 0; i < libros.size(); i++) {
    				if(borrar_espacios(edi_busc) == a_minusculas(borrar_espacios(quitar_tildes(libros[i].get_editorial())))) {
    					libros[i].mostrarLibro();
    					band = true;
    				}
    			}
    			if(!band) {
    				cout<<"La editorial no existe."<<endl;

    			}

    		} while(!band && edi_busc != "E" && edi_busc != "e");
    		break;
    	}
    	case '6' : {
    		string anio_busc;
    		bool band;
    		do {
    			cout<<"Ingrese el AC1o de Publicacion a buscar(E para salir): "<<endl;
    			cin>>anio_busc;
    			cout<<"Libros del aC1o "<<anio_busc<<endl;

    			for(size_t i = 0; i < libros.size(); i++) {
    				if(borrar_espacios(anio_busc) == borrar_espacios(libros[i].get_anio_P())) {
    					libros[i].mostrarLibro();
    					band = true;
    				}
    			}
    		} while(!band && anio_busc != "E" && anio_busc != "e");

    		break;
    	}

    	case '7' : {
    	    bool band;

               do {
                band = false;

    			cout<<" 1/LIBROS NO DISPONIBLES     2/ LIBROS DISPONIBLES   3/SALIR"<<endl;
    			cin >> opcionCase7;

                if(opcionCase7 == 1 || opcionCase7 == 2){

                    opcionCase7 -=1;
                    for(size_t i = 0; i < libros.size(); i++){

                        if(opcionCase7 == libros[i].getEstadoSN() ){

                            libros[i].mostrarLibro();

                        }
                    }
                     band = false;

                }else if(opcionCase7 != 1 && opcionCase7 != 2 && opcionCase7 != 3){
                   cout<< "OPCION INVALIDA"<< endl;
                   band = true;
                }

    		} while(!band && opcionCase7 != 3);
    	}
    	case '8' : {

    	    cout<< "INGRESE UBICACION DEL LIBRO"<< endl;
    	    cout<< "COLUMNA: ";
    	    cin >> columnaB;
    	    cin.ignore();

    	    cout<< "FILA: ";
    	    cin >> filaB;
    	    cin.ignore();

    	    for(size_t i=0; i<libros.size(); i++){

                if( ( columnaB == libros[i].getColumna() ) && ( filaB == libros[i].getFila() ) ){

                    libros[i].mostrarLibro();
                }
    	    }

    		break;
    	}
    	case '9' : {

    	    cout<< "INGRESE EL ESTADO  QUE QUIERE BUSCAR ( BUENO - REGULAR - MALO - DESTRUIDO ): ";
    	    cin >> busquedaEstado;

    	    busquedaEstado = a_minusculas(busquedaEstado);

    	    for(size_t i=0; i< libros.size(); i++){

                if(busquedaEstado == libros[i].getEstado() ){

                    libros[i].mostrarLibro();
                }
    	    }

    		break;
    	}

    	case 's' | 'S' : {

            cout<< "SALIENDO"<< endl;
            break;
    	}
    	default: {
    	    cout<< "OPCION INVALIDA ( MENU BUSQUEDA_LIBRO )"<< endl;
    		break;
    	}
	}

	return flagID;
}

/**---------------------------------------------------------------------------------------------------*/

void mostrarL(vector <libro>& vectorLibro){

    for(size_t i=0; i<vectorLibro.size(); i++){

        vectorLibro[i].mostrarLibro();
    }
    cout<< "------------------------------"<< endl;
}

/**---------------------------------------------------------------------------------------------------*/
