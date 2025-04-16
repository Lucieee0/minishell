/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:33:47 by lusimon           #+#    #+#             */
/*   Updated: 2024/10/28 12:43:40 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	to_find;
	unsigned char	*to_look;
	size_t			i;

	to_find = (unsigned char)c;
	to_look = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*to_look == to_find)
		{
			return ((void *)to_look);
		}
		to_look++;
		i++;
	}
	return (NULL);
}
// int main()
// {
// char look_in[10] = "Hello";
// unsigned char to_find = 'e';

// printf("Before memchr: %s\n", look_in);

// char *result = ft_memchr(look_in, to_find, 5);
// printf("%s\n",result);
// return 0;
// }
