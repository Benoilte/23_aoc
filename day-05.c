/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day-05.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:04:42 by bebrandt          #+#    #+#             */
/*   Updated: 2023/12/05 07:47:37 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "days.h"

void	day_05(void)
{
	char	*file;
	char	*line;
	int		fd;
	char	**seeds;
	t_list	map[7];
	int		i;

	file = "input/day-05.txt";
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	seeds = ft_split(ft_strchr(line, ' ') + 1, ' ');
	display_str_array(seeds, "seed");
	i = 0;
	while (line)
	{
		set_map_str(map + i, fd);
		line = get_next_line(fd);
	}
	close(fd);
	i = 0;
	while (i < 7)
	{
		display_struct(map + i, 'a', "map");
		i++;
	}
}
