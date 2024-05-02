#include "Figura.h"
#include <iostream>

// constructor por defecto (todo zeros)
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
			m_forma[i][j] = NO_FIGURA; // lo mismo a que no haya figura
		}
	}
}

// constructor con parámetros que inicializa cualquier figura
Figura::Figura(const TipusFigura& fifi) // constructor con parámetros que inicializa cualquier figura
{
	m_tipus = fifi;
	m_gir = 0;
	for (int i = 0; i < MAX_ALCADA; i++) // inicializa la matriz a 0s para que no haya valores basura
	{
		for (int j = 0; j < MAX_AMPLADA; j++)
		{
			m_forma[i][j] = NO_FIGURA; 
		}
	}
	m_X = 0;
	m_Y = 0;
	m_color = NO_COLOR;

	// inicialitza la matriz con su forma correspondiente, solo hay que preocuparse de las posiciones que no deben ser 0 
	// también indica el centro de la figura, que es el punto de referencia para moverla
	// he "dibujado" la forma de cada figura para que sea mas facil de entender

	switch (fifi)
	{
	case FIGURA_O:
		m_forma[0][0] = fifi; m_forma[0][1] = fifi; 
		m_forma[1][0] = fifi; m_forma[1][1] = fifi;
		m_X = 1; // supondremos que el centro de la figura es el 1,1
		m_Y = 1;
		m_color = COLOR_GROC;
		break;

	case FIGURA_I:
		m_forma[1][0] = fifi; m_forma[1][1] = fifi; m_forma[1][2] = fifi; m_forma[1][3] = fifi;
		m_X = 1;
		m_Y = 2;
		m_color = COLOR_BLAUCEL;
		break;

	case FIGURA_T:
							  m_forma[0][1] = fifi;
		m_forma[1][0] = fifi; m_forma[1][1] = fifi; m_forma[1][2] = fifi;
		m_X = 1;
		m_Y = 1;
		m_color = COLOR_MAGENTA;
		break;

	case FIGURA_L:
													m_forma[0][2] = fifi;
		m_forma[1][0] = fifi; m_forma[1][1] = fifi; m_forma[1][2] = fifi;
		m_X = 1;
		m_Y = 1;
		m_color = COLOR_TARONJA;
		break;

	case FIGURA_J:
		m_forma[0][0] = fifi;
		m_forma[1][0] = fifi; m_forma[1][1] = fifi; m_forma[1][2] = fifi;
		m_X = 1;
		m_Y = 1;
		m_color = COLOR_BLAUFOSC;
		break;

	case FIGURA_Z:
		m_forma[0][0] = fifi; m_forma[0][1] = fifi;
							  m_forma[1][1] = fifi; m_forma[1][2] = fifi;
		m_X = 1;
		m_Y = 1;
		m_color = COLOR_VERMELL;
		break;

	case FIGURA_S:
							  m_forma[0][1] = fifi; m_forma[0][2] = fifi;
		m_forma[0][1] = fifi; m_forma[1][1] = fifi;
		m_X = 1;
		m_Y = 1;
		m_color = COLOR_VERD;
		break;

	default: //ñ  NO_FIGURA
		break;
	}
}

// mueve la casillade referencia de la figura a la posición (X,Y)
void Figura::moureFigura(const int& X, const int& Y) // mueve el centro de la figura
{
	m_X += X; // desplaza arriba o abajo, solo se puede hacia ABAJO pero PARA LOS TESTS NO IMPORTA (lo dejo como una función extra)
	m_Y += Y; // desplaza izquierda o derecha
}

// baja por defecto la figura una posición
void Figura::baixarFigura()
{
	m_X++;
}

// gira cualquier figura en sentido horario o antihorario
void Figura::girarFigura(const DireccioGir& gir)
{
	

	int novaForma[MAX_ALCADA][MAX_AMPLADA];
	if (m_tipus != FIGURA_O) // la figura O no se puede girar
	{
		// para la figura 4x4
		if (m_tipus == FIGURA_I)
		{
			if (gir == GIR_HORARI)
			{
				m_gir = (m_gir + 1) % 4; // actualiza el giro de la figura, puede ser 0, 1, 2 o 3
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
					m_gir = (m_gir - 1) % 4; // actualiza el giro de la figura, puede ser 0, 1, 2 o 3
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
			// actualiza el centro de la figura y luego
			// usa el metodo moureFigura para colocar la figura en la posición correcta
			if (m_gir == 0)
				m_X = 1; m_Y = 2;
			if (m_gir == 1)
				m_X = 2; m_Y = 2;
			if (m_gir == 2)
				m_X = 2; m_Y = 1;
			if (m_gir == 3)
				m_X = 1; m_Y = 1;

		}
		
		// para figuras de 3x3 (en MAX_ALCADA y MAX_AMPLADA he puesto un -1, así la tratará como una 3x3)
		else
		{
			if (gir == GIR_HORARI)
			{
				m_gir = (m_gir + 1) % 4; // actualiza el giro de la figura, puede ser 0, 1, 2 o 3
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
					m_gir = (m_gir - 1) % 4; // actualiza el giro de la figura, puede ser 0, 1, 2 o 3
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
	}
}

// recupera la forma de la figura en cualquier momento
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

