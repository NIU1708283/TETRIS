#include "Tauler.h"
// -HOLA-

Tauler::Tauler()
{

	for (int i = 0; i < MAX_FILA; i++)
		for (int j = 0; j < MAX_COL; j++)
			m_tauler[i][j] = NO_FIGURA;
	//ñ falta inicializar la figura siguiente como vacia o una figura aleatoria?
}

bool Tauler::girValid()
{
	//ñ esta función debe comprobar si la figura se puede girar o no
	//ñ si se puede girar, se debe girar la figura
	//ñ si no se puede girar, se debe devolver false
	//ñ se debe comprobar si la figura se sale del tablero o si colisiona con otra figura


	return false;
}

bool Tauler::movimentValid()
{
	return false;
}

int Tauler::comprovaFiles()
{
	int n = -1; // fila encontrada donde no hay 0
	bool filaTrobada = false;
	int i = (MAX_FILA - 1);

	while (!filaTrobada && i >= 0)
	{
		int j = 0;
		filaTrobada = true;
		while (filaTrobada && j < MAX_COL)
		{
			if (m_tauler[i][j] == 0)
				filaTrobada = false;
			else
				j++;
		}
		if (filaTrobada == true)
			n = i;
		else
			i--;
	}

	return n;
}
void Tauler::eliminaFila()
{
	// n es la fila que se debe borrar, se tiene que hacer cada vez que una figura se "bloquea"
	// n es la primera fila borrable, se debe comprobar para todas las filas
	//ñ la funcion debe borrar la fila que se pasa por referencia, bajar todas las anteriores e
	//ñ inicializar primera fila a 0s

	for(int k = 0; k < MAX_ALCADA; k++) // debe hacerlo 4 veces, ya que la pieza mas grande ocupa 4 bloques
	{
		int n = comprovaFiles(); // y esta función busca unicamente la primera fila completa
		if (n != -1)
		{
			for (int i = n; i >= 0; i--)
			{
				for (int j = 0; j < 8; j++)
				{
					m_tauler[i][j] = m_tauler[i - 1][j];
				}
			}

			for (int j = 0; j < MAX_COL; j++)
				m_tauler[0][j] = NO_FIGURA;
		}
	}
}
