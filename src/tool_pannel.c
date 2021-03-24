/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** my_world
*/

#include "world.h"

void selection_update(world *_world, s_keyboard const input)
{
	if (input.mouse_left.pressed) {
		for (int i = 0; i < TOOL_BUTTON_NUMBER; i++) {
			if (input.mouse_pos.x > _world->tl_panel.buttons[i]->hitbox.left &&
			input.mouse_pos.y > _world->tl_panel.buttons[i]->hitbox.top &&
			input.mouse_pos.x < _world->tl_panel.buttons[i]->hitbox.left +
			_world->tl_panel.buttons[i]->hitbox.width &&
			input.mouse_pos.y < _world->tl_panel.buttons[i]->hitbox.top +
			_world->tl_panel.buttons[i]->hitbox.height) {
				_world->tl_panel.selected_tool = _world->tl_panel.buttons[i]->id;
			}
		}
		update_selected_tool(_world);
	}
}

void update_selected_tool(world *wrld)
{
	int selected = wrld->tl_panel.selected_tool;
	sfRectangleShape_setPosition(wrld->tl_panel.selected, 
		(sfVector2f) {wrld->tl_panel.buttons[selected]->hitbox.left -
		TOOL_SELECTED_BORDER_WIDTH,
		wrld->tl_panel.buttons[selected]->hitbox.top -
		TOOL_SELECTED_BORDER_WIDTH});
	sfRectangleShape_setSize(wrld->tl_panel.selected,
		(sfVector2f) {wrld->tl_panel.buttons[selected]->hitbox.width +
		TOOL_SELECTED_BORDER_WIDTH * 2,
		wrld->tl_panel.buttons[selected]->hitbox.height +
		TOOL_SELECTED_BORDER_WIDTH * 2});
}
