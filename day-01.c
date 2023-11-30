/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day-01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:47:31 by bebrandt          #+#    #+#             */
/*   Updated: 2023/11/24 20:51:54 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "days.h"

static void	first_part(int day);
static void	second_part(int day);

void	day_01(void)
{
	first_part(1);
	second_part(1);
}

void	first_part(int day)
{
	ft_printf("first part result day %.2d\n", day);
}

void	second_part(int day)
{
	ft_printf("second part result day %.2d\n", day);
}
