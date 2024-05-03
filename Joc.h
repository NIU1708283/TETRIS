#ifndef JOC_H
#define JOC_H
#include "Tauler.h"
#include "Figura.h"
#include <string>
using namespace std;

class Joc
{
public:
	//constructor (hace que cada vez que se cree un juego, ciertas variables empiecen con un resultado fijo)
	Joc() { m_posicioFigura.fila = 0; m_posicioFigura.columna = 0; m_figuraActualColocada = false; }
	void inicialitza(const string& nomFitxer);
	bool giraFigura(DireccioGir direccio);
	bool mouFigura(int dirX);
	int baixaFigura(); 
	void escriuTauler(const string& nomFitxer);

private:
	Tauler m_tauler;
	Figura m_figuraActual;
	bool m_figuraActualColocada;
	Casella m_posicioFigura;
	
};

#endif