/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mju-ferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 17:28:49 by mju-ferr          #+#    #+#             */
/*   Updated: 2025/09/21 00:21:42 by mju-ferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}
/*
int	ft_atoi(char *str)
{
	int i = 0;
	int res = 0;
	int sign = 1;

	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * sign);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		ft_putnbr(ft_atoi(av[1]));
	else
		write(1, "Invalid Arguments", 17);
	return (0);
}*/
