#include <iostream>
#include <fstream>
#include "getch.h"
#include "estructuras.h"
#include "GestorSanciones.h"
using namespace std;

void clear() {
    ifstream archivo("/etc/os-release");
    if (archivo.good()) {
        system("clear");
    } else {
        system("cls");
    }
}

int main() {
    // crear objeto GestorSanciones
    cadena fSanciones   = "sanciones";
    cadena fRadares     = "radares";
    cadena fVehiculos   = "coches.dat";
    cadena fTipoSancion = "tipossanciones.dat";

    GestorSanciones gs(fSanciones, fRadares, fVehiculos, fTipoSancion);

    // comprobar si el fichero de sanciones se abrio correctamente
    if (!gs.getFicheroSancionesActivo()) {
        cout << "ERROR. No se pudo abrir el fichero de sanciones." << endl;
        return 1;
    }

    char opcion = '0';
    while (opcion == '0') {
        clear();
        cout << "SANCIONES APP. MENU PRINCIPAL." << endl;
        cout << "========================================" << endl;
        cout << "    1. Consultar Vehiculo." << endl;
        cout << "    2. Anyadir vehiculo." << endl;
        cout << "    3. Mostrar radares." << endl;
        cout << "    4. Mostrar radar." << endl;
        cout << "    5. Procesar radar." << endl;
        cout << "    6. Mostrar fichero de sanciones." << endl;
        cout << "    7. Mostrar cuantia de sancion." << endl;
        cout << "    8. Salir." << endl;
        cout << "Seleccione una opcion: ";
        opcion = getch();
        clear();

        switch (opcion) {
            case '1': {
                cadena matricula;
                cout << "Introduce la matricula: ";
                cin >> matricula;
                if (!gs.mostrarVehiculo(matricula)) {
                    cout << "ERROR. No se encontro ningun vehiculo con esa matricula." << endl;
                }
                break;
            }
            case '2': {
                coche v;
                cout << "Introduce la matricula: ";
                cin >> v.matricula;
                cout << "Introduce la fecha de ITV (dia mes anno): ";
                cin >> v.fechaitv.dia >> v.fechaitv.mes >> v.fechaitv.anno;
                cout << "Introduce la marca: ";
                cin >> v.marca;
                cout << "Introduce el modelo: ";
                cin >> v.modelo;
                if (gs.anyadirVehiculo(v)) {
                    cout << "Vehiculo anyadido correctamente." << endl;
                } else {
                    cout << "ERROR. No se pudo anyadir el vehiculo." << endl;
                }
                break;
            }
            case '3': {
                gs.mostrarRadares();
                break;
            }
            case '4': {
                int codigo;
                cout << "Introduce el codigo del radar: ";
                cin >> codigo;
                if (!gs.mostrarRadar(codigo)) {
                    cout << "ERROR. No se encontro ningun radar con ese codigo." << endl;
                }
                break;
            }
            case '5': {
                int codigo;
                cout << "Introduce el codigo del radar a procesar: ";
                cin >> codigo;
                if (gs.procesarRadar(codigo)) {
                    cout << "Radar procesado correctamente." << endl;
                } else {
                    cout << "ERROR. No se pudo procesar el radar." << endl;
                }
                break;
            }
            case '6': {
                gs.mostrarSanciones();
                break;
            }
            case '7': {
                int anno;
                cout << "Introduce el anno: ";
                cin >> anno;
                if (!gs.mostrarTipoSancion(anno)) {
                    cout << "ERROR. No se encontro ninguna cuantia para ese anno." << endl;
                }
                break;
            }
            case '8': {
                return 0;
            }
            default: {
                cout << "ERROR. Opcion no valida." << endl;
                opcion = '0';
            }
        }

        if (opcion != '0') {
            cout << "\nPulse cualquier tecla para continuar...";
            getch();
            opcion = '0';
        }
    }

    return 0;
}
