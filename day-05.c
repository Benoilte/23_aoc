/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day-05.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:04:42 by bebrandt          #+#    #+#             */
/*   Updated: 2023/12/05 23:00:47 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "days.h"

static long	get_lowest_location(t_list *maps, long *source, long size);
static void	find_next_detination(t_list *ranges, long *source, long size);
static long	**get_seeds_range(char **seeds, long *size);

void	day_05(void)
{
	char	*file;
	char	*line;
	int		fd;
	char	**seeds;
	t_list  *maps;
	long	*source;
	long	**source_range;
	long	size;
	long	i;

	file = "input/day-05.txt";
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	seeds = ft_split(ft_strchr(line, ' ') + 1, ' ');
	maps = NULL;
	while (line)
	{
		if (ft_isdigit(line[0]))
			ft_lstadd_back(&maps, ft_lstnew(set_range(line, fd)));
		line = get_next_line(fd);
	}
	size = 0;
	while (seeds[size])
		size++;
	source = convert_strptr_to_intptr(seeds, size);
	ft_printf("lowest location: %u\n", get_lowest_location(maps, source, size));
	free(source);
	source_range = get_seeds_range(seeds, &size);
	i = 0;
	while (i < (size / 2))
	{
		ft_printf("min - max\n");
		display_long_int_array(source_range[i++], 2, "min_max");
	}
	// display_long_int_array(source, size, "source");
	// ft_printf("lowest location 2: %u\n", get_lowest_location(maps, source, size));
}

static long	**get_seeds_range(char **seeds, long *size)
{
	long	*source;
	long	**source_range;
	// long	len;
	long	i;

	source = convert_strptr_to_intptr(seeds, *size);
	// len = 0;
	i = 0;
	source_range = ft_calloc(*size / 2, sizeof(long *));
	while (i < *size)
	{
		source_range[i / 2] = ft_calloc(2, sizeof(long));
		source_range[i / 2][0] = source[i];
		source_range[i / 2][1] = source[i] + source[i + 1];
		i += 2;
	}
	return (source_range);
}

static long	get_lowest_location(t_list *maps, long *source, long size)
{
	t_list	*tmp_maps;
	long		i;
	long	lowest;

	tmp_maps = maps;
	while (tmp_maps)
	{
		find_next_detination(tmp_maps->content, source, size);
		tmp_maps = tmp_maps->next;
	}
	i = 0;
	lowest = 0;
	while (i < size)
	{
		if (lowest == 0 || source[i] < lowest)
			lowest = source[i];
		i++;
	}
	return (lowest);
}

static void	find_next_detination(t_list *ranges, long *source, long size)
{
	t_list	*tmp;
	char	**range_str;
	long	*range_i;
	long	i;

	// display_long_int_array(source, size, "source");
	i = 0;
	while (i < size)
	{
		tmp = ranges;
		while (tmp)
		{
			range_str = ft_split(tmp->content, ' ');
			range_i = convert_strptr_to_intptr(range_str, 3);
			if (source[i] >= range_i[1] && source[i] < (range_i[1] + range_i[2]))
			{
				// printf("condition: %li >= %li && %li < (%li + %li) (%li)\n", source[i], range_i[1], source[i], range_i[1], range_i[2], (range_i[1] + range_i[2]));
				source[i] += range_i[0] - range_i[1];
				// printf("new_value = %li\n", source[i]);
				tmp = NULL;
			}
			if (tmp)
				tmp = tmp->next;
		}
		i++;
	}
}
