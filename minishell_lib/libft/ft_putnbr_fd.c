/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:06:00 by lusimon           #+#    #+#             */
/*   Updated: 2024/10/21 16:27:59 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar('-', fd);
		nbr = -nbr;
	}
	if (nbr < 10)
	{
		ft_putchar(nbr + 48, fd);
	}
	else
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putchar(nbr % 10 + 48, fd);
	}
}
// int main()
// {
// 	ft_putnbr_fd(-2147483648, 1);
// }
