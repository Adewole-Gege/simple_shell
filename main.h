#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

extern char **environ;

void betty_compliant_code(void); /* Task 0 prototype */
void simple_shell(void);         /* Task 1 prototype */

#endif /* MAIN_H */
