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

class Figura
{
private:
    ColorFigura m_color; // color de la figura
    TipusFigura m_tipus; // tipus de la figura
    
    int m_fila; // fila actual del centro de la figura
    int m_col; // columna actual del centro de la figura
    int m_gir; // gir actual de la figura
    ColorFigura m_forma[MAX_ALCADA][MAX_AMPLADA]; // forma de la figura ES UNA MATRIZ DE COLORES

    //ñ Tiene que guardar esta información: tipus, fila, columna y gir
public:
    Figura();
    Figura(const TipusFigura& fifi);

    void moureFigura(const int& X, const int& Y); // mover la figura a la derecha o a la izquierda
    void baixarFigura(); // mover la figura abajo por defecto
    void girarFigura(const DireccioGir& gir); // girar la figura

    void getForma(ColorFigura forma[MAX_ALCADA][MAX_AMPLADA]) const;

    TipusFigura getTipus() const { return m_tipus ; }
    ColorFigura getColor() const { return m_color; }
    ColorFigura setColor(const ColorFigura& color) { m_color = color; }

    int getFila() const { return m_fila; }
    int getCol() const { return m_col; }

    void setFila(const int& fila) { m_fila = fila; } 
    void setCol(const int& col) { m_col = col; } 

    int getGir() const { return m_gir; }


};



#endif