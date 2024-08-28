#ifndef MAIN_H
#define MAIN_H

/* Necessary libraries that I included*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* My Used Function prototypes */
int _putchar(char c);
void execute_command(char **argv);
char *read_line(void);
char **parse_line(char *line);
void free_memory(char **tokens);

#endif /* MAIN_H */
