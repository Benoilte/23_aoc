/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 09:04:16 by bebrandt          #+#    #+#             */
/*   Updated: 2023/10/31 15:07:48 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Convert the unsigned int 'n' into its corresponding hex nbr 
and writes it on the file descriptor 'fd'
*/
void	ft_putnbr_hex_fd(unsigned int uint, int fd)
{
	char	*str_hex;

	str_hex = "0123456789abcdef";
	if (uint > 15)
		ft_putnbr_hex_fd((uint / 16), fd);
	ft_putchar_fd(str_hex[uint % 16], fd);
}
