/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:04:37 by lbordona          #+#    #+#             */
/*   Updated: 2022/11/22 15:15:29 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	main(void)
{
	char			a;
	char			*str;
	int				i;
	unsigned int	ui;
	unsigned int	hex;

	a = 'a';
	str = "Lucas";
	i = 100;
	ui = 4294967295;
	hex = 45632123;
	//%c:
	ft_printf("%s", "Char:");
	printf("\n");
	ft_printf("%s", "ft_printf: ");
	ft_printf("%c", a);
	ft_printf("%s", " | printf: ");
	printf("%c\n\n", a);
	//%s
	ft_printf("%s", "String:");
	printf("\n");
	ft_printf("%s", "ft_printf: ");
	ft_printf("%s", str);
	ft_printf("%s", " | printf: ");
	printf("%s\n\n", str);
	//%p
	ft_printf("%s", "Pointer:");
	printf("\n");
	ft_printf("%s", "ft_printf: ");
	ft_printf("%p", &i);
	ft_printf("%s", " | printf: ");
	printf("%p\n\n", &i);
	//%d
	ft_printf("%s", "Decimal:");
	printf("\n");
	ft_printf("%s", "ft_printf: ");
	ft_printf("%d", i);
	ft_printf("%s", " | printf: ");
	printf("%d\n\n", i);
	//%i
	ft_printf("%s", "Integer:");
	printf("\n");
	ft_printf("%s", "ft_printf: ");
	ft_printf("%i", i);
	ft_printf("%s", " | printf: ");
	printf("%i\n\n", i);
	//%u
	ft_printf("%s", "Unsigned int:");
	printf("\n");
	ft_printf("%s", "ft_printf: ");
	ft_printf("%u", ui);
	ft_printf("%s", " | printf: ");
	printf("%u\n\n", ui);
	//%x
	ft_printf("%s", "Hexadecimal lowercase:");
	printf("\n");
	ft_printf("%s", "ft_printf: ");
	ft_printf("%x", hex);
	ft_printf("%s", " | printf: ");
	printf("%x\n\n", hex);
	//%X
	ft_printf("%s", "Hexadecimal uppercase:");
	printf("\n");
	ft_printf("%s", "ft_printf: ");
	ft_printf("%X", hex);
	ft_printf("%s", " | printf: ");
	printf("%X\n\n", hex);
	//%%
	ft_printf("%s", "% Sign:");
	printf("\n");
	ft_printf("%s", "ft_printf: ");
	ft_printf("%%");
	ft_printf("%s", " | printf: ");
	printf("%%\n\n");
	return (0);
}
