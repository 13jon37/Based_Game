#include "include/platform.h"

#include <stdio.h>
#include <stdlib.h>

platform_t* platform_init(const char* window_name)
{
    platform_t* platform = malloc(sizeof(struct PLATFORM_STRUCT));
    
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("Failed to init sdl video.\n");
        exit(1);
    }
    
    platform->buffer.window = SDL_CreateWindow(window_name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);
    
    if (platform->buffer.window)
    {
        platform->buffer.renderer = SDL_CreateRenderer(platform->buffer.window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    }
    else
    {
        printf("Failed to create window.\n");
        exit(1);
    }
    
    platform->running = true;
    
    return platform;
}

void platform_clear(platform_t* platform)
{
    SDL_SetRenderDrawColor(platform->buffer.renderer, 0, 0, 0, 255);
    SDL_RenderClear(platform->buffer.renderer);
}

void platform_render(platform_t* platform)
{
    SDL_RenderPresent(platform->buffer.renderer);
}

void platform_destroy(platform_t* platform)
{
    SDL_DestroyWindow(platform->buffer.window);
    SDL_DestroyRenderer(platform->buffer.renderer);
    
    platform->running = false;
    
    free(platform);
    SDL_Quit();
}