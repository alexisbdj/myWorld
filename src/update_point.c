/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** my_world
*/

#include "world.h"
#include "my_maths.h"
#include <math.h>
#include "defines.h"

void basic_tool(world *_world, sfTime deltaTime, s_keyboard const input, s_points stat)
{
	float current = matrix_get(_world->level_height, stat.current_point.x, stat.current_point.y);
	float new;
	float dist = distance((sfVector2f) {stat.current_point.x, stat.current_point.y},
		(sfVector2f) {stat.center.x, stat.center.y});

	float sum = 10 * cos((dist/15)*1.55);
	if (input.mouse_right.status) {
		sum *= -1;
	}
	new = current + sum * sfTime_asSeconds(deltaTime);

	matrix_set(_world->level_height, stat.current_point.x, stat.current_point.y, new);
}

void plan_tool(world *_world, s_keyboard const input, s_points stat)
{
	if (input.mouse_left.status) {
		matrix_set(_world->level_height, stat.current_point.x, stat.current_point.y, _world->tl_panel.plan_height);
	}
	else if (input.mouse_right.status) {
		matrix_set(_world->level_height, stat.current_point.x, stat.current_point.y, 0.f);
	}
}

void update_point(world *_world, sfTime deltaTime, s_keyboard const input, s_points stat)
{
	float dist = distance((sfVector2f) {stat.current_point.x, stat.current_point.y},
		(sfVector2f) {stat.center.x, stat.center.y});
	if (dist < 15.f) {
		if (_world->tl_panel.selected_tool == ID_BASIC_TOOL)
			basic_tool(_world, deltaTime, input, stat);
		else if (_world->tl_panel.selected_tool == ID_PLAN_TOOL)
			plan_tool(_world, input, stat);
	}
}
