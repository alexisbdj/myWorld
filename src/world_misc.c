/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** my_world
*/

#include "world.h"

s_points create_stat(sfVector2i point, sfVector2i center)
{
	s_points ret;
	ret.center = center;
	ret.current_point = point;
	return ret;
}
