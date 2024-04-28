#include "Figura.h"


void Figura::inicialitzaMatrizFigura(const TipusFigura& fifi) //ñ se debe pasar la posición de la figura dentro del tablero
{
	// inicialitza la matriu de la figura segons el tipus de figura
	m_girFigura = 0;
	switch (fifi)
	{
	case 0:
		// tatata
		break;
	case 1:
		
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				m_matrizFigura[i][j] = FIGURA_O;
		for (int i = 2; i < 4; i++)
			for (int j = 2; j < 4; j++)
				m_matrizFigura[i][j] = NO_FIGURA;
		m_X = 0;
		m_Y = 1;
		break;
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
		m_X = 2;
		m_Y = 1;
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
		for (int i = 3; i < 4; i++)
			for (int j = 3; j < 4; j++)
				m_matrizFigura[i][j] = NO_FIGURA;
		m_X = 1;
		m_Y = 1;
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
		for (int i = 3; i < 4; i++)
			for (int j = 3; j < 4; j++)
				m_matrizFigura[i][j] = NO_FIGURA;
		m_X = 1;
		m_Y = 1;
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
		for (int i = 3; i < 4; i++)
			for (int j = 3; j < 4; j++)
				m_matrizFigura[i][j] = NO_FIGURA;
		m_X = 1;
		m_Y = 1;
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
		for (int i = 3; i < 4; i++)
			for (int j = 3; j < 4; j++)
				m_matrizFigura[i][j] = NO_FIGURA;
		m_X = 1;
		m_Y = 1;
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
		for (int i = 3; i < 4; i++)
			for (int j = 3; j < 4; j++)
				m_matrizFigura[i][j] = NO_FIGURA;
		m_X = 1;
		m_Y = 1;
		break;

	default:
		break;
	}
}

void Figura::desplacarFigura(int& x, int& y)
{
	
}

void Figura::baixarFigura(int& x, int& y)
{

}

void Figura::girarFigura(int matrizFigura[MAX_ALCADA][MAX_AMPLADA], const DireccioGir& gir)
{
	// gira la figura en sentit horari o antihorari dintre de la seva matriu

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

void Figura::setMatrizFigura(int matrizFigura[MAX_ALCADA][MAX_AMPLADA], const int& x, const int& y)
{

}


