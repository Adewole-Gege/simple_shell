#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>

void execute_command(char **argv);
pid_t fork_process(char **argv);
void execute_child(char **argv);

#endif /* MAIN_H */
