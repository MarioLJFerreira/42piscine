/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mju-ferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:41:08 by mju-ferr          #+#    #+#             */
/*   Updated: 2025/09/17 19:39:31 by mju-ferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	diff;
	unsigned int	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] && i < n)
		i++;
	
	diff = s1[i] - s2[i];
	return (diff);
}

/*int	main(void)
{
	char *test1 = "Test";
	char *test2 = "TesT";
	printf("%d", ft_strncmp(test1, test2, 3));
	return (0);
}*/
