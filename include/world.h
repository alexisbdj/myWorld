/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** my_world
*/

#ifndef WORLD_H_
#define WORLD_H_

#include <SFML/Graphics.h>
#include "keyboard.h"
#include "matrix.h"
#include "defines.h"
#include "button.h"

typedef struct
{
	sfVector2i current_point;
	sfVector2i center;
} s_points;

typedef struct
{
	float angle_x;
	float angle_y;
	float scaling;
} camera;

typedef struct
{
	sfVertexArray *_map;
	sfVertexArray *border;
} map;

typedef struct
{
	sfVertexArray *background;
	button **buttons;
	int selected_tool;
	sfRectangleShape *selected;
	float plan_height;
	sfTexture *tex;
} tool_panel;

typedef struct
{
	matrix *level_height;
	sfVertexArray *ground_lines;
	sfVertexArray *ground_fill;
	map ground_map;
	tool_panel tl_panel;
	sfVector2f **projected_ground;
	sfVector3f **_3d_ground;
	sfColor **colors;
	camera camera_info;
	char *path;
} world;

world *world_create(matrix *map, char *path);
int world_create_tabs(world *new);
void init_cam(world *new);
void tools_background(world *new);

void world_destroy(world *_world);

void world_update(world *_world, sfTime deltaTime, s_keyboard const input);
void world_ground_update(world *_world, sfTime deltaTime, s_keyboard const input);
void update_point(world *_world, sfTime deltaTime, s_keyboard const input, s_points stat);
s_points create_stat(sfVector2i point, sfVector2i center);
sfVector2i find_point_on_proj(world *_world, sfVector2i mouse_pos);

void world_prerender(world *wrld);
void v_fill(world *wrld);
void ground_map_update(world *wrld);
void prepare_3d_map(world *wrld);
void projection_2d(world *wrld);

void render_world(sfRenderWindow *window, world *_world);

void update_selected_tool(world *_world);
void selection_update(world *_world, s_keyboard const input);

#endif
