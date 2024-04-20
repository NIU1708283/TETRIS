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
	case 2:
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
				if (i == 1)
				{
					m_matrizFigura[i][j] = FIGURA_I;
				}
				else
					m_matrizFigura[i][j] = NO_FIGURA;
		}
		break;
	case 3:
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i == 0)
				{
					if (j % 2 != 0)
					{
						m_matrizFigura[i][j] = FIGURA_T;
					}
					else
						m_matrizFigura[i][j] = NO_FIGURA;
				}
				if (i == 1)
				{
					m_matrizFigura[i][j] = FIGURA_T;
				}
				else
					m_matrizFigura[i][j] = NO_FIGURA;
			}
		}
	
		break;
	case 4:
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i == 0)
				{
					if (j == 2)
					{
						m_matrizFigura[i][j] = FIGURA_L;
					}
					else
						m_matrizFigura[i][j] = NO_FIGURA;
				}
				if (i == 1)
				{
					m_matrizFigura[i][j] = FIGURA_L;
				}
				else
					m_matrizFigura[i][j] = NO_FIGURA;
			}
		}
		break;
	case 5:
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i == 0)
				{
					if (j == 0)
					{
						m_matrizFigura[i][j] = FIGURA_J;
					}
					else
						m_matrizFigura[i][j] = NO_FIGURA;
				}
				if (i == 1)
				{
					m_matrizFigura[i][j] = FIGURA_J;
				}
				else
					m_matrizFigura[i][j] = NO_FIGURA;
			}
		}
		break;
	case 6: //z
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i == 0)
				{
					if (j < 2)
					{
						m_matrizFigura[i][j] = FIGURA_Z;
					}
					else
						m_matrizFigura[i][j] = NO_FIGURA;
				}
				if (i == 1)
				{
					if (j > 0)
					{
						m_matrizFigura[i][j] = FIGURA_Z;
					}
					else
						m_matrizFigura[i][j] = NO_FIGURA;
				}
				else
					m_matrizFigura[i][j] = NO_FIGURA;
			}
		}
		break;
	case 7: //s
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i == 0)
				{
					if (j > 0)
					{
						m_matrizFigura[i][j] = FIGURA_S;
					}
					else
						m_matrizFigura[i][j] = NO_FIGURA;
				}
				if (i == 1)
				{
					if (j < 2)
					{
						m_matrizFigura[i][j] = FIGURA_S;
					}
					else
						m_matrizFigura[i][j] = NO_FIGURA;
				}
				else
					m_matrizFigura[i][j] = NO_FIGURA;
			}
		}
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
	int nuevaMatriz[3][3];


	if (gir == 0)
	{

		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				nuevaMatriz[j][2 - i] = matrizFigura[i][j];
			}
		}

		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				matrizFigura[i][j] = nuevaMatriz[i][j];
			}
		}
	}
	else
	{

		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				nuevaMatriz[2 - j][i] = matrizFigura[i][j];
			}
		}

		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				matrizFigura[i][j] = nuevaMatriz[i][j];
			}
		}
	}
}

void Figura::setTipusFigura(const int tipusFigura[MAX_FIGURES])
{

}
