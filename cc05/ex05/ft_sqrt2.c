/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mju-ferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 21:33:11 by mju-ferr          #+#    #+#             */
/*   Updated: 2025/09/22 22:03:41 by mju-ferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

double	ft_sqrt_precision(int nb, double inc)
{
	int	incr = inc*10;
	while (inc < incr)
		inc++;
	if (inc * inc > nb)
		return (inc);
	printf("%lf\n", inc);
	return (ft_sqrt_precision(nb, inc*10)+inc);
}

int     main(void)
{
	double nb;
	double inc;
	printf("Enter your number: ");
	scanf("%lf", &nb);
	printf("Enter your decimals: ");
	scanf("%lf", &inc);
	printf("%lf\n", ft_sqrt_precision(nb, inc));
	return (0);
}

