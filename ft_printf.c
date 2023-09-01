/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:55:20 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/06/02 10:10:08 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_eval_format(va_list args, const char *format, int i)
{
	int	printed_chars;

	printed_chars = 0;
	if (format[i] == 'c')
		printed_chars = ft_format_c(va_arg(args, int));
	else if (format[i] == 's')
		printed_chars = ft_format_s(va_arg(args, char *));
	else if (format[i] == 'p')
		printed_chars = ft_format_p(va_arg(args, unsigned long));
	else if (format[i] == 'd' || format[i] == 'i')
		printed_chars = ft_format_i_d(va_arg(args, int));
	else if (format[i] == 'u')
		printed_chars = ft_format_u(va_arg(args, unsigned int));
	else if (format[i] == 'x' || format[i] == 'X')
		printed_chars = ft_format_x(va_arg(args, unsigned long), format[i]);
	else if (format[i] == '%')
		printed_chars = ft_format_c('%');
	return (printed_chars);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		printed_chars;
	va_list	args;

	va_start(args, format);
	if (!format)
		return (-1);
	i = 0;
	printed_chars = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			printed_chars += ft_eval_format(args, format, i);
		}
		else
			printed_chars += ft_format_c(format[i]);
		i++;
	}
	va_end(args);
	return (printed_chars);
}
