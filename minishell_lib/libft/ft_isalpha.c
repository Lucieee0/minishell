/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:13:12 by lusimon           #+#    #+#             */
/*   Updated: 2024/10/21 09:55:22 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
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
