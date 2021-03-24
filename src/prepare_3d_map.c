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

static void ground_set_3d_points(world *_world)
{
	for (int i = 0; i < WORLD_X; i++) {
		for (int j = 0; j < WORLD_Y; j++) {
			_world->_3d_ground[i][j] = (sfVector3f){i * _world->camera_info.scaling, j * _world->camera_info.scaling, matrix_get(_world->level_height, i, j) * _world->camera_info.scaling};
		}
	}
}

static void ground_center(world *_world)
{
	float x = _world->_3d_ground[(WORLD_X / 2)][(WORLD_Y / 2)].x;
	float y = _world->_3d_ground[(WORLD_X / 2)][(WORLD_Y / 2)].y;

	for (int i = 0; i < WORLD_X; i++) {
		for (int j = 0; j < WORLD_Y; j++) {
			_world->_3d_ground[i][j].y -= y;
			_world->_3d_ground[i][j].x -= x;
		}
	}
}

static void rotate_point(world *wrld, int i, int j)
{
	sfVector2f k = {wrld->_3d_ground[i][j].x, wrld->_3d_ground[i][j].y};
	wrld->_3d_ground[i][j].x = k.x*cos(rad(wrld->camera_info.angle_x)) - k.y * sin(rad(wrld->camera_info.angle_x));
	wrld->_3d_ground[i][j].y = k.x*sin(rad(wrld->camera_info.angle_x)) + k.y * cos(rad(wrld->camera_info.angle_x));
}

static void apply_camera(world *wrld)
{
	for (int i = 0; i < WORLD_X; i++) {
		for (int j = 0; j < WORLD_Y; j++) {
			rotate_point(wrld, i, j);
		}
	}
}


void prepare_3d_map(world *wrld)
{
	ground_set_3d_points(wrld);
	ground_center(wrld);
	apply_camera(wrld);
}
