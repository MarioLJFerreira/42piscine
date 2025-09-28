/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mju-ferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 20:28:42 by mju-ferr          #+#    #+#             */
/*   Updated: 2025/09/22 21:29:25 by mju-ferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	while (i * i < nb)
		i++;
	if(i * i == nb)
		return (i);
	return (0);
}

int	main(void)
{
	int nb;

	printf("Enter your number: ");
	scanf("%d", &nb);
	printf("%d\n", ft_sqrt(nb));
	return (0);
}
