/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day-05-utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 07:28:47 by bebrandt          #+#    #+#             */
/*   Updated: 2023/12/05 07:48:42 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "days.h"

void	set_map_str(t_list *map, int fd)
{
	char	*line;
	char	**range;

	line = get_next_line(fd);
	while (ft_isdigit(line[0]))
	{
		range = ft_split(line, ' ');
		ft_lstadd_back(&map, ft_lstnew(range));
		line = get_next_line(fd);
	}
}
