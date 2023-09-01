/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:22:26 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/05/24 15:45:46 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_u(unsigned int nbr)
{
	int				base;
	int				len;
	unsigned int	num;

	num = nbr;
	if (num < 0)
		return (-1);
	base = 1;
	len = 0;
	while ((num / base) > 9)
		base *= 10;
	while (base != 0)
	{
		len += ft_format_c((num / base) + '0');
		num %= base;
		base /= 10;
	}
	return (len);
}
