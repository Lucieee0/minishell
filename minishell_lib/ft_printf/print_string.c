/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:13:28 by lusimon           #+#    #+#             */
/*   Updated: 2024/11/12 16:13:49 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
		str = "(null)";
	while (str[i] != '\0')
	{
		count += print_char((int)str[i]);
		if (count < 0)
			return (-1);
		i++;
	}
	return (i);
}
