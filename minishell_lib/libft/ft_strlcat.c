/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:41:39 by lusimon           #+#    #+#             */
/*   Updated: 2024/10/22 16:33:15 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*source;
	size_t	len_dst;
	size_t	len_src;
	size_t	result;
	size_t	i;

	result = 0;
	i = 0;
	source = (char *)src;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(source);
	if (dstsize > len_dst)
		result = len_src + len_dst;
	else
		result = len_src + dstsize;
	while (src[i] != '\0' && (len_dst + 1) < dstsize)
	{
		dst[len_dst] = src[i];
		len_dst++;
		i++;
	}
	dst[len_dst] = '\0';
	return (result);
}

//We are doing 2 different things at the same time
//returning the lengh
//which is always the lengh of the source + 
//(dstsize if dst > dstsize or dst if dst <dstsize)
