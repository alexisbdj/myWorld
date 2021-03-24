/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** my_world
*/

#ifndef SAVE_H_
#define SAVE_H_

#include "matrix.h"

matrix *load(char *path);

int save(char *path, matrix *map);

#endif
