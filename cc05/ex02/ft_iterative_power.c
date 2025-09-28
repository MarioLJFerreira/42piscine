/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mju-ferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 19:13:54 by mju-ferr          #+#    #+#             */
/*   Updated: 2025/09/22 19:14:05 by mju-ferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_iterative_power(int nb, int power)
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

/*int	main(void)
{
	printf("%d", ft_iterative_power(2, 2));
	return (0) ;
}*/
