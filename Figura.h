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
    NO_COLOR
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
const int MAX_FIGURES = 8;
const int FORMA_ACTUAL_FIGURA = 4;
typedef enum
{
    GIR_HORARI = 0,
    GIR_ANTI_HORARI
} DireccioGir;

class Figura
{
private:
    ColorFigura m_colorFigura;
    TipusFigura m_tipusFigura;
    DireccioGir m_gir;
    int m_girFigura;
    int m_X;
    int m_Y;
    int m_matrizFigura[MAX_ALCADA][MAX_AMPLADA];
    int m_formaActualFigura[FORMA_ACTUAL_FIGURA][FORMA_ACTUAL_FIGURA];

    //ñ Tiene que guardar esta información: tipus, fila, columna y gir hola 
public:

    void inicialitzaMatrizFigura(const TipusFigura& fifi); // inicializar la matriz de la figura
    void desplacarFigura(int& x); // mover de izquierda a derecha con el teclado
    void baixarFigura(int& y); // mover todo abajo, tanto por defecto como con el teclado
    void girarFigura(const TipusFigura& tipusFigura, const DireccioGir& gir, const int& x, const int& y); // girar la figura
    void setMatrizFigura(const TipusFigura& tipusFigura, const int& x, const int& y);
    // recuperar la forma actual de la figura
};


#endif
