/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day-03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:04:14 by bebrandt          #+#    #+#             */
/*   Updated: 2023/12/03 22:04:54 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "days.h"

static int		count_part_number(char **input);
static int		*check_side(char **in, int y, int x, int (*f)(char));
static int		*check_diagonal(char **in, int y, int x, int (*f)(char));
static int		count_gear(char **input);
// static void		add_coord(t_list **coord, int x, int y);

void	day_03(void)
{
	char	**input;
	int		size;
	int		fd;
	char	*file;

	file = "input/day-03.txt";
	fd = open(file, O_RDONLY);
	size = count_line(fd);
	close(fd);
	fd = open(file, O_RDONLY);
	input = from_txt_to_array_of_str(fd, size);
	// display_str_array(input);
	ft_printf("part number sum: %d\n", count_part_number(input));
	ft_printf("gear sum       : %d\n", count_gear(input));
	close(fd);
}

static int	count_part_number(char **input)
{
	int		i_f_n;
	int 	part_number;
	int		i;
	int 	j;

	i_f_n = -1;
	part_number = 0;
	i = 0;
	while (input[i])
	{
		j = 0;
		while (input[i][j])
		{
			if (ft_isdigit(input[i][j]) && (i_f_n < 0))
				i_f_n = j;
			else if (ft_isalnum(input[i][j]) == 0)
				i_f_n = -1;
			if (ft_isdigit(input[i][j]) && check_side(input, i, j, &is_sym))
			{
				part_number += ft_get_digit(input[i] + i_f_n, &i_f_n);
				j = i_f_n - 1;
				i_f_n = -1;
			}
			j++;
		}
		i++;
	}
	return (part_number);
}

static int	count_gear(char **input)
{
	int		i_f_n;
	int 	p_num;
	int		i;
	int 	j;
	int		*xy;
	t_ord	*lst_ord;

	i_f_n = -1;
	p_num = 0;
	i = 0;
	lst_ord = NULL;
	while (input[i])
	{
		j = 0;
		while (input[i][j])
		{
			if (ft_isdigit(input[i][j]) && (i_f_n < 0))
				i_f_n = j;
			else if (ft_isalnum(input[i][j]) == 0)
				i_f_n = -1;
			if (ft_isdigit(input[i][j]))
				xy = check_side(input, i, j, &is_star);
			if (ft_isdigit(input[i][j]) && xy)
			{
				p_num = ft_get_digit(input[i] + i_f_n, &i_f_n);
				lstord_iter(&lst_ord, convert_xy_to_str(xy[0], xy[1]), p_num);
				j = i_f_n - 1;
				i_f_n = -1;
			}
			j++;
		}
		i++;
	}
	return (gear_ratio(lst_ord));
}

static int	*check_side(char **in, int y, int x, int (*f)(char))
{
	int	len;
	int	size;

	len = ft_strlen(in[0]);
	size = 0;
	while (in[size])
		size++;
	if (y && y < (size - 1))
	{
		if (f(in[y - 1][x]))
			return (set_xy(x, y - 1));
		if (f(in[y + 1][x]))
			return (set_xy(x, y + 1));
	}
	else if (y == (size - 1) && f(in[y - 1][x]))
		return (set_xy(x, y - 1));
	else if (y == 0 && f(in[y + 1][x]))
		return (set_xy(x, y + 1));
	if (x && x < (len - 1))
	{
		if (f(in[y][x - 1]))
			return (set_xy(x - 1, y));
		if (f(in[y][x + 1]))
			return (set_xy(x + 1, y));
	}
	else if (x == (len - 1) && f(in[y][x - 1]))
		return (set_xy(x - 1, y));
	else if (x == 0 && f(in[y][x + 1]))
		return (set_xy(x + 1, y));
	return (check_diagonal(in, y, x, f));
}

static int	*check_diagonal(char **in, int y, int x, int (*f)(char))
{
	int	len;
	int	size;

	len = ft_strlen(in[0]);
	size = 0;
	while (in[size])
		size++;
	if ((y && (y < (size - 1))) && (x && (x < (len - 1))))
	{
		if (f(in[y - 1][x - 1]))
			return (set_xy(x - 1, y - 1));
		if (f(in[y + 1][x + 1]))
			return (set_xy(x + 1, y + 1));
		if (f(in[y - 1][x + 1]))
			return (set_xy(x + 1, y - 1));
		if (f(in[y + 1][x - 1]))
			return (set_xy(x - 1, y + 1));
	}
	else if ((y == (size - 1)) && (x == (len - 1)) && f(in[y + 1][x - 1]))
		return (set_xy(x - 1, y + 1));
	else if ((y == (size - 1)) && (x == 0) && (f(in[y + 1][x + 1])))
		return (set_xy(x + 1, y + 1));
	else if ((y == (size - 1)) && (x && (x < (len - 1))))
	{
		if ((f(in[y - 1][x + 1])))
			return (set_xy(x + 1, y - 1));
		if ((f(in[y - 1][x - 1])))
			return (set_xy(x - 1, y - 1));
	}
	else if (((x == (len - 1)) && (y == 0)) && (f(in[y + 1][x - 1])))
		return (set_xy(x - 1, y + 1));
	else if (((y == 0) && (x == 0)) && (f(in[y + 1][x + 1])))
		return (set_xy(x + 1, y + 1));
	else if ((y == 0) && (x && (x < (len - 1))))
	{
		if (f(in[y + 1][x + 1]))
			return (set_xy(x + 1, y + 1));
		if (f(in[y + 1][x - 1]))
			return (set_xy(x - 1, y + 1));
	}
	return (NULL);
}
