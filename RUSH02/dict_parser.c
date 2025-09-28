#include "rush02.h"

t_dict_entry *parse_dict_line(char *line)
{
    char **parts;
    t_dict_entry *entry;
    int i;

    if (!line)
        return (NULL);
    
    parts = ft_split(line, ": ");
    if (!parts || !parts[0] || !parts[1])
    {
        if (parts)
        {
            i = 0;
            while (parts[i])
            {
                free(parts[i]);
                i++;
            }
            free(parts);
        }
        return (NULL);
    }
    
    entry = malloc(sizeof(t_dict_entry));
    if (!entry)
    {
        i = 0;
        while (parts[i])
        {
            free(parts[i]);
            i++;
        }
        free(parts);
        return (NULL);
    }
    
    entry->number = parts[0];
    entry->word = parts[1];
    
    if (parts[2])
    {
        i = 2;
        while (parts[i])
        {
            free(parts[i]);
            i++;
        }
    }
    free(parts);
    
    return (entry);
}