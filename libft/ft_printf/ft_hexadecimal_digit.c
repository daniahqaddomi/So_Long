/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal_digit.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniah <daniah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 06:23:05 by daniah            #+#    #+#             */
/*   Updated: 2024/11/10 06:29:39 by daniah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexadecimal_digit(unsigned int digit, int lowercase)
{
	char	hex_char;

	if (digit < 10)
	{
		hex_char = digit + '0';
	}
	else
	{
		if (lowercase)
			hex_char = digit - 10 + 'a';
		else
			hex_char = digit - 10 + 'A';
	}
	return (ft_putchar(hex_char));
}
