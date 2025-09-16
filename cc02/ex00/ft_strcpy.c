/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mju-ferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 03:26:10 by mju-ferr          #+#    #+#             */
/*   Updated: 2025/09/16 04:14:50 by mju-ferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	while (*src)
	{
		*dest = *src;	
		dest++;
		src++;
	}

	*dest = *src;
	return (dest);
}

/*int	main(void)
{
	char original[] = "Old Original";
	char new[] = "Unchanged New";

	ft_strcpy(new, original);
	printf("%s\n", new);
	return (0);
}*/
