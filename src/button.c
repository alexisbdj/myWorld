/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** my_world
*/

#include "button.h"
#include "defines.h"
#include <stdlib.h>

button *button_create(int id)
{
	button *new = malloc(sizeof(button));
	
	new->shape = sfRectangleShape_create();
	sfRectangleShape_setFillColor(new->shape, sfWhite);
	new->id = id;
	switch (id)
	{
		case ID_BASIC_TOOL:
			button_create_basic(new);
		break;
		case ID_PLAN_TOOL:
			button_create_plan(new);
	}

	return new;
}

void button_destroy(button *_button)
{
	sfRectangleShape_destroy(_button->shape);
	free(_button);
}

void button_render(sfRenderWindow *window, button *_button)
{
	sfRenderWindow_drawRectangleShape(window, _button->shape, NULL);
}
