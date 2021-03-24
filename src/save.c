/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** my_world
*/

#include "save.h"
#include "defines.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

matrix *load(char *path)
{
	int file = open(path, O_RDONLY);
	matrix *mat = matrix_create(WORLD_X, WORLD_Y, NULL);
	read(file, mat->content, (WORLD_X * WORLD_Y) * 4);
	close(file);
	return mat;
}

int save(char *path, matrix *map)
{
	int file = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	write(file, map->content, (WORLD_X * WORLD_Y) * 4);
	close(file);
	return 0;
}
