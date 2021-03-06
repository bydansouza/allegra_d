#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
 
#include <stdio.h>
#include <stdbool.h>
 
const int LARGURA_TELA = 640;
const int ALTURA_TELA = 480;
 
ALLEGRO_DISPLAY *janela = NULL;
ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
 
bool inicializar();
 
int main(void)
{
    bool sair = false;
 
    if (!inicializar())
    {
        return -1;
    }
 
    
    float x = 0;

    int x_aux=0;
    int x_aux2=80;
    int y_aux=80;
    
    int dir_x = 1, dir_y = 1;
    //no maximo 8 quadrados
    while (!sair)
    {
        if (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);
 
            if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
        }


        
        
        if(x<x_aux2){            
            al_draw_filled_rectangle(0, 0, x_aux,80, al_map_rgb(255, 0, 0));
            x_aux++;            
        }
        else{ //fazer a função for para um numero de tarefas e discretizar de acordo
            //for...            
            al_draw_filled_rectangle(x-80, 0, x+x_aux2-80,80, al_map_rgb(255, 0, 0));
        }
        
        //al_draw_filled_rectangle(x, 0, x+x_aux,80, al_map_rgb(255, 0, 0));        
        //al_draw_filled_rectangle(x+2*x_aux, 0,x+4*x_aux,80, al_map_rgb(255, 0, 0));
        
        //criar o fade out dos negocios
        //implementar o fade in para o for
        
        al_flip_display();
        al_clear_to_color(al_map_rgb(0, 0, 0));
        x += 1.0 * dir_x;
        //y += 1.0 * dir_y;


 
        if (x>= LARGURA_TELA)
        {            
            x = 0;
            x_aux=0;            
        } 
 
        
 
        al_rest(0.005);
    }
 
    al_destroy_event_queue(fila_eventos);
    al_destroy_display(janela);
 
    return 0;
}
 
bool inicializar()
{
    if (!al_init())
    {
        fprintf(stderr, "Falha ao inicializar Allegro.\n");
        return false;
    }
 
    if (!al_init_primitives_addon())
    {
        fprintf(stderr, "Falha ao inicializar add-on allegro_primitives.\n");
        return false;
    }
 
    janela = al_create_display(LARGURA_TELA, ALTURA_TELA);
    if (!janela)
    {
        fprintf(stderr, "Falha ao criar janela.\n");
        return false;
    }
 
    al_set_window_title(janela, "allegra_d");
 
    fila_eventos = al_create_event_queue();
    if (!fila_eventos)
    {
        fprintf(stderr, "Falha ao criar fila de eventos.\n");
        al_destroy_display(janela);
        return false;
    }
 
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
 
    return true;
}