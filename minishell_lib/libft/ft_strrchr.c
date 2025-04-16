/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:24:57 by lusimon           #+#    #+#             */
/*   Updated: 2024/10/28 14:44:07 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		count;
	char	*res;

	count = 0;
	res = (char *)s;
	while (res[count] != '\0')
		count++;
	while (count >= 0)
	{
		if (res[count] == (char)c)
		{
			return ((char *)s + count);
		}
		count--;
	}
	return (NULL);
}
// int main()
// {
//     const char *test = "Lucue";
//     int to_be_found = 'u';

//     char *found = ft_strrchr(test, to_be_found);
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
