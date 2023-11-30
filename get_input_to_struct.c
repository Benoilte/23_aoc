/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input_to_struct.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 23:35:55 by bebrandt          #+#    #+#             */
/*   Updated: 2023/11/28 21:55:18 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "days.h"

static int	*get_int_ptr(int value);

/*
parse txt file and return a linked list of struct with a int as member.
text file should have 1 number on each line
*/
t_list	*from_txt_to_struct_of_int(int fd)
{
	int		is_line;
	int		check_new_line;
	char	*line;
	char	*str;
	t_list	*input;

	input = NULL;
	is_line = 1;
	while (is_line)
	{
		line = get_next_line(fd);
		if (line)
		{
			check_new_line = 0;
			if (ft_strchr(line, '\n'))
				check_new_line = 1;
			str = ft_substr(line, 0, ft_strlen(line) - check_new_line);
			ft_lstadd_back(&input, ft_lstnew(get_int_ptr(ft_atoi(str))));
			free(str);
		}
		else
			is_line = 0;
		free(line);
	}
	return (input);
}

/*
parse txt file and return a linked list of struct with a int as member.
text file should have 1 number on each line
*/
t_list	*from_txt_to_struct_of_str(int fd)
{
	int		is_line;
	int		check_new_line;
	char	*line;
	char	*str;
	t_list	*input;

	input = NULL;
	is_line = 1;
	while (is_line)
	{
		line = get_next_line(fd);
		if (line)
		{
			check_new_line = 0;
			if (ft_strchr(line, '\n'))
				check_new_line = 1;
			str = ft_substr(line, 0, ft_strlen(line) - check_new_line);
			ft_lstadd_back(&input, ft_lstnew(str));
		}
		else
			is_line = 0;
		free(line);
	}
	return (input);
}

/*
return a pointer of int and assign its value withh the parameter
*/
int	*get_int_ptr(int value)
{
	int	*ptr;

	ptr = ft_calloc(1, sizeof(int *));
	*ptr = value;
	return (ptr);
}
