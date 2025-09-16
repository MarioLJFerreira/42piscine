/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mju-ferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 20:43:59 by mju-ferr          #+#    #+#             */
/*   Updated: 2025/09/16 20:49:16 by mju-ferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int		i;
	char	*original_dest;

	original_dest = dest;
	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (original_dest);
}

/*int	main(void)
{
	char original[] = "Old Original";
	char new[6];
	unsigned int num = 5;
	
	printf("%s\n", ft_strncpy(new, original, num));
	return (0);
}*/
