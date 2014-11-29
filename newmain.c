/* 
 * File:   newmain.c
 * Author: pepo
 *
 * Created on November 27, 2014, 9:21 PM
 */

#include "testheader.h"
#define WIDTH 800
#define HEIGHT 600
#define RESWIDTH 100
#define RESHEIGHT 50

const float FPS = 60;



/*
 * 
 */
int main(int argc, char** argv) {
    
     ALLEGRO_DISPLAY *display = NULL;
     ALLEGRO_EVENT_QUEUE *event_queue = NULL;
     ALLEGRO_TIMER *timer = NULL;
     ALLEGRO_BITMAP *copadares = NULL;
     
     
     float copadares_x = 0;
     float copadares_y = 0;
     
     bool dibujar=true;
     
     int verline,horline,genericevent;
 
     PTR2NODET reslist=NULL,linelist=NULL;
     
     
     
     //empiezo las inicializaciones
     if(!al_init()) {
      fprintf(stderr, "failed to initialize allegro!\n");
      return -1;
   }
     
     al_init_font_addon(); // initialize the font addon
     al_init_ttf_addon();// initialize the ttf (True Type Font) addon
     
     if(!al_init_image_addon()) {
      al_show_native_message_box(display, "Error", "Error", "Failed to initialize al_init_image_addon!", 
                                 NULL, ALLEGRO_MESSAGEBOX_ERROR);
      return 0;
   }
     

     
     if(!al_install_keyboard()) {
      fprintf(stderr, "failed to initialize the keyboard!\n");
      return -1;
   }
     
     if(!al_install_mouse()) {
      fprintf(stderr, "failed to initialize the mouse!\n");
      return -1;
   }
     
   
     
     //ACA INCIALIZO ELEMENTOS DE PUNTERO
     timer = al_create_timer(1.0 / FPS);
   if(!timer) {
      fprintf(stderr, "failed to create timer!\n");
      return -1;
   }
     
     
 
   display = al_create_display(WIDTH, HEIGHT);
   if(!display) {
      fprintf(stderr, "failed to create display!\n");
      return -1;
   }
   
   copadares = al_load_bitmap("copada2.png");
 
   if(!copadares) {
      al_show_native_message_box(display, "Error", "Error", "Failed to load image!", 
                                 NULL, ALLEGRO_MESSAGEBOX_ERROR);
      al_destroy_display(display);
      return 0;
   }
   
   al_set_target_bitmap(al_get_backbuffer(display));
   

   
   event_queue = al_create_event_queue();
   if(!event_queue) {
      fprintf(stderr, "failed to create event_queue!\n");
      al_destroy_display(display);
      return -1;
   }
  
   
   
   
   //registro los eventos  
   
   al_register_event_source(event_queue, al_get_display_event_source(display));
   al_register_event_source(event_queue, al_get_keyboard_event_source());
   al_register_event_source(event_queue, al_get_mouse_event_source());
   al_register_event_source(event_queue, al_get_timer_event_source(timer));
   al_start_timer(timer);

 
 
  
   //ARRANCO EL PROGRAMA
   
   while(1)
   {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);
           
       
       //RECEPTORES DE EVENTOS
        if(ev.type == ALLEGRO_EVENT_TIMER) {
         dibujar = true;
        }
        
        
        
        if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
         break;
        } 
         else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
             genericevent=maquina(ev);
         }
        
        
         
         else if(ev.type == ALLEGRO_EVENT_MOUSE_AXES ||
              ev.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY) {           
         copadares_x = ev.mouse.x;
         copadares_y = (ev.mouse.y-RESHEIGHT/2);
        
         cuadric(&copadares_x,&copadares_y);
        
         }
        
        
        
        else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
           // maquina(ev);
          
      }
       
        
        
        
        
        
        
        
        //ESTO DIBUJA. VA AL FINAL--
        
        if(dibujar && al_is_event_queue_empty(event_queue)) {
         dibujar = false;
            
        
        
        
            al_clear_to_color(al_map_rgb(255, 255, 255));
            
            
            
            
            for(verline=0;verline<=WIDTH;verline+=COLUMNAS){
            al_draw_line(verline,0,verline,HEIGHT, al_map_rgb(0,0,0), 1);
            }
            for(horline=0;horline<=HEIGHT;horline+=FILAS){
            al_draw_line(0,horline,WIDTH,horline, al_map_rgb(0,0,0), 1);
            }
            
            
            //dibujo las resistencias
            
            al_draw_bitmap(copadares, copadares_x, copadares_y, 0);
            
            
            al_flip_display();
                
        }
    
   }
   return (EXIT_SUCCESS);
}

