#include "rush02.h"

/*
void ft_putchar(char c)
{
    write(1, &c, 1);
}
*/



int ft_linecount(t_file rush02)
{
    int i;
    int count;

	rush02.str = malloc(10000 * sizeof(char));
	read(rush02.fd, rush02.str, 10000);
	count = 0;
	i = 0;
    while (rush02.str[i])
    {
        if (rush02.str[i] == '\n')
            count++;
        i++;
    }
	free(rush02.str);
    return (count);
}

int main(int ac, char **av)
{
    t_file rush02;
	(void)ac;
	(void)av;
	int linecount;
    rush02.file_name = "numbers.dict";
    rush02.fd = open(rush02.file_name, O_RDONLY);
	// if (rush02.fd == -1)
	// {
	// 	write(1, "Error\n", 6);
	// 	return (1);
	// }
	linecount = ft_linecount(rush02);
	printf("linecount: %d\n", linecount);
    close(rush02.fd);
    return (0);
}