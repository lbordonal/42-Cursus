/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 11:24:45 by lbordona          #+#    #+#             */
/*   Updated: 2023/08/28 20:19:15 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	random_move(t_game *game)
{
	int	random_move;

	random_move = rand() % 4;
	enemy_position(game, random_move);
}

int	check_next_window(t_game *game, int x, int y)
{
	if (game->map[y][x] == '0')
		return (1);
	if (game->map[y][x] == '1')
		return (0);
	if (game->map[y][x] == 'C')
		return (0);
	if (game->map[y][x] == 'T')
		return (0);
	if (game->map[y][x] == 'P')
	{
		ft_printf("\033[0;31mYOU WERE VANISHED BY THANOS!\n");
		exit_game(game);
	}
	return (0);
}

int	enemy_position(t_game *game, int random_move)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_rows)
	{
		j = 0;
		while (j < game->map_cols)
		{
			if (game->map[i][j] == 'T')
			{
				enemy_move(game, j, i, random_move);
				if (random_move == 3)
					j++;
				if (random_move == 2)
					i++;
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	enemy_move(t_game *game, int x, int y, int random_move)
{
	if (random_move == 0)
	{
		if (check_next_window(game, x, y - 1) == 1)
			change_enemy_image_w(game, x, y);
	}
	else if (random_move == 1)
	{
		if (check_next_window(game, x - 1, y) == 1)
			change_enemy_image_a(game, x, y);
	}
	else if (random_move == 2)
	{
		if (check_next_window(game, x, y + 1) == 1)
			change_enemy_image_s(game, x, y);
	}
	else if (random_move == 3)
	{
		if (check_next_window(game, x + 1, y) == 1)
			change_enemy_image_d(game, x, y);
	}
}

int	animations(t_game *game)
{
	static int	i;
	int			num;

	num = 20000;
	i++;
	if (i == num * 2)
		collectible_animation(game, 0);
	if (i == num * 3)
		random_move(game);
	if (i == num * 4)
	{
		collectible_animation(game, 1);
		i = 0;
	}
	return (1);
}
