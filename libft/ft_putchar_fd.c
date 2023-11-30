/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 09:26:08 by bebrandt          #+#    #+#             */
/*   Updated: 2023/10/24 10:35:10 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Write 'c' pn the file descriptor 'fd'
*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
