/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day-09.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:06:15 by bebrandt          #+#    #+#             */
/*   Updated: 2023/12/09 08:49:04 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "days.h"

static int	get_next_value(char *history);
static long		check_diff(long *history, int size);

void	day_09(void)
{
	t_list	*input;
	int	sum;
	t_list 	*tmp;
	int			fd;
	char		*file;

	file = "input/day-09.txt";
	fd = open(file, O_RDONLY);
	input = from_txt_to_struct_of_str(fd);
	display_struct(input,'s', "network");
	close(fd);
	tmp = input;
	sum = 0;
	while (tmp)
	{
		sum += get_next_value(tmp->content);
		tmp = tmp->next;
	}
	ft_printf("total : %d\n", sum);
}

static int	get_next_value(char *history)
{
	char	**step1;
	long	*step2;
	long	*first;
	t_list	*diff;
	long	this_is_the_first;
	long	sum;
	int		i;
	int		size;

	diff = NULL;
	first = NULL;
	step1 = ft_split(history, ' ');
	size = 0;
	while (step1[size])
		size++;
	step2 = convert_strptr_to_intptr(step1, size);
	display_long_int_array(step2, size, "history");
	size--;
	this_is_the_first = step2[0];
	printf("sum  ....: %li \n", this_is_the_first);
	// step3 = ft_calloc(size, sizeof(char *));
	while (check_diff(step2, size) != 0)
	{
		i = 0;
		while (i < size)
		{
			step2[i] = step2[i + 1] - step2[i];
			i++;
		}
		ft_printf("new step2\n");
		display_long_int_array(step2, size, "diff");
		first = ft_calloc(1, sizeof(long *));
		*first = step2[0];
		ft_lstadd_front(&diff, ft_lstnew(first));
		// printf("first: %li\n", last);
		size--;
	}
	display_struct(diff, 'l', "next");
	sum = 0;
	while (diff->next)
	{
		sum = *((long *)(diff->next->content)) - sum;
		printf("result: %li\n", sum);
		diff = diff->next;
	}
	return (this_is_the_first - sum);
}

static long		check_diff(long *history, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (history[i])
			return (1);
		i++;
	}
	return (0);
}
