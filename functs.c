
#include "testheader.h"



#define round(c) ( ( (c)-((int)(c))*10 ) >=5 ?  ( ((int)(c)) +1 ) : ( ((int)(c)) ))

void cuadric(float *coord_x,float *coord_y)
{
    *coord_x=(round((*coord_x)/(FILAS)))*(FILAS);
    *coord_y=(round((*coord_y)/(COLUMNAS)))*(COLUMNAS);
}

int printtext(ALLEGRO_EVENT ev)


