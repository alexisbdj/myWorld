/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** my_world
*/

#include <stdlib.h>
#include "game.h"

game *game_create(matrix *map, char *path)
{
	game *new = malloc(sizeof(game));
	sfFloatRect view_rect;
	view_rect.left = 0;
	view_rect.top = 0;
	view_rect.width = VIEW_X;
	view_rect.height = VIEW_Y;
	new->window = sfRenderWindow_create(sfVideoMode_getDesktopMode(), "World", sfDefaultStyle, NULL);
	sfRenderWindow_setFramerateLimit(new->window, 60);
	sfRenderWindow_setVerticalSyncEnabled(new->window, sfTrue);
	new->_world = world_create(map, path);
	new->view = sfView_createFromRect(view_rect);
	keyboard_keyboard(&new->keyboard);
	return new;
}

void game_destory(game *_game)
{
	sfRenderWindow_destroy(_game->window);
	world_destroy(_game->_world);
	free(_game);
}
