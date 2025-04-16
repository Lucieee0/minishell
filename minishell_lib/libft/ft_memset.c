/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:42:24 by lusimon           #+#    #+#             */
/*   Updated: 2024/10/21 11:53:12 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	value;
	unsigned char	*mem;

	i = 0;
	value = (unsigned char)c;
	mem = (unsigned char *)b;
	while (i < len)
	{
		mem[i] = value;
		i++;
	}
	return ((void *)b);
}

// int main()
// {
// char to_be_replaced[] = "Hello";
// unsigned char use = 'e';

// printf("Before ft_memset: %s\n", to_be_replaced);

// ft_memset(to_be_replaced, use, sizeof(to_be_replaced) - 1);

// printf("After ft_memset: %s\n", to_be_replaced);

// return 0;
// }