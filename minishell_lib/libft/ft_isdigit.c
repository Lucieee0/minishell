/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:19:37 by lusimon           #+#    #+#             */
/*   Updated: 2024/10/21 09:55:40 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

// int main()
// {
//     char test1 = 'A';
//     char test2 = '0';

//     int box = ft_isdigit(test1);
//     int box_2 = ft_isdigit(test2);
//     printf("%d\n", box);
//     printf("%d\n", box_2);
//     return 0;
// }