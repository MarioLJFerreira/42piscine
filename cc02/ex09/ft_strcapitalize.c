/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mju-ferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 21:51:44 by mju-ferr          #+#    #+#             */
/*   Updated: 2025/09/16 22:24:19 by mju-ferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	cap_next;

	cap_next = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if(cap_next)
				str[i] = str[i] - 32;
		}

		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			if(!(cap_next))
				str[i] = str[i] + 32;
		}

		if ((str[i] >= '0' && str[i] <= '9')
			 || (str[i] >= 'A' && str[i] <= 'Z')
			 || (str[i] >= 'a' && str[i] <= 'z'))
			cap_next = 0;
		else
			cap_next = 1;
		i++;
	}
	return (str);
}

/*int	main(void)
{
	char strTest[] = "hi, how are you? 42words forty-two; fifty+and+one";

	printf("%s\n", strTest);
	printf("%s\n", ft_strcapitalize(strTest));
	return (0);
}*/
