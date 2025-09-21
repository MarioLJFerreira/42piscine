/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mju-ferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 23:59:16 by mju-ferr          #+#    #+#             */
/*   Updated: 2025/09/21 00:21:19 by mju-ferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *str)
{
	int i = 0;
	int res = 0;
	int sign = 1;

	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		sign *= -1;
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
		printf("%d\n", ft_atoi(av[1]));
	else
		printf("Invalid Arguments\n");	
	return (0);
}
