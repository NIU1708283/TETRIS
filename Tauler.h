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
	int m_fila;
	int m_col;
	
public:
	Tauler();
	void inicialitzaTauler(); // inicializa el tablero todo a COLOR_NEGRE

	bool movimentValid(const Figura& figura, const int& fila, const int& col) const; /// COMPRUEBA SI HAY ALGUNA COLISION DE CUALQUIER TIPO
	void eliminaFigura(const Figura& figura, const int& fila, const int& col); // debe eliminar la figura del tablero para poder dibujarla en otra posición
	void setFigura(const Figura& figura, const int& fila, const int& col); // debe dibujar la figura en el tablero

	// estas dos sirven para marcar y recuperar el color de una casilla
	void setColorCasella(const int& fila, const int& col, const ColorFigura& color) { m_tauler[fila][col] = color; }
	ColorFigura getColorCasella(const int& fila, const int& col) const { return m_tauler[fila][col]; }

	int getFila() const { return m_fila; }
	int getCol() const { return m_col; }	

	void setFila(const int& fila) { m_fila = fila; }
	void setCol(const int& col) { m_col = col; }
	

	void eliminaFila(const int& fila); // comprueba todas las filas del tablero y vacia si hay alguna completa
};
#endif