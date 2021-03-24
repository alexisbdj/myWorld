/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** my_world
*/

#include <stdlib.h>
#include "world.h"
#include "defines.h"
#include "mini_lib.h"

static void tool_panel_set_rect(world *new)
{
	sfIntRect rect;

	rect.height = 100;
	rect.width = 130;
	rect.top = 0;
	rect.left = 0;
	sfRectangleShape_setTextureRect(new->tl_panel.buttons[0]->shape, rect);
	rect.left = 130;
	sfRectangleShape_setTextureRect(new->tl_panel.buttons[1]->shape, rect);
}

static void tool_panel_init(world *new)
{
	tools_background(new);
	new->tl_panel.buttons = malloc(sizeof(button*) * TOOL_BUTTON_NUMBER);
	for (int i = 0; i < TOOL_BUTTON_NUMBER; i++)
		new->tl_panel.buttons[i] = button_create(i);

	new->tl_panel.selected_tool = 0;
	new->tl_panel.selected = sfRectangleShape_create();
	sfRectangleShape_setFillColor(new->tl_panel.selected, sfRed);
	new->tl_panel.tex = sfTexture_createFromFile("./rc/buttons.png", NULL);
	for (int i = 0; i < TOOL_BUTTON_NUMBER; i++) {
		sfRectangleShape_setTexture(new->tl_panel.buttons[i]->shape, new->tl_panel.tex, sfFalse);
	}
	tool_panel_set_rect(new);
}

world *world_create(matrix *map, char *path)
{
	world *new = malloc(sizeof(world));
	new->level_height = map;
	new->ground_fill = sfVertexArray_create();
	new->ground_lines = sfVertexArray_create();
	new->ground_map._map = sfVertexArray_create();
	new->ground_map.border = sfVertexArray_create();
	tool_panel_init(new);
	update_selected_tool(new);
	init_cam(new);
	world_create_tabs(new);
	if (path != NULL) {
		new->path = my_strdup(path);
	}
	else {
		new->path = my_strdup("./save");
	}
	return new;
}

void world_destroy(world *_world)
{
	matrix_destruct(_world->level_height);
	sfVertexArray_destroy(_world->ground_fill);
}


void render_world(sfRenderWindow *window, world *_world)
{
	sfRenderWindow_drawVertexArray(window, _world->ground_fill, NULL);
	sfRenderWindow_drawVertexArray(window, _world->ground_map._map, NULL);
	sfRenderWindow_drawVertexArray(window, _world->ground_map.border, NULL);
	sfRenderWindow_drawVertexArray(window, _world->tl_panel.background, NULL);
	sfRenderWindow_drawRectangleShape(window, _world->tl_panel.selected, NULL);
	for (int i = 0; i < TOOL_BUTTON_NUMBER; i++)
		button_render(window, _world->tl_panel.buttons[i]);
}
