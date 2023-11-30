/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:57:30 by bebrandt          #+#    #+#             */
/*   Updated: 2023/11/24 19:26:19 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
Returns number of characters that precede the terminating NULL character
*/
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

/*
Add new elem. at the end of the list.
set new elem. as first elem. of the list if *lst is null.
Set new->next as null and new->str = str
*/
void	ft_gnl_lstadd_back(t_gnl_lst **lst, char *str)
{
	t_gnl_lst	*last;
	t_gnl_lst	*new;

	if (!lst)
	{
		return ;
	}
	new = (t_gnl_lst *)malloc(sizeof(t_gnl_lst));
	if (!new)
	{
		return ;
	}
	ft_strlcpy(new->str, str, ft_strlen(str) + 1);
	new->next = (void *)0;
	if (!*lst)
		*lst = new;
	else
	{
		last = *lst;
		while (last->next)
			last = last->next;
		last->next = new;
	}
}

/*
Deletes and free the memory of the element passed as parameter
and all the following elements
*/
void	*ft_gnl_lstclear(t_gnl_lst **lst)
{
	t_gnl_lst	*next_el;

	if (!lst)
		return ((void *)0);
	while (*lst)
	{
		next_el = (*lst)->next;
		free(*lst);
		*lst = next_el;
	}
	free(*lst);
	*lst = (void *)0;
	return ((void *)0);
}

/*
Return the sum of all str member length.
*/
int	ft_count_line_chars(t_gnl_lst *lst)
{
	int			len;
	t_gnl_lst	*tmp;

	if (!lst)
		return (0);
	tmp = lst;
	len = 0;
	while (tmp)
	{
		len += ft_strlen(tmp->str);
		tmp = tmp->next;
	}
	return (len);
}

/*
copies up to dstsize - 1 characters from the string src to dst.
return the total length of the strings it tried to create.
If the return value is >= dstsize, the output string has been truncated.
*/
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	long unsigned int	i;
	long unsigned int	len;

	i = 0;
	if (size)
	{
		while (src[i] && (size - 1) != i)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	len = 0;
	while (src[len])
		len++;
	return (len);
}
