/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day-06-utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 06:48:01 by bebrandt          #+#    #+#             */
/*   Updated: 2023/12/06 07:52:21 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "days.h"

int	*parse_input_d6(char *line, int *len)
{
	int		i;
	char	*str;
	char	**str_str;
	int		*tab;

	i = 0;
	while (!ft_isdigit(line[i]))
		i++;
	*len = ft_strlen(line);
	while (!ft_isdigit(line[*len]))
		*len -= 1;
	str = ft_substr(line, i, *len);
	str_str = ft_split(str, ' ');
	free(str);
	i = 0;
	while (str_str[i])
		i++;
	*len = i;
	tab = convert_strtab_to_inttab(str_str, i);
	return (tab);
}

long	parse_input_d6_p2(char *line)
{
	int		i;
	int		len;
	char	*str;
	long	num;

	i = 0;
	len = 0;
	while(line[i])
	{
		if (ft_isdigit(line[i]))
			len++;
		i++;
	}
	str = ft_calloc(len, sizeof(char) + 1);
	i = 0;
	len = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
			str[len++] = line[i];
		i++;
	}
	str[len] = '\0';
	num = ft_atoi_long(str);
	free(str);
	return (num);
}

int	*convert_strtab_to_inttab(char **str, int size)
{
	int		i;
	int		*tab;

	i = 0;
	tab = ft_calloc(size, sizeof(int));
	while (i < size)
	{
		tab[i] = ft_atoi(str[i]);
		i++;
	}
	return (tab);
}
