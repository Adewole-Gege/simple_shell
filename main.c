#include "main.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
* read_command - Reads the command input by the user.
*
* Description: This function reads a line of input from the user
* and removes the newline character at the end.
*
* Return: A pointer to the command line input by the user,
* or NULL if there was an error.
*/
char *read_command(void)
{
char *line = NULL;
size_t len = 0;
ssize_t nread;
nread = getline(&line, &len, stdin);
if (nread == -1)
{
if (feof(stdin))
{
free(line);
exit(EXIT_SUCCESS); /* End of file */
}
perror("getline");
exit(EXIT_FAILURE);
}
if (line[nread - 1] == '\n') /* Remove newline character */
line[nread - 1] = '\0';
return (line);
}
/**
* fork_process - Forks a process to execute a command.
* @line: The command to execute.
*
* Return: The PID of the child process.
*/
pid_t fork_process(char *line)
{
pid_t pid;
pid = fork();
if (pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
return (pid);
}
/**
* execute_child - Executes the command in the child process.
* @line: The command to execute.
*/
void execute_child(char *line)
{
char *argv[] = {line, NULL};
if (execve(line, argv, NULL) == -1)
{
perror("./shell");
exit(EXIT_FAILURE);
}
}
/**
* execute_command - Executes the command.
* @line: The command to execute.
*/
void execute_command(char *line)
{
pid_t pid;
int status;
pid = fork_process(line);
if (pid == 0) /* Child process */
{
execute_child(line);
}
else /* Parent process */
{
wait(&status);
}
}
/**
* main - Simple UNIX command line interpreter.
*
* Description: A basic shell that executes commands
* from the user input.
*
* Return: Always 0 (Success)
*/
int main(void)
{
char *line;
while (1)
{
printf("#cisfun$ ");
line = read_command();
execute_command(line);
free(line);
}
return (0);
}
