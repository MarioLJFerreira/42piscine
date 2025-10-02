/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by student           #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	free_parts_from(char **parts, int start)
{
	int	i;

	if (!parts)
		return ;
	i = start;
	while (parts[i])
	{
		free(parts[i]);
		i++;
	}
}

char	*ft_trim(char *str)
{
	int	start;
	int	end;
	int	len;

	if (!str)
		return (NULL);
	start = 0;
	while (str[start] == ' ' || str[start] == '\t')
		start++;
	end = ft_strlen(str) - 1;
	while (end >= start && (str[end] == ' ' || str[end] == '\t'))
		end--;
	len = end - start + 1;
	return (allocate_and_copy(str, start, len));
}

static char	**split_and_validate(char *line)
{
	char	**parts;

	if (!line)
		return (NULL);
	parts = ft_split(line, ":");
	if (!parts || !parts[0] || !parts[1])
	{
		free_split_parts(parts);
		return (NULL);
	}
	return (parts);
}

t_dict_entry	*parse_dict_line(char *line)
{
	char			**parts;
	t_dict_entry	*entry;

	parts = split_and_validate(line);
	if (!parts)
		return (NULL);
	entry = malloc(sizeof(t_dict_entry));
	if (!entry)
	{
		free_parts_from(parts, 0);
		free(parts);
		return (NULL);
	}
	entry->number = ft_trim(parts[0]);
	entry->word = ft_trim(parts[1]);
	free_parts_from(parts, 0);
	free(parts);
	return (entry);
}

char	*find_word_for_number(char **lines, char *number)
{
	t_dict_entry	*entry;
	int				i;
	char			*result;

	i = 0;
	while (lines[i])
	{
		entry = parse_dict_line(lines[i]);
		if (entry && ft_strcmp(entry->number, number) == 0)
		{
			result = entry->word;
			free(entry->number);
			free(entry);
			return (result);
		}
		if (entry)
		{
			free(entry->number);
			free(entry->word);
			free(entry);
		}
		i++;
	}
	return (NULL);
}
