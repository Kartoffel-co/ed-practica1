#include <iostream>
#include <fstream>

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

	char opcion=0;
	while (opcion!='8')
	{        
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
        cout<<"Introduce un opcion";    
		opcion=getch();
        cout<<opcion;
	    clear();
    };
	clear();
	return 0;		
};
