#ifndef MAIN_H
#define MAIN_H

/* Necessary libraries that I included*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/* My Used Function prototypes */
int main(void);
int _putchar(char c);
char *read_line(void);
char **parse_line(char *line);
void free_memory(char **tokens);
void execute_command(char **argv);
pid_t fork_process(char **argv);
void execute_child(char **argv);

#endif /* MAIN_H */
