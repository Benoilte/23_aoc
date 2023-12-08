/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day-08-utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 06:35:36 by bebrandt          #+#    #+#             */
/*   Updated: 2023/12/08 09:11:57 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "days.h"

void	parse_content_day8(t_list *input)
{
	char 	**network;
	t_list	*tmp;

	tmp = input;
	while (tmp)
	{
		network = ft_calloc(4, sizeof(char *));
		network[0] = ft_substr(tmp->content, 0, 3);
		network[1] = ft_substr(tmp->content, 7, 3);
		network[2] = ft_substr(tmp->content, 12, 3);
		network[3] = 0;
		free(tmp->content);
		tmp->content = network;
		tmp = tmp->next;
	}
}

t_list	*get_all_starts(t_list *input)
{
	t_list	*starts;
	t_list	*tmp;
	char	*start_node;

	starts = NULL;
	tmp = input;
	while (tmp)
	{
		if (((char **)(tmp->content))[0][2] == 'A')
		{
			// ft_printf("test 01\n");
			start_node = ft_calloc(4, sizeof(char));
			ft_strlcpy(start_node, ((char **)(tmp->content))[0], 4);
			// ft_printf("start_node: %s\n", start_node);
			ft_lstadd_back(&starts, ft_lstnew(start_node));
		}
		tmp = tmp->next;
	}
	return (starts);
}

int	is_ends(t_list *starts)
{
	t_list *tmp;

	tmp = starts;
	while (tmp)
	{
		if (((char *)(tmp->content))[2] == 'Z')
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}
