/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:34:24 by lusimon           #+#    #+#             */
/*   Updated: 2024/10/28 12:26:26 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;

	if (!dst && !src)
		return (0);
	i = 0;
	if (dst > src && dst < src + len)
	{
		i = len - 1;
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((const unsigned char *)src)[i];
			i--;
		}
	}
	else
	{
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((const unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}

// #include <stdio.h>
// int main()
// {
// 	char overlap[] = "overlap Testtttt";
// 	printf("Before %s\n", overlap);
// 	ft_memmove(overlap + 8, overlap, 8);
// 	printf("After %s\n", overlap);
//     return 0;
// }
