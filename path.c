#include "shell.h"
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

char *find_command_in_path(char *command)
{
    char *path, *path_copy, *dir;
    char full_path[1024];
    struct stat st;

    if (command == NULL)
        return (NULL);

    if (command[0] == '/' || command[0] == '.')
    {
        if (stat(command, &st) == 0 && (st.st_mode & S_IXUSR))
        {
            char *command_copy = malloc(strlen(command) + 1);
            if (command_copy == NULL)
                return (NULL);
            strcpy(command_copy, command);
            return (command_copy);
        }
        return (NULL);
    }

    path = getenv("PATH");
    if (path == NULL)
        return (NULL);

    path_copy = malloc(strlen(path) + 1);
    if (path_copy == NULL)
        return (NULL);
    strcpy(path_copy, path);

    dir = strtok(path_copy, ":");
    while (dir != NULL)
    {
        snprintf(full_path, sizeof(full_path), "%s/%s", dir, command);
        if (stat(full_path, &st) == 0 && (st.st_mode & S_IXUSR))
        {
            free(path_copy);
            char *full_path_copy = malloc(strlen(full_path) + 1);
            if (full_path_copy == NULL)
                return (NULL);
            strcpy(full_path_copy, full_path);
            return (full_path_copy);
        }
        dir = strtok(NULL, ":");
    }

    free(path_copy);
    return (NULL);
}
