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
	//Figura figura; // no se si es necesario
	
public:
	Tauler();
	void inicialitzaTauler();

	bool movimentValid(const Figura& figura, int fila, int col) const; // COMPRUEBA SI HAY ALGUNA COLISION DE CUALQUIER TIPO
	void setFigura (const Figura& figura, const int& fila, const int& col); // debe dibujar la figura en el tablero
	void eliminaFila(const int& fila); // comprueba todas las filas del tablero y vacia si hay alguna completa
	
	ColorFigura getColorCasella(const int& fila, const int& col) const { return m_tauler[fila][col]; }
	void setColorCasella(const int& fila, const int& col, const ColorFigura& color) { m_tauler[fila][col] = color; }
	void eliminaFigura(const Figura& figura); // debe eliminar la figura del tablero para poder dibujarla en otra posición
};
#endif