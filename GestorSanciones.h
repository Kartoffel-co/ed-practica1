#ifndef GESTORSANCIONES_H
#define GESTORSANCIONES_H

#include <iostream>
#include <fstream>
#include <cstring>
#include "estructuras.h"  // ← donde están cadena, radartramo, coche, etc.

using namespace std;

class GestorSanciones {
	fstream ficheroSanciones;
	cadena nomFicheroRadares;
	cadena nomFicheroVehiculos;
	cadena nomFicheroTipoSancion;
	bool ficheroSancionesActivo;

	bool esFechaPosterior(tlectura lectura2, tlectura lectura1);
	int calcularTiempo(tlectura lectura1, tlectura lectura2);
public:
	~GestorSanciones();
	GestorSanciones(cadena nFSanciones, cadena nFRadares, cadena nFVehiculos, cadena nFTipoSancion);
	bool getFicheroSancionesActivo();
	void getNomFicheroVehiculos(cadena &nF);
	void getNomFicheroTipoSancion(cadena &nF);
	void mostrarRadares();
	bool mostrarRadar(int c);
	bool mostrarLecturasRadar(int c);
	bool procesarRadar(int c);
	bool mostrarVehiculo(cadena m);
	bool anyadirVehiculo(coche v);
	bool mostrarTipoSancion(int a);
	void mostrarSanciones();
};
