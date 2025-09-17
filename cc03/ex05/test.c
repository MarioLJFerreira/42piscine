#include <stdio.h>

void	ft_test(char *str)
{
	char a = str[3];
	printf("%c", a);
}

int	main(void)
{
	char *test = "Hello World!";
	ft_test(test);
	return (0);
}

