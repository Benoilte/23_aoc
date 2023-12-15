/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day-14.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:08:00 by bebrandt          #+#    #+#             */
/*   Updated: 2023/12/15 02:15:46 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "days.h"

void	get_rounded_rocks(t_list **rounded_rocks, t_list *input);
void	get_cube_rocks(t_list **cube_rocks, t_list *input);
void	sliding_rocks(t_list **o_rocks, t_list *cube_rocks);
void	move_rocks_north(int *xy, t_list *o_rocks, t_list *cube_rocks);
void	move_rocks_west(int *xy, t_list *o_rocks, t_list *cube_rocks);
void	move_rocks_south(int *xy, t_list *o_rocks, t_list *cube_rocks);
void	move_rocks_east(int *xy, t_list *o_rocks, t_list *cube_rocks);
int		is_pos_empty(int x, int y, t_list *o_rocks, t_list *cube_rocks);
int		sum_load(t_list *o_rocks, int size);

void	day_14(void)
{
	t_list	*input;
	t_list	*rounded_rocks;
	t_list	*cube_rocks;
	int		fd;
	char	*file;
	int		load;

	file = "input/day-14.txt";
	fd = open(file, O_RDONLY);
	input = from_txt_to_struct_of_str(fd);
	close(fd);
	display_struct(input, 's', "springs");
	rounded_rocks = NULL;
	get_rounded_rocks(&rounded_rocks, input);
	display_struct(rounded_rocks, 'i', "rounded");
	cube_rocks = NULL;
	get_cube_rocks(&cube_rocks, input);
	ft_printf("\nsliding_rocks\n\n");
	// display_struct(cube_rocks, 'i', "cubed-Shaped");
	sliding_rocks(&rounded_rocks, cube_rocks);
	ft_printf("test 01\n");
	display_struct(rounded_rocks, 'i', "rounded");
	load = sum_load(rounded_rocks, ft_lstsize(input));
	ft_printf("load on the north support beams: %d\n", load);
}

int	sum_load(t_list *o_rocks, int size)
{
	t_list	*tmp_o;
	int		load;

	tmp_o = o_rocks;
	ft_printf("size: %d\n", size);
	load = 0;
	while (tmp_o)
	{
		load += (size - ((int *)(tmp_o->content))[1]);
		tmp_o = tmp_o->next;
	}
	return (load);
}

void	sliding_rocks(t_list **o_rocks, t_list *cube_rocks)
{
	t_list	*tmp_o;

	tmp_o = *o_rocks;
	while (tmp_o)
	{
		ft_printf("test 01\n");
		move_rocks_north(tmp_o->content, *o_rocks, cube_rocks);
		tmp_o = tmp_o->next;
	}
	tmp_o = *o_rocks;
	while (tmp_o)
	{
		ft_printf("test 02\n");
		move_rocks_west(tmp_o->content, *o_rocks, cube_rocks);
		tmp_o = tmp_o->next;
	}
	tmp_o = *o_rocks;
	while (tmp_o)
	{
		ft_printf("test 03\n");
		move_rocks_south(tmp_o->content, *o_rocks, cube_rocks);
		tmp_o = tmp_o->next;
	}
	tmp_o = *o_rocks;
	while (tmp_o)
	{
		ft_printf("test 04\n");
		move_rocks_east(tmp_o->content, *o_rocks, cube_rocks);
		tmp_o = tmp_o->next;
	}
}

void	move_rocks_north(int *xy, t_list *o_rocks, t_list *cube_rocks)
{
	if (xy[1] > 0)
	{
		while (xy[1] > 0 && (is_pos_empty(xy[0], xy[1] - 1, o_rocks, cube_rocks)))
			xy[1] -= 1;
	}
}

void	move_rocks_west(int *xy, t_list *o_rocks, t_list *cube_rocks)
{
	if (xy[0] > 0)
	{
		while (xy[0] > 0 && (is_pos_empty(xy[0] - 1, xy[1], o_rocks, cube_rocks)))
			xy[0] -= 1;
	}
}

void	move_rocks_south(int *xy, t_list *o_rocks, t_list *cube_rocks)
{
	if (xy[1] < 9)
	{
		while (xy[1] < 9 && (is_pos_empty(xy[0], xy[1] + 1, o_rocks, cube_rocks)))
			xy[1] += 1;
	}
}

void	move_rocks_east(int *xy, t_list *o_rocks, t_list *cube_rocks)
{
	if (xy[0] < 9)
	{
		while (xy[0] < 9 && (is_pos_empty(xy[0] + 1, xy[1], o_rocks, cube_rocks)))
			xy[0] += 1;
	}
}

int	is_pos_empty(int x, int y, t_list *o_rocks, t_list *cube_rocks)
{
	t_list	*tmp_o;
	t_list	*tmp_cube;

	tmp_o = o_rocks;
	while (tmp_o)
	{
		if (((int *)(tmp_o->content))[0] == x && ((int *)(tmp_o->content))[1] == y)
			return (0);
		tmp_o = tmp_o->next;
	}
	tmp_cube = cube_rocks;
	while (tmp_cube)
	{
		if (((int *)(tmp_cube->content))[0] == x && ((int *)(tmp_cube->content))[1] == y)
			return (0);
		tmp_cube = tmp_cube->next;
	}
	return (1);
}


void	get_rounded_rocks(t_list **rounded_rocks, t_list *input)
{
	t_list	*tmp;
	int		*xy;
	int		x;
	int		y;

	tmp = input;
	y = 0;
	while (tmp)
	{
		x = 0;
		while (((char *)(tmp->content))[x])
		{
			if (((char *)(tmp->content))[x] == 'O')
			{
				xy = ft_calloc(2, sizeof(int));
				xy[0] = x;
				xy[1] = y;
				ft_lstadd_back(rounded_rocks, ft_lstnew(xy));
			}
			x++;
		}
		y++;
		tmp = tmp->next;
	}
}

void	get_cube_rocks(t_list **cube_rocks, t_list *input)
{
	t_list	*tmp;
	int		*xy;
	int		x;
	int		y;

	tmp = input;
	y = 0;
	while (tmp)
	{
		x = 0;
		while (((char *)(tmp->content))[x])
		{
			if (((char *)(tmp->content))[x] == '#')
			{
				xy = ft_calloc(2, sizeof(int));
				xy[0] = x;
				xy[1] = y;
				ft_lstadd_back(cube_rocks, ft_lstnew(xy));
			}
			x++;
		}
		y++;
		tmp = tmp->next;
	}
}
