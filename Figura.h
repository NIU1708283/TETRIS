#ifndef FIGURA_H
#define FIGURA_H

///EXPLICACIÓN
/*
- Ha de servir per poder gestionar figures que van caient.
- Ha de poder guardar tota la informació necessària per gestionar la caiguda de la figura: tipus i
  color de la figura, posició actual, forma actual de la figura.
- Ha de tenir mètodes que permetin fer el moviment i el gir de la figura i la interacció amb el tauler:
▪ Desplaçar-se lateralment
▪ Baixar dins del tauler
▪ Girar
▪ Recuperar la forma actual de la figura
*/
typedef enum
{
    COLOR_NEGRE = 0,
    COLOR_GROC,
    COLOR_BLAUCEL,
    COLOR_MAGENTA,
    COLOR_TARONJA,
    COLOR_BLAUFOSC,
    COLOR_VERMELL,
    COLOR_VERD,
    NO_COLOR,
} ColorFigura;

typedef enum
{
    NO_FIGURA = 0,
    FIGURA_O,
    FIGURA_I,
    FIGURA_T,
    FIGURA_L,
    FIGURA_J,
    FIGURA_Z,
    FIGURA_S,
} TipusFigura;

const int MAX_ALCADA = 4;
const int MAX_AMPLADA = 4;

typedef enum
{
    GIR_HORARI = 0,
    GIR_ANTI_HORARI
} DireccioGir;

typedef struct
{
    int fila;
    int columna;
} Casella;

class Figura
{
private:
    ColorFigura m_color; // color de la figura
    TipusFigura m_tipus; // tipus de la figura
    ColorFigura m_forma[MAX_ALCADA][MAX_AMPLADA]; // forma de la figura ES UNA MATRIZ DE COLORES

    int m_mida; // mida de la figura 2x2, 3x3, 4x4
    Casella m_casella; // fila y columna del centro de la figura

    // Tiene que guardar esta información: tipus, fila, columna y gir
public:
    Figura();
    Figura(const TipusFigura& fifi);


    void inicialitzaFigura(const TipusFigura& fifi); // inicializa la figura
    void moureFigura(const int& Y); // mover la figura a la derecha o a la izquierda
    void baixarFigura(const int& X); // mover la figura abajo por defecto
    void girarFigura(const DireccioGir& gir); // girar la figura


    ColorFigura getForma(const int& fila, const int& col) const { return m_forma[fila][col]; }
    ColorFigura getColor() const { return m_color; }
    Casella getCasella() const { return m_casella; }
    void setCasella(const Casella& casella) { m_casella = casella; }
    int getMida() const { return m_mida; }


};



#endif