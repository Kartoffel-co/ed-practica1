#include <iostream>
#include <fstream>
#include <conio>
using namespace std;

int main() 
{	
	char opcion;
	while (opcion!=8)
	{
		cout<<opcion<<enl<<endl;
		cout<<"SANCIONES APP. MENU PRINCIPAL"<<endl;
		cout<<"===================================="<<endl;
		cout<<"	1. Consultar cehiculo."<<endl;
		cout<<"	2. Añadir vehiculo."<<endl;
		cout<<"	3. Mostrar radares."<<endl;
		cout<<"	4. Mostrar radar."<<endl;
		cout<<"	5. Procsar radar."<<endl;
		cout<<"	6. Mostrar fichero de sanciones."<<endl;
		cout<<"	7. Mostrar cuantia de sancion."<<endl;
		cout<<"	8. Salir."<<endl;
		opcion=getch();
	};
	system("clear");
	return 0;		
};
