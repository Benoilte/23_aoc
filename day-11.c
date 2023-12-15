/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day-11.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:07:07 by bebrandt          #+#    #+#             */
/*   Updated: 2023/12/11 09:31:45 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "days.h"

static t_list	**expand_universe(char **input);
static t_list	*get_galaxy(char **input);
static int	shortest_path(t_list *galaxy, t_list **expansion);
static int	compute_path(int *galaxy1, int *galaxy2, t_list **expansion, int *inter);
static int count_intersection(t_list *cross, int ord1, int ord2);

void	day_11(void)
{
	char	**input;
	int		size;
	int			fd;
	char		*file;
	t_list	**xy;
	t_list	*galaxy;

	file = "input/day-11.txt";
	fd = open(file, O_RDONLY);
	size = count_line(fd);
	close(fd);
	fd = open(file, O_RDONLY);
	input = from_txt_to_array_of_str(fd, size);
	close(fd);
	display_str_array(input, "line");
	xy = expand_universe(input);
	// display_struct(xy[0], 'd', "x_lst");
	// display_struct(xy[1], 'd', "y_lst");
	galaxy = get_galaxy(input);
	// display_struct(galaxy, 'i', "galaxy position");
	ft_printf("shortest path: %d\n", shortest_path(galaxy, xy));
}

static int	shortest_path(t_list *galaxy, t_list **expansion)
{
	t_list	*tmp1;
	t_list	*tmp2;
	int		inter[1];
	int		path_sum;
	int		i;
	int		j;

	path_sum = 0;
	tmp1 = galaxy;
	i = 1;
	*inter = 0;
	while (tmp1->next)
	{
		tmp2 = tmp1->next;
		j = i + 1;
		while (tmp2)
		{
			// ft_printf("galaxy %d to galaxy %d ", i, j);
			// ft_printf("steps %d\n", compute_path(tmp1->content, tmp2->content, expansion));
			path_sum += compute_path(tmp1->content, tmp2->content, expansion, inter);
			tmp2 = tmp2->next;
			j++;
		}
		tmp1 = tmp1->next;
		i++;
	}
	printf("inter: %li\n", ((long)(*inter) * 999999) + path_sum);
	return (path_sum);
}

static int	compute_path(int *galaxy1, int *galaxy2, t_list **expansion, int *inter)
{
	int x;
	int y;

	*inter += count_intersection(expansion[0], galaxy1[0], galaxy2[0]);
	*inter += count_intersection(expansion[1], galaxy1[1], galaxy2[1]);
	x = 0;
	y = 0;
	(void)expansion;
	if (galaxy1[0] > galaxy2[0])
		x += galaxy1[0] - galaxy2[0];
	else
		x += galaxy2[0] - galaxy1[0];
	if (galaxy1[1] > galaxy2[1])
		y += galaxy1[1] - galaxy2[1];
	else
		y += galaxy2[1] - galaxy1[1];
	return (x + y);
}

static int count_intersection(t_list *cross, int ord1, int ord2)
{
	t_list	*tmp;
	int		intersection;

	tmp = cross;
	intersection = 0;
	while (tmp)
	{
		if (ord1 < ord2)
		{
			if (*((int *)(tmp->content)) > ord1 && *((int *)(tmp->content)) < ord2)
				intersection += 1;
		}
		else
		{
			if (*((int *)(tmp->content)) > ord2 && *((int *)(tmp->content)) < ord1)
				intersection += 1;
		}
		tmp = tmp->next;
	}
	return (intersection);
}

static t_list	*get_galaxy(char **input)
{
	t_list	*galaxy;
	int		*xy;
	int		x;
	int		y;

	galaxy = NULL;
	y = 0;
	while (input[y])
	{
		x = 0;
		while (input[y][x])
		{
			if (input[y][x] == '#')
			{
				xy = ft_calloc(2, sizeof(int));
				xy[0] = x;
				xy[1] = y;
				ft_lstadd_back(&galaxy, ft_lstnew(xy));
			}
			x++;
		}
		y++;
	}
	return (galaxy);
}

static t_list	**expand_universe(char **input)
{
	t_list	**xy_lst;
	t_list	*x_lst;
	t_list	*y_lst;
	int		x;
	int		y;
	int		galaxy;

	x_lst = NULL;
	y_lst = NULL;
	x = 0;
	y = 0;
	while (input[y])
	{
		if (!ft_strchr(input[y], '#'))
			ft_lstadd_back(&y_lst, ft_lstnew(get_int_ptr(y)));
		y++;
	}
	y = 0;
	while (input[y][x])
	{
		galaxy = 0;
		while (input[y])
		{
			if (input[y][x] == '#')
				galaxy = 1;
			y++;
		}
		if (!galaxy)
			ft_lstadd_back(&x_lst, ft_lstnew(get_int_ptr(x)));
		x++;
		y = 0;
	}
	xy_lst = ft_calloc(2, sizeof(t_list *));
	xy_lst[0] = x_lst;
	xy_lst[1] = y_lst;
	return (xy_lst);
}
