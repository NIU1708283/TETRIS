#include "Figura.h"
#include <iostream>

// constructor por defecto (todo zeros)
Figura::Figura() // constructor por defecto
{
	m_tipus = NO_FIGURA;
	m_color = NO_COLOR;
	m_casella.fila = 0; 
	m_casella.columna = 0;
	m_mida = 0;

	for (int i = 0; i < MAX_ALCADA; i++)
	{
		for (int j = 0; j < MAX_AMPLADA; j++)
		{
			m_forma[i][j] = NO_COLOR; // lo mismo a que no haya figura
		}
	}
}

// constructor con parámetros que inicializa cualquier figura
Figura::Figura(const TipusFigura& fifi) // constructor con parámetros que inicializa cualquier figura
{
	m_tipus = fifi;
	m_color = NO_COLOR;
	m_casella.fila = 0;
	m_casella.columna = 0;
	m_mida = 0;


	for (int i = 0; i < MAX_ALCADA; i++) // inicializa la matriz a 0s para que no haya valores basura
	{
		for (int j = 0; j < MAX_AMPLADA; j++)
		{
			m_forma[i][j] = NO_COLOR; 
		}
	}

	// inicialitza la matriz con su forma correspondiente, solo hay que preocuparse de las posiciones que no deben ser 0 
	// también indica el centro de la figura, que es el punto de referencia para moverla
	// he "dibujado" la forma de cada figura para que sea mas facil de entender

	switch (fifi)
	{
	case FIGURA_O:
		m_forma[0][0] = COLOR_GROC; m_forma[0][1] = COLOR_GROC; 
		m_forma[1][0] = COLOR_GROC; m_forma[1][1] = COLOR_GROC;

		m_mida = 2;
		m_color = COLOR_GROC;
		break;

	case FIGURA_I:
		m_forma[1][0] = COLOR_BLAUCEL; m_forma[1][1] = COLOR_BLAUCEL; m_forma[1][2] = COLOR_BLAUCEL; m_forma[1][3] = COLOR_BLAUCEL;
		
		m_mida = 4;
		m_color = COLOR_BLAUCEL;
		break;

	case FIGURA_T:
									   m_forma[0][1] = COLOR_MAGENTA;
		m_forma[1][0] = COLOR_MAGENTA; m_forma[1][1] = COLOR_MAGENTA; m_forma[1][2] = COLOR_MAGENTA;
		
		m_mida = 3;
		m_color = COLOR_MAGENTA;
		break;

	case FIGURA_L:
		m_forma[0][1] = COLOR_TARONJA;
		m_forma[1][1] = COLOR_TARONJA; 
		m_forma[2][1] = COLOR_TARONJA; m_forma[2][2] = COLOR_TARONJA;
		
		m_mida = 3;
		m_color = COLOR_TARONJA;
		break;

	case FIGURA_J:
										m_forma[0][1] = COLOR_BLAUFOSC;
										m_forma[1][1] = COLOR_BLAUFOSC; 
		m_forma[2][0] = COLOR_BLAUFOSC; m_forma[2][1] = COLOR_BLAUFOSC;
		
		m_mida = 3;
		m_color = COLOR_BLAUFOSC;
		break;

	case FIGURA_Z:
		m_forma[0][0] = COLOR_VERMELL; m_forma[0][1] = COLOR_VERMELL;
									   m_forma[1][1] = COLOR_VERMELL; m_forma[1][2] = COLOR_VERMELL;
		
		m_mida = 3;
		m_color = COLOR_VERMELL;
		break;

	case FIGURA_S:
									m_forma[0][1] = COLOR_VERD; m_forma[0][2] = COLOR_VERD;
		m_forma[1][0] = COLOR_VERD; m_forma[1][1] = COLOR_VERD;

		m_mida = 3;
		m_color = COLOR_VERD;
		break;

	default: //ñ  COLOR_NEGRE
		break;
	}
}

void Figura::inicialitzaFigura(const TipusFigura& fifi)
{
	m_tipus = fifi;
	m_color = NO_COLOR;
	m_casella.fila = 0;
	m_casella.columna = 0;
	m_mida = 0;


	for (int i = 0; i < MAX_ALCADA; i++) // inicializa la matriz a 0s para que no haya valores basura
	{
		for (int j = 0; j < MAX_AMPLADA; j++)
		{
			m_forma[i][j] = NO_COLOR;
		}
	}

	// inicialitza la matriz con su forma correspondiente, solo hay que preocuparse de las posiciones que no deben ser 0 
	// también indica el centro de la figura, que es el punto de referencia para moverla
	// he "dibujado" la forma de cada figura para que sea mas facil de entender

	switch (fifi)
	{
	case FIGURA_O:
		m_forma[0][0] = COLOR_GROC; m_forma[0][1] = COLOR_GROC;
		m_forma[1][0] = COLOR_GROC; m_forma[1][1] = COLOR_GROC;

		m_mida = 2;
		m_color = COLOR_GROC;
		break;

	case FIGURA_I: // la trataremos como una 5x5 para que sea mas facil de girar, así el centro no cambia
		m_forma[1][0] = COLOR_BLAUCEL; m_forma[1][1] = COLOR_BLAUCEL; m_forma[1][2] = COLOR_BLAUCEL; m_forma[1][3] = COLOR_BLAUCEL;

		m_mida = 4;
		m_color = COLOR_BLAUCEL;
		break;

	case FIGURA_T:
		m_forma[0][1] = COLOR_MAGENTA;
		m_forma[1][0] = COLOR_MAGENTA; m_forma[1][1] = COLOR_MAGENTA; m_forma[1][2] = COLOR_MAGENTA;

		m_mida = 3;
		m_color = COLOR_MAGENTA;
		break;

	case FIGURA_L:
		m_forma[0][1] = COLOR_TARONJA;
		m_forma[1][1] = COLOR_TARONJA;
		m_forma[2][1] = COLOR_TARONJA; m_forma[2][2] = COLOR_TARONJA;

		m_mida = 3;
		m_color = COLOR_TARONJA;
		break;

	case FIGURA_J:
		m_forma[0][1] = COLOR_BLAUFOSC;
		m_forma[1][1] = COLOR_BLAUFOSC;
		m_forma[2][0] = COLOR_BLAUFOSC; m_forma[2][1] = COLOR_BLAUFOSC;

		m_mida = 3;
		m_color = COLOR_BLAUFOSC;
		break;

	case FIGURA_Z:
		m_forma[0][0] = COLOR_VERMELL; m_forma[0][1] = COLOR_VERMELL;
		m_forma[1][1] = COLOR_VERMELL; m_forma[1][2] = COLOR_VERMELL;

		m_mida = 3;
		m_color = COLOR_VERMELL;
		break;

	case FIGURA_S:
		m_forma[0][1] = COLOR_VERD; m_forma[0][2] = COLOR_VERD;
		m_forma[1][0] = COLOR_VERD; m_forma[1][1] = COLOR_VERD;

		m_mida = 3;
		m_color = COLOR_VERD;
		break;

	default: //ñ  COLOR_NEGRE
		break;
	}
}

// mueve la casilla de referencia de la figura a la posición (X,Y)
void Figura::moureFigura(const int& Y) // mueve el centro de la figura
{
	if (Y == -1)
		m_casella.columna--;
	else
		m_casella.columna++; // desplaza izquierda o derecha
}

// baja por defecto la figura una posición
void Figura::baixarFigura(const int& X) // X será 1 mas o menos por defecto
{
	if (X == -1)
		m_casella.fila--;
	else
		m_casella.fila++; // baja la figura una posición
}

// gira cualquier figura en sentido horario o antihorario
void Figura::girarFigura(const DireccioGir& gir)
{
		ColorFigura novaForma[MAX_ALCADA][MAX_AMPLADA]; // matriz auxiliar para guardar la nueva forma de la figura
		ColorFigura transp[MAX_ALCADA][MAX_AMPLADA]; // matriz auxiliar para guardar la transpuesta de la forma

		// Transpone forma de la figura (me habia dejado este paso)
		for (int i = 0; i < m_mida; ++i)
			for (int j = 0; j < m_mida; ++j)
				transp[j][i] = m_forma[i][j];

		for (int i = 0; i < m_mida; ++i)
			for (int j = 0; j < m_mida; ++j)
				m_forma[i][j] = transp[i][j];

		if (gir == GIR_HORARI)
		{
			// gira la figura en sentido horario
			for (int i = 0; i < m_mida; i++)
			{
				for (int j = 0; j < m_mida; j++)
				{
					novaForma[i][j] = m_forma[i][m_mida - 1 - j];
				}
			}
		}
		if (gir == GIR_ANTI_HORARI)
		{
			// gira la figura en sentido antihorario
			for (int i = 0; i < m_mida; i++)
			{
				for (int j = 0; j < m_mida; j++)
				{
					novaForma[i][j] = m_forma[m_mida - 1 - i][j];
				}
			}
		}

		// Actualizar la forma de la figura con la nueva forma girada
		for (int i = 0; i < m_mida; i++)
		{
			for (int j = 0; j < m_mida; j++)
			{
				m_forma[i][j] = novaForma[i][j];
			}
		}
}


