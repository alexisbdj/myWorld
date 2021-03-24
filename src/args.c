/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** my_world
*/

#include "game.h"
#include "defines.h"
#include "mini_lib.h"
#include "save.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void show_help()
{
	int file;
	char un[30000];
	int nb;
	int compteur = 0;
	file = open(README_PATH, O_RDONLY);
	nb = 1;
		while (nb > 0) {
			nb = read(file, un, 30000-compteur);
		        write(1, un, nb);
			compteur += nb;
		}
	close(file);
}

void user_dont_know_how_to_use_this_prog()
{
	write(1, HELP_MSG, 37);
}

int launch(matrix *mat, char *path)
{
	game *_game = game_create(mat, path);
	return game_run(_game);	
}


int w_args(int argc, char **argv)
{
	if (my_strcmp(argv[1], "-h") == 0) {
		show_help();
	}
	else if (my_strcmp(argv[1], "-l") == 0) {
		launch(load(argv[2]), argv[2]);
	}
	else if (my_strcmp(argv[1], "-n") == 0) {
		if (argc >= 3) {
			launch(matrix_create(WORLD_X, WORLD_Y, NULL), argv[2]);	
		}
	}
	else if (my_strcmp(argv[1], "-c") == 0) {
		if (argc >= 3) {
			launch(load(argv[2]), NULL);	
		}
	}
	else {
		user_dont_know_how_to_use_this_prog();
	}
	return 0;
}
