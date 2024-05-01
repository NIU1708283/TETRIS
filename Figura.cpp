#include "Figura.h"
#include <iostream>

Figura::Figura() // constructor por defecto
{
	m_tipus = NO_FIGURA;
	m_color = NO_COLOR;
	m_X = 0; 
	m_Y = 0;
	m_gir = 0;

	for (int i = 0; i < MAX_ALCADA; i++)
	{
		for (int j = 0; j < MAX_AMPLADA; j++)
		{
			m_forma[i][j] = 0; // lo mismo a que no haya figura
		}
	}
}

Figura::Figura(const TipusFigura& fifi, const ColorFigura& color) //ñ se debe pasar la posición de la figura dentro del tablero
{
	m_tipus = fifi;
	m_color = color; //ñ el color tambien representa el tipo de figura por el numero que es
	m_X = 0;
	m_Y = 0;
	m_gir = 0;
	for (int i = 0; i < MAX_ALCADA; i++) // inicializa la matriz a 0s para que no haya valores basura
	{
		for (int j = 0; j < MAX_AMPLADA; j++)
		{
			m_forma[i][j] = 0; 
		}
	}

	// inicialitza la matriz con su forma correspondiente, solo hay que preocuparse de las posiciones que no deben ser 0 
	// he "dibujado" la forma de cada figura para que sea mas facil de entender

	switch (fifi)
	{ // tambien se puede usar el tipus(fifi) para inicializar la matriz
	case FIGURA_O:
		m_forma[0][0] = color; m_forma[0][1] = color; 
		m_forma[1][0] = color; m_forma[1][1] = color;
		m_X = 1;
		m_Y = 0;
		break;

	case FIGURA_I:
		m_forma[1][0] = color; m_forma[1][1] = color; m_forma[1][2] = color; m_forma[1][3] = color;
		m_X = 1;
		m_Y = 2;
		break;

	case FIGURA_T:
							   m_forma[0][1] = color;
		m_forma[1][0] = color; m_forma[1][1] = color; m_forma[1][2] = color;
		m_X = 1;
		m_Y = 1;
		break;

	case FIGURA_L:
													  m_forma[0][2] = color;
		m_forma[1][0] = color; m_forma[1][1] = color; m_forma[1][2] = color;
		m_X = 1;
		m_Y = 1;
		break;

	case FIGURA_J:
		m_forma[0][0] = color;
		m_forma[1][0] = color; m_forma[1][1] = color; m_forma[1][2] = color;
		m_X = 1;
		m_Y = 1;
		break;

	case FIGURA_Z:
		m_forma[0][0] = color; m_forma[0][1] = color;
							   m_forma[1][1] = color; m_forma[1][2] = color;
		m_X = 1;
		m_Y = 1;
		break;

	case FIGURA_S:
							   m_forma[0][1] = color; m_forma[0][2] = color;
		m_forma[0][1] = color; m_forma[1][1] = color;
		m_X = 1;
		m_Y = 1;
		break;

	default: //ñ  NO_FIGURA
		break;
	}
}

void Figura::moureFigura(const char& move)
{
	switch (move)
	{
	case 'a':
		m_Y--;
		break;

	case 'd':
		m_Y++;
		break;

	case 's':
		m_X++;
		break;

	case 'A':
		m_Y--;
		break;

	case 'D':
		m_Y++;
		break;

	case 'S':
		m_X++;
		break;

	default:
		break;
	}
}

void Figura::baixarFigura()
{
	m_X++;
}

void Figura::girarFigura(const DireccioGir& gir)
{
	// gira la figura en sentido horari o antihorari dintro de la matriz

	int novaForma[MAX_ALCADA][MAX_AMPLADA];
	if (m_tipus != FIGURA_O) // la figura O no se puede girar
	{
		// para la figura 4x4
		if (m_tipus == FIGURA_I)
		{
			if (gir == GIR_HORARI)
			{
				// gira la figura en sentido horario
				for (int i = 0; i < MAX_ALCADA; i++)
				{
					for (int j = 0; j < MAX_AMPLADA; j++)
					{
						novaForma[j][MAX_ALCADA - 1 - i] = m_forma[i][j];
					}
				}
			}
			else
			{
				if (gir == GIR_ANTI_HORARI)
				{
					// gira la figura en sentido antihorario
					for (int i = 0; i < MAX_ALCADA; i++)
					{
						for (int j = 0; j < MAX_AMPLADA; j++)
						{
							novaForma[MAX_AMPLADA - 1 - j][i] = m_forma[i][j];
						}
					}
				}
			}
		}
		
		// para figuras de 3x3 (en MAX_ALCADA y MAX_AMPLADA he puesto un -1, así la tratará como una 3x3)
		else
		{
			if (gir == GIR_HORARI)
			{
				// gira la figura en sentido horario
				for (int i = 0; i < MAX_ALCADA-1; i++)
				{
					for (int j = 0; j < MAX_AMPLADA-1; j++)
					{
						novaForma[j][MAX_ALCADA - 1 - i] = m_forma[i][j];
					}
				}
			}
			else
			{
				if (gir == GIR_ANTI_HORARI)
				{
					// gira la figura en sentido antihorario
					for (int i = 0; i < MAX_ALCADA-1; i++)
					{
						for (int j = 0; j < MAX_AMPLADA-1; j++)
						{
							novaForma[MAX_AMPLADA - 1 - j][i] = m_forma[i][j];
						}
					}
				}
			}
		}
	}

	// Actualizar la forma de la figura con la nueva forma girada
	if (m_tipus != FIGURA_O) // la figura O no se puede girar
	{
		// para la figura 4x4
		if (m_tipus == FIGURA_I)
		{
			for (int i = 0; i < MAX_ALCADA; i++)
			{
				for (int j = 0; j < MAX_AMPLADA; j++)
				{
					m_forma[i][j] = novaForma[i][j];
				}
			}
		}

		// para figuras de 3x3
		else
		{
			for (int i = 0; i < MAX_ALCADA-1; i++)
			{
				for (int j = 0; j < MAX_AMPLADA-1; j++)
				{
					m_forma[i][j] = novaForma[i][j];
				}
			}
		}
		m_gir = (m_gir + 1) % 4; // actualiza el giro de la figura, puede ser 0, 1, 2 o 3
	}
}

void Figura::getForma(int forma[MAX_ALCADA][MAX_AMPLADA]) const
{
	for (int i = 0; i < MAX_ALCADA; i++)
	{
		for (int j = 0; j < MAX_AMPLADA; j++)
		{
			forma[i][j] = m_forma[i][j];
		}
	}
}
