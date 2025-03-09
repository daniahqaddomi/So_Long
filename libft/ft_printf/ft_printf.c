/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dqaddomi <dqaddomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:24:14 by dqaddomi          #+#    #+#             */
/*   Updated: 2024/11/10 16:28:25 by dqaddomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printfcheck(char s, va_list args)
{
	int	count;

	count = 0;
	if (s == 's')
		count += ft_putstring(va_arg(args, char *));
	else if (s == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (s == 'd' || s == 'i')
		count += ft_putnumber(va_arg(args, int));
	else if (s == 'u')
		count += ft_put_unsigned_number(va_arg(args, unsigned int));
	else if (s == 'x')
		count += ft_put_hexadecimal(va_arg(args, unsigned int), 1);
	else if (s == 'X')
		count += ft_put_hexadecimal(va_arg(args, unsigned int), 0);
	else if (s == 'p')
		count += ft_putpointer(va_arg(args, void *));
	else if (s == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			i++;
			count += ft_printfcheck(string[i], args);
		}
		else
		{
			count += ft_putchar(string[i]);
		}
		i++;
	}
	va_end(args);
	return (count);
}
