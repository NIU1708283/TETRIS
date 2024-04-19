#include "Figura.h"


void Figura::setMatrizFigura(const TipusFigura& fifi)
{
	switch (fifi)
	{
	case 0:
		// tatata
		break;
	case 1:
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				m_matrizFigura[i][j] = FIGURA_O;
		break;
	case 2:
		// tatata
		break;
	case 3:
		// tatata
		break;
	case 4:
		// tatata
		break;
	case 5:
		// tatata
		break;
	case 6:
		// tatata
		break;
	case 7:
		// tatata
		break;

	default:
		break;
	}
}

void Figura::desplacarFigura()
{

}

void Figura::baixarFigura()
{

}

void Figura::girarFigura(int matrizFigura[MAX_ALCADA][MAX_AMPLADA], const DireccioGir& gir)
{

}

void Figura::setTipusFigura(const int tipusFigura[MAX_FIGURES])
{

}
