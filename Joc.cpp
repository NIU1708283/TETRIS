#include "Joc.h"

void Joc::inicialitza(const string& nomFitxer)
{
	// inicializa el tablero con las figuras correspondientes 
	// deja preparada la proxima figura que aparecer� dentro del tablero
}

bool Joc::giraFigura(DireccioGir direccio)
{
	// llama a la funci�n girafigura y si es possible, la gira, sino, no hace nada
	return false;
}

bool Joc::mouFigura(int dirX)
{
	// llama a la funci�n moverfigura y compueba si se puede mover, si se puede lo hace y sin� no hace nada
	return false;
}

int Joc::baixaFigura()
{
	// llama a la funci�n bajarfigura (que se debe poder bajar automaticamente o con las flechas verticales) y comprueba que sea un movimiento valido
	return 0;
}

void Joc::escriuTauler(const string& nomFitxer)
{
	// guarda la informacion del tablero y la de la proxima figura en aparecer en �l
}
