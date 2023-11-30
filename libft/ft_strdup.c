/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:14:20 by bebrandt          #+#    #+#             */
/*   Updated: 2023/10/24 10:37:15 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Allocates sufficient memory for a copy of the string s1, does the copy, and 
returns a pointer to it. If insufficient memory is available, NULL is returned
*/
char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		i;

	dest = (char *)malloc((ft_strlen((char *)s1) + 1) * sizeof(char));
	if (!dest)
		return ((void *)0);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
