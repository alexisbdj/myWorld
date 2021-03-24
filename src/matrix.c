/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** my_world
*/

#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>

matrix *matrix_create(unsigned int x, unsigned int y, void (*fillF)(matrix *mat))
{
	matrix *new = malloc(sizeof(matrix));
	if (new == NULL) {
		return new;
	}
	
	new->content = malloc(sizeof(float) * x * y);
	if (new->content == NULL) {
		free(new);
		return new;
	}
	new->x = x;
	new->y = y;
	if (fillF == NULL)
		matrix_fill(new, 0);
	else
		fillF(new);
	return new;
}

void matrix_destruct(matrix *mat)
{
	free(mat->content);
	free(mat);
}

void matrix_fill(matrix *mat, float value)
{
	for (int i = 0; i < (mat->x*mat->y); i++) {
		mat->content[i] = value;
	}
}


float matrix_get(matrix *mat, int x, int y)
{
	if (x < 0 || x >= mat->x ||
		y < 0 || y >= mat->y) {
		return 0;
	}
	return mat->content[x + (y * mat->x)];
}

void matrix_set(matrix *mat, int x, int y, float value)
{
	if (!(x < 0 || x >= mat->x ||
		y < 0 || y >= mat->y)) {
		mat->content[x + (y * mat->x)] = value;
	}
}
