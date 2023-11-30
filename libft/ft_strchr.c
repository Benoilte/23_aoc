/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:12:23 by bebrandt          #+#    #+#             */
/*   Updated: 2023/10/24 10:37:11 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Locates the first occurence of 'c' in the string 's'. The terminating null 
character is considered to be part of the string. 
Return a pointer to the located character, or NULL if there is no occurence
*/
char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((unsigned char) str[i] == (unsigned char) c)
			return ((char *)(str + i));
		i++;
	}
	if ((unsigned char) str[i] == (unsigned char) c)
		return ((char *)(str + i));
	return ((void *)0);
}
