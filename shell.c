#include "main.h"

/**
 * betty_compliant_code - Task 0: Ensures code passes Betty checks
 * (Placeholder for Task 0's functionality)
 */
void betty_compliant_code(void)
{
    /* Task 0 specific code here */
}

/**
 * simple_shell - Task 1: Basic shell loop that handles command execution
 */
void simple_shell(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read_len;
    char *args[2];
    pid_t pid;

    while (1)
    {
        printf("#cisfun$ "); /* Display prompt */

        read_len = getline(&line, &len, stdin);
        if (read_len == -1) /* Handle Ctrl+D */
        {
            printf("\n");
            break;
        }

        line[read_len - 1] = '\0'; /* Remove newline character */

        args[0] = line;  /* First argument is the command */
        args[1] = NULL;  /* No arguments passed */

        pid = fork();
        if (pid == -1) /* Handle fork failure */
        {
            perror("Error:");
            break;
        }
        if (pid == 0) /* Child process */
        {
            if (execve(args[0], args, environ) == -1) /* Execute the command */
            {
                perror("./hsh");
            }
            exit(EXIT_FAILURE);
        }
        else /* Parent process */
        {
            wait(NULL); /* Wait for the child process to finish */
        }
    }

    free(line);
}
