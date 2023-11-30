/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:25:52 by bebrandt          #+#    #+#             */
/*   Updated: 2023/10/31 19:00:39 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
Convert n in hexadecimal number string and print it.
Flag '+' and ' ' are NOT supported.
*/
int	ft_print_hex(unsigned int n, t_printf_lst *lst)
{
	char	*hex_nbr;

	if (lst->precision == 0 && n == 0)
		return (ft_print_zero_precision_fd(lst, 1));
	hex_nbr = ft_itoa_hex((long unsigned int)n);
	return (ft_print_hex_format(hex_nbr, lst));
}
