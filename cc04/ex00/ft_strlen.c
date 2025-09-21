/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mju-ferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 00:35:35 by mju-ferr          #+#    #+#             */
/*   Updated: 2025/09/18 04:13:09 by mju-ferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_strlen (char *str)
{
	int	i;
	
	i = 0;
	if (str)
	{
		while (str[i])
			i++;
	}
	return (i);
}

/*int	main(void)
{
	char *test = "test";
	printf("%d", ft_strlen (test));
}*/
