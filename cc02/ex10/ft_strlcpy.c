/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mju-ferr <mju-ferr@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 22:27:18 by mju-ferr          #+#    #+#             */
/*   Updated: 2025/09/20 20:20:27 by mju-ferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}

int	main(void)
{
	char	test_src[] = "This is a test.";
	char	test_dest[16];
	int	num = 3;

	printf("The src '%s'\n", test_src);
	printf("Returned Len of '%d'\n", ft_strlcpy(test_dest, test_src, num));
	printf("Dest value is now '%s'\n", test_dest);
}
