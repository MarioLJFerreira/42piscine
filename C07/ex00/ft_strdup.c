/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mju-ferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 02:49:25 by mju-ferr          #+#    #+#             */
/*   Updated: 2025/09/23 15:15:04 by mju-ferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(ft_strlen(src)+1);
	return (ft_strcpy(dest, src));
}

/*
#include <stdio.h>
int	main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("Inserted string is: %s\n", av[1]);
		printf("Your duplicate string is: %s\n", ft_strdup(av[1]));
	}
	else
		printf("Invalid Argument: %s <src string>\n", av[0]);
	return (0);
}*/
