#include "Tauler.h"
// -HOLA-

Tauler::Tauler()
{

	for (int i = 0; i < MAX_FILA; i++)
		for (int j = 0; j < MAX_COL; j++)
			m_tauler[i][j] = NO_FIGURA;
	//ñ falta inicializar la figura siguiente como vacia o una figura aleatoria?
}

bool Tauler::comprovaFiles()
{
	return false;
}

bool Tauler::girValid()
{
	return false;
}

bool Tauler::movimentValid()
{
	return false;
}
