/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:07:04 by lbordona          #+#    #+#             */
/*   Updated: 2023/02/24 09:23:10 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int	ft_isdigitorsignal(char c)
{
	if ((c >= '0' && c <= '9') || (c == '-' || c == '+') || c == ' ')
		return (1);
	return (0);
}

/* int	main(void)
{
	int		a = 'a';
	int		b = '1';

	printf("%d", ft_isdigit(a));
	printf("\n");
	printf("%d", isdigit(a));
	printf("\n");
	printf("\n");
	printf("%d", ft_isdigit(b));
	printf("\n");
	printf("%d", isdigit(b));
	return (0);
} */
