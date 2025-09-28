/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mju-ferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 18:47:17 by mju-ferr          #+#    #+#             */
/*   Updated: 2025/09/22 18:56:40 by mju-ferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	fac;
	int	res;

	res = nb;
	fac = nb - 1;
	if (nb < 0)
		return (0);
	while (fac > 0)
	{
		res = res * fac;
		fac--;
	}
	return (res);
}

/*int	main(void) 
{
	printf("%d", ft_iterative_factorial(9));
	return (0) ;
}*/
