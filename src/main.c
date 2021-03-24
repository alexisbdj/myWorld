/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** my_world
*/

#include "game.h"
#include "defines.h"

int w_args(int argc, char **argv);

int main(int argc, char **argv)
{
	if (argc > 1) {
		return w_args(argc, argv);
	}
	else {
		game *_game = game_create(matrix_create(WORLD_X, WORLD_Y, NULL), NULL);
		return game_run(_game);
	}
	return 0;
}
