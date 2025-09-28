/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by student           #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	handle_tens_and_units(char **lines, char *str)
{
	char	tens_str[3];
	char	units_str[2];
	char	*word;

	tens_str[0] = str[0];
	tens_str[1] = '0';
	tens_str[2] = '\0';
	word = find_word_for_number(lines, tens_str);
	if (word)
	{
		ft_putstr(word);
		free(word);
		if (str[1] != '0')
		{
			ft_putstr(" ");
			units_str[0] = str[1];
			units_str[1] = '\0';
			convert_units_str(lines, units_str);
		}
	}
}

void	free_split_parts(char **parts)
{
	int	i;

	if (parts)
	{
		i = 0;
		while (parts[i])
		{
			free(parts[i]);
			i++;
		}
		free(parts);
	}
}

char	*allocate_and_copy(char *str, int start, int len)
{
	char	*result;
	int		i;

	result = malloc(len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = str[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
