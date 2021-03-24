/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** my_world
*/

#include "world.h"
#include "my_maths.h"

sfVector2i find_point_on_proj(world *_world, sfVector2i mouse_pos)
{
	sfVector2f float_m_pos = {mouse_pos.x, mouse_pos.y};
	sfVector2i result;
	float dist = 1900;

	for (int i = 0; i < WORLD_X; i++) {
		for (int j = 0; j < WORLD_Y; j++) {
			float d = distance(float_m_pos, _world->projected_ground[i][j]);
			if (d < dist) {
				result.x = i;
				result.y = j;
				dist = d;
			}

		}
	}
	return result;
}
