/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:33:12 by lbordona          #+#    #+#             */
/*   Updated: 2022/11/18 11:41:09 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"

int	main(void)
{
	int		fd;
	int		i;
	char	*line;

/* 	fd = open("../Tests/files/miranha.txt", O_RDONLY);
	fd = open("../Tests//files/simpsons.txt", O_RDONLY); */
	fd = open("../Tests/files/hp.txt", O_RDONLY);
/* 	fd = open("../Tests/files/hltv.txt", O_RDONLY);
	fd = open("../Tests/files/big_line_with_nl", O_RDONLY);
	fd = open("../Tests/files/big_line_no_nl", O_RDONLY); */
	i = 1;
	while ((line = get_next_line(fd)))
	{
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
