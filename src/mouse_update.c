/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** my_world
*/

#include "keyboard.h"

void mouse_update_status(s_keyboard *keyboard, int button, sfBool value)
{
	switch(button)
	{
		case 0:
			keyboard->mouse_left.status = value;
			if (value == sfTrue)
				keyboard->mouse_left.pressed = sfTrue;
		break;
		case 1:
			keyboard->mouse_right.status = value;
			if (value == sfTrue)
				keyboard->mouse_left.pressed = sfTrue;
		break;
	}
}
