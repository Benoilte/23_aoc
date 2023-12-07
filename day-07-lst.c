/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day-07-lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 07:46:43 by bebrandt          #+#    #+#             */
/*   Updated: 2023/12/07 08:45:17 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "days.h"

t_hand	*lsthand_new(char *hand, int bid, int type)
{
	t_hand	*new;

	new = (t_hand *)malloc(sizeof(t_hand));
	if (!new)
		return (NULL);
	new->hand = hand;
	new->bid = bid;
	new->type = type;
	new->next = NULL;
	return (new);
}

/*
Si new->type < lsthand->type placer la structure devant l'élément.
*/
void	lsthand_addordered(t_hand **lst, t_hand *new)
{
	t_hand	*tmp;
	t_hand	*prev;

	tmp = *lst;
	prev = NULL;
	if (!tmp)
	{
		*lst = new;
		return ;
	}
	else if (ft_is_weaker(new, *lst))
	{
		new->next = *lst;
		*lst = new;
		return ;
	}
	while (tmp)
	{
		if (ft_is_weaker(new, tmp))
		{
			prev->next = new;
			new->next = tmp;
			return ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = new;
}

/*
Add new elem. at the beginning of the list and set new->next
to the previous first elem. re-define the ptr of the new first elem.
*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
