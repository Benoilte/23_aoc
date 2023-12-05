/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:38:26 by bebrandt          #+#    #+#             */
/*   Updated: 2023/12/05 07:48:06 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "days.h"

void	display_struct(t_list *lst, char data, char *text)
{
	t_list	*tmp;

	tmp = lst;
	if (data == 'a')
	{
		display_str_array(((char **)(tmp->content)), text);
		return ;
	}
	while (tmp)
	{
		if (data == 'd')
			ft_printf("%s: %d\n", text, *((int *)(tmp->content)));
		if (data == 's')
			ft_printf("%s: %s\n", text, tmp->content);
		tmp = tmp->next;
	}
}

void	display_str_array(char	**tab, char *text)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_printf("%s[%d] = %s\n", text, i, tab[i]);
		i++;
	}
}

void	display_int_array(int *tab, int size, char *text)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_printf("%s[%d] = %d\n", text, i, tab[i]);
		i++;
	}
}
