/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:38:26 by bebrandt          #+#    #+#             */
/*   Updated: 2023/11/30 09:14:22 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "days.h"

void	display_struct(t_list *lst, char data)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (data == 'd')
			ft_printf("data: %d\n", tmp->content);
		if (data == 's')
			ft_printf("data: %s\n", tmp->content);
		tmp = tmp->next;
	}
}

void	display_str_array(char	**tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_printf("str[%d] = %s\n", i, tab[i]);
		i++;
	}
}
