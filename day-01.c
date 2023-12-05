/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day-01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:47:31 by bebrandt          #+#    #+#             */
/*   Updated: 2023/12/05 08:27:27 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "days.h"

static int	first_part(void);
static int	second_part(void);
static int	ft_get_calibration(t_list *input);
static int	ft_get_calibration_filter(t_list *input);
static int	check_occurence(char *str);

void	day_01(void)
{
	first_part();
	second_part();
}

int	first_part(void)
{
	t_list	*input;
	int			fd;
	int			calibration;
	char		*file;

	file = "input/day-01.txt";
	fd = open(file, O_RDONLY);
	input = from_txt_to_struct_of_str(fd);
	display_struct(input, 's', "line");
	calibration = ft_get_calibration(input);
	close(fd);
	ft_printf("calibration : %d\n", calibration);
	return (0);
}

int	second_part(void)
{
	t_list	*input;
	int			fd;
	int			calibration;
	char		*file;

	file = "input/day-01.txt";
	fd = open(file, O_RDONLY);
	input = from_txt_to_struct_of_str(fd);
	display_struct(input, 's', "line");
	calibration = ft_get_calibration_filter(input);
	close(fd);
	ft_printf("calibration : %d\n", calibration);
	return (0);
}

static int	ft_get_calibration(t_list *input)
{
	char		*digit;
	int			i;
	int			j;
	int			sum;
	t_list	*tmp;

	digit = ft_calloc(3, sizeof(char));
	digit[2] = '\0';
	tmp = input;
	sum = 0;
	while (tmp)
	{
		i = 0;
		j = 0;
		while (((char *)(tmp->content))[i])
		{
			if (ft_isdigit(((char *)(tmp->content))[i]))
			{
				if (j == 0)
				{
					digit[0] = ((char *)(tmp->content))[i];
					digit[1] = ((char *)(tmp->content))[i];
					j++;
				}
				else
					digit[j] = ((char *)(tmp->content))[i];
			}
			i++;
		}
		ft_printf("digit: %s\n", digit);
		sum += ft_atoi(digit);
		tmp = tmp->next;
	}
	return (sum);
}

static int	ft_get_calibration_filter(t_list *input)
{
	char		*digit;
	int			i;
	int			char_digit;
	int			j;
	int			sum;
	t_list	*tmp;

	digit = ft_calloc(3, sizeof(char));
	digit[2] = '\0';
	tmp = input;
	sum = 0;
	while (tmp)
	{
		i = 0;
		j = 0;
		while (((char *)(tmp->content))[i])
		{
			if (ft_isdigit(((char *)(tmp->content))[i]))
			{
				if (j == 0)
				{
					digit[0] = ((char *)(tmp->content))[i];
					digit[1] = ((char *)(tmp->content))[i];
					j++;
				}
				else
					digit[j] = ((char *)(tmp->content))[i];
			}
			else if (check_occurence(((char *)(tmp->content)) + i) != -1)
			{
				char_digit = check_occurence(((char *)(tmp->content)) + i);
				// ft_printf("char digit : %d\n", char_digit);
				// ft_printf("j : %d\n", j);
				if (j == 0)
				{
					digit[0] = char_digit + 48;
					digit[1] = char_digit + 48;
					j++;
				}
				else
					digit[j] = char_digit + 48;
			}
			i++;
		}
		ft_printf("digit: %s\n", digit);
		sum += ft_atoi(digit);
		tmp = tmp->next;
	}
	return (sum);
}

static int check_occurence(char *str)
{
	char		*tenth_str;
	char		**zero_to_nine;
	int			i;
	int			digit;

	// ft_printf("str: %s\n", str);
	tenth_str = "zero,one,two,three,four,five,six,seven,eight,nine";
	zero_to_nine = ft_split(tenth_str, ',');
	// display_str_array(zero_to_nine);
	if (ft_strlen(str) < 3)
		return (-1);
	i = 0;
	digit = -1;
	while (zero_to_nine[i])
	{
		if (ft_strnstr(str, zero_to_nine[i], ft_strlen(zero_to_nine[i])))
		{
			digit = i;
			break ;
		}
		i++;
	}
	return (digit);
}
