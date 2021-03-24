/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** my_world
*/

#include <math.h>
#include "world.h"
#include "my_maths.h"
#include "world.h"
#include "defines.h"

static sfVector2f point_projection(sfVector3f v)
{
	sfVector2f _projection;
	
	_projection.x = cos(rad(X_ANGLE)) * v.x - cos(rad(X_ANGLE)) * v.y;
	_projection.y = sin(rad(Y_ANGLE)) * v.y + sin(rad(Y_ANGLE)) * v.x - v.z;
	return _projection;
}

static void ground_projection(world *_world)
{
	for (int i = 0; i < WORLD_X; i++) {
		for (int j = 0; j < WORLD_Y; j++) {
			_world->projected_ground[i][j] = point_projection(_world->_3d_ground[i][j]);
		}
	}
}

static void center_on_view(world *_world)
{
	for (int i = 0; i < WORLD_X; i++) {
		for (int j = 0; j < WORLD_Y; j++) {
			_world->projected_ground[i][j].x += ((VIEW_X - TOOL_WIDTH) / 2) + TOOL_WIDTH;
			_world->projected_ground[i][j].y += VIEW_Y / 2;
		}
	}
}

void projection_2d(world *wrld)
{
	ground_projection(wrld);
	center_on_view(wrld);
}
