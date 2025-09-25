/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mju-ferr <mju-ferr@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:51:00 by mju-ferr          #+#    #+#             */
/*   Updated: 2025/09/25 13:18:58 by mju-ferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if(str)
	{
		while (str[i])
			i++;
	}
return (i);
}

void	ft_joinstr(char *sep, int *i, char *cat_str, char **strs)
{
	i[1] = 0;
	while (i[1] < ft_strlen(strs[i[0]]))
	{
		cat_str[i[2]] = strs[i[0]][i[1]];
		i[1]++;
		i[2]++;
	}
	i[4] = 0;
	if (i[0] < i[5])
	{
		while (i[4] < ft_strlen(sep))
		{
			cat_str[i[2]] = sep[i[4]];
			i[4]++;
			i[2]++;
		}

	}
	i[0]++;
}

/*
i[0] = Index of Array Of char arrays
i[1] = Index of Each Array of char]
i[2] = Index for counter of cat_str
i[3] = alloc_sz
i[4] = sep index
i[5] = size - 1
*/

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*cat_str;
	int	str_arr_i;
	int	i[6];

	i[3] = 0;
	str_arr_i = 0;
	while (str_arr_i < size)// allocation size
		i[3] += ft_strlen(strs[str_arr_i++]);
	i[3] += ft_strlen(sep) * size;// size for null terminated string
	cat_str = malloc(sizeof(char) * i[3]);
	i[0] = 0;
	i[2] = 0;//i[0] = str_mrg_i, i[1] = char_iterate, i[2] = cnt
	i[5] = size - 1;
	while (i[0] < size)
		ft_joinstr(sep, i, cat_str, strs);
	cat_str[i[2]] = '\0';
	return (cat_str);
}

#include <stdio.h>
int	main(void)
{
	char *strs[] = {"Banana", "Pedro", "Mario"};
	char *sep = ", ";
	printf("%s",ft_strjoin(0, strs, sep));
	return (0);
}

