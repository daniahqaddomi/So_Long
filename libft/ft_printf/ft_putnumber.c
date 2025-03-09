/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnumber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniah <daniah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 04:10:42 by daniah            #+#    #+#             */
/*   Updated: 2024/11/10 06:29:08 by daniah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnumber(int num)
{
	int	count;

	count = 0;
	if (num == -2147483648)
	{
		return (ft_putstring("-2147483648"));
	}
	if (num < 0)
	{
		count += ft_putchar('-');
		num = -num;
	}
	if (num >= 10)
	{
		count += ft_putnumber(num / 10);
	}
	count += ft_putchar((num % 10) + '0');
	return (count);
}
