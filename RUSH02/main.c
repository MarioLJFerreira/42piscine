#include "rush02.h"

void parse_and_display_dict(t_file rush02)
{
    char *content;
    char **lines;
    t_dict_entry *entry;
    int i;

    content = malloc(10000 * sizeof(char));
    if (!content)
        return;
    
    read(rush02.fd, content, 10000);
    lines = ft_split(content, "\n");
    free(content);
    
    if (!lines)
        return;
    
    i = 0;
    while (lines[i])
    {
        entry = parse_dict_line(lines[i]);
        if (entry)
        {
            printf("Number: %s -> Word: %s\n", entry->number, entry->word);
            free(entry->number);
            free(entry->word);
            free(entry);
        }
        free(lines[i]);
        i++;
    }
    free(lines);
}

int main(int ac, char **av)
{
    t_file rush02;
    (void)ac;
    (void)av;
    
    rush02.file_name = "numbers.dict";
    rush02.fd = open(rush02.file_name, O_RDONLY);
    if (rush02.fd == -1)
    {
        write(1, "Error\n", 6);
        return (1);
    }
    
    parse_and_display_dict(rush02);
    close(rush02.fd);
    return (0);
}