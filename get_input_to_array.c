/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input_to_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:04:33 by bebrandt          #+#    #+#             */
/*   Updated: 2023/11/28 21:50:35 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "days.h"

/*
parse txt file and return an arry of int.
text file should have 1 number on each line
*/
int	*from_txt_to_array_of_int(int fd, int size)
{
	int		is_line;
	char	*line;
	char	*str;
	int		*input;
	int		i;

	is_line = 1;
	input = ft_calloc(size, sizeof(int));
	i = 0;
	while (is_line)
	{
		line = get_next_line(fd);
		if (line)
		{
			str = ft_substr(line, 0, ft_strlen(line) - 1);
			input[i++] = ft_atoi(str);
			free(line);
			free(str);
		}
		else
			is_line = 0;
	}
	return (input);
}

/*
parse txt file and return an array of string.
text file should have 1 number on each line
*/
char	**from_txt_to_array_of_str(int fd, int size)
{
	int		is_line;
	int		check_new_line;
	char	*line;
	char	**input;
	int		i;

	is_line = 1;
	input = ft_calloc(size, sizeof(char *));
	i = 0;
	while (is_line)
	{
		line = get_next_line(fd);
		if (line)
		{
			check_new_line = 0;
			if (ft_strchr(line, '\n'))
				check_new_line = 1;
			input[i++] = ft_substr(line, 0, ft_strlen(line) - check_new_line);
			free(line);
		}
		else
			is_line = 0;
	}
	return (input);
}

/*
Go through a text file and count and return numbers line
*/
int	count_line(int fd)
{
	int		is_line;
	int		count;
	char	*line;

	is_line = 1;
	count = 0;
	while (is_line)
	{
		line = get_next_line(fd);
		if (line)
			count++;
		else
			is_line = 0;
		free(line);
	}
	return (count);
}
