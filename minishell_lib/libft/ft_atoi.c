/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:55:13 by lusimon           #+#    #+#             */
/*   Updated: 2024/10/24 09:53:05 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	integer;
	int	sign;

	integer = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
	{
		str++;
	}
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
		{
			sign = -sign;
		}
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		integer = integer * 10 + (*str - 48);
		str++;
	}
	return (integer * sign);
}
// int main()
// {
// 	char	str[] = " ---+---+1234ab567";
// 	int result = ft_atoi(str);
// 	int result_2 = atoi(str);
// 	printf("%i\n", result);
// 	printf("%i\n", result_2);
// }
