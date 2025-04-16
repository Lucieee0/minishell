/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:56:18 by lusimon           #+#    #+#             */
/*   Updated: 2024/10/28 12:46:41 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

static size_t	ft_strlenn(const char	*s)
{
	int	length;

	length = 0;
	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char			*new_string;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	new_string = malloc(sizeof(char) * (ft_strlenn(s) + 1));
	if (!new_string)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		new_string[i] = f(i, s[i]);
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
