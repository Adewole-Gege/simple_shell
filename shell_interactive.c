#include "shell.h"

/**
 * process_input - Processes user input in interactive mode
 * @line: Pointer to the input line
 * @len: Pointer to the size of the buffer for getline
 *
 * Return: 0 to continue, 1 to exit the shell
 */
int process_input(char **line, size_t *len)
{
	ssize_t read;
	int result;

	read = getline(line, len, stdin);
	if (read == -1)
	{
		if (feof(stdin))
			write(STDOUT_FILENO, "\n", 1);
		return (1);
	}

	if (read > 0 && (*line)[read - 1] == '\n')
		(*line)[read - 1] = '\0';

	if ((*line)[0] == '\0')
		return (0);

	result = execute_command(*line);
	if (result == -1)
		perror("./hsh");
	else if (result == 2)
		return (1);

	return (0);
}
