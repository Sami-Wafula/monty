#include "monty.h"

int main(int ac, char *av[])
{
	char *buf = NULL, *string[100] = {NULL};
	int ln = 0, i = 0, fd, y, x;
	stack_t *ptr;
	stack_t *stack = NULL;

	instruction_t st[] = {
		{"pall", pall},
		{"pint", pint},
		{"add", add},
		{"swap", swap},
		{"pop", pop},
		{"nop", NULL}
	};

    if (ac != 2)
		printf("not right ac");
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
    {
            fprintf(stderr, "%s won't open", av[1]);
            exit(EXIT_FAILURE);
    }
	buf = malloc(1000);
    if (buf == NULL)
    {
        fprintf(stderr, "Malloc Failure");
        exit(EXIT_FAILURE);
    }
	for (x = 0; x < 1000; x++)
		buf[x] = '\0';
    y = read(fd, buf, 1000);
    if (y == -1)
        exit(EXIT_FAILURE);
	//printf("%s\n", buf);
    string[ln] = strtok(buf, "\n");
	while (string[ln++])
		string[ln] = strtok(NULL, "\n");
	
	for(ln = 0; string[ln]; ln++)
	{	
		if (_strcmp("push", string[ln]))
			push(&stack, ln, pushint(string[ln]));
		else
		{	
			i = 0;
			while (st[i].opcode != "nop")
			{	
				if (_strcmp(st[i].opcode, string[ln]))
					st[i].f(&stack, ln);
				i++;
			}
		}
	}
	free_stack(stack);
	free(buf);
	close(fd);
	return (0);
}
