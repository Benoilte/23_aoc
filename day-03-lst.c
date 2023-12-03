/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day-03-lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:01:03 by bebrandt          #+#    #+#             */
/*   Updated: 2023/12/03 22:00:48 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "days.h"

/*
si premier élément on l'ajoute et lui assigne sa coordonnée
avec son part number.

si déjà d'autres élément, on itère et on compare
si sa coordonée est existante.

si sa coordonée est existente, on assigne le part number aux membre p_num_2

si elle n'éxiste pas, on crée une nouvelle structure. On l'ajoute à l'arrière
des structures existente
*/
void	lstord_iter(t_ord **lst, char *xy, int p_num)
{
	t_ord	*tmp;
	t_ord	*new;
	int		not_add;

	tmp = *lst;
	not_add = 1;
	while (tmp)
	{
		if (ft_strncmp(tmp->ord, xy, ft_strlen(xy)) == 0)
		{
			lstord_add_pnum(tmp, p_num);
			not_add--;
			break ;
		}
		tmp = tmp->next;
	}
	if (not_add)
	{
		new = lstord_new(xy, p_num);
		lstord_addback(lst, new);
	}
}

t_ord	*lstord_new(char *xy, int p_num)
{
	t_ord	*new;

	new = (t_ord *)malloc(sizeof(t_ord));
	if (!new)
		return (NULL);
	new->ord = xy;
	new->p_num_1 = p_num;
	new->p_num_2 = -1;
	new->next = NULL;
	return (new);
}

void	lstord_addback(t_ord **lst, t_ord *new)
{
	t_ord	*tmp;

	tmp = *lst;
	if (!tmp)
	{
		*lst = new;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	lstord_add_pnum(t_ord *lst, int p_num)
{
	if (lst->p_num_2 == -1)
		lst->p_num_2 = p_num;
}

int		gear_ratio(t_ord *lst)
{
	t_ord	*tmp;
	int		ratio;

	ratio = 0;
	tmp = lst;
	while (tmp)
	{
		if (tmp->p_num_2 != -1)
			ratio += (tmp->p_num_1 * tmp->p_num_2);
		tmp = tmp->next;
	}
	return (ratio);
}
