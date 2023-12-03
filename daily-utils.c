/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daily-utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:56:37 by bebrandt          #+#    #+#             */
/*   Updated: 2023/12/03 08:04:49 by bebrandt         ###   ########.fr       */
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

/*
Return the integer found in a string.
's' should be the first position of a digital char.
"42hel5lo88" => 42;
*/
int	ft_get_digit(const char *s, int *j)
{
	int		end;
	int		num;
	char	*str_digit;

	end = 0;
	while (ft_isdigit(s[end]) && s[end])
		end++;
	str_digit = ft_substr(s, 0, end);
	num = ft_atoi(str_digit);
	free(str_digit);
	*j += end;
	return (num);
}
