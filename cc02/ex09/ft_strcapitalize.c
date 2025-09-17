/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mju-ferr <mju-ferr@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 21:51:44 by mju-ferr          #+#    #+#             */
/*   Updated: 2025/09/17 18:32:03 by mju-ferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	case_change(char *str, int i, int *capbool)
{
	if (str[i] >= 'a' && str[i] <= 'z')
	{
		if (*capbool)
			str[i] = str[i] - 32;
	}
	if (str[i] >= 'A' && str[i] <= 'Z')
	{
		if (!(*capbool))
			str[i] = str[i] + 32;
	}
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	cap_next;

	cap_next = 1;
	i = 0;
	while (str[i])
	{
		case_change(str, i, &cap_next);
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

int	main(void)
{
	char strTest[] = "hi, how are you? 42words forty-two; fifty+and+one";

	printf("%s\n", strTest);
	printf("%s\n", ft_strcapitalize(strTest));
	return (0);
}
