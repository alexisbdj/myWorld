/*
** EPITECH PROJECT, 2018
** my_world
** File description:
** my_world
*/

#include "mini_lib.h"
#include <stdlib.h>

int my_strcmp(char const *s1, char const *s2)
{
	int i = 0;
	while (!(s1[i] == 0 && s2[i] == 0) && s1[i] == s2[i])
	{
		i++;
	}
	if (s1[i] == s2[i])
	{
		return 0;
	}
	else
	{
		return (s1[i] - s2[i]);
	}
}

int my_strlen(char const *str)
{
	int retour = 0;
	for (int i = 0; str[i] ; i++){
		retour++;
	}
	return retour;
}

char *my_strcpy(char *dest, char const *src)
{
	int length = my_strlen(src);
	for (int i = 0; i < length; i++)
	{
		dest[i] = src[i];
	}
	dest[length] = 0;
	return dest;
}

char *my_strdup(char const *src)
{
	char *str;

	str = malloc(my_strlen(src) + 1);
	my_strcpy(str, src);

	return str;
}
