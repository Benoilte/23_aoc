/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:03:45 by bebrandt          #+#    #+#             */
/*   Updated: 2023/10/24 10:35:04 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Writes len bytes of value 'c'. return 'str'
*/
void	*ft_memset(void *str, int c, size_t n)
{
	int				i;
	unsigned char	*src;

	i = 0;
	src = (unsigned char *)str;
	while (n > 0)
	{
		src[i++] = c;
		n--;
	}
	return (str);
}
