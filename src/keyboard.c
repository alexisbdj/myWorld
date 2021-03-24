/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** my_world
*/

#include "keyboard.h"

void keyboard_keyboard(s_keyboard *keyboard)
{
	keyboard->D.status = 0;
	keyboard->Q.status = 0;
	keyboard->S.status = 0;
	keyboard->Z.status = 0;
	keyboard->F.status = 0;
	keyboard->mouse_left.status = 0;
	keyboard->mouse_right.status = 0;
}

void keyboard_update_status(s_keyboard *keyboard, sfKeyCode key, sfBool value)
{
	switch(key)
	{
		case sfKeyW:	//changed before sharing to fit qwerty keyboards
			keyboard->Z.status = value;
			if (value == sfTrue)
				keyboard->Z.pressed = sfTrue;
		break;
		case sfKeyS:
			keyboard->S.status = value;
			if (value == sfTrue)
				keyboard->S.pressed = sfTrue;
		break;
		case sfKeyA:	//changed before sharing to fit qwerty keyboards
			keyboard->Q.status = value;
			if (value == sfTrue)
				keyboard->Q.pressed = sfTrue;
		break;
		case sfKeyD:
			keyboard->D.status = value;
			if (value == sfTrue)
				keyboard->D.pressed = sfTrue;
		break;
		case sfKeyF:
			keyboard->F.status = value;
			if (value == sfTrue)
				keyboard->F.pressed = sfTrue;
		break;
	}
}

void keyboard_update(s_keyboard *keyboard)
{
	keyboard->D.pressed = sfFalse;
	keyboard->Q.pressed = sfFalse;
	keyboard->Z.pressed = sfFalse;
	keyboard->S.pressed = sfFalse;
	keyboard->F.pressed = sfFalse;
	keyboard->mouse_left.pressed = sfFalse;
	keyboard->mouse_right.pressed = sfFalse;
}
