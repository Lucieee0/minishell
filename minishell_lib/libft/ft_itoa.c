/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:44:33 by lusimon           #+#    #+#             */
/*   Updated: 2024/10/24 15:46:32 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

static int	count_digit_sign(int nbr)
{
	int	count;

	count = 0;
	if (nbr <= 0)
	{
		count++;
		nbr = nbr * (-1);
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		count ++;
	}
	return (count);
}

static char	*ft_strdup(const char *s1)
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

char	*ft_itoa(int n)
{
	char	*new_string;
	int		len;

	len = count_digit_sign(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	new_string = malloc((sizeof(char)) * (len + 1));
	if (!new_string)
		return (0);
	if (n < 0)
	{
		new_string[0] = '-';
		n = -n;
	}
	if (n == 0)
		new_string[0] = '0';
	new_string[len--] = '\0';
	while (n)
	{
		new_string[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (new_string);
}
// int main()
// {
// 	char *result;

// 	result = ft_itoa(1263);
// 	printf("%s\n", result);
// 	free(result);
// 	return (0);
// }
