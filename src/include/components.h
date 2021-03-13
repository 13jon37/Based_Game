/* date = March 13th 2021 2:44 pm */

#ifndef COMPONENTS_H
#define COMPONENTS_H

#include "platform.h"

// Source = https://prdeving.wordpress.com/2018/06/27/videogames-programming-ecs-system-in-plain-c/

typedef struct COMPONENT_POSITION_STRUCT {
    f32 x;
    f32 y;
} component_position_t;

typedef struct COMPONENT_DRAW_STRUCT {
    i32 color;
    i32 size;
} component_draw_t;

typedef struct COMPONENTS_STRUCT {
    component_position_t* component_position;
    component_draw_t* component_draw;
} components_t;

typedef struct ENTITY_STRUCT {
    u32 uuid;
    components_t components;
} entity_t;

void add_component_position(entity_t* entity, i32 x, i32 y);
void add_component_draw(entity_t* entity, i32 color, i32 size);
void free_entity(entity_t* entity);
i32 update_position_system(entity_t* entity);
i32 draw_system(entity_t* entity);

#endif //COMPONENTS_H
