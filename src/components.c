#include "include/components.h"
#include "include/game_render.h"

#include <stdlib.h>

void add_component_position(entity_t* entity, i32 x, i32 y)
{
    entity->components.component_position = malloc(sizeof(component_position_t));
    entity->components.component_position->x = x;
    entity->components.component_position->y = y;
}

void add_component_draw(entity_t* entity, i32 color, i32 size)
{
    entity->components.component_draw = malloc(sizeof(component_draw_t));
    entity->components.component_draw->color = color;
    entity->components.component_draw->size = size;
}

void free_entity(entity_t* entity)
{
    if (entity->components.component_position) free(entity->components.component_position);
    if (entity->components.component_draw) free(entity->components.component_draw);
}

i32 update_position_system(entity_t* entity)
{
    if (!entity->components.component_position) return 1;
    entity->components.component_position->x++;
    entity->components.component_position->y--;
}

i32 draw_system(entity_t* entity)
{
    if (!entity->components.component_position || !entity->components.component_draw) return 1;
}