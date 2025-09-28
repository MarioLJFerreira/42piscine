#ifndef RUSH02_H
#define RUSH02_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s_file
{
    char *file_name;
    int fd;
    char *str;
} t_file;

#endif