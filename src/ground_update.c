/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** my_world
*/

#include "world.h"
#include "my_maths.h"
#include <math.h>

sfVector2i find_point_map(sfVector2i mouse_pos)
{
	sfVector2i result;

	result.x = ((float) mouse_pos.x / (float) X_MAP_SIZE) * WORLD_X;
	result.y = ((float) mouse_pos.y / (float) Y_MAP_SIZE) * WORLD_Y;

	return result;
}

void update_area(world *_world, sfTime deltaTime, s_keyboard const input, sfVector2i center)
{
	if (input.mouse_left.pressed) {
		_world->tl_panel.plan_height = matrix_get(_world->level_height, center.x, center.y);
	}

	for (int i = center.x - 15; i < center.x + 15; i++) {
		for (int j = center.y - 15; j < center.y + 15; j++) {
			update_point(_world, deltaTime, input,
				create_stat((sfVector2i){i, j}, center));
		}
	}
}

void world_ground_update(world *_world, sfTime deltaTime, s_keyboard const input)
{
	if (input.mouse_left.status || input.mouse_right.status) {
		if (input.mouse_pos.x < X_MAP_SIZE && input.mouse_pos.y < Y_MAP_SIZE) {
			update_area(_world, deltaTime, input, 
				find_point_map(input.mouse_pos));
		}
		else if (input.mouse_pos.x > TOOL_WIDTH) {
			update_area(_world, deltaTime, input, 
				find_point_on_proj(_world, input.mouse_pos));
		}
	}
}
