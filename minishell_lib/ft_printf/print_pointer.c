/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:03:49 by lusimon           #+#    #+#             */
/*   Updated: 2024/11/12 16:05:41 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(void *ptr)
{
	int			count;
	uintptr_t	adress;

	count = 0;
	adress = (uintptr_t)ptr;
	if (ptr == NULL)
	{
		if (print_string("0x0") == -1)
			return (-1);
		return (3);
	}
	if (ptr == (void *)0)
	{
		count += print_string("0x10");
		if (count < 0)
			return (-1);
		return (hexa_ptr(adress) + count);
	}
	else
	{
		count += print_string("0x");
		if (count < 0)
			return (-1);
		return (hexa_ptr(adress) + count);
	}
}
