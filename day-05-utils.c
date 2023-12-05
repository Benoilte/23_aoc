/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day-05-utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 07:28:47 by bebrandt          #+#    #+#             */
/*   Updated: 2023/12/05 15:54:59 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "days.h"

t_list	*set_range(char *line, int fd)
{
	t_list	*range;
	char	*str;

	range = NULL;
	while (line && ft_isdigit(line[0]))
	{
		str = ft_substr(line, 0, ft_strlen(line) - 1);
		ft_lstadd_back(&range, ft_lstnew(str));
		line = get_next_line(fd);
	}
	return (range);
}

long	*convert_strptr_to_intptr(char **seeds, int size)
{
	int		i;
	long	*loc;

	i = 0;
	loc = ft_calloc(size, sizeof(long));
	while (i < size)
	{
		loc[i] = ft_atoi_long(seeds[i]);
		i++;
	}
	return (loc);
}
