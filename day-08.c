/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day-08.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:05:57 by bebrandt          #+#    #+#             */
/*   Updated: 2023/12/08 09:49:55 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "days.h"

static long	count_steps_part_2(char *instructions, t_list *input);
static long	count_steps(char *next_node, char *instructions, t_list *input);
static char	*get_next_node(char *next_node, char instruction, t_list *input);

void	day_08(void)
{
	t_list	*input;
	char	*instructions;
	// t_hand 	*hand;
	// t_list 	*tmp;
	int			fd;
	char		*file;

	file = "input/day-08.txt";
	fd = open(file, O_RDONLY);
	instructions = get_next_line(fd);
	get_next_line(fd);
	input = from_txt_to_struct_of_str(fd);
	parse_content_day8(input);
	// display_struct(input,'a', "network");
	// ft_printf("steps	   : %d\n", count_steps(instructions, input));
	// display_struct(input,'a', "network");
	ft_printf("steps part 2: %u\n", count_steps_part_2(instructions, input));
	close(fd);
}

/*
Créer une structure de liste chaînée "start", avec comme élément, chaque node qui termine par 'A'
itérer chaque fois à travers la list chainée et appliquer l'instruction pour accéder à la node suivante,
Controler si chaque node se termine par Z.

Si c'est le cas on arrête et on retourne les steps.
sinon, on continue de suivre les instructions.
*/

static long	count_steps_part_2(char *instructions, t_list *input)
{
	t_list	*starts;
	t_list	*tmp;
	long	steps;

	starts = get_all_starts(input);
	// display_struct(starts, 's', "node");
	steps = 1;
	tmp = starts;
	while (tmp)
	{
		ft_printf("node: %s - steps: %u\n", tmp->content, steps);
		steps *= count_steps((char *)(tmp->content), instructions, input);
		tmp = tmp->next;
	}
	// ends = 0;
	// while (ends != size)
	// {
	// 	if (instructions[i] == '\n')
	// 		i = 0;
	// 	tmp = starts;
	// 	while (tmp)
	// 	{
	// 		tmp->content = get_next_node(tmp->content, instructions[i], input);
	// 		if (((char *)(tmp->content))[2] == 'Z')
	// 			ends += 1;
	// 		tmp = tmp->next;
	// 	}
	// 	i++;
	// 	steps++;
	// }
	return (steps);
}

static long	count_steps(char *next_node, char *instructions, t_list *input)
{
	int		i;
	long		steps;

	// ft_printf("next_node: %s\n", next_node);
	i = 0;
	steps = 0;
	while (next_node[2] != 'Z')
	{
		if (instructions[i] == '\n')
			i = 0;
		next_node = get_next_node(next_node, instructions[i], input);
		i++;
		steps++;
	}
	return (steps);
}

static char	*get_next_node(char *next_node, char instruction, t_list *input)
{
	t_list	*tmp;

	tmp = input;
	// ft_printf("next_node: %s, inst: %c\n", next_node, instruction);
	while (tmp)
	{
		if (ft_strncmp(((char **)(tmp->content))[0], next_node, 3) == 0)
		{
			if (instruction == 'L')
			{
				// ft_printf("Left: node: %s - node-left: %s - node-right: %s\n", ((char **)(tmp->content))[0], ((char **)(tmp->content))[1], ((char **)(tmp->content))[2]);
				return (((char **)(tmp->content))[1]);
			}
			else
			{
				// ft_printf("Right: node: %s - node-left: %s - node-right: %s\n", ((char **)(tmp->content))[0], ((char **)(tmp->content))[1], ((char **)(tmp->content))[2]);
				return (((char **)(tmp->content))[2]);
			}
		}
		tmp = tmp->next;
	}
	return (NULL);
}
