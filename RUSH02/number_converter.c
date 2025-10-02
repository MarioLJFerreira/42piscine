/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_converter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by student           #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static char	*get_scale_basic(int position)
{
	static char	*scales[] = {"", "1000", "1000000", "1000000000",
		"1000000000000", "1000000000000000", "1000000000000000000",
		"1000000000000000000000", NULL};

	if (position < 0 || position >= 8)
		return (NULL);
	return (scales[position]);
}

static void	process_group(char **lines, char *group, int pos, int *first)
{
	char	*scale_word;
	char	*scale_name;

	if (!group || is_all_zeros(group))
		return ;
	if (!*first)
		ft_putstr(" ");
	convert_hundreds_str(lines, group);
	if (pos > 0)
	{
		scale_name = get_scale_basic(pos);
		if (scale_name)
		{
			scale_word = find_word_for_number(lines, scale_name);
			if (scale_word)
			{
				ft_putstr(" ");
				ft_putstr(scale_word);
				free(scale_word);
			}
		}
	}
	*first = 0;
}

static void	handle_groups(char **lines, char *number, int len)
{
	char	*group;
	int		group_pos;
	int		start_pos;
	int		first_output;

	first_output = 1;
	group_pos = (len - 1) / 3;
	while (group_pos >= 0)
	{
		start_pos = len - (group_pos + 1) * 3;
		if (start_pos < 0)
			start_pos = 0;
		group = ft_substr(number, start_pos,
				len - start_pos - group_pos * 3);
		process_group(lines, group, group_pos, &first_output);
		if (group)
			free(group);
		group_pos--;
	}
}

void	convert_number_to_words(char **lines, char *number)
{
	char	*exact_match;

	exact_match = find_word_for_number(lines, number);
	if (exact_match)
	{
		ft_putstr(exact_match);
		free(exact_match);
		return ;
	}
	if (is_all_zeros(number))
	{
		exact_match = find_word_for_number(lines, "0");
		if (exact_match)
		{
			ft_putstr(exact_match);
			free(exact_match);
		}
		return ;
	}
	handle_groups(lines, number, ft_strlen(number));
}
