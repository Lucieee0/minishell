/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:57:34 by lusimon           #+#    #+#             */
/*   Updated: 2024/10/21 11:53:32 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*zero;
	size_t			i;

	zero = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		zero[i] = 0;
		i++;
	}
}

// int main()
// {
// char to_be_replaced[] = "Hello";
// printf("Before bzero: %s\n", to_be_replaced);
// ft_bzero(to_be_replaced, sizeof(to_be_replaced) -1);
// printf("After bzero: %s\n", to_be_replaced);
// }