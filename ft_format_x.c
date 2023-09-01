/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:31:07 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/06/02 10:24:41 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hex(unsigned int nbr, char *base)
{
	if (nbr > 15)
	{
		ft_print_hex(nbr / 16, base);
		ft_print_hex(nbr % 16, base);
	}
	else
		ft_format_c(base[nbr]);
}

int	ft_format_x(unsigned int nbr, char specifier)
{
	int				len;
	char			*lower_case;
	char			*upper_case;

	len = 0;
	if (nbr == 0)
		return (len += ft_format_c('0'));
	lower_case = "0123456789abcdef";
	upper_case = "0123456789ABCDEF";
	if (specifier == 'x')
		ft_print_hex(nbr, lower_case);
	if (specifier == 'X')
		ft_print_hex(nbr, upper_case);
	while (nbr != 0)
	{
		nbr /= 16;
		len++;
	}
	return (len);
}
