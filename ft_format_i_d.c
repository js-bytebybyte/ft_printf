/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_i_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:37:08 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/05/26 12:07:02 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_i_d(int nbr)
{
	int	len;
	int	base;

	len = 0;
	base = 1;
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nbr < 0)
	{
		len += ft_format_c('-');
		nbr = nbr * (-1);
	}
	while ((nbr / base) > 9)
		base *= 10;
	while (base != 0)
	{
		len += ft_format_c((nbr / base) + '0');
		nbr %= base;
		base /= 10;
	}
	return (len);
}
