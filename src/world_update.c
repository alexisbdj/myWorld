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
#include "keyboard.h"
#include "save.h"

static void color_update(world *_world)
{
	for (int i = 0; i < WORLD_X; i++) {
		for (int j = 0; j < WORLD_Y; j++) {
			_world->colors[i][j].a = 255;
			_world->colors[i][j].r = 0;
			_world->colors[i][j].g = 255 * ((matrix_get(_world->level_height, i, j) + 100) / 200);
			_world->colors[i][j].b = 0;
		}
	}
}

void cam_update_rotation(world *_world, sfTime deltaTime, s_keyboard const input)
{
	if (input.Q.status) {
		_world->camera_info.angle_x -= CAM_SPEED * sfTime_asSeconds(deltaTime);
		if (_world->camera_info.angle_x < -(40)) {
			_world->camera_info.angle_x = -(40);
		}
	}
	if (input.D.status) {
		_world->camera_info.angle_x += CAM_SPEED * sfTime_asSeconds(deltaTime);
		if (_world->camera_info.angle_x > 130) {
			_world->camera_info.angle_x = 130;
		}
	}
}

void world_update(world *_world, sfTime deltaTime, s_keyboard const input)
{
	world_ground_update(_world, deltaTime, input);
	cam_update_rotation(_world, deltaTime, input);
	if (input.Z.status) {
		_world->camera_info.scaling += CAM_SPEED * sfTime_asSeconds(deltaTime);
	}
	if (input.S.status) {
		_world->camera_info.scaling -= CAM_SPEED * sfTime_asSeconds(deltaTime);
		if (_world->camera_info.scaling < 1) {
			_world->camera_info.scaling = 1;
		}
	}
	selection_update(_world, input);
	color_update(_world);
	if (input.F.pressed) {
		save(_world->path, _world->level_height);
	}
}
