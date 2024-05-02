#include "Joc.h"
#include <fstream>

void Joc::inicialitza(const string& nomFitxer)
{
    ifstream fitxer;
    fitxer.open(nomFitxer);
    if (fitxer.is_open())
    {
        while (!fitxer.eof())
        {
            int tipus, fila, columna, gir;
            fitxer >> tipus >> fila >> columna >> gir;

            m_figuraActual = Figura(static_cast<TipusFigura>(tipus)); // pasa de int a TipusFigura
            for (int i = 0; i < gir; i++)
            {
                m_figuraActual.girarFigura(GIR_HORARI); // gira la figura a su posición correspondiente
            }

            m_tauler.inicialitzaTauler(); // inicializa el tablero todo a NO_COLOR
            m_tauler.mouFigura(m_figuraActual, fila, columna); // mueve la figura a su posición correspondiente

            for (int i = 0; i < MAX_FILA; i++)
            {
                for (int j = 0; j < MAX_COL; j++)
                {
                    int color;
                    fitxer >> color;
                    if (color != NO_COLOR) // lo hace solo si el espacio debe tener color, así se ahorra tiempo
                    {
                        m_tauler.setColorCasella(i, j, static_cast<ColorFigura>(color)); // pasa de int a ColorFigura
                    }
                }
            }
        }

        fitxer.close();
    }
}

bool Joc::giraFigura(DireccioGir direccio)
{
    Figura figuraGirada = m_figuraActual;
    figuraGirada.girarFigura(direccio);
    if (m_tauler.movimentValid(figuraGirada, figuraGirada.getPosX(), figuraGirada.getPosY()))
    {
        m_figuraActual = figuraGirada;
        return true;
    }
    return false;
}

bool Joc::mouFigura(int dirX) // vale 1 si se mueve a la derecha y -1 si se mueve a la izquierda
{
    Figura figuraMoguda = m_figuraActual;

    m_tauler.mouFigura(figuraMoguda, 0, figuraMoguda.getPosY() + dirX);
    if (m_tauler.movimentValid(figuraMoguda, figuraMoguda.getPosX(), figuraMoguda.getPosY()))
    {
        m_figuraActual = figuraMoguda;
        return true;
    }
    return false;
}

int Joc::baixaFigura()
{
    Figura figuraBaixada = m_figuraActual;
    figuraBaixada.baixarFigura();
    if (m_tauler.movimentValid(figuraBaixada, figuraBaixada.getPosX(), figuraBaixada.getPosY()))
    {
        m_figuraActual = figuraBaixada; // si se puede bajar la figura, se baja
        return 0;
    }
    else // si no se puede, comprobara si hay alguna fila completa
    {
        m_tauler.mouFigura(m_figuraActual, m_figuraActual.getPosX(), m_figuraActual.getPosY());
        int filesEliminades = 0;
        for (int fila = 0; fila < MAX_FILA; fila++)
        {
            bool filaCompleta = true;
            for (int col = 0; col < MAX_COL; col++)
            {
                if (m_tauler.getColorCasella(fila, col) == NO_COLOR)
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
        fitxer << static_cast<int>(m_figuraActual.getTipus()) << " ";
        fitxer << m_figuraActual.getPosX() << " ";
        fitxer << m_figuraActual.getPosY() << " ";
        fitxer << m_figuraActual.getGir() << endl;

        // guarda el contenido del tablero (sin contar la figura)
        for (int i = 0; i < MAX_FILA; i++)
        {
            for (int j = 0; j < MAX_COL; j++)
            {
                ColorFigura color = m_tauler.getColorCasella(i, j);
                
                fitxer << static_cast<int>(color) << " ";
            }
            fitxer << endl;
        }
        fitxer.close();
    }
}