

#ifndef TST4EADER_H
#define	TST4EADER_H

#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include "allegro5/allegro_image.h"
#include <string.h>
#include "allegro5/allegro_native_dialog.h"
#include <allegro5/allegro_primitives.h>
#include <allegro5/keyboard.h>
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"



#define COLUMNAS 25
#define FILAS 25



//typedef de la maquina de estados--------------------------


typedef unsigned char BYTE;
typedef struct tabla_estado STATE;
struct tabla_estado

{
	int evento;
	STATE *prx_estado;
	void (*p_rut_accion)(ALLEGRO_EVENT ev);
};
#define FIN_TABLA 00
 

//typedef del arreglo dinamico de las resistencias--------------------------
typedef struct
		{
			char nombre[7];
			unsigned int ohm;
                        float x;
                        float y;
                        int in;
                        int out;
		} RESISTENCIA;

typedef struct node NODET;
struct	node
		{
			RESISTENCIA resist;
			NODET * next;
			NODET * prev;

		};

typedef NODET * PTR2NODET;

//arreglo dinamico de las lineas----------


typedef struct
		{
			float x1;
                        float y1;
                        float x2;
                        float y2;
                        int in;
                        int out;
		} LINEA;

typedef struct node2 NODETLINE;
struct	node2
		{
			LINEA line;
			NODETLINE * nextli;
			NODETLINE * prevli;

		};

typedef NODETLINE * PTR2LINE;



//prototipos----------------------------------------


//cuadricula---------
void cuadric(float *,float *);


//arrreglo dinamico-------
void create_list(PTR2NODET * ptop);
void add_node_RES (PTR2NODET * ptop , RESISTENCIA * pres);
void del_node(PTR2NODET * ptop,char *nombre);


//linea
void add_node_line (PTR2LINE * ptop , LINEA * pline);

//maquina de estados----------
int maquina(ALLEGRO_EVENT ev);
void reset_FSM(void);
STATE * fsm(STATE *pstate,ALLEGRO_EVENT ev);
int GetResName(ALLEGRO_EVENT ev,)


#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* TST4EADER_H */

