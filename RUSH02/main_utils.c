/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by student           #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	check_args(int ac, char **av, char **dict_file, char **number)
{
	if (ac < 2 || ac > 3)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (ac == 2)
	{
		*dict_file = "numbers.dict";
		*number = av[1];
	}
	else
	{
		*dict_file = av[1];
		*number = av[2];
	}
	if (!is_valid_number(*number))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	process_dict(char *dict_file, char ***lines_ptr)
{
	t_file	rush02;
	char	**lines;

	rush02.file_name = dict_file;
	rush02.fd = open(rush02.file_name, O_RDONLY);
	if (rush02.fd == -1)
	{
		write(1, "Dict Error\n", 11);
		return (1);
	}
	lines = load_dictionary(rush02);
	close(rush02.fd);
	if (!lines)
	{
		write(1, "Dict Error\n", 11);
		return (1);
	}
	*lines_ptr = lines;
	return (0);
}

int	is_valid_number(char *str)
{
	int	i;

	if (!str || !str[0])
		return (0);
	if (str[0] == '0' && str[1] != '\0')
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	free_lines(char **lines)
{
	int	i;

	if (!lines)
		return ;
	i = 0;
	while (lines[i])
	{
		free(lines[i]);
		i++;
	}
	free(lines);
}
