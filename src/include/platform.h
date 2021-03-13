/* date = March 13th 2021 1:50 pm */

#ifndef PLATFORM_H
#define PLATFORM_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "language_layer.h"

// Buffer struct for all things SDL video related
typedef struct BUFFER_STRUCT {
    SDL_Window* window;
    SDL_Renderer* renderer;
} buffer_t;

// Platform "Class" - C-OOP
typedef struct PLATFORM_STRUCT {
    buffer_t buffer; // Nested data structure :)
    bool running;
    SDL_Event event;
} platform_t;

// Platform "methods"
platform_t* platform_init(const char* window_name);
void platform_render(platform_t* platform);
void platform_clear(platform_t* platform);
void platform_destroy(platform_t* platform);

#endif //PLATFORM_H
