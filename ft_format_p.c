/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:02:21 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/06/01 16:58:13 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_address(unsigned long num, char *base)
{
	if (num > 15)
	{
		ft_print_address(num / 16, base);
		ft_print_address(num % 16, base);
	}
	else
		ft_format_c(base[num]);
}

int	ft_format_p(unsigned long ptr_value)
{
	int		len;
	char	*base;

	len = 0;
	len += write (1, "0x", 2);
	if (ptr_value == 0)
		return (len += ft_format_c('0'));
	base = "0123456789abcdef";
	ft_print_address(ptr_value, base);
	while (ptr_value != 0)
	{
		ptr_value /= 16;
		len++;
	}
	return (len);
}
