/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** my_world
*/

#ifndef KEYBOARD_H_
#define KEYBOARD_H_

#include <SFML/Graphics.h>

typedef struct
{
	sfBool status;
	sfBool pressed;
} input;

typedef struct
{
	input Z;
	input Q;
	input S;
	input D;
	input F;
	input mouse_left;
	input mouse_right;
	sfVector2i mouse_pos;
} s_keyboard;

void keyboard_keyboard(s_keyboard *keyboard);

void keyboard_update(s_keyboard *keyboard);
void keyboard_update_status(s_keyboard *keyboard, sfKeyCode key, sfBool value);

void mouse_update_status(s_keyboard *keyboard, int button, sfBool value);

#endif
