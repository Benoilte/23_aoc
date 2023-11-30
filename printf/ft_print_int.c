/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:22:37 by bebrandt          #+#    #+#             */
/*   Updated: 2023/10/31 18:47:47 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
Print intege in base 10 with its corresponding flag, width and precision.
only flag '#' is NOT supported.
*/
int	ft_print_int(int n, t_printf_lst *lst)
{
	return (ft_print_decimal(n, lst));
}
