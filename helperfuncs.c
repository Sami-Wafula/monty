#include "monty.h"

/**
 * _strcmp - compares strings
 * @opcode: a string to be compared
 * @list: a string to be compared
 * Return: 0
 */
int _strcmp(char *opcode, char *list)
{

	
	while (*list != '\0')
	{
		if (*opcode == *list)
		{
			opcode++;
			list++;
			if (*opcode == '\0')
				return (1);
		}
		else
			list++;
	}
	return (0);
}

int pushint(char *list)
{
	char *opcode = "push";

	while (*list != '\0')
	{
		if (*opcode == *list)
		{
			opcode++;
			list++;
			if (*opcode == '\0')
				while (*list)
				{
					if (*list > '0' && *list < '9')
					{
						//printf("%d/n", atoi(list));
						return (atoi(list));
					}
					list++;
				}
		}
		else
			list++;
	}
	return (0);
}