/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:11:11 by lusimon           #+#    #+#             */
/*   Updated: 2024/10/28 12:31:19 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (!dst && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

// void	ft_bzero(void *s, size_t n)
// {
// 	unsigned char	*zero;
// 	size_t			i;

// 	zero = (unsigned char *)s;
// 	i = 0;
// 	while (i < n)
// 	{
// 		zero[i] = 0;
// 		i++;
// 	}
// }
// size_t	ft_strlen(const char	*s)
// {
// 	int	length;

// 	length = 0;
// 	while (s[length] != '\0')
// 	{
// 		length++;
// 	}
// 	return (length);
// }

// #include <stdio.h>
// int main()
// {
// 	char src[] = "Hello, World!";
// 	char dest[20];

// 	ft_bzero(dest, sizeof(dest));
// 	ft_memcpy(dest, src, (ft_strlen(src) + 1));
// 	printf("Source: %s\n", src);
// 	printf("Destination: %s\n", dest);
// }
