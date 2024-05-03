#include "Joc.h"
#include <fstream>
using namespace std;


void Joc::inicialitza(const string& nomFitxer)
{
    ifstream fitxer;
    fitxer.open(nomFitxer);
    if (fitxer.is_open())
    {
        int tipus, fila, columna, gir;
        fitxer >> tipus >> fila >> columna >> gir;
        while (!fitxer.eof())
        {
            m_tauler.inicialitzaTauler(); // inicializa el tablero todo a COLOR_NEGRE

            for (int i = 0; i < MAX_FILA; i++)
            {
                for (int j = 0; j < MAX_COL; j++)
                {
                    int color;
                    fitxer >> color;
                    if (color != NO_COLOR)
                    {
                        m_tauler.setColorCasella(i, j, static_cast<ColorFigura>(color)); // pasa de int a ColorFigura
                    }
                }
            }
        }
        m_figuraActual = Figura(static_cast<TipusFigura>(tipus)); // pasa de int a TipusFigura
        for (int i = 0; i < (gir + 1); i++)
        {
            m_figuraActual.girarFigura(GIR_HORARI); // gira la figura a su posición correspondiente
        }
        m_tauler.setFigura(m_figuraActual, fila, columna); // mueve la figura a su posición correspondiente dentro del tablero

        fitxer.close();
    }
}

bool Joc::giraFigura(DireccioGir direccio)
{
    m_tauler.eliminaFigura(m_figuraActual, m_tauler.getFila(), m_tauler.getCol()); // elimina la figura del tablero evitar colision con ella misma
    Figura figuraGirada = m_figuraActual;
    figuraGirada.girarFigura(direccio);
    if (m_tauler.movimentValid(figuraGirada, m_tauler.getFila(), m_tauler.getCol()))
    {
        m_figuraActual = figuraGirada;
        m_tauler.setFigura(m_figuraActual, m_tauler.getFila(), m_tauler.getCol());
        return true;
    }
    else
    {
        m_tauler.setFigura(m_figuraActual, m_tauler.getFila(), m_tauler.getCol());
        return false;
    }
    
}

bool Joc::mouFigura(int dirX) // vale 1 si se mueve a la derecha y -1 si se mueve a la izquierda
{
    Figura figuraMoguda = m_figuraActual;
    m_tauler.eliminaFigura(m_figuraActual, m_tauler.getFila(), m_tauler.getCol());

    if (m_tauler.movimentValid(figuraMoguda, m_tauler.getFila(), m_tauler.getCol() + dirX))
    {
        m_tauler.setCol(m_tauler.getCol() + dirX);
        m_figuraActual = figuraMoguda;
        m_tauler.setFigura(m_figuraActual, m_tauler.getFila(), m_tauler.getCol());
        return true;
    }
    else
    {
		m_tauler.setFigura(m_figuraActual, m_tauler.getFila(), m_tauler.getCol());
        return false;
	}
}

int Joc::baixaFigura()
{
    m_tauler.eliminaFigura(m_figuraActual, m_tauler.getFila(), m_tauler.getCol());
    Figura figuraBaixada = m_figuraActual;
    figuraBaixada.baixarFigura();
    if (m_tauler.movimentValid(figuraBaixada, m_tauler.getFila() + 1, m_tauler.getCol()))
    {
        m_tauler.setFila(m_tauler.getFila() + 1);
        m_figuraActual = figuraBaixada; // si se puede bajar la figura, se baja
        m_tauler.setFigura(m_figuraActual, m_tauler.getFila(), m_tauler.getCol());
        return 0;
    }
    else // si no se puede bajar, comprobara si hay alguna fila completa
    {
        m_tauler.setFigura(m_figuraActual, m_tauler.getFila(), m_tauler.getCol());
        int filesEliminades = 0;
        for (int fila = 0; fila < MAX_FILA; fila++)
        {
            bool filaCompleta = true;
            for (int col = 0; col < MAX_COL; col++)
            {
                if (m_tauler.getColorCasella(fila, col) == COLOR_NEGRE)
                {
                    filaCompleta = false;
                    break; // se que esto se tiene que cambiar por un while, pero no es tan aestetic como un break
                }
            }
            if (filaCompleta)
            {
                m_tauler.eliminaFila(fila); // si la fila esta completa, la elimina
                filesEliminades++;
            }
        }
        return filesEliminades;
    }
}

void Joc::escriuTauler(const string& nomFitxer)
{
    ofstream fitxer;
    fitxer.open(nomFitxer);
    if (fitxer.is_open())
    {
        // guarda el contenido de la figura actual
        fitxer << static_cast<int>(m_figuraActual.getTipus()) << " "; // pasa de TipusFigura a int
        fitxer << m_tauler.getFila() << " ";
        fitxer << m_tauler.getCol() << " ";
        fitxer << m_figuraActual.getGir() << endl;

        m_tauler.eliminaFigura(m_figuraActual, m_tauler.getFila(), m_tauler.getCol()); // elimina la figura del tablero para no guardarla dos veces

        // guarda el contenido del tablero (sin contar la figura)
        for (int i = 0; i < MAX_FILA; i++)
        {
            for (int j = 0; j < MAX_COL; j++)
            {
                ColorFigura color = m_tauler.getColorCasella(i, j);
                
                fitxer << static_cast<int>(color) << " "; // pasa de ColorFigura a int
            }
            fitxer << endl;
        }
        fitxer.close();
    }
    
}
