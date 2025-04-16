/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:54:49 by lusimon           #+#    #+#             */
/*   Updated: 2024/11/12 16:18:35 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	unsigned_int(unsigned int u);
int	print_pointer(void *ptr);
int	print_hexa_up(unsigned int n);
int	hexa_ptr(uintptr_t n);
int	print_hexa_low(unsigned int n);
int	print_digit(int n);
int	print_char(int c);
int	print_string(char *str);

#endif // LIBFTPRINTF_H