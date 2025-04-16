/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 13:29:39 by lusimon           #+#    #+#             */
/*   Updated: 2024/10/27 15:10:13 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	*ft_calloc(size_t count, size_t size)
// {
// 	void			*table;
// 	size_t			i;
// 	size_t			total_size;
// 	unsigned char	*p;

// 	i = 0;
// 	total_size = count * size;
// 	table = malloc(total_size);
// 	if (table == NULL)
// 	{
// 		return (NULL);
// 	}
// 	p = table;
// 	while (i < total_size)
// 	{
// 		p[i] = 0;
// 		i++;
// 	}
// 	return (table);
// }

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

static int	count_words(const char *s, char c)
{
	int	inside_word;
	int	count;
	int	i;

	i = 0;
	count = 0;
	inside_word = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			inside_word = 0;
			i++;
		}
		else if (s[i] != c && inside_word == 0)
		{
			inside_word = 1;
			count++;
			i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*substring(const char *string, int start, int end)
{
	char	*sub;
	int		i;

	i = 0;
	sub = malloc((end - start + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	while (start < end)
		sub[i++] = string[start++];
	sub[i] = '\0';
	return (sub);
}

static void	*free_substring(char **st, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(st[i]);
		i++;
	}
	free(st);
	return (NULL);
}

static void	initiate(size_t *i, int *j, int *word_start)
{
	*i = 0;
	*j = 0;
	*word_start = -1;
}

char	**ft_split(const char *s, char c)
{
	size_t	i;
	int		j;
	int		word_start;
	char	**result;

	initiate(&i, &j, &word_start);
	result = ft_calloc((count_words(s, c) + 1), sizeof(char *));
	if (!result)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && word_start < 0)
			word_start = i;
		else if (((s[i] == c || i == ft_strlen(s)) && word_start != -1))
		{
			result[j] = substring(s, word_start, i);
			if (!result[j])
				return (free_substring(result, j));
			word_start = -1;
			j++;
		}
		i++;
	}
	result[j] = NULL;
	return (result);
}
// int main()
// {
// 	int i = 0;
// 	char *se = "lorem ipsum dolor sit amet, consectetur";
// 	char **resultat = ft_split(se, 'i');
// 	int word_count;
// 	word_count = count_words(se, 'i');
// 	while (i <= word_count) 
// 	{
// 	printf("%s\n", resultat[i]);
// 	i++;
// 	}
// }
