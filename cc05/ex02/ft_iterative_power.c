#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	int	res;

	res = nb;
	if (power < 0)
		return (0);
	if (nb  == 0 && power == 0)
		return (1);
	while (power - 1 > 0)
	{
		res = res * nb;
		power--;
	}
	return (res);
}

int	main(void)
{
	printf("%d", ft_recursive_power(2, 2));
	return (0) ;
}