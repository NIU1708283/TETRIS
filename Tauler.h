#ifndef TAULER_H
#define TAULER_H
#include "Figura.h"
#include <string>
using namespace std;

const int MAX_FILA = 8;
const int MAX_COL = 8;

class Tauler
{
private: // en vez de mirar los bloques, miraremos los colores de los bloques
	ColorFigura m_tauler[MAX_FILA][MAX_COL];
	bool casellaCorrecta(const Casella& pos) const; // comprueba si la casilla está dentro del tablero
	
public:
	Tauler();
	void inicialitzaTauler(ColorFigura tauler[MAX_FILA][MAX_COL]); // inicializa el tablero todo a COLOR_NEGRE

	bool movimentValid(const Figura& figura, const Casella& pos) const; /// COMPRUEBA SI HAY ALGUNA COLISION DE CUALQUIER TIPO
	void eliminaFigura(const Figura& figura, const Casella& pos); // debe eliminar la figura del tablero para poder dibujarla en otra posición
	void setFigura(Figura figura, const Casella& pos); // debe dibujar la figura en el tablero

	int eliminaFilas(); // comprueba todas las filas del tablero y vacia las completas y devuelve el número de filas eliminadas


	// estas dos sirven para guardar y recuperar la información del tablero
	void setTauler(const int& fila, const int& col, const ColorFigura& color) { m_tauler[fila][col] = color; }
	ColorFigura getTauler(const int& fila, const int& col) const { return m_tauler[fila][col]; }


};
#endif