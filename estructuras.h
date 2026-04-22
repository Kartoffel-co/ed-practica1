#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

#include <iostream>

using namespace std;

typedef char cadena[50];

struct radartramo {
	int codigo; //código identificador único del radar.
	cadena nombre; //nombre del radar.
	cadena provincia; //provincia en la que se ubica el radar.
	cadena localizacion; //localización exacta del radar.
	float distancia; //distancia (en km) que separa los puntos de captura.
	int velocidadMediaMaxima; //velocidad máxima permitida en el tramo.
	cadena ficheropunto1; //fichero de lecturas de coches en el punto 1.
	cadena ficheropunto2; //fichero de lectura de coches en el punto 2.
};

struct tfecha{
	int dia;
	int mes;
	int anno;
};

struct thora{
	int hora;
	int min;
	int seg;
};

struct tlectura {
	tfecha fecha;
	thora hora;
};

struct lecturavehiculo {
	cadena matricula; //matrícula del vehículo.
	tlectura lec; //fecha y hora a la que se ha generado la lectura.
};

struct coche {
	cadena matricula;//matrícula del vehículo.
	tfecha fechaitv;//fecha de caducidad de la última inspección realizada del vehículo.
	cadena marca;//marca del vehículo.
	cadena modelo;//modelo del vehículo.
};

struct tipossanciones {
	int anno;//año de vigencia de las sanciones.
	float eurosv[3];
	int puntosv[3];
	int puntositv;
};

struct sanciones {
	cadena matricula;//matrícula del vehículo sancionado.
	float euros;//cuantía en euros de la multa emitida por la infracción.
	int puntos;//número de puntos de carné sancionados (si procede).
	int codRadar;//código identificador del radar que registró la infracción.
	tlectura fh;//fecha/hora de la infracción (fecha/hora del paso del vehículo por el
	//punto 2 del radar).
};
#endif
