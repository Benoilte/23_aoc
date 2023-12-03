/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day-03-utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:30:22 by bebrandt          #+#    #+#             */
/*   Updated: 2023/12/03 21:01:58 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "days.h"

int	is_sym(char c)
{
	return (!ft_isalnum(c) && c != '.');
}

int	is_star(char c)
{
	return (c == '*');
}

int	*set_xy(int x, int y)
{
	int	*xy;

	xy = ft_calloc(2, sizeof(int));
	xy[0] = x;
	xy[1] = y;
	return (xy);
}

char	*convert_xy_to_str(int x, int y)
{
	char	*x_str;
	char	*y_str;
	char	*xy_str;
	char	*tmp_str;

	x_str = ft_itoa(x);
	y_str = ft_itoa(y);
	tmp_str = ft_strjoin(x_str, " ");
	xy_str = ft_strjoin(tmp_str, y_str);
	free(x_str);
	free(y_str);
	free(tmp_str);
	return (xy_str);
}
