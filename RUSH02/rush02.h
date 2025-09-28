/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by student           #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_file
{
	char	*file_name;
	int		fd;
	char	*str;
}	t_file;

typedef struct s_dict_entry
{
	char	*number;
	char	*word;
}	t_dict_entry;

char			**ft_split(char *str, char *charset);
t_dict_entry	*parse_dict_line(char *line);
int				ft_atoi(char *str);
int				ft_strcmp(char *s1, char *s2);
char			*find_word_for_number(char **lines, char *number);
void			ft_putstr(char *str);
void			convert_number_to_words(char **lines, char *number);
void			convert_number_to_words_mega(char **lines, char *number);
void			convert_hundreds_str(char **lines, char *str);
void			convert_tens_str(char **lines, char *str);
void			convert_units_str(char **lines, char *str);
void			handle_tens_and_units(char **lines, char *str);
void			free_split_parts(char **parts);
int				ft_strlen(char *str);
char			*ft_substr(char *str, int start, int len);
int				string_to_int(char *str);
int				is_all_zeros(char *str);
char			*get_scale_name(int position);
char			*allocate_and_copy(char *str, int start, int len);
char			**load_dictionary(t_file rush02);
void			free_lines(char **lines);
int				is_valid_number(char *str);
int				check_args(int ac, char **av, char **dict, char **number);
int				process_dict(char *dict_file, char ***lines_ptr);

#endif