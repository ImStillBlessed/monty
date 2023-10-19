#include "monty.h"



int main(int argc, char **argv)
{
	FILE *file_read;
	char *commands;
	size_t bufsize = 32;
	size_t characters;

	if (argc < 2)
	{
		perror("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	commands = malloc(sizeof(char) * bufsize);
	if (commands == NULL)
	{
		perror("Unable to allocate mem");
                exit(EXIT_FAILURE);
	}

	file_read = fopen(argv[1], "r");
	if (file_read == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	/*
	while (fgets(commands, 32, file_read) != NULL)
		printf("%s\n", commands);
	*/
	characters = getline(&commands, &bufsize, file_read);
	printf("%s", commands);
	return (0);
}
