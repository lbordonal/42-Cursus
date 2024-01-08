/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:48:02 by lbordona          #+#    #+#             */
/*   Updated: 2022/11/22 15:15:07 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *input, ...)
{
	int		i;
	int		bytes;
	va_list	args;

	i = 0;
	bytes = 0;
	va_start(args, input);
	while (input[i])
	{
		if (input[i] == '%')
		{
			bytes += check_argument(args, input[i + 1]);
			i++;
		}
		else
			bytes += ft_putchar_count(input[i]);
		i++;
	}
	va_end(args);
	return (bytes);
}
