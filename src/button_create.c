/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** my_world
*/

#include "button.h"
#include "defines.h"

void button_create_basic(button *new)
{
	new->hitbox.top = TOOL_TOP + TOOL_BUTTON_SPACE;
	new->hitbox.left = TOOL_BUTTON_BORDER_SPACE;
	new->hitbox.width = TOOL_WIDTH - TOOL_BUTTON_BORDER_SPACE * 2;
	new->hitbox.height = TOOL_BUTTON_SIZE_Y;
	sfRectangleShape_setPosition(new->shape, (sfVector2f) {new->hitbox.left, new->hitbox.top});
	sfRectangleShape_setSize(new->shape, (sfVector2f) {new->hitbox.width, new->hitbox.height});
}

void button_create_plan(button *new)
{
	new->hitbox.top = TOOL_TOP + TOOL_BUTTON_SPACE * 2 + TOOL_BUTTON_SIZE_Y * 1;
	new->hitbox.left = TOOL_BUTTON_BORDER_SPACE;
	new->hitbox.width = TOOL_WIDTH - TOOL_BUTTON_BORDER_SPACE * 2;
	new->hitbox.height = TOOL_BUTTON_SIZE_Y;
	sfRectangleShape_setPosition(new->shape, (sfVector2f) {new->hitbox.left, new->hitbox.top});
	sfRectangleShape_setSize(new->shape, (sfVector2f) {new->hitbox.width, new->hitbox.height});
}
