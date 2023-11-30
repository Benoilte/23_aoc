/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 10:28:20 by bebrandt          #+#    #+#             */
/*   Updated: 2023/11/24 17:55:54 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Count number of element of the linked list and return the value.
*/
int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*el_lst;

	i = 0;
	el_lst = lst;
	while (el_lst)
	{
		el_lst = el_lst->next;
		i++;
	}
	return (i);
}
