#include "buscar_socios.h"

/**---------------------------------------------------------------------------------------------------*/

int busquedaSocios(vector<socio>& socios){

	string eleccion;
	int flagDNI = -1;///INDICA EL INDICE DEL SOCIO ENCONTRADO -- USADO EN MAIN -- LINEA  78

	do {
		cout<< "Seleccione una opcion de busqueda y filtrado de socios: "<<endl;
		cout<< " 1.Apellido\n 2.Dni\n 3.Sexo\n 4.Direccion\n 5.Numero de Telefono\n 6.Edad\n 7.Fecha de Nacimiento\n 8.Mail\n 'S'/SALIR"<<endl << ">";
		cin >> eleccion;

	} while(eleccion != "1" && eleccion != "2" && eleccion != "3" && eleccion != "4" && eleccion != "5"&& eleccion != "6"&& eleccion != "7"&& eleccion != "8");

	int opcion = stoi(eleccion); //evitamos overflow de int, hacemos string to int

	switch(opcion) {
    	case 1: {
    		bool existe;
    		string apellido_busc;

    		do {
    			existe = false;
    			cout<<"Ingrese el Apellido a Buscar(E para salir): "<<endl;
    			cin>>apellido_busc;

                ///PASA TODO EL STRING A MINUSCULA
    			apellido_busc = a_minusculas(quitar_tildes(apellido_busc));

    			for(size_t i = 0; i<socios.size(); i++) {

                    ///COMPARA EL APELLIDO INGRESO CON EL APELLIDO DEL OBJETO PASADO A MINUSCULA
    				if(apellido_busc == a_minusculas(socios[i].getapll() ) ) {
                    //size_t es un unsigned long long

    					socios[i].mostrarSocio();
    					existe = true;
    					flagDNI = i;

    				}
    			}

    			if(!existe) {
    				cout<<"El apellido indicado no existe."<<endl;
    			}

    		}while(!existe && apellido_busc != "E" && apellido_busc != "e");
    	}
    	break;

    	case 2: {
    		bool existe ;
    		string dni_ ;

    		do {
    			existe = false;
    			cout<<"Ingrese el Dni a Buscar(E para salir): "<<endl;
    			cin >> dni_;

    			for(size_t i = 0; i<socios.size(); i++){

    				if(dni_ == socios[i].getdni()) {
    					socios[i].mostrarSocio();
    					existe = true;
    					flagDNI = i;
    				}
    			}

    			if(!existe) {
    				cout<<"El Dni no existe."<<endl;
    			}

    		} while(!existe && dni_ != "E" && dni_ != "e");
    	}
    	break;

    	case 3: {
    		string sexo_busc;
    		cout<<"Ingrese el sexo a buscar(female, male) o E para salir: "<<endl;
    		cin >> sexo_busc;

    		sexo_busc = a_minusculas(sexo_busc);

    		while(sexo_busc !="male" && sexo_busc != "female" && sexo_busc != "E" && sexo_busc != "e") { //no tiene q ser ninguna de las 4 opciones para seguir pidiendo el ingreso

    			cout<<"El sexo ingresado no existe."<<endl;
    			cout<<"Ingrese el sexo a buscar(female, male): "<<endl;
    			cin>>sexo_busc;

    			sexo_busc = a_minusculas(sexo_busc);
    		}

    		for(size_t i = 0; i<socios.size(); i++ ) {
    			if(sexo_busc == socios[i].getsex()) {
    				socios[i].mostrarSocio();
    			}
    		}
    	}
    	break;

    	case 4: {
    		string direccion_busc;
    		bool bandera;
    		cin.ignore();
    		do {
    			bandera = false;
    			cout<<"Ingrese la Direccion a buscar(E para salir): "<<endl;
                //ignora el salto de linea(que queda en el buffer despues de leer) para que getline funcione correctamente
    			getline(cin, direccion_busc);

    			direccion_busc = borrar_espacios(a_minusculas(direccion_busc) );

    			for(size_t i = 0; i<socios.size(); i++ ) {

    				if(direccion_busc == borrar_espacios(a_minusculas(socios[i].getdir() ) ) ){
    					socios[i].mostrarSocio();
    					bandera = true;
    				}
    			}
    			if(!bandera) {
    				cout<<"La direccion ingresada no existe."<<endl;
    			}

    		} while(!bandera && direccion_busc != "E" && direccion_busc != "e");
    	}
    	break;

    	case 5: {
    		bool existe;
    		string num_busc;
    		do {
    			cout<<"Ingrese el numero a buscar(E para salir): "<<endl;
    			getline(cin, num_busc);
                cin.ignore();

    			existe = false;

    			num_busc = borrar_espacios(num_busc);

    			for(unsigned long i = 0; i< socios.size(); i++) { //.Size devuelve un unsigned long

    				if(num_busc == borrar_espacios(socios[i].getnum() ) ) {

    					socios[i].mostrarSocio();
    					existe = true;
    				}
    			}
    			if(!existe) {
    				cout<<"El numero ingresado no existe."<<endl;
    			}

    		} while(!existe && num_busc != "E" && num_busc != "e");
    	}
    	break;

    	case 6: {
    		string entrada;
    		int opcion = 0;
    		cin.ignore();
    		do {
    			cout<<"Ingrese una opcion de busqueda de edad(E para salir): "<<endl;
    			cout<<"1.Mayores a 18.\t 2.Mayores a 30.\t 3.Mayores a 60.\t 4.Edad Especifica.\n"<<endl;

    			getline(cin, entrada); //almacenamos un string para evitar overflow si fuera un int

    		} while(entrada != "1" && entrada != "2" && entrada != "3" && entrada != "4" && entrada != "e" && entrada != "E"); //mientras no sea la correcta

    		if(entrada != "E" && entrada != "e") {
    			if (entrada == "1") {
    				opcion = 1;
    			}
    			else if (entrada == "2") {
    				opcion = 2;
    			}
    			else if (entrada == "3") {
    				opcion = 3;
    			}
    			else if (entrada == "4") {
    				opcion = 4;
    			}

    		}else{
                    opcion = 5 ;
            }

    		switch(opcion) {
    		case 1: { //+18
    			cout << "Socios Mayores a 18." << endl;
    			for (size_t i = 0; i < socios.size(); i++) {
    				string edad_str = socios[i].getedad();
    				if (es_entero_valido(edad_str) && stoi(edad_str) >= 18) {
    					socios[i].mostrarSocio();
    				}
    			}
    			break;
    		}

    		case 2: {
    			cout << "Socios Mayores a 60." << endl;
    			for (size_t i = 0; i < socios.size(); i++) {
    				string edad_str = socios[i].getedad();
    				if (es_entero_valido(edad_str) && stoi(edad_str) >= 60) {
    					socios[i].mostrarSocio();
    				}
    			}
    			break;
    		}

    		case 3: {
    			cout << "Socios Mayores a 60." << endl;
    			for (size_t i = 0; i < socios.size(); i++) {
    				if (es_entero_valido(socios[i].getedad()) && stoi(socios[i].getedad()) >= 60) {
    					socios[i].mostrarSocio();
    				}
    			}
    			break;
    		}

    		case 4: { //edad especifica
    			bool existe;
    			do {
    				string edad_busc;
    				existe  = false;

    				cout<<"Ingrese la edad a buscar: "<<endl;
    				cin>>edad_busc;

    				cout<<"Socios con "<<edad_busc<<" anios."<<endl;

    				for(size_t i = 0; i < socios.size(); i++) {
    					if(socios[i].getedad()  == edad_busc) {
    						socios[i].mostrarSocio();
    						existe  = true;
    					}
    				}
    			} while(!existe);
    			break;
    		}
    		case 5: {
    			cout<<"Saliendo del programa...."<<endl;
    		}
    		default: {
    			if(opcion != 5) {
    				cout<<"Opcion ingresada invalida."<<endl;
    			}
    		}
    		break;
    		}
    	}
    	break;
    	case 7: {
    		string fechaNaci_busc;
    		bool existe = false;

    		cout<<"Ingrese la Fecha de Nacimiento a buscar(mes/dia/anio(xx/xx/xxxx) o E para salir): "<<endl;
    		cin>>fechaNaci_busc;//xx/xx/xxxx

    		fechaNaci_busc = borrar_ceros(fechaNaci_busc);
    		fechaNaci_busc = normalizar_anio(fechaNaci_busc);

    		while(!fecha_valida(fechaNaci_busc) && fechaNaci_busc != "e" && fechaNaci_busc != "E") { //mientras no sea valida(consultar fecha_valida() para ver los formatos admitidos)
    			cout<<"Formato incorrecto o fecha inexistente."<<endl;
    			cout<<"Ingrese la Fecha de Nacimiento a buscar(mes/dia/anio(xx/xx/xxxx)): "<<endl;
    			cin>>fechaNaci_busc;
    			fechaNaci_busc = normalizar_anio(borrar_ceros(fechaNaci_busc));
    		}
    		for(unsigned long i = 0; i< socios.size(); i++) { //.Size devuelve un unsigned long
    			if(fechaNaci_busc == socios[i].getfechaN()) {
    				socios[i].mostrarSocio();
    				existe = true;
    			}
    		}
    		if(!existe && fechaNaci_busc != "e" && fechaNaci_busc != "E") {
    			cout<<"La fecha ingresada no existe."<<endl;
    		}
    	}
    	break;
    	case 8: {
    		bool band;
    		string mail_busc;
    		do {
    			band = false;
    			cout<<"Ingrese el Email a Buscar(E para salir): "<<endl;
    			cin>>mail_busc;

    			mail_busc = a_minusculas(mail_busc);

    			for(unsigned long i = 0; i<socios.size(); i++) {
    				if(a_minusculas(socios[i].getmail()) == mail_busc) {
    					socios[i].mostrarSocio();
    					band = true;
    					flagDNI = i;
    				}
    			}
    			if(!band && mail_busc != "e" && mail_busc != "E") {
    				cout<<"El email "<<mail_busc<<" no existe."<<endl;
    			}
    		} while(!band && mail_busc != "e" && mail_busc != "E");
    	}
    	break;

    	case 's' | 'S' : {

            cout<< "SALIENDO AL MENU PRINCIAL"<< endl;
    	}

    	default: {
    		cout<<"Error."<<endl;
    		break;
    	}
    }

    return flagDNI;
}

/**---------------------------------------------------------------------------------------------------*/
