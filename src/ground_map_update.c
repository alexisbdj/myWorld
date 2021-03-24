/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** my_world
*/

#include "world.h"

static void reset(world *wrld)
{
	sfVertexArray_destroy(wrld->ground_map._map);
	wrld->ground_map._map = sfVertexArray_create();
	sfVertexArray_setPrimitiveType(wrld->ground_map._map, sfQuads);
	sfVertexArray_destroy(wrld->ground_map.border);
	wrld->ground_map.border = sfVertexArray_create();
	sfVertexArray_setPrimitiveType(wrld->ground_map.border, sfQuads);
}

static void add_point(world *wrld, int i, int j)
{
	sfVertex vertex;

	vertex.color = wrld->colors[i][j];
	vertex.position.x = X_MAP_SIZE * (float) ((float) i / (float) WORLD_X);
	vertex.position.y = Y_MAP_SIZE * (float) ((float) j / (float) WORLD_Y);
	sfVertexArray_append(wrld->ground_map._map, vertex);
}

static void fill_map(world *wrld)
{
	for (int i = 0; i < WORLD_X - 1; i++) {
		for (int j = 0; j < WORLD_Y - 1; j++) {
			add_point(wrld, i, j);
			add_point(wrld, i+1, j);
			add_point(wrld, i+1, j+1);
			add_point(wrld, i, j+1);
		}
	}
}

static void border(world *wrld)
{
	sfVertex vertex;

	vertex.color = sfWhite;
	vertex.position.x = X_MAP_SIZE;
	vertex.position.y = 0;
	sfVertexArray_append(wrld->ground_map.border, vertex);
	vertex.position.x += MAP_BORDER_WIDTH;
	sfVertexArray_append(wrld->ground_map.border, vertex);
	vertex.position.y = Y_MAP_SIZE + MAP_BORDER_WIDTH;
	sfVertexArray_append(wrld->ground_map.border, vertex);
	vertex.position.x -= MAP_BORDER_WIDTH;
	sfVertexArray_append(wrld->ground_map.border, vertex);
	vertex.position.x = 0;
	vertex.position.y = Y_MAP_SIZE;
	sfVertexArray_append(wrld->ground_map.border, vertex);
	vertex.position.x = X_MAP_SIZE + MAP_BORDER_WIDTH;
	sfVertexArray_append(wrld->ground_map.border, vertex);
	vertex.position.y += MAP_BORDER_WIDTH;
	sfVertexArray_append(wrld->ground_map.border, vertex);
	vertex.position.x = 0;
	sfVertexArray_append(wrld->ground_map.border, vertex);	
}

void ground_map_update(world *wrld)
{
	reset(wrld);
	fill_map(wrld);
	border(wrld);
}
