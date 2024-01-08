/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 13:08:51 by lbordona          #+#    #+#             */
/*   Updated: 2023/08/28 18:54:55 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static int	map_extension_checker(char *map)
{
	int	i;

	if (!map)
		return (0);
	i = ft_strlen(map) - 1;
	if (map[i] == 'r' && map[i - 1] == 'e'
		&& map[i - 2] == 'b' && map[i - 3] == '.')
		return (1);
	return (0);
}

int	verify(int ac, char **av)
{
	int	fd;

	if (ac != 2)
	{
		ft_printf("\033[0;31mError → Entry should be: ./so_long mapXYZ.ber.\n");
		exit (1);
	}
	fd = open(av[1], O_RDONLY);
	if (map_extension_checker(av[1]) == 0)
	{
		ft_printf("\033[0;31mError → Invalid map extension.\n");
		exit (1);
	}
	else if (fd < 0)
	{
		ft_printf("\033[0;31mError → Invalid map file.\n");
		exit (1);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_game	game;

	verify(ac, av);
	game.mlx = 0;
	game.win = 0;
	init_struct(&game);
	full_map_checker(av[1], &game);
	start_game(&game);
	exit_game(&game);
}
