#include <stdio.h>

#include "include/platform.h"
#include "include/components.h"

int main(int argc, char* argv[])
{
    platform_t* platform = platform_init("Based Game");
    
    entity_t rectangle;
    
    add_component_position(&rectangle, 0, 0);
    add_component_draw(&rectangle, 0xFF00FF, 20);
    
    SDL_Rect rect = 
    {
        rectangle.components.component_position->x,
        rectangle.components.component_position->y,
        8, 
        8
    };
    
    while (platform->running) {
        while (SDL_PollEvent(&platform->event))
        {
            switch(platform->event.type)
            {
                case SDL_QUIT: {
                    platform->running = false;
                } break;
            }
        }
        platform_clear(platform);
        
        SDL_SetRenderDrawColor(platform->buffer.renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(platform->buffer.renderer, &rect);
        
        platform_render(platform);
    }
    
    free_entity(&rectangle);
    platform_destroy(platform);
    
    return 0;
}