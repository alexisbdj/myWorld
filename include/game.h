/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** my_world
*/

#ifndef GAME_H_
#define GAME_H_

#include <SFML/Graphics.h>
#include "world.h"
#include "keyboard.h"
#include "matrix.h"

typedef struct
{
	sfRenderWindow *window;
	sfView *view;
	world *_world;
	s_keyboard keyboard;
} game;

game *game_create(matrix *map, char *path);

void game_destory(game *_game);

int game_run(game *_game);

void game_process_event(game *_game);

void game_update(game *_game, sfTime deltaTime);

void game_render(game *_game);

#endif
