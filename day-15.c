/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day-15.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:08:18 by bebrandt          #+#    #+#             */
/*   Updated: 2023/12/15 13:05:28 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "days.h"

int	compute_code(char **sequence);
void	add_lens(t_list	**box, char *lens);
void	remove_lens(t_list	**box, char	*lens);
int		is_label_exist(char *label_src, char *label_cmp);


void	day_15(void)
{
	char	*input;
	int		fd;
	char	*file;
	char	**init_sequence;

	file = "input/day-15.txt";
	fd = open(file, O_RDONLY);
	input = get_next_line(fd);
	close(fd);
	// ft_printf("line: %s", input);
	init_sequence = ft_split(input, ',');
	// display_str_array(init_sequence, "code");
	ft_printf("sum of the initialization sequences: %d\n", compute_code(init_sequence));
}

int compute_code(char **sequence)
{
	t_list *box;
	t_list *box_ptr;
	t_list *tmp;
	int	i;
	int	j;
	int code;
	int	result;
	int last_char;

	i = 0;
	result = 0;
	box = ft_calloc(256, sizeof(t_list));
	// ft_initialize_lst(box, 256);
	while (sequence[i])
	{
		j = 0;
		code = 0;
		while (sequence[i][j] != '=' && sequence[i][j] != '-' && sequence[i][j] != '\n')
		{
			code += sequence[i][j];
			code *= 17;
			code %= 256;
			j++;
		}
		box_ptr = box + code;
		// ft_printf("label: %s\n", sequence[i]);
		if (sequence[i][j] == '=')
			add_lens(&box_ptr, sequence[i]);
		if (sequence[i][j] == '-')
			remove_lens(&box_ptr, sequence[i]);
		// result += code;
		i++;
		// display_struct(box, 's', "lens_0 after cmp");
	}
	display_struct(box, 's', "lens_0");
	ft_printf("-------------------------------\n");
	display_struct(box + 1, 's', "lens_1");
	ft_printf("-------------------------------\n");
	display_struct(box + 3, 's', "lens_3");
	i = 0;
	while (i < 256)
	{
		tmp = box + i;
		j = 1;
		while (tmp)
		{
			if (tmp->content)
			{
				ft_printf("lens: %s\n", tmp->content);
				last_char = ft_strlen((char *)(tmp->content)) - 1;
				if (((char *)(tmp->content))[last_char] == '\n')
					last_char--;
				ft_printf("focal: %c\n", ((char *)(tmp->content))[last_char]);
				ft_printf("box: %d\n", i);
				ft_printf("slot: %d\n", j);
				result += ((i + 1) * j * (((char *)(tmp->content))[last_char] - 48));
				j++;
			}
			tmp = tmp->next;
		}
		i++;
	}
	return (result);
}

void	add_lens(t_list	**box, char	*lens)
{
	t_list	*tmp;
	// t_list	*last;

	tmp = *box;
	// ft_printf("add_lens: %s\n", lens);
	// ft_printf("tmp = %p\n", tmp);
	// ft_printf("tmp->next = %p\n", tmp->next);
	if (!(tmp->content))
	{
		tmp->content = lens;
		return ;
	}
	while (tmp)
	{
		// ft_printf("content: %s\n", tmp->content);
		// ft_printf("lens: %s\n", lens);
		if (tmp->content && is_label_exist(tmp->content, lens))
		{
			// ft_printf("modify content\n");
			tmp->content = lens;
			return ;
		}
		tmp = tmp->next;
	}
	ft_lstadd_back(box, ft_lstnew(lens));
	// display_struct(*box, 's', "test_2");
}

void	remove_lens(t_list	**box, char	*lens)
{
	t_list	*prev;
	t_list	*to_del;
	t_list	*tmp;

	tmp = *box;
	// if (!(tmp->content))
	// {
	// 	return ;
	// }
	while (tmp)
	{
		if (tmp->content && is_label_exist(tmp->content, lens))
		{
			to_del = tmp;
			if (tmp == *box)
				tmp->content = NULL;
			else
				prev->next = tmp->next;
			tmp = tmp->next;
			ft_lstdelone(to_del, &del);
		}
		else
		{
			prev = tmp;
			tmp = tmp->next;
		}
	}
}

int is_label_exist(char *label_src, char *label_cmp)
{
	int i;

	i = 0;
	ft_printf("labelsrc: %s, labelCmp: %s\n", label_src, label_cmp);
	ft_printf("src: %c, cmp: %c\n", label_src[i], label_cmp[i]);
	while ((label_src[i] == label_cmp[i]) && label_src[i] != '-' && label_src[i] != '='
			&& label_cmp[i] != '-' && label_cmp[i] != '=')
	{
		i++;
	}
	if (!ft_isalpha(label_src[i]) && !ft_isalpha(label_cmp[i]))
	{
		return (1);
	}
	else
		return (0);
}
