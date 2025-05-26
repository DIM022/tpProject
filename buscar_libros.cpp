#include "buscar_libros.h"
#include "funcionesLibro.h"

int estadoBSN = 0;

void busqueda_libros(vector<libro> libros) {

	string eleccion;

	do {
		cout<<"Seleccione una opcion de busqueda y filtrado de libros: "<<endl;
		cout<<" 1.Nombre\n 2.Area\n 3.Sub Area\n 4.Autores\n 5.Editorial\n 6.Anio de Publicacion\n"
            << "7.Estado ( Disponible / No Disponible )\n 8.Ubicacion\n 9.Estado(Prestado, Devuelto)\n"<<endl;
		cin>>eleccion;

	} while(eleccion != "1" && eleccion != "2" && eleccion != "3" && eleccion != "4" && eleccion != "5" && eleccion != "6" && eleccion != "7" && eleccion != "8" && eleccion != "9" );

    //todas tienen que ser falsas para seguir pidiendo el ingreso;
	int opcion = 0;
	opcion = stoi(eleccion);

	switch(opcion) {
    	case 1: {
    		bool band;
    		string nombre_busc;
    		cin.ignore();

    		do {

    			band = 0;
    			cout<<"Ingrese el nombre del libro a buscar(E para salir): "<<endl;
    			getline(cin, nombre_busc);
    			nombre_busc = a_minusculas(quitar_tildes(nombre_busc));
    			for(unsigned long i = 0; i<libros.size(); i++) {
    				if(borrar_espacios(nombre_busc) == borrar_espacios(a_minusculas(quitar_tildes(libros[i].get_nombre())))) {
    					libros[i].mostrarLibro();
    					band = 1;
    				}
    			}
    		} while(!band && nombre_busc != "E" && nombre_busc != "e");
    		break;
    	}
    	case 2: {
    		string area_busc;
    		bool exist = false;
    		cin.ignore();
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
    	case 3: {
    		cin.ignore();//limpiar buffer
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
    	case 4: {
    		bool band;
    		string autor_busc;
    		cin.ignore();
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
    	case 5: {
    		bool band;
    		string edi_busc;
    		cin.ignore();
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
    	case 6: {
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

    	case 7: {
    	    bool band;

               do {
                band = false;

    			cout<<" 1/LIBROS NO DISPONIBLES     2/ LIBROS DISPONIBLES   3/SALIR"<<endl;
    			cin >> estadoBSN;

                if(estadoBSN == 1 || estadoBSN == 2){

                    estadoBSN -=1;
                    for(size_t i = 0; i < libros.size(); i++){

                        if(estadoBSN == libros[i].getEstadoSN() ){

                            libros[i].mostrarLibro();

                        }
                    }
                     band = false;

                }else if(estadoBSN != 1 && estadoBSN != 2 && estadoBSN != 3){
                   cout<< "OPCION INVALIDA"<< endl;
                   band = true;
                }

    		} while(!band && estadoBSN != 3);
    	}
    	case 8: {
    		break;
    	}
    	case 9: {
    		break;
    	}
    	default: {
    		break;
    	}
	}
}
