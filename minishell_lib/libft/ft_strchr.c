/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:17:05 by lusimon           #+#    #+#             */
/*   Updated: 2024/10/28 12:28:35 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if ((char)c == '\0')
	{
		while (*s != (char)c)
			s++;
		return ((char *)s);
	}
	else
	{
		while (*s != '\0')
		{
			if (*s == (char)c)
				return ((char *)s);
			s++;
		}
	}
	return (NULL);
}
// int main()
// {
//     const char *test = "Lucie";
//     int to_be_found = 'u';

//     char *found = ft_strchr(test, to_be_found);
//     if (found)
//     {
//         printf("Found '%c' at adress: %p\n", *found, (void *)found);
//     }
//     else
//     {
//         printf("Character not found.\n");
//     }
//     return 0;
// }
