#include "structuras.cpp"
#include "GestorSanciones.h"

using namespace std;

class GestorSancios {
	fstream ficheroSancios;
	cadena nomFicheroRadares;
	cadena nomFicherosVehiculos;
	cadena nomFicherosTipoSancion;
	bool ficheroSancionesActivo;
}
public:
	~GestorSancios();
	GestorSancios(cadena nFSanciones, cadena nFRadares, cadena nFVehiculos, cadena nFTipoSancion);
	bool getFicheroSancionesActivo();
	void getNomFicheroVehiculos(cadena nF);
	void getNomFicheroTipoSancion(cadena nF);
	void mostrarRadares();
	bool mostrarRadar(int c);
	bool mostrarLecturasRadar(int c);
	bool procesarRadar(int c);
	bool mostrarVehiculo(cadena m);
	bool anyadirVehiculo(coche v);
	bool mostrarTipoSancion(int a);
	void mostrarSanciones();
};
