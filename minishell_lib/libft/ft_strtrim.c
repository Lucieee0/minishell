/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:33:11 by lusimon           #+#    #+#             */
/*   Updated: 2024/10/24 12:01:25 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

static int	find_char(char const *string, char c)
{
	int	i;

	i = 0;
	if (!string)
		return (0);
	while (string[i] != '\0')
	{
		if (string[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*give_start(char const *s, char const *check)
{
	int	i;

	i = 0;
	if (!s || !check)
		return (NULL);
	while (s[i] != '\0')
	{
		if (!find_char(check, s[i]))
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

static char	*give_end(char const *s, char const *check)
{
	int	i;

	i = 0;
	if (!s || !check)
		return (NULL);
	while (s[i] != '\0')
		i++;
	i = i - 1;
	while (i > 0)
	{
		if (!find_char(check, s[i]))
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}

static char	*create_empty_string(void)
{
	char	*new_string;

	new_string = malloc(1);
	if (new_string)
		new_string[0] = '\0';
	return (new_string);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*new_string;
	int		len;
	int		i;

	if (!s1 || !set)
		return (NULL);
	start = give_start(s1, set);
	end = give_end(s1, set);
	if (!start || !end || start > end)
		return (create_empty_string());
	len = end - start + 1;
	new_string = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_string)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_string[i] = start[i];
		i++;
	}
	new_string[len] = '\0';
	return (new_string);
}

// #include <stdio.h>
// int main() 
// {
//     char trim[] = "|||000Je m'en vais222";
//     char to_remove[] = "|02";
//     char *result;
//     result = ft_strtrim(trim, to_remove);
//     printf("Trimmed result: '%s'\n", result);
//     free(result);
//     return 0;
// }
