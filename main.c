#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "main.h"

#define MAX_LINE 1024

/**
 * execute_command - Executes the given command by forking a process.
 * @argv: Array of strings representing the command and its arguments.
 */
void execute_command(char **argv)
{
    if (argv[0] != NULL)
    {
        pid_t pid = fork_process(argv);
        if (pid > 0)
        {
            int status;
            waitpid(pid, &status, 0);
        }
    }
}

/**
 * fork_process - Creates a child process to execute the command.
 * @argv: Array of strings representing the command and its arguments.
 * 
 * Return: The PID of the child process.
 */
pid_t fork_process(char **argv)
{
    pid_t pid = fork();
    if (pid == 0)
    {
        execute_child(argv);
    }
    return pid;
}

/**
 * execute_child - Replaces the child process image with the command.
 * @argv: Array of strings representing the command and its arguments.
 */
void execute_child(char **argv)
{
    execvp(argv[0], argv);
    perror("execvp");
    exit(EXIT_FAILURE);
}

/**
 * main - Entry point for the shell.
 * 
 * Return: Always 0 (Success).
 */
int main(void)
{
    char line[MAX_LINE];
    char *argv[MAX_LINE / 2 + 1];
    char *token;
    int i;

    while (1)
    {
        printf("#cisfun$ ");
        if (fgets(line, sizeof(line), stdin) == NULL)
        {
            if (feof(stdin))
            {
                printf("\n");
                break; /* Handle EOF (Ctrl+D) */
            }
            perror("fgets");
            exit(EXIT_FAILURE);
        }

        /* Tokenize the input line */
        i = 0;
        token = strtok(line, " \n");
        while (token != NULL && i < MAX_LINE / 2 + 1)
        {
            argv[i++] = token;
            token = strtok(NULL, " \n");
        }
        argv[i] = NULL;

        /* Execute the command */
        execute_command(argv);
    }

    return 0;
}
