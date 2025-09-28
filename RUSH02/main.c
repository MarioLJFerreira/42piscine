/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by student           #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

char	**load_dictionary(t_file rush02)
{
	char	*content;
	char	**lines;

	content = malloc(10000 * sizeof(char));
	if (!content)
		return (NULL);
	read(rush02.fd, content, 10000);
	lines = ft_split(content, "\n");
	free(content);
	return (lines);
}

int	main(int ac, char **av)
{
	char	*dict_file;
	char	*number;
	char	**lines;

	if (check_args(ac, av, &dict_file, &number))
		return (1);
	if (process_dict(dict_file, &lines))
		return (1);
	convert_number_to_words(lines, number);
	free_lines(lines);
	return (0);
}
