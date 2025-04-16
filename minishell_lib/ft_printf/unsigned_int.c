/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:58:39 by lusimon           #+#    #+#             */
/*   Updated: 2024/11/12 16:02:31 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	unsigned_int(unsigned int u)
{
	int	count;

	count = 0;
	if (u >= 10)
	{
		count += unsigned_int(u / 10);
		if (count < 0)
			return (-1);
	}
	count += print_char((u % 10) + '0');
	if (count < 0)
		return (-1);
	return (count);
}
