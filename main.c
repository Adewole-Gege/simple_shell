#include "main.h"
/**
* main - Entry point for the shell.
*
* Return: Always 0.
*/
int main(void)
{
char *line = NULL;
size_t len = 0;
ssize_t nread;
while (1)
{
printf("#cisfun$ ");
nread = getline(&line, &len, stdin);
if (nread == -1)
{
if (feof(stdin))
{
free(line);
exit(0); /* Exit on Ctrl+D */
}
perror("getline");
free(line);
exit(EXIT_FAILURE);
}
if (line[nread - 1] == '\n')
line[nread - 1] = '\0'; /* Remove newline character */
if (line[0] != '\0')
execute_command(line);
}
free(line);
return (0);
}
/**
* execute_command - Forks and executes the command in a child process.
* @line: The command line to execute.
*/
void execute_command(char *line)
{
pid_t pid = fork_process(line);
if (pid == 0) /* Child process */
{
char *argv[2];   /* Declare the array */
argv[0] = line;  /* Assign the command to the first element */
argv[1] = NULL;  /* Set the second element to NULL */
if (execve(line, argv, NULL) == -1)
{
perror("./shell");
exit(EXIT_FAILURE);
}
}
else if (pid < 0) /* Error forking */
{
perror("fork");
}
else /* Parent process */
{
wait(NULL); /* Wait for child to finish */
}
}
/**
* fork_process - Forks the current process.
* @line: The command line to execute (not used directly here).
*
* Return: The PID of the child process.
*/
pid_t fork_process(char *line)
{
(void)line; /* Unused parameter */
return (fork());
}
