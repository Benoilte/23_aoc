/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:11:06 by bebrandt          #+#    #+#             */
/*   Updated: 2023/11/24 21:31:13 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "days.h"

static void	ft_day_01_to_09(int day);
static void	ft_day_10_to_19(int day);
static void	ft_day_20_to_25(int day);

int	main(int argc, char **argv)
{
	int	day;

	if (argc >= 2)
	{
		day = ft_atoi(argv[1]);
		if (day >= 1 && day <= 9)
			ft_day_01_to_09(day);
		else if (day >= 10 && day <= 19)
			ft_day_10_to_19(day);
		else if (day >= 20 && day <= 25)
			ft_day_20_to_25(day);
	}
}

void	ft_day_01_to_09(int day)
{
	if (day == 1)
		day_01();
	else if (day == 2)
		day_02();
	else if (day == 3)
		day_03();
	else if (day == 4)
		day_04();
	else if (day == 5)
		day_05();
	else if (day == 6)
		day_06();
	else if (day == 7)
		day_07();
	else if (day == 8)
		day_08();
	else if (day == 9)
		day_09();
}

void	ft_day_10_to_19(int day)
{
	if (day == 10)
		day_10();
	else if (day == 11)
		day_11();
	else if (day == 12)
		day_12();
	else if (day == 13)
		day_13();
	else if (day == 14)
		day_14();
	else if (day == 15)
		day_15();
	else if (day == 16)
		day_16();
	else if (day == 17)
		day_17();
	else if (day == 18)
		day_18();
	else if (day == 19)
		day_19();
}

void	ft_day_20_to_25(int day)
{
	if (day == 20)
		day_20();
	else if (day == 21)
		day_21();
	else if (day == 22)
		day_22();
	else if (day == 23)
		day_23();
	else if (day == 24)
		day_24();
	else if (day == 25)
		day_25();
}
