/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mju-ferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 03:26:10 by mju-ferr          #+#    #+#             */
/*   Updated: 2025/09/16 06:25:42 by mju-ferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char	*original_dest;
	int	i;

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
	char new[] = "Unchanged New";
	unsigned int num = 9;
	
	ft_strncpy(new, original, num);
	printf("%s\n", new);
	return (0);
}*/
