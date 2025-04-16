/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:23:10 by lusimon           #+#    #+#             */
/*   Updated: 2024/10/21 09:55:08 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

// int main()
// {
//     char test1 = 'A';
//     char test2 = '@';

//     int box = ft_isalpha(test1);
//     int box_2 = ft_isalpha(test2);
//     printf("%d\n", box);
//     printf("%d\n", box_2);
//     return 0;
// }