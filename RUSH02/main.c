#include "rush02.h"

void ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

void parse_and_display_dict(t_file rush02, int n)
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

	entry = parse_dict_line(lines[n]);
	printf("%s", entry->word);
    //while (lines[i])
    //{
    //    entry = parse_dict_line(lines[i]);
	//	ft_putstr(entry->word);
	//	ft_putstr("\n");
    //    //if (entry)
    //    //{
    //    //    write(1, "Number: ", 8);
    //    //    ft_putstr(entry->number);
    //    //    write(1, " -> Word: ", 10);
    //    //    ft_putstr(entry->word);
    //    //    write(1, "\n", 1);
    //    //    free(entry->number);
    //    //    free(entry->word);
    //    //    free(entry);
    //    //}
    //    free(lines[i]);
    //    i++;
    //}
    free(lines);
}

int main(int ac, char **av)
{
    t_file rush02;    
	(void) ac;
    rush02.file_name = "numbers.dict";
    rush02.fd = open(rush02.file_name, O_RDONLY);
    if (rush02.fd == -1)
    {
        write(1, "Error\n", 6);
        return (1);
    }
    if(ft_atoi(av[1]) <= 20)
    	parse_and_display_dict(rush02, ft_atoi(av[1]));
    close(rush02.fd);
    return (0);
}