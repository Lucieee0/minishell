/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:11:15 by lusimon           #+#    #+#             */
/*   Updated: 2024/10/28 14:44:03 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

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

// int main()
// {
//     const char *original = "Lucie";
//     char *copy;
//     copy = ft_strdup(original);

//     printf("original %s\n", original);
//     printf("duplicate %s\n", copy);
//     free(copy);
//     return 0; 
// }
