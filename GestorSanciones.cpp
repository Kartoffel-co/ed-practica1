#include "GestorSanciones.h"



GestorSanciones::GestorSanciones(cadena nFSanciones, cadena nFRadares, cadena nFVehiculos, cadena nFTipoSancion){
    strcpy(nFRadares, nomFicheroRadares);
    strcpy(nFVehiculos, nomFicheroVehiculos);
    strcpy(nFTipoSancion, nomFicheroTipoSancion);
	ficheroSancionesActivo = false;
    ficheroSanciones.open(nFSanciones, ios::binary);

    if (ficheroSanciones.fail()){
        ficheroSancionesActivo = false;
    };

    ficheroSancionesActivo = true;
};

GestorSanciones::~GestorSanciones(){
	if (ficheroSanciones.is_open()){
		ficheroSanciones.close();
	}
};

bool GestorSanciones::getFicheroSancionesActivo(){
	return ficheroSancionesActivo;	
};

// privada

// publica
void GestorSanciones::getNomFicheroVehiculos(cadena &nF){
	strcpy(nF, nomFicheroVehiculos);
};

void GestorSanciones::getNomFicheroTipoSancion(cadena &nF){
	strcpy(nF, nomFicheroTipoSancion);
};

void GestorSanciones::mostrarRadares(){
	ifstream fradares;

	if (fradares.fail()){
		cout << "ERROR. No hay radares registrados en el sistema." << endl;
		fradares.close();
	} else {
		radartramo radar;
		fradares.open((char*) &radar, sizeof(radartramo));
		while (!fradares.fail()){
			cout << "Codigo:             " << radar.codigo << endl;
			cout << "Nombre:             " << radar.nombre << endl;
			cout << "Provincia:          " << radar.provincia << endl;
			cout << "Localizacion:       " << radar.localizacion << endl;
			cout << "Distancia:          " << radar.distancia << " km/h" <<endl;
			cout << "Velocidad maxima:   " << radar.velocidadMediaMaxima << " km/h" << endl;
			cout << "Fichero punto 1:    " << radar.ficheropunto1 << endl;
			cout << "Fichero punto 2:    " << radar.ficheropunto2 << endl << endl;
		}
	fradares.close();
	}		
};

bool GestorSanciones::mostrarRadar(int c){
	return false;
};

bool GestorSanciones::mostrarLecturasRadar(int c){
	return false;	
};

bool GestorSanciones::procesarRadar(int c){
	return false;	
};
bool GestorSanciones::mostrarVehiculo(cadena m){
	return false;	
};
bool GestorSanciones::anyadirVehiculo(coche v){
	return false;	
};
bool GestorSanciones::mostrarTipoSancion(int a){
	return false;	
};
void GestorSanciones::mostrarSanciones(){
	
};
