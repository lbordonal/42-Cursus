/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:42:59 by lbordona          #+#    #+#             */
/*   Updated: 2022/11/22 15:14:48 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <strings.h>
# include <stddef.h>
# include <ctype.h>
# include <stdarg.h>
# include <stdint.h>

/*ft_printf.c:*/
int			ft_printf(const char *input, ...);

/* ft_printf_utils.c:*/
int			check_argument(va_list args, const char type);

/* ft_args_csp.c:*/
int			ft_putchar_count(int c);
int			ft_putstr_count(char *str);
int			ft_putptr_count(unsigned long long ptr);
int			ft_ptrlen(uintptr_t ptr);
void		ft_putptr(uintptr_t ptr);

/* ft_args_diu.c:*/
int			ft_putnbr_count(int n);
int			ft_put_unsignedint_count(unsigned int n);
int			ft_numlen(unsigned int n);
char		*ft_uitoa(unsigned int n);

/* ft_args_xXpercent.c: */
int			ft_puthex_count(unsigned int n, const char type);
int			ft_hexlen(unsigned int n);
void		ft_puthex(unsigned int n, const char type);
int			ft_putpercent(void);

/* libft_functions.c: */
void		ft_putchar_fd(char c, int fd);
char		*ft_itoa(int n);
int			absolute_value(int nbr);
int			ft_digit_count(int nbr);

#endif
