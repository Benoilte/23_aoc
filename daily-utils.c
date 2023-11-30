/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daily-utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:56:37 by bebrandt          #+#    #+#             */
/*   Updated: 2023/11/29 21:27:40 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "days.h"

int	power_of_two(int n)
{
	int	result;

	result = 1;
	while (n > 0)
	{
		result *= 2;
		n--;
	}
	return (result);
}

void	*copy(void *content)
{
	char	*copy;

	copy = ft_strdup((char *)content);
	return (copy);
}
