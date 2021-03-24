/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** my_world
*/

#include "world.h"

static void add_point(world *wrld, int i, int j)
{
	sfVertex vertex;
	
	vertex.color = wrld->colors[i][j];
	vertex.position = wrld->projected_ground[i][j];
	sfVertexArray_append(wrld->ground_fill, vertex);
}

void v_fill(world *wrld)
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
