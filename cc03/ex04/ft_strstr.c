/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mju-ferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 20:08:47 by mju-ferr          #+#    #+#             */
/*   Updated: 2025/09/17 20:52:07 by mju-ferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	if (to_find[0] == '\0')
		return (str);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i+j] && str[i + j] == to_find[j])
		{
			if (str[i+j])
				return (&str[i]);
		}
		i++;
	}
	return (0);
}

/*int	main(void)
{
	char *str = "Testee";
	char *toFind = "st";
	printf("%s", ft_strstr(str, toFind));
	return (0);
}*/
