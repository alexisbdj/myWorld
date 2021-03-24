/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** my_world
*/

#ifndef BUTTON_H_
#define BUTTON_H_

#include <SFML/Graphics.h>

typedef struct button button;
struct button
{
	sfRectangleShape *shape;
	sfFloatRect hitbox;
	void (*pressed)(button *this, void *_world);
	int id;
};

button *button_create(int id);
void button_destroy(button *_button);
void button_render(sfRenderWindow *window, button *_button);

void button_create_basic(button *new);
void button_create_plan(button *new);

#endif
