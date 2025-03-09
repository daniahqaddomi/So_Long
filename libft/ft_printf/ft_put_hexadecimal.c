/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexadecimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dqaddomi <dqaddomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 04:11:45 by daniah            #+#    #+#             */
/*   Updated: 2024/11/10 16:25:02 by dqaddomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hexadecimal(unsigned long num, int lower)
{
	int	count;

	count = 0;
	if (num == 0)
	{
		count += ft_putchar('0');
		return (count);
	}
	if (num >= 16)
	{
		count += ft_put_hexadecimal(num / 16, lower);
	}
	count += ft_hexadecimal_digit(num % 16, lower);
	return (count);
}
