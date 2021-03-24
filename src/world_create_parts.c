/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** my_world
*/

#include "world.h"
#include <stdlib.h>

void init_cam(world *new)
{
	new->camera_info.angle_x = 0;
	new->camera_info.angle_y = 0;
	new->camera_info.scaling = BASE_SCALE;
}

int world_create_tabs(world *new)
{
	new->projected_ground = malloc(sizeof(sfVector2f*) * WORLD_X);
	for (int i = 0; i < WORLD_X; i++) {
		new->projected_ground[i] = malloc(sizeof(sfVector2f) * WORLD_Y);
	}
	new->_3d_ground = malloc(sizeof(sfVector3f*) * WORLD_X);
	for (int i = 0; i < WORLD_X; i++) {
		new->_3d_ground[i] = malloc(sizeof(sfVector3f) * WORLD_Y);
	}
	new->colors = malloc(sizeof(sfColor*) * WORLD_X);
	for (int i = 0; i < WORLD_X; i++) {
		new->colors[i] = malloc(sizeof(sfColor) * WORLD_Y);
	}
	return 0;
}

void tools_background(world *new)
{
	new->tl_panel.background = sfVertexArray_create();
	sfVertexArray_setPrimitiveType(new->tl_panel.background, sfQuads);
	sfVertex vertex;
	vertex.color.a = 255;
	vertex.color.r = TOOL_BACKGROUND_GREY_LEVEL;
	vertex.color.g = TOOL_BACKGROUND_GREY_LEVEL;
	vertex.color.b = TOOL_BACKGROUND_GREY_LEVEL;
	vertex.position.x = 0;
	vertex.position.y = TOOL_TOP;
	sfVertexArray_append(new->tl_panel.background, vertex);
	vertex.position.x = TOOL_WIDTH;
	sfVertexArray_append(new->tl_panel.background, vertex);	
	vertex.position.y = VIEW_Y;
	sfVertexArray_append(new->tl_panel.background, vertex);	
	vertex.position.x = 0;
	sfVertexArray_append(new->tl_panel.background, vertex);
}
