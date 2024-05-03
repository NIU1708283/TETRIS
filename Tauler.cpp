#include "Tauler.h"
#include <fstream>


// comprueba si la posicon de la casilla es correcta/valida
bool Tauler::casellaCorrecta(const Casella& pos) const
{
    //verifica si la posición esta dentro del tablero y si esta ocupada (el color no es 0 (negro))
    if (pos.fila < 0 || pos.fila >= MAX_FILA || pos.columna < 0 || pos.columna >= MAX_COL || m_tauler[pos.fila][pos.columna] != COLOR_NEGRE)
        return false;

    return true;
}

// inicializa el tablero con todos los valores a COLOR_NEGRE
Tauler::Tauler()
{
    for (int i = 0; i < MAX_FILA; i++)
    {
        for (int j = 0; j < MAX_COL; j++)
        {
            m_tauler[i][j] = COLOR_NEGRE;
        }
    }
}

// inicializa el tablero con los valores del tablero que se pasa por parámetro
void Tauler::inicialitzaTauler(ColorFigura tauler[MAX_FILA][MAX_COL])
{
    for (int i = 0; i < MAX_FILA; i++)
    {
        for (int j = 0; j < MAX_COL; j++)
        {
            m_tauler[i][j] = tauler[i][j];
        }
    }
}

// comprueba si cualquier figura puede moverse a la posición indicada (casilla de referencia)
bool Tauler::movimentValid(const Figura& figura, const Casella& pos) const
{
    // se presupone que se ha eliminado la figura del tablero 

    bool valid = true;

    int i = 0;
    while (i < figura.getMida() && valid)
    {
        int j = 0;
        while (j < figura.getMida() && valid)
        {
            if (figura.getForma(i, j) != NO_COLOR) // si la figura tiene color
            {
                //se calcula la posición temporal de la celda actual
                Casella temp;
                temp.fila = pos.fila + i;
                temp.columna = pos.columna + j;

                //verifica si la posición es correcta/valida
                valid = casellaCorrecta(temp);
            }
            j++;
        }
        i++;
    }
    return valid;
}

// elimina la figura del tablero para poder dibujarla en otra posición
void Tauler::eliminaFigura(const Figura& figura, const Casella& pos)
{
    // pinta de negro las casillas de la figura
    for (int i = 0; i < figura.getMida(); i++)
    {
        for (int j = 0; j < figura.getMida(); j++)
        {
            if (figura.getForma(i, j) != NO_COLOR)
            {
                m_tauler[pos.fila + i][pos.columna + j] = COLOR_NEGRE;
            }
        }
    }
}

// pone la figura en la posición indicada (casilla de referencia)
void Tauler::setFigura(Figura figura, const Casella& pos) // figura no puede ser una constante pq se actualiza
{
    // se presupone que la posicion es válida

    for (int i = 0; i < figura.getMida(); i++)
        for (int j = 0; j < figura.getMida(); j++)
        {
            //dibuja la figura en cada casilla correspondiente
            if (figura.getForma(i, j) != NO_COLOR)
            {
                m_tauler[pos.fila + i][pos.columna + j] = figura.getColor();
            }
        }
    //actualitza la posicion de la figura
    figura.setCasella(pos);
}

// elimina filas del tablero, desplazando las filas superiores hacia abajo y poniendo la fila superior a NO_COLOR
int Tauler::eliminaFilas()
{
    int nFiles = 0; // nombre de filas eliminadas/completadas

    // Comprovar totes les files i buscar las filas completadas
    for (int i = 0; i < MAX_FILA; ++i)
    {
        bool completa = true;
        int j = 0;

        while (j < MAX_COL&& completa)
        {
            //compruebba si la fila esta completa
            if (m_tauler[i][j] == 0) 
            {
                completa = false;
            }
            j++;
        }

        //si esta completa, baja un nivel todas las filas superiores y añade una fila negra en la fila 0
        if (completa)
        {
            nFiles++;
            for (int f = i; f > 0; f--)
            {
                for (int c = 0; c < MAX_COL; c++)
                {
                    m_tauler[f][c] = m_tauler[f - 1][c];
                }
            }
            for (int c = 0; c < MAX_COL; c++)
            {
                m_tauler[0][c] = COLOR_NEGRE;
            }
        }

    }
    return nFiles;
}

