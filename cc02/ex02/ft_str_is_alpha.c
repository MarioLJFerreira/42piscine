/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mju-ferr <mju-ferr@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:26:21 by mju-ferr          #+#    #+#             */
/*   Updated: 2025/09/17 07:27:31 by mju-ferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] > 'Z' && str[i] < 'a')
			return (0);
		else if (str[i] < 'A' || str[i] > 'z')
			return (0);
		i++;
	}
	return (1);
}

/*int	main(void)
{
	printf("Lisboa = %d\n", ft_str_is_alpha("Lisboa"));
	printf("42Lisboa = %d\n", ft_str_is_alpha("42Lisboa"));
	return (0);
}*/
