/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:34:19 by lusimon           #+#    #+#             */
/*   Updated: 2024/10/24 10:16:31 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*new;
	size_t	len_1;
	size_t	len_2;
	int		f;

	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	if (!s1 && !s2)
		return (NULL);
	new = malloc((len_1 + len_2 + 1) * sizeof(char));
	if (!new)
	{
		return (NULL);
	}
	f = 0;
	while (*s1)
		new[f++] = *s1++;
	while (*s2)
		new[f++] = *s2++;
	new[f] = '\0';
	return (new);
}
// int main()
// {
// 	char *lu = "top";
// 	char *ci = "la";
// 	char *result;

// 	result = ft_strjoin(lu, ci);
// 	printf("%s\n", result);

// 	free(result);
// 	return 0;
// }
