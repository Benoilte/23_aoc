/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day-06.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:04:58 by bebrandt          #+#    #+#             */
/*   Updated: 2023/12/06 07:54:52 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "days.h"

static int	count_way_to_win(int *time, int *distance, int size);
static long	possibilities(long time, long distance);

void	day_06(void)
{
	t_list	*input;
	int		fd;
	char	*file;
	int		*time;
	int		*distance;
	long	t;
	long	d;
	int		len;

	file = "input/day-06.txt";
	fd = open(file, O_RDONLY);
	input = from_txt_to_struct_of_str(fd);
	display_struct(input, 's', "data");
	len = 0;
	time = parse_input_d6(input->content, &len);
	distance = parse_input_d6(input->next->content, &len);
	display_int_array(time, 3, "time");
	display_int_array(distance, 3, "dist");
	ft_printf("record sum: %d\n", count_way_to_win(time, distance, len));
	t = parse_input_d6_p2(input->content);
	d = parse_input_d6_p2(input->next->content);
	printf("t = %li || d = %li\n", t, d);
	ft_printf("record sum 2: %d\n", possibilities(t, d));
	close(fd);
}

/*
Your toy boat has a starting speed of zero millimeters per millisecond.
For each whole millisecond you spend at the beginning of the race holding
down the button, the boat's speed increases by one millimeter per millisecond.
*/

static int	count_way_to_win(int *time, int *distance, int size)
{
	int way_to_win;
	int i;

	way_to_win = 1;
	i = 0;
	while (i < size)
	{
		way_to_win *= possibilities(time[i], distance[i]);
		i++;
	}
	return (way_to_win);
}

static long	possibilities(long time, long distance)
{
	long	speed;
	long	time_remain;
	long	dist_reach;
	long	winner;

	winner = 0;
	speed = 0;
	// ft_printf("time: %d\n", time);
	// ft_printf("speed: %d\n", speed);
	// ft_printf("distance: %d\n", distance);
	while (speed < time)
	{
		time_remain = time - speed;
		// ft_printf("time-remain: %d\n", time_remain);
		dist_reach = speed * time_remain;
		if (dist_reach > distance)
			winner++;
		speed++;
	}
	return (winner);
}
