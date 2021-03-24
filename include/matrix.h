/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** matchstick
*/

#ifndef matrix_H_
#define matrix_H_

typedef struct
{
	unsigned int x;
	unsigned int y;
	float *content;
} matrix;

matrix *matrix_create(unsigned int x, unsigned int y, void (*fillF)(matrix *mat));

void matrix_destruct(matrix *mat);

void matrix_fill(matrix *mat, float value);

float matrix_get(matrix *mat, int x, int y);

void matrix_set(matrix *mat, int x, int y, float value);

#endif
