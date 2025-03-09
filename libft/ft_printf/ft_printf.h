/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniah <daniah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 13:32:31 by dqaddomi          #+#    #+#             */
/*   Updated: 2024/11/10 06:28:42 by daniah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int	ft_printf(const char *string, ...);
int	ft_putchar(char c);
int	ft_putstring(char *str);
int	ft_putnumber(int num);
int	ft_put_unsigned_number(unsigned int num);
int	ft_put_hexadecimal(unsigned long num, int lower);
int	ft_hexadecimal_digit(unsigned int digit, int lowercase);
int	ft_putpointer(void *ptr);

#endif
