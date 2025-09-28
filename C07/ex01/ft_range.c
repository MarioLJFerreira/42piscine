/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mju-ferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 03:19:17 by mju-ferr          #+#    #+#             */
/*   Updated: 2025/09/23 04:39:48 by mju-ferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;

	if (min >= max)
		return (NULL);
	arr = malloc((max - min) * 4);
	if (!arr)
		return (NULL);
	i = 0;
	while (min < max)
	{
		arr[i] = min;
		i++;
		min++;
	}
	return (arr);
}
/*
#include <stdio.h>
int	main(void)
{
	int	min;
	int	max;
	int	i;

	printf("Enter minimum value of array: ");
	scanf("%d", &min);
	printf("Enter maximum value of array: ");
	scanf("%d", &max);
	i = 0;
	printf("{");
	while (i < max - min)
	{
		printf("%d", ft_range(min, max)[i]);
		if (i < max - min - 1)
			printf(", ");
		i++;
	}
	printf("}\n");
	return (0);
}*/
