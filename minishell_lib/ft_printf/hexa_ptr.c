/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:09:01 by lusimon           #+#    #+#             */
/*   Updated: 2024/11/12 16:09:28 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexa_ptr(uintptr_t n)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	count = 0;
	if (n >= 16)
	{
		count += hexa_ptr(n / 16);
		if (count < 0)
			return (-1);
	}
	count += print_char(symbols[n % 16]);
	if (count < 0)
		return (-1);
	return (count);
}
