/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:07:22 by lbordona          #+#    #+#             */
/*   Updated: 2023/04/20 23:19:43 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != c)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)s + i);
}

/* int		main(void)
{
	char str[] = "Lucas";
	char	a;

	a = 'u';
	ft_strchr(str, a);
	printf("%s", (char *)ft_strchr(str, a));
	printf("\n");
	printf("%s", strchr(str, a));
	return (0);
} */
