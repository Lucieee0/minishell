/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:29:47 by lusimon           #+#    #+#             */
/*   Updated: 2024/10/22 17:01:40 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;

	count = 0;
	while (count < n && (*s1 != '\0' || *s2 != '\0'))
	{
		if ((unsigned char)*s1 != (unsigned char)*s2)
		{
			return ((unsigned char)*s1 - (unsigned char)*s2);
		}
		else
		{
			s1++;
			s2++;
			count++;
		}
	}
	return (0);
}
// int main()
// {
//     const char *r1 = "Lacue";
//     const char *r2 = "Lacuf";

//     int box = ft_strncmp(r1, r2, 4);
//     printf("%d\n", box);
//     return 0;
// }

/* What is unsigned characters????*/
