#ifndef TAULER_H
#define TAULER_H
#include "Figura.h"

const int MAX_FILA = 8;
const int MAX_COL = 8;
//ñ se puede hacer que vaya mirando fila por fila en cada iteración o es mucho tiempo? para poder bajar las figuras cuando se elimina una fila.
class Tauler
{
private:
	int m_tauler[MAX_FILA][MAX_COL];
	//Figura figura;
	
public:
	Tauler();
	int comprovaFiles(); // comprueba todas las filas del tablero y vacia si hay alguna completa
	bool girValid();
	bool movimentValid(); // COMPRUEBA SI HAY ALGUNA COLISION
	void eliminaFila();
};
#endif