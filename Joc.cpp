#include "Joc.h"
#include <fstream>
using namespace std;


void Joc::inicialitza(const string& nomFitxer)
{
    int tipus, gir;
    Casella casella;

    m_figuraActualColocada = false;
	ifstream fitxer;
    fitxer.open(nomFitxer);

    if (fitxer.is_open())
    { // el while (!eof) es para cuando no se sabe cuantos datos hay que leer
        fitxer >> tipus;
        m_figuraActual.inicialitzaFigura(TipusFigura(tipus));

        fitxer >> casella.fila >> casella.columna;

        casella.fila--;
        casella.columna--;

        m_figuraActual.setCasella(casella);
        m_posicioFigura = casella;

        fitxer >> gir;
        for (int i = 0; i < gir; i++)
            m_figuraActual.girarFigura(GIR_HORARI);

        for (int i = 0; i < MAX_COL; i++)
        {
            for (int j = 0; j < MAX_FILA; j++)
            {
                int color;
                fitxer >> color;

                m_tauler.setTauler(i, j, ColorFigura(color));
            }
        }

        fitxer.close();
    }
}

bool Joc::giraFigura(DireccioGir direccio)
{
    m_figuraActual.girarFigura(direccio); // gira la figura

    if (!m_tauler.movimentValid(m_figuraActual, m_posicioFigura)) // si no se puede girar la figura, la vuelve a su posición original
    {
        if (direccio == GIR_HORARI)
            m_figuraActual.girarFigura(GIR_ANTI_HORARI);
        else
            m_figuraActual.girarFigura(GIR_HORARI);
        return false;
    }

    return true;
}

bool Joc::mouFigura(int dirX) // vale 1 si se mueve a la derecha y -1 si se mueve a la izquierda
{
    bool moguda = true;
    m_figuraActual.moureFigura(dirX); // mueve la figura

    if (!m_tauler.movimentValid(m_figuraActual, m_figuraActual.getCasella())) // si no se puede mover la figura, la vuelve a su posición original
    {
        if (dirX == -1)
            m_figuraActual.moureFigura(1);
        else
            m_figuraActual.moureFigura(-1);
        moguda = false;
    }
    else
        m_posicioFigura = m_figuraActual.getCasella();

    return moguda;
}

int Joc::baixaFigura()
{
    int nFiles = 0;
    m_figuraActual.baixarFigura(1); // baja la figura

    if (!m_tauler.movimentValid(m_figuraActual, m_figuraActual.getCasella())) // si no se puede bajar la figura, la coloca en su posición final
    {
        m_figuraActual.baixarFigura(-1);
        m_tauler.setFigura(m_figuraActual, m_figuraActual.getCasella());
        m_figuraActualColocada = true;
        nFiles = m_tauler.eliminaFilas();
    }
    else
        m_posicioFigura = m_figuraActual.getCasella();

    return nFiles;
}

void Joc::escriuTauler(const string& nomFitxer)
{
    int i, j;
    ofstream fitxer;

    fitxer.open(nomFitxer);
    if (fitxer.is_open())
    {
        //si la figura aun no se ha colocado, se coloca temporalmente para escribir el tablero
        if (!m_figuraActualColocada)
            m_tauler.setFigura(m_figuraActual, m_posicioFigura);

        //escribe todos los valores del tablero
        for (int i = 0; i < MAX_COL; i++)
        {
            for (int j = 0; j < MAX_FILA; j++)
            {
                fitxer << int(m_tauler.getTauler(i, j)) << " ";
            }
            fitxer << endl;
        }

        //elimina la figura temporalmente colocada
        if (!m_figuraActualColocada)
            m_tauler.eliminaFigura(m_figuraActual, m_posicioFigura);

        fitxer.close();
    }
}
