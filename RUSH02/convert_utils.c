/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by student           #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	convert_units_str(char **lines, char *str)
{
	char	*word;

	if (!str || str[0] == '0')
		return ;
	word = find_word_for_number(lines, str);
	if (word)
	{
		ft_putstr(word);
		free(word);
	}
}

void	convert_tens_str(char **lines, char *str)
{
	int	val;

	if (!str)
		return ;
	val = string_to_int(str);
	if (val == 0)
		return ;
	if (val < 20)
	{
		convert_units_str(lines, str);
		return ;
	}
	handle_tens_and_units(lines, str);
}

static void	handle_hundreds(char **lines, char *str, int len)
{
	char	units_str[2];
	char	*word;

	units_str[0] = str[0];
	units_str[1] = '\0';
	convert_units_str(lines, units_str);
	ft_putstr(" ");
	word = find_word_for_number(lines, "100");
	if (word)
	{
		ft_putstr(word);
		free(word);
	}
	if (len > 1 && (str[1] != '0' || str[2] != '0'))
		ft_putstr(" ");
}

static void	handle_lower_digits(char **lines, char *str, int len)
{
	char	tens_str[3];

	if (len >= 2)
	{
		tens_str[0] = str[len - 2];
		tens_str[1] = str[len - 1];
		tens_str[2] = '\0';
		convert_tens_str(lines, tens_str);
	}
	else if (len == 1)
	{
		convert_units_str(lines, str);
	}
}

void	convert_hundreds_str(char **lines, char *str)
{
	int	len;

	if (!str)
		return ;
	len = ft_strlen(str);
	if (len >= 3 && str[0] != '0')
		handle_hundreds(lines, str, len);
	handle_lower_digits(lines, str, len);
}
