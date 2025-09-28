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

typedef struct s_dict_entry
{
    char *number;
    char *word;
} t_dict_entry;

char **ft_split(char *str, char *charset);
t_dict_entry *parse_dict_line(char *line);
int ft_atoi(char *str);

#endif