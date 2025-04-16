/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:41:41 by lusimon           #+#    #+#             */
/*   Updated: 2024/10/21 16:26:49 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	leng;

	leng = 0;
	while (s[leng] != '\0')
	{
		leng++;
	}
	write(fd, s, leng);
}
// int main()
// {
//     char s[] = "Lucie";
//     ft_putstr_fd(s, 1);
// }
