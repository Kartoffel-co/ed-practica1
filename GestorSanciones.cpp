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
	};
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
	fradares.open(nomFicheroRadares, ios::binary);
	
	if (fradares.fail()){
		cout << "ERROR. No hay radares registrados en el sistema." << endl;
		fradares.close();
	} else {
		radartramo radar;
		fradares.read((char*) &radar, sizeof(radartramo));

		while (!fradares.fail()){
			cout << "Codigo:             " << radar.codigo << endl;
			cout << "Nombre:             " << radar.nombre << endl;
			cout << "Provincia:          " << radar.provincia << endl;
			cout << "Localizacion:       " << radar.localizacion << endl;
			cout << "Distancia:          " << radar.distancia << " km/h" <<endl;
			cout << "Velocidad maxima:   " << radar.velocidadMediaMaxima << " km/h" << endl;
			cout << "Fichero punto 1:    " << radar.ficheropunto1 << endl;
			cout << "Fichero punto 2:    " << radar.ficheropunto2 << endl << endl;
			fradares.read((char*) &radar, sizeof(radartramo));
		};
		
		fradares.close();
	};
};

bool GestorSanciones::mostrarRadar(int c){
	ifstream fradares;
	fradares.open(nomFicheroRadares, ios::binary);

	radartramo radar;
	fradares.read((char*) &radar, sizeof(radartramo));

	while (!fradares.fail()){
		if (radar.codigo == c){
			cout << "Codigo:             " << radar.codigo << endl;
			cout << "Nombre:             " << radar.nombre << endl;
			cout << "Provincia:          " << radar.provincia << endl;
			cout << "Localizacion:       " << radar.localizacion << endl;
			cout << "Distancia:          " << radar.distancia << " km/h" <<endl;
			cout << "Velocidad maxima:   " << radar.velocidadMediaMaxima << " km/h" << endl;
			cout << "Fichero punto 1:    " << radar.ficheropunto1 << endl;
			cout << "Fichero punto 2:    " << radar.ficheropunto2 << endl << endl;
			
			fradares.close();	
			return true;	
		};
		
		fradares.read((char*) &radar, sizeof(radartramo));
	};
	
	fradares.close();
	return false;
};

bool GestorSanciones::mostrarLecturasRadar(int c){
	ifstream fradares;
	fradares.open(nomFicheroRadares, ios::binary);

	radartramo radar;
	fradares.read((char*) &radar, sizeof(radartramo));

	while (!fradares.fail()){
		if (radar.codigo == c){
			fradares.close();
			
			ifstream fpunto1;
			ifstream fpunto2;

			fpunto1.open(radar.ficheropunto1, ios::binary);
			fpunto2.open(radar.ficheropunto2, ios::binary);

			if(fpunto1.fail() || fpunto2.fail()){
				fpunto1.close();
				fpunto2.close();
				return false;
			};
			
			lecturavehiculo punto1;
			lecturavehiculo punto2;

			fpunto1.read((char*) &punto1, sizeof(lecturavehiculo));
			fpunto2.read((char*) &punto2, sizeof(lecturavehiculo));
			//se entiende que los dos ficheros de lectura son simetricos

			
			while (!fpunto1.fail() && !fpunto2.fail()){
				cout << "Matricula: " << punto1.matricula;
				cout << "	Fecha: " << punto1.lec.fecha.dia << "/" << punto1.lec.fecha.mes << "/" << punto1.lec.fecha.anno;
				cout << "	Hora: " << punto1.lec.hora.hora << ":" << punto1.lec.hora.min << ":" << punto1.lec.hora.seg;

				cout << "		Matricula: " << punto2.matricula;
				cout << "	Fecha: " << punto2.lec.fecha.dia << "/" << punto2.lec.fecha.mes << "/" << punto2.lec.fecha.anno<<endl;

				fpunto1.read((char*) &punto1, sizeof(lecturavehiculo));
				fpunto2.read((char*) &punto2, sizeof(lecturavehiculo));
			}
			
			fpunto1.close();
			fpunto2.close();				
			return true;	
		};
		
		fradares.read((char*) &radar, sizeof(radartramo));
	};
	
	fradares.close();
	return false;	
};

bool GestorSanciones::procesarRadar(int c){
	return false;	
};

bool GestorSanciones::mostrarVehiculo(cadena m){
	int posicion = atoi(m) % 1000;

	ifstream fcoches;
	fcoches.open(nomFicheroVehiculos, ios::binary);

	if (fcoches.fail()){
		fcoches.close();
		return false;
	};

	coche vehiculo;
	
	fcoches.seekg(posicion * sizeof(coche), ios::beg);
	fcoches.read((char*) &vehiculo, sizeof(coche));

	if(fcoches.fail()){
		fcoches.close();
		return false;
	};

	cout << "Matricula: " << vehiculo.matricula;
	cout << "	Marca: " << vehiculo.marca;
	cout << "	Modelo: " << vehiculo.modelo;
	cout << "	Fecha ITV: " << vehiculo.fechaitv.dia << "/" << vehiculo.fechaitv.mes << "/" << vehiculo.fechaitv.anno;

	fcoches.close();
	return true;
};

bool GestorSanciones::anyadirVehiculo(coche v){
	int posicion = atoi(v.matricula) % 1000;

	fstream fcoches;
	fcoches.open(nomFicheroVehiculos, ios::in | ios::out | ios::binary);

	if (fcoches.fail()){
		fcoches.close();
		return false;
	};

	coche vehiculo;
	
	fcoches.seekg(posicion * sizeof(coche), ios::beg);
	fcoches.read((char*) &vehiculo, sizeof(coche));

	if(!fcoches.fail()){
			fcoches.close();
			return false;
	} else {
		fcoches.clear();
		fcoches.seekp(posicion * sizeof(coche), ios::beg);
		fcoches.write((char*) &v, sizeof(coche));
	};

	fcoches.close();
	return true;	
};
bool GestorSanciones::mostrarTipoSancion(int a){
	int posicion = a % 2000;

	ifstream fTipoSancion;
	fTipoSancion.open(nomFicheroTipoSancion, ios::binary);

	if (fTipoSancion.fail()){
		fTipoSancion.close();
		return false;
	};

	tipossanciones tiposancion;
	
	fTipoSancion.seekg(posicion * sizeof(tipossanciones), ios::beg);
	fTipoSancion.read((char*) &tiposancion, sizeof(tipossanciones));

	if(fTipoSancion.fail()){
		fTipoSancion.close();
		return false;
	};

	cout << "Anno: " << tiposancion.anno << endl;
	cout << "Euros: " << tiposancion.eurosv[0] << " , " << tiposancion.eurosv[1] << " , " << tiposancion.eurosv[2] << endl;
	cout << "Puntos Velocidad: " << tiposancion.puntosv[0] << " , " << tiposancion.puntosv[1] << " , " << tiposancion.puntosv[2] << endl;
	cout << "Puntos ITV: " << tiposancion.puntositv;

	fTipoSancion.close();
	return true;	
};
void GestorSanciones::mostrarSanciones(){
	
};
