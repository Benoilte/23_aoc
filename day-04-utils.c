/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day-04-utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 07:19:42 by bebrandt          #+#    #+#             */
/*   Updated: 2023/12/04 08:37:12 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "days.h"

char	**parse_win_num(char *str)
{
	int		start;
	int		end;
	char	*win_num_str;
	char	**win_num_tab;

	start = 0;
	while (str[start] != ':')
		start++;
	end = start;
	while (str[end] != '|')
		end++;
	start += 2;
	end -= 2;
	win_num_str = ft_substr(str, start, (end - start) + 1);
	win_num_tab = ft_split(win_num_str, ' ');
	free(win_num_str);
	return (win_num_tab);
}

char	**parse_my_num(char *str)
{
	int		start;
	int		end;
	char	*my_num_str;
	char	**my_num_tab;

	start = 0;
	while (str[start] != '|')
		start++;
	end = start;
	while (str[end])
		end++;
	start += 2;
	end -= 1;
	my_num_str = ft_substr(str, start, (end - start) + 1);
	my_num_tab = ft_split(my_num_str, ' ');
	free(my_num_str);
	return (my_num_tab);
}

void	add_copy(int i, int n, int *copy, int size)
{
	int	to_add;

	to_add = copy[i - 1];
	while (n > 0 && i < size)
	{
		copy[i] += to_add;
		i++;
		n--;
	}
}
