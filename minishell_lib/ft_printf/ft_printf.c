/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:19:02 by lusimon           #+#    #+#             */
/*   Updated: 2024/11/12 16:16:54 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_format(char type, va_list ap)
{
	int	count;

	count = 0;
	if (type == 'c')
		count += print_char(va_arg(ap, int));
	else if (type == 's')
		count += print_string(va_arg(ap, char *));
	else if (type == 'd' || type == 'i')
		count += print_digit(va_arg(ap, int));
	else if (type == 'u')
		count += unsigned_int(va_arg(ap, unsigned int));
	else if (type == 'p')
		count += print_pointer(va_arg(ap, void *));
	else if (type == 'x')
		count += print_hexa_low(va_arg(ap, unsigned int));
	else if (type == 'X')
		count += print_hexa_up(va_arg(ap, unsigned int));
	else
		count += write(1, &type, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			count;
	int			i;

	count = 0;
	i = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			count += print_format((format[++i]), ap);
			if (count < 0)
				return (-1);
		}
		else
			count += print_char((int)format[i]);
		if (count < 0)
			return (-1);
		i++;
	}
	va_end(ap);
	return (count);
}

// #include <stdio.h>

// int main	(void)
// {
// 	int	return_1;
// 	int	return_2;

// 	return_1 = ft_printf("%u\n", -10);
// 	return_2 = printf("%u\n", -10);
// 	printf("%d, %d\n", return_1, return_2);
// 	return (0);
// }

// int main (void)
// {
// 	ft_printf(" %c %c %c \n", '0', 0, '1');
// 	printf(" %c %c %c \n", '0', 0, '1');
// 	// ft_printf(" %c %c %c ", '2', '1', 0);
// 	// ft_printf(" %c %c %c ", 0, '1', '2');
// 	return (0);
// }

// int main	(void)
// {
// 	int return_1;
// 	int return_2;
// 	return_1 = ft_printf("%p\n", (void *)-14523);
// 	return_2 = printf("%p\n", (void *)-14523);
// 	printf("%d %d\n", return_1, return_2);
// 	return (0);
// }

// int main	(void)
// {
// 	int return_1;
// 	int return_2;
// 	return_1 = ft_printf("%p %p\n", "", NULL);
// 	return_2 = printf("%p %p\n", "", NULL);
// 	printf("%d %d\n", return_1, return_2);
// 	return (0);
// }

// int main	(void)
// {
// 	int return_1;
// 	int return_2;
// 	return_1 = ft_printf("\001\002\007\v\010\f\r\n");
// 	return_2 = printf("\001\002\007\v\010\f\r\n");
// 	printf("%d %d\n", return_1, return_2);
// 	return (0);
// }

// int main	(void)
// {
// 	int return_1;
// 	int return_2;
// 	return_1 = ft_printf("%p\n", "");
// 	return_2 = printf("%p\n", "");
// 	printf("%d %d\n", return_1, return_2);
// 	return (0);
// }

// int	main(void)
// {
// 	int counte;
// 	int nbr = 42;
// 	void *test = &nbr;
// 	ft_printf("Hello toi %s vas-tu %c %d %x %p\n", "comment", 'b', 4, 10, test);
// 	return (ft_printf("%p", (void *)-14523));
// 	// return (printf("%p", (void *)-14523));
// }
