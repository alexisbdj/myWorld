/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** my_world
*/

#include <math.h>
#include <SFML/Graphics.h>
#include "my_maths.h"

float rad(float angle)
{
	return (angle * M_PI)/180;
}

float float_abs(float n)
{
	if (n > 0) {
		return n;
	}
	return n * -1;
}

float float_square(float n)
{
	return n * n;
}

float distance(sfVector2f a, sfVector2f b)
{
	return sqrt(float_square(float_abs(a.x - b.x)) + float_square(float_abs(a.y - b.y)));
}
