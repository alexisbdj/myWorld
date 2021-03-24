/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** my_world
*/

#include <math.h>
#include "my_maths.h"
#include "world.h"
#include "defines.h"


static void ground_fill_vertex_update(world *wrld)
{
	sfVertexArray_destroy(wrld->ground_fill);
	wrld->ground_fill = sfVertexArray_create();
	sfVertexArray_setPrimitiveType(wrld->ground_fill, sfQuads);
	v_fill(wrld);
}
void world_prerender(world *wrld)
{
	prepare_3d_map(wrld);
	projection_2d(wrld);
	ground_fill_vertex_update(wrld);
	ground_map_update(wrld);
}
