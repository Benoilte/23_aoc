/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day-12.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:07:29 by bebrandt          #+#    #+#             */
/*   Updated: 2023/12/15 00:09:22 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "days.h"

static int	sum_of_arrangements(t_list *input);
static int	count_arrangements(char *springs);

void	day_12(void)
{
	t_list	*input;
	int		fd;
	char	*file;

	file = "input/day-12.txt";
	fd = open(file, O_RDONLY);
	input = from_txt_to_struct_of_str(fd);
	close(fd);
	// display_struct(input, 's', "springs");
	ft_printf("sum of arrangements: %d\n", sum_of_arrangements(input));
}
static int	sum_of_arrangements(t_list *input)
{
	int		arrangements;
	t_list	*tmp;

	arrangements = 0;
	tmp = input;
	while (tmp)
	{
		arrangements += count_arrangements(tmp->content);
		tmp = tmp->next;
	}
	return (arrangements);
}

static int	count_arrangements(char *springs)
{
	int		possibilities;
	char	**broken_springs;
	char	**groups;

	possibilities = 0;
	broken_springs = ft_split(springs, ' ');
	display_str_array(broken_springs, "broken springs");
	groups = ft_split(broken_springs[1], ',');
	display_str_array(groups, "groups");
	// possibilities += find_different_arrangements(broken_springs[0], groups);
	return (possibilities);
}

// static int	find_different_arrangements(char *springs, char **groups)
// {
// 	int	i;

// 	i = 0;
// 	while (groups[i])
// 	{

// 	}
// }
