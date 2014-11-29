#include "testheader.h"

extern STATE estado_0[];
extern STATE estado_01[];
extern STATE estado_1[];
extern STATE estado_S[];

STATE *p2state=NULL;

int maquina(ALLEGRO_EVENT ev)
{
    int keypressed=0;
    
    
    *p2state=estado_0;
    p2state=fsm(p2state,ev);
    
   
    switch(ev.keyboard.keycode){
    case ALLEGRO_KEY_R:
       keypressed=0;
       break; /* optional */
    case ALLEGRO_KEY_L:
       keypressed=1;
       break; /* optional */
    
    }
      
    return keypressed;
}

STATE * fsm(STATE *pstate,ALLEGRO_EVENT ev)
{
    while ( (pstate -> evento != ev.keyboard.keycode ||	pstate -> evento!= ev.mouse.button)&& pstate -> evento != ALLEGRO_KEY_ESCAPE)	//Recorre las tablas de estado
        ++pstate;
    (pstate->p_rut_accion)(ev);
    pstate=pstate->prx_estado;
    return pstate;
}

    

STATE estado_0[]=
{
  	{ALLEGRO_KEY_L,estado_1,do_nothing},
  	{ALLEGRO_KEY_R,estado_01,do_nothing},
        {ALLEGRO_KEY_S,estado_S,do_nothing},
        {ALLEGRO_KEY_ESCAPE,estado_1,do_nothing},
};

 STATE estado_01[]=
{
  	{1,estado_01,insert_ressistance()},
        {ALLEGRO_KEY_L,estado_1,do_nothing},
        {ALLEGRO_KEY_S,estado_S,do_nothing},
        {ALLEGRO_KEY_ESCAPE,estado_0,do_nothing},
};
 
 
 STATE estado_1[]=
{
	{1,estado_1,do_nothing},
        {ALLEGRO_KEY_R,estado_01,do_nothing},
        {ALLEGRO_KEY_S,estado_S,do_nothing},
        {ALLEGRO_KEY_ESCAPE,estado_0,do_nothing},
};
 
 STATE estado_S[]=
{
	{1,estado_1,do_nothing},
        {ALLEGRO_KEY_L,estado_1,do_nothing},
        {ALLEGRO_KEY_R,estado_01,do_nothing},
        {ALLEGRO_KEY_ESCAPE,estado_0,do_nothing},
};

 void insert_ressistance(ALLEGRO_EVENT ev)
 {
     RESISTENCIA *  tempres=(RESISTENCIA*)malloc(sizeof(RESISTENCIA));
     float resx,resy;
     char * name= (char *)calloc(10,1);
     
     resx=ev.mouse.x;
     resy=ev.mouse.y;
     
     cuadric(&resx,&resy);
     
     tempres->x=resx;
     tempres->y=resy;
     
     GetResName(ev,name);
     
     strcpy ( tempres->nombre, name);
     
     
     
     
 }
 
 
 int GetResValue(ALLEGRO_EVENT ev,char * value)
 {
     
 }
 
 
 int GetResName(ALLEGRO_EVENT ev,char * name)
 {
     ALLEGRO_EVENT_QUEUE *name_queue = NULL;
     ALLEGRO_FONT *font = al_load_ttf_font("pirulen.ttf",12,0 );
     int nampos;
     
     name_queue = al_create_event_queue();
     al_register_event_source(name_queue, al_get_keyboard_event_source());
     
     
     
     
     for(nampos=0;nampos<=9;)
     {
         ALLEGRO_EVENT namev;
         al_wait_for_event(name_queue, &namev);
         
         if(namev.type==ALLEGRO_EVENT_KEY_DOWN)
         {
             
             if(namev.keyboard.keycode==ALLEGRO_KEY_ENTER)
             {
                 
                 break;
             }
             else if(namev.keyboard.keycode==ALLEGRO_KEY_BACKSPACE)
             {
                 if(nampos>=1){
                 name[nampos]=0;  
                 nampos--;
                 }
                 
             }
             else if( ( (namev.keyboard.unichar>=65) && (namev.keyboard.unichar<=90) ) || (  (namev.keyboard.unichar>=97) && (namev.keyboard.unichar<=122) )   || (  (namev.keyboard.unichar>=48) && (namev.keyboard.unichar<=57) ) )
             {
                 name[nampos]=(char)namev.keyboard.unichar;
                 nampos++;
             }
         
             
             al_draw_text(font, al_map_rgb(250,120,60), ev.mouse.x, ev.mouse.y+40,ALLEGRO_ALIGN_CENTRE, name);
             al_flip_display();
             
         
         }
     }
     
     
 }
 
 
 void do_nothing(void)
 {
     //holis
 } 
   
