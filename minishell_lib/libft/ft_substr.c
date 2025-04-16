/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:04:47 by lusimon           #+#    #+#             */
/*   Updated: 2024/10/28 12:30:10 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		substring = (char *)malloc(sizeof(char));
		if (substring != NULL)
			substring[0] = '\0';
		return (substring);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	substring = (char *)malloc((len + 1) * sizeof (char));
	if (substring == NULL)
		return (NULL);
	while (s[start + i] != '\0' && i < len)
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}

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

// int main()

// {
// 	char	*test = "Lucie";
// 	char	*result;

// 	result = ft_substr(test, 3, 8);
// 	printf("%s\n", result);

// 	free(result);
// 	return (0);
// }
