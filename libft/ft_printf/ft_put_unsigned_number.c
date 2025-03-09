/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_number.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniah <daniah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 06:20:58 by daniah            #+#    #+#             */
/*   Updated: 2024/11/10 06:29:13 by daniah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_unsigned_number(unsigned int num)
{
	int	count;

	count = 0;
	if (num == 0)
	{
		return (ft_putchar('0'));
	}
	if (num >= 10)
	{
		count += ft_put_unsigned_number(num / 10);
	}
	count += ft_putchar((num % 10) + '0');
	return (count);
}
