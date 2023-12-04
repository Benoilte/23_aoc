/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day-04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:04:30 by bebrandt          #+#    #+#             */
/*   Updated: 2023/12/04 08:38:08 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "days.h"

static int	compute_card(t_list *input);
static int	compute_winners(char **num, char **win);
static int	compute_scratchedcards(t_list *input);
static int	count_instances(t_list *match);

void	day_04(void)
{
	t_list	*input;
	int		fd;
	char	*file;

	file = "input/day-04.txt";
	fd = open(file, O_RDONLY);
	input = from_txt_to_struct_of_str(fd);
	ft_printf("score: %d\n", compute_card(input));
	ft_printf("cards: %d\n", compute_scratchedcards(input));
	close(fd);
}

static int	compute_card(t_list *input)
{
	t_list	*tmp;
	char	**my_num;
	char	**win_num;
	int		score;
	int		result;

	score = 0;
	tmp = input;
	result = 0;
	while (tmp)
	{
		my_num = parse_my_num(tmp->content);
		win_num = parse_win_num(tmp->content);
		score = compute_winners(my_num, win_num);
		if (score)
			result += power_of_two(score - 1);
		tmp = tmp->next;
	}
	return (result);
}

static int	compute_winners(char **num, char **win)
{
	int	i;
	int	j;
	int	score;

	i = 0;
	score = 0;
	while (num[i])
	{
		j = 0;
		while (win[j])
		{
			if (ft_strncmp(num[i], win[j], 2) == 0)
				score++;
			j++;
		}
		i++;
	}
	return (score);
}

static int	compute_scratchedcards(t_list *input)
{
	t_list	*tmp;
	t_list	*winners;
	char	**my_num;
	char	**win_num;
	int		score;

	score = 0;
	tmp = input;
	winners = NULL;
	while (tmp)
	{
		my_num = parse_my_num(tmp->content);
		win_num = parse_win_num(tmp->content);
		score = compute_winners(my_num, win_num);
		ft_lstadd_back(&winners, ft_lstnew(get_int_ptr(score)));
		tmp = tmp->next;
	}
	return (count_instances(winners));
}

static int	count_instances(t_list *match)
{
	int		size;
	int		i;
	int		*copy;
	t_list	*tmp;

	size = ft_lstsize(match);
	copy = ft_calloc(size, sizeof(int));
	if (!copy)
		return (0);
	i = 0;
	while (i < size)
		copy[i++] = 1;
	tmp = match;
	i = 0;
	while (tmp)
	{
		add_copy(i + 1, *((int *)(tmp->content)), copy, size);
		i++;
		tmp = tmp->next;
	}
	return  (ft_sum(copy, size));
}
