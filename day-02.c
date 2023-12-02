/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day-02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:03:57 by bebrandt          #+#    #+#             */
/*   Updated: 2023/12/02 07:46:09 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "days.h"

static int	count_possibility(t_list *input);
static int	check_cube(char *str);
static char	**parse_str(char *str);
static int	get_fewer(char *str, int red, int blue, int green);
static int	count_power_set(t_list *input);

void	day_02(void)
{
	t_list	*input;
	int		fd;
	char	*file;

	file = "input/day-02.txt";
	fd = open(file, O_RDONLY);
	input = from_txt_to_struct_of_str(fd);
	ft_printf("possibilities id: %d\n", count_possibility(input));
	ft_printf("power_set: %d\n", count_power_set(input));
	close(fd);
}

static int	count_possibility(t_list *input)
{
	t_list	*tmp;
	int		id_sum;

	tmp = input;
	id_sum = 0;
	while (tmp)
	{
		id_sum += check_cube(((char *)(tmp->content)));
		tmp = tmp->next;
	}
	return (id_sum);
}

static int count_power_set(t_list *input)
{
	t_list	*tmp;
	int		power_set;

	tmp = input;
	power_set = 0;
	while (tmp)
	{
		power_set += get_fewer(((char *)(tmp->content)), 1, 1, 1);
		tmp = tmp->next;
	}
	return (power_set);
}

// only 12 red cubes, 13 green cubes, and 14 blue cubes
static int	check_cube(char *str)
{
	char	**game;
	int		id;
	int		cube;
	int		i;
	int		j;

	game = parse_str(str);
	id = ft_atoi(game[0]);
	i = 1;
	while (game[i])
	{
		j = 0;
		cube = ft_get_digit(game[i], &j);
		j++;
		if (ft_strncmp(game[i] + j, "red", 3) == 0 && cube > 12)
			return (0);
		else if (ft_strncmp(game[i] + j, "blue", 4) == 0 && cube > 14)
			return (0);
		else if (ft_strncmp(game[i] + j, "green", 5) == 0 && cube > 13)
			return (0);
		i++;
	}
	return (id);
}

static int	get_fewer(char *str, int red, int blue, int green)
{
	char	**game;
	int		cube;
	int		i;
	int		j;

	game = parse_str(str);
	i = 1;
	while (game[i])
	{
		j = 0;
		cube = ft_get_digit(game[i], &j);
		j++;
		if (ft_strncmp(game[i] + j, "red", 3) == 0 && cube > red)
			red = cube;
		else if (ft_strncmp(game[i] + j, "blue", 4) == 0 && cube > blue)
			blue = cube;
		else if (ft_strncmp(game[i] + j, "green", 5) == 0 && cube > green)
			green = cube;
		i++;
	}
	return (red * blue * green);
}

static char **parse_str(char *str)
{
	char	**game;
	char	*tmp;
	int		i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == ';') || (str[i] == ':'))
			str[i] = ',';
		i++;
	}
	i = 0;
	game = ft_split(str + 5, ',');
	while (game[i])
	{
		tmp = ft_strtrim(game[i], " ");
		free(game[i]);
		game[i] = tmp;
		i++;
	}
	return (game);
}
