/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mju-ferr <mju-ferr@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 21:00:14 by mju-ferr          #+#    #+#             */
/*   Updated: 2025/09/17 07:27:06 by mju-ferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= 32 && str[i] <= 126))
			return (0);
		i++;
	}
	return (1);
}

/* int	main(void)
{
	printf("!';42/Sq±\\n = %d\n", ft_str_is_printable("!';42/Sq±"));
	printf("42 School! = %d\n", ft_str_is_printable("42 School!"));
	return (0);
}
 */