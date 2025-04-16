/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:58:40 by lusimon           #+#    #+#             */
/*   Updated: 2024/10/24 15:23:08 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*table;
	size_t			i;
	size_t			total_size;
	unsigned char	*p;

	i = 0;
	total_size = count * size;
	table = malloc(total_size);
	if (table == NULL)
	{
		return (NULL);
	}
	p = table;
	while (i < total_size)
	{
		p[i] = 0;
		i++;
	}
	return (table);
}
// int main()
// {
//     int *ptr;

//     ptr = (int *)ft_calloc(5, sizeof(int));

//     free (ptr);
//     return 0;
// }
