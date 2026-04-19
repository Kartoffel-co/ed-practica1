#include <iostream>
#include <fstream>
#include "getch.h"
#include "estructuras.h"
#include "GestorSanciones.h"

using namespace std;

void clear(){
	ifstream archivo("/etc/os-release");
        
        if (archivo.good()) {
                system("clear");
            } else {
                system("cls");
            };
};



int main(){ 
	char opcion='0';
	while (opcion=='0')
	{       	
		clear();
		cout<<"SANCIONES APP. MENU PRINCIPAL"<<endl;
		cout<<"===================================="<<endl;
        	cout<<"Indroduce un numero entre 1 y 8"<<endl;
		cout<<"	1. Consultar cehiculo."<<endl;
		cout<<"	2. Añadir vehiculo."<<endl;
		cout<<"	3. Mostrar radares."<<endl;
		cout<<"	4. Mostrar radar."<<endl;
		cout<<"	5. Procsar radar."<<endl;
		cout<<"	6. Mostrar fichero de sanciones."<<endl;
		cout<<"	7. Mostrar cuantia de sancion."<<endl;
		cout<<"	8. Salir."<<endl;
        	cout<<"Introduce una opcion entre 1 y 8";    
		opcion=getch();
	    	clear();
		
    		switch(opcion){
    			case '1':
			cout<<"1"<<endl;
			break;
   		case '2':
			cout<<"2"<<endl;
			break;
    		case '3':
			cout<<"3"<<endl;
			break;
    		case '4':
			cout<<"4"<<endl;
			break;
    		case '5':
			cout<<"5"<<endl;
			break;
    		case '6':
			cout<<"6"<<endl;
			break;
	    	case '7':
			cout<<"7"<<endl;
			break;
    		case '8':
			cout<<"8"<<endl;
			return 0;
    		default:
		opcion='0';
		}
    	}
	cout<<"salio"<<endl;
};
