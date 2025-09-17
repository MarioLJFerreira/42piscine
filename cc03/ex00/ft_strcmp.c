/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mju-ferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:41:08 by mju-ferr          #+#    #+#             */
/*   Updated: 2025/09/17 19:02:00 by mju-ferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	diff;
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	diff = s1[i] - s2[i];
	return (diff);
}

/*int	main(void)
{
	char *test1 = "T";
	char *test2 = "TesT";
	printf("%d", ft_strcmp(test1, test2));
	return (0);
}*/
