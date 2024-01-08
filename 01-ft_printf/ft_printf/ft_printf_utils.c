/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:32:04 by lbordona          #+#    #+#             */
/*   Updated: 2022/11/22 15:15:11 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	check_argument(va_list args, const char type)
{
	int	length;

	length = 0;
	if (type == 'c')
		length += ft_putchar_count(va_arg(args, int));
	else if (type == 's')
		length += ft_putstr_count(va_arg(args, char *));
	else if (type == 'p')
		length += ft_putptr_count(va_arg(args, unsigned long long));
	else if (type == 'd' || type == 'i')
		length += ft_putnbr_count(va_arg(args, int));
	else if (type == 'u')
		length += ft_put_unsignedint_count(va_arg(args, unsigned int));
	else if (type == 'x' || type == 'X')
		length += ft_puthex_count(va_arg(args, unsigned int), type);
	else if (type == '%')
		length += ft_putpercent();
	return (length);
}
