/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:07:11 by lusimon           #+#    #+#             */
/*   Updated: 2024/11/12 16:23:00 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hexa_up(unsigned int n)
{
	long	nbr;
	int		count;
	char	*symbols;

	symbols = "0123456789ABCDEF";
	count = 0;
	nbr = (unsigned long)n;
	if (nbr == 0)
	{
		count += print_char('0');
		if (count < 0)
			return (-1);
		return (count);
	}
	if (nbr >= 16)
	{
		count += print_hexa_up(nbr / 16);
		if (count < 0)
			return (-1);
	}
	count += print_char(symbols[nbr % 16]);
	if (count < 0)
		return (-1);
	return (count);
}
