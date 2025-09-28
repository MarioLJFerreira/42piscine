/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mju-ferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 19:17:52 by mju-ferr          #+#    #+#             */
/*   Updated: 2025/09/22 20:28:18 by mju-ferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_fibonacci(int index)
{
	if (index == 0 || index == 1)
		return (index);
	if (index < 0)
		return (-1);
	return (ft_fibonacci(index-2) + ft_fibonacci(index-1));
}

/*int	main(void)
{
	printf("%d", ft_fibonacci(9));
	return (0);
}*/
