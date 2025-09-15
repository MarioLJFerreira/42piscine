/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mju-ferr <mju-ferr@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 02:04:59 by mju-ferr          #+#    #+#             */
/*   Updated: 2025/09/15 09:07:18 by mju-ferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	swapped;

	i = 0;
	while (i < size)
	{
		swapped = 0;
		j = 0;
		while (j < size - 1 - i)
		{
			if (tab[j] > tab[j + 1])
			{
				ft_swap(&tab[j], &tab[j + 1]);
				swapped = 1;
			}
			j++;
		}
		if (!swapped)
			break ;
		i++;
	}
}
/*
int	main (void)
{
	int	tab[10] = {4, 2, 3, 5, 1, 0, 8, 4, 6, 7};
	int	size;

	size = 10;
	
	printf("Before sorting: ");
	
	int	i;

	i = 0;
	while (i < size)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
	
	ft_sort_int_tab(tab, size);
	
	printf("After sorting:  ");
	int	j;

	j = 0;
	while (j < size)
	{
		printf("%d ", tab[j]);
		j++;
	}
	printf("\n");
	return (0);
}*/
