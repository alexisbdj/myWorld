/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** my_world
*/

#include "game.h"

int game_run(game *_game)
{
	sfClock *clock = sfClock_create();
	sfTime delta_time = sfTime_Zero;
	while (sfRenderWindow_isOpen(_game->window)) {
		delta_time = sfClock_restart(clock);
		game_process_event(_game);
		game_update(_game, delta_time);
		game_render(_game);
	}
	game_destory(_game);
	return 0;
}

void game_process_event(game *_game)
{
	sfEvent event;
	keyboard_update(&_game->keyboard);
	while (sfRenderWindow_pollEvent(_game->window, &event)) {
		if (event.type == sfEvtClosed) {
			sfRenderWindow_close(_game->window);
		}
		if (event.type == sfEvtKeyPressed) {
			keyboard_update_status(&_game->keyboard, event.key.code, sfTrue);
		}
		if (event.type == sfEvtKeyReleased) {
			keyboard_update_status(&_game->keyboard, event.key.code, sfFalse);
		}
		if (event.type == sfEvtMouseButtonPressed) {
			if (event.mouseButton.button == sfMouseLeft) {
				mouse_update_status(&_game->keyboard, 0, sfTrue);
			}
			else if (event.mouseButton.button == sfMouseRight) {
				mouse_update_status(&_game->keyboard, 1, sfTrue);
			}
		}
		if (event.type == sfEvtMouseButtonReleased) {
			if (event.mouseButton.button == sfMouseLeft) {
				mouse_update_status(&_game->keyboard, 0, sfFalse);
			}
			else if (event.mouseButton.button == sfMouseRight) {
				mouse_update_status(&_game->keyboard, 1, sfFalse);
			}
		}
	}
	_game->keyboard.mouse_pos = sfMouse_getPositionRenderWindow(_game->window);
	_game->keyboard.mouse_pos.y *= (float) VIEW_Y / (float) sfRenderWindow_getSize(_game->window).y;
	_game->keyboard.mouse_pos.y *= (float) VIEW_X / (float) sfRenderWindow_getSize(_game->window).x;
}

void game_update(game *_game, sfTime deltaTime)
{
	world_update(_game->_world, deltaTime, _game->keyboard);
}

void game_render(game *_game)
{
	world_prerender(_game->_world);
	sfRenderWindow_setView(_game->window, _game->view);
	sfRenderWindow_clear(_game->window, sfBlack);
	render_world(_game->window, _game->_world);
	sfRenderWindow_display(_game->window);
}
