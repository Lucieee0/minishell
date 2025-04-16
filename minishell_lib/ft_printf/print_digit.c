/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:12:17 by lusimon           #+#    #+#             */
/*   Updated: 2024/11/12 16:12:44 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_digit(int n)
{
	long	nbr;
	int		count;

	count = 0;
	nbr = n;
	if (nbr < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		count = 1;
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		count += print_digit(nbr / 10);
		if (count < 0)
			return (-1);
	}
	count += print_char((nbr % 10) + 48);
	if (count < 0)
		return (-1);
	return (count);
}
