/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:56:40 by lusimon           #+#    #+#             */
/*   Updated: 2024/10/21 16:28:53 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	leng;

	leng = 0;
	while (s[leng] != '\0')
	{
		leng++;
	}
	write(fd, s, leng);
	if (s[leng] == '\0')
	{
		write(fd, "\n", 1);
	}
}
// int main()
// {
//     char s[] = "Lucie";
//     ft_putendl_fd(s, 1);
// }
