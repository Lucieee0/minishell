/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:49:55 by lusimon           #+#    #+#             */
/*   Updated: 2024/10/21 12:13:59 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*compared;
	const unsigned char	*compare_with;
	size_t				i;

	i = 0;
	compared = (const unsigned char *)s1;
	compare_with = (const unsigned char *)s2;
	while (i < n)
	{
		if (compared[i] != compare_with[i])
		{
			return (compared[i] - compare_with[i]);
		}
		i++;
	}
	return (0);
}
// int main()
// {
//     char string1[] = "Hello";
//     char string2[] = "Hemmo";
//     int box;
//     box = ft_memcmp(string1, string2, 3);
//     printf("%d\n", box);
//     return 0;
// }
