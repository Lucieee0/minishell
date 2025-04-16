/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:48:17 by lusimon           #+#    #+#             */
/*   Updated: 2024/12/09 11:09:30 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char	*s)
{
	int	length;

	length = 0;
	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}

int	strlen_line(const char	*s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		i ++;
	}
	if (s[i] == '\n')
		i++;
	return (i);
}

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

char	*ft_strdup(const char *s1)
{
	char	*new;
	int		i;

	i = 0;
	while (s1[i] != '\0')
	{
		i++;
	}
	new = malloc(sizeof(char) * (i + 1));
	if (new == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

int	check_end_line(char **storage)
{
	int	i;

	i = 0;
	if (!storage || !*storage)
		return (-1);
	while ((*storage)[i])
	{
		if ((*storage)[i] == '\n' || ((*storage)[i] == '\0'))
			return (1);
		i++;
	}
	return (0);
}

