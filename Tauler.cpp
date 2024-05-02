#include "Tauler.h"
#include <fstream>

// inicializa el tablero con todos los valores a NO_COLOR
Tauler::Tauler()
{
    for (int i = 0; i < MAX_FILA; i++)
    {
        for (int j = 0; j < MAX_COL; j++)
        {
            m_tauler[i][j] = NO_COLOR;
        }
    }
}

// inicializa el tablero con todos los valores a NO_COLOR
void Tauler::inicialitzaTauler()
{
    for (int i = 0; i < MAX_FILA; i++)
    {
        for (int j = 0; j < MAX_COL; j++)
        {
            m_tauler[i][j] = NO_COLOR;
        }
    }
}

// comprueba si cualquier figura puede moverse a la posición indicada (casilla de referencia)
bool Tauler::movimentValid(const Figura& figura, int fila, int col) const // solo tiene que comprobar que la figura se puede mover
{
    //ñ fila y col deben ser las coordenadas del centro de la figura en el tablero

    int filaFig, colFig; // espacios del tablero
    int forma[MAX_ALCADA][MAX_AMPLADA]; 
    figura.getForma(forma); // forma de la figura guardada en una variable auxiliar

    // se debe separar en 2 casos: figura 3x3 (la figura 2x2 tiene el mismo centro) y figura 4x4

    if (figura.getTipus() != FIGURA_I)
    {
        for (int i = 0; i < MAX_ALCADA-1; i++) // el -1 es pq es una figura 3x3
        {
            for (int j = 0; j < MAX_AMPLADA-1; j++) // el -1 es pq es una figura 3x3
            {
                filaFig = (fila - 1) + i; // espacio que ocupa la figura dentro del tablero
                colFig = (col - 1) + j; // se coloca un "-1" pq el centro de la figura es el 1,1 y queremos mirar a partir de la posición 0,0
                if (forma[i][j] != NO_COLOR) // si la figura tiene color (no es un 0)
                {
                    if (filaFig < 0 || filaFig >= MAX_FILA || colFig < 0 || colFig >= MAX_COL || m_tauler[filaFig][colFig] != NO_COLOR)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    else // figura 4x4
    {
        if (figura.getGir() == 0)
        {
            for (int i = 0; i < MAX_ALCADA; i++)
            {
                for (int j = 0; j < MAX_AMPLADA; j++)
                {
                    filaFig = (fila - 1) + i; // espacio que ocupa la figura dentro del tablero
                    colFig = (col - 2) + j; // se coloca un "-2" pq el centro de la figura es el 1,2 y queremos mirar a partir de la posición 0,0
                    if (forma[i][j] != NO_COLOR) // si la figura tiene color (no es un 0)
                    {
                        if (filaFig < 0 || filaFig >= MAX_FILA || colFig < 0 || colFig >= MAX_COL || m_tauler[filaFig][colFig] != NO_COLOR)
                        {
                            return false;
                        }
                    }
                }
            }
            return true;
        }
        if (figura.getGir() == 1)
		{
            for (int i = 0; i < MAX_ALCADA; i++)
            {
                for (int j = 0; j < MAX_AMPLADA; j++)
                {
                    filaFig = (fila - 2) + i; // espacio que ocupa la figura dentro del tablero
                    colFig = (col - 2) + j; // se coloca un "-2" pq el centro de la figura es el 2,2 y queremos mirar a partir de la posición 0,0
                    if (forma[i][j] != NO_COLOR) // si la figura tiene color (no es un 0)
                    {
                        if (filaFig < 0 || filaFig >= MAX_FILA || colFig < 0 || colFig >= MAX_COL || m_tauler[filaFig][colFig] != NO_COLOR)
                        {
                            return false;
                        }
                    }
                }
            }
            return true;
		}
		if (figura.getGir() == 2)
		{
            for (int i = 0; i < MAX_ALCADA; i++)
            {
                for (int j = 0; j < MAX_AMPLADA; j++)
                {
                    filaFig = (fila - 2) + i; // espacio que ocupa la figura dentro del tablero
                    colFig = (col - 1) + j; // se coloca un "-1" pq el centro de la figura es el 2,1 y queremos mirar a partir de la posición 0,0
                    if (forma[i][j] != NO_COLOR) // si la figura tiene color (no es un 0)
                    {
                        if (filaFig < 0 || filaFig >= MAX_FILA || colFig < 0 || colFig >= MAX_COL || m_tauler[filaFig][colFig] != NO_COLOR)
                        {
                            return false;
                        }
                    }
                }
            }
            return true;
		}
		if (figura.getGir() == 3)
		{
            for (int i = 0; i < MAX_ALCADA; i++)
            {
                for (int j = 0; j < MAX_AMPLADA; j++)
                {
                    filaFig = (fila - 1) + i; // espacio que ocupa la figura dentro del tablero
                    colFig = (col - 1) + j; // se coloca un "-1" pq el centro de la figura es el 1,1 y queremos mirar a partir de la posición 0,0
                    if (forma[i][j] != NO_COLOR) // si la figura tiene color (no es un 0)
                    {
                        if (filaFig < 0 || filaFig >= MAX_FILA || colFig < 0 || colFig >= MAX_COL || m_tauler[filaFig][colFig] != NO_COLOR)
                        {
                            return false;
                        }
                    }
                }
            }
            return true;
		}
    }
}

// mueve la figura a la posición indicada (casilla de referencia)
void Tauler::mouFigura(const Figura& figura, const int& fila, const int& col)
{
    int forma[MAX_ALCADA][MAX_AMPLADA];
    figura.getForma(forma); // forma de la figura guardada en una variable auxiliar

    if (figura.getTipus() != FIGURA_I) // si la figura es 3x3 o menor
    {
        for (int i = 0; i < MAX_ALCADA - 1; i++) // el -1 es pq es una figura 3x3
        {
            for (int j = 0; j < MAX_AMPLADA - 1; j++)
            {
                if (forma[i][j] != NO_COLOR)
                {
                    m_tauler[fila - 1 + i][col - 1 + j] = figura.getColor(); // se coloca el color del bloque i,j en el tablero
                }
            }
        }
    }
    else // si la figura es 4x4
    {
        if (figura.getGir() == 0)
        {
            for (int i = 0; i < MAX_ALCADA; i++)
            {
                for (int j = 0; j < MAX_AMPLADA; j++)
                {
                    if (forma[i][j] != NO_COLOR)
                    {
                        m_tauler[fila - 1 + i][col - 2 + j] = figura.getColor(); // se coloca el color del bloque i,j en el tablero
                    }
                }
            }
        }
        if (figura.getGir() == 1)
		{
            for (int i = 0; i < MAX_ALCADA; i++)
            {
                for (int j = 0; j < MAX_AMPLADA; j++)
                {
                    if (forma[i][j] != NO_COLOR)
                    {
                        m_tauler[fila - 2 + i][col - 2 + j] = figura.getColor(); // se coloca el color del bloque i,j en el tablero
                    }
                }
            }
		}
        if (figura.getGir() == 2)
        {
            for (int i = 0; i < MAX_ALCADA; i++)
            {
                for (int j = 0; j < MAX_AMPLADA; j++)
                {
                    if (forma[i][j] != NO_COLOR)
                    {
                        m_tauler[fila - 2 + i][col - 1 + j] = figura.getColor(); // se coloca el color del bloque i,j en el tablero
                    }
                }
            }
        }
        if (figura.getGir() == 3)
		{
            for (int i = 0; i < MAX_ALCADA; i++)
            {
                for (int j = 0; j < MAX_AMPLADA; j++)
                {
                    if (forma[i][j] != NO_COLOR)
                    {
                        m_tauler[fila - 1 + i][col - 1 + j] = figura.getColor(); // se coloca el color del bloque i,j en el tablero
                    }
                }
            }
		}
    }
}

// elimina UNA UNICA fila del tablero, desplazando las filas superiores hacia abajo y poniendo la fila superior a NO_COLOR
void Tauler::eliminaFila(const int& fila)
{
    for (int f = fila; f > 0; f--)
    {
        for (int j = 0; j < MAX_COL; j++)
        {
            m_tauler[f][j] = m_tauler[f - 1][j];
        }
    }
    for (int j = 0; j < MAX_COL; j++)
    {
        m_tauler[0][j] = NO_COLOR;
    }
}
