/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day-10.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:06:33 by bebrandt          #+#    #+#             */
/*   Updated: 2023/12/11 01:22:26 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "days.h"

static int	count_inner_tile(char **input);
static int	get_farthest_tile(char **input);
static int	count_loop_step(char **input, int *start);
static int	*find_start(char **input);

void	day_10(void)
{
	char	**input;
	int		size;
	int			fd;
	// int			calibration;
	char		*file;

	file = "input/day-10.txt";
	fd = open(file, O_RDONLY);
	size = count_line(fd);
	close(fd);
	fd = open(file, O_RDONLY);
	input = from_txt_to_array_of_str(fd, size);
	display_str_array(input, "line");
	ft_printf("step : %d\n", get_farthest_tile(input));
	display_str_array(input, "line");
	ft_printf("inner : %d\n", count_inner_tile(input));
	// calibration = ft_get_calibration(input);
	close(fd);
	// ft_printf("calibration : %d\n", calibration);
}

static int	count_inner_tile(char **input)
{
	int y;
	int x;
	int inner;
	int	count;

	y = 0;
	count = 0;
	while (input[y])
	{
		x = 0;
		inner = 0;
		while (input[y][x])
		{
			if (input[y][x] == 'U' && inner == 0)
				inner = 1;
			else if (input[y][x] == 'D' && inner == 1)
				inner = 0;
			if (input[y][x] != 'U' && input[y][x] != 'D' && input[y][x] != '_' && inner == 1)
			{
				ft_printf("x: %d - y: %d\n", x, y);
				ft_printf("tile : %c\n", input[y][x]);
				count++;
			}
			x++;
		}
		y++;
	}
	return (count);
}

static int	get_farthest_tile(char **input)
{
	int	*start;
	int step;

	start = find_start(input);
	display_int_array(start, 2, "s");
	step = count_loop_step(input, start);
	if (step % 2)
		step++;
	return (step / 2);
}

/*
| is a vertical pipe connecting north and south.
- is a horizontal pipe connecting east and west.
L is a 90-degree bend connecting north and east.
J is a 90-degree bend connecting north and west.
7 is a 90-degree bend connecting south and west.
F is a 90-degree bend connecting south and east.
. is ground; there is no pipe in this tile.
S is the starting position of the animal; there is a pipe on this
*/
static int	count_loop_step(char **input, int *start)
{
	int	x;
	int	y;
	int	x_min;
	int	y_min;
	int	x_max;
	int	y_max;
	int	prev_x;
	int	prev_y;
	int step;

	x = start[0];
	y = start[1];
	input[y][x] = 'D';
	// start loop below the first position.
	y += 1;
	prev_x = start[0];
	prev_y = start[1];
	step = 0;
	x_max = x;
	y_max = y;
	x_min = x;
	y_min = y;
	while ((x != start[0]) || (y != start[1]))
	{
		// ft_printf("prev_x: %d - prev_y: %d\n", prev_x, prev_y);
		// ft_printf("x: %d - y: %d\n", x, y);
		// ft_printf("tile : %c\n", input[y][x]);
		step++;
		if (y < y_min)
			y_min = y;
		else if (y > y_max)
			y_max = y;
		if (x < x_min)
			x_min = x;
		else if (x > x_max)
			x_max = x;
		if (input[y][x] == '|')
		{
			if (prev_y < y)
			{
				input[y][x] = 'D';
				prev_y = y;
				y += 1;
			}
			else
			{
				input[y][x] = 'U';
				prev_y = y;
				y -= 1;
			}
		}
		else if (input[y][x] == '-')
		{
			input[y][x] = '_';
			if (prev_x < x)
			{
				prev_x = x;
				x += 1;
			}
			else
			{
				prev_x = x;
				x -= 1;
			}
		}
		else if (input[y][x] == 'L')
		{
			if (prev_y < y)
			{
				input[y][x] = 'D';
				prev_x = x;
				prev_y = y;
				x += 1;
			}
			else
			{
				input[y][x] = 'U';
				prev_x = x;
				prev_y = y;
				y -= 1;
			}
		}
		else if (input[y][x] == 'J')
		{
			if (prev_y < y)
			{
				input[y][x] = 'D';
				prev_x = x;
				prev_y = y;
				x -= 1;
			}
			else
			{
				input[y][x] = 'U';
				prev_x = x;
				prev_y = y;
				y -= 1;
			}
		}
		else if (input[y][x] == '7')
		{
			if (prev_y > y)
			{
				input[y][x] = 'U';
				prev_x = x;
				prev_y = y;
				x -= 1;
			}
			else
			{
				input[y][x] = 'D';
				prev_x = x;
				prev_y = y;
				y += 1;
			}
		}
		else if (input[y][x] == 'F')
		{
			if (prev_y > y)
			{
				input[y][x] = 'U';
				prev_x = x;
				prev_y = y;
				x += 1;
			}
			else
			{
				input[y][x] = 'D';
				prev_x = x;
				prev_y = y;
				y += 1;
			}
		}
	}
	ft_printf("x_max: %d | y_max: %d | x_min: %d | y_min: %d\n", x_max, y_max, x_min, y_min);
	return (step);
}

// static int *find_next_tile(char **input, )

static int	*find_start(char **input)
{
	int	*xy;
	int	*x;
	int	*y;

	xy = ft_calloc(2, sizeof(int));
	x = xy;
	y = xy + 1;
	while (input[*y])
	{
		// display_int_array(xy, 2, "xy_in_while");
		// ft_printf("%s\n", input[*y]);
		if (ft_strchr(input[*y], 'S'))
		{
			while (input[*y][*x] != 'S')
				*x += 1;
			break ;
		}
		*y += 1;
	}
	return (xy);
}
