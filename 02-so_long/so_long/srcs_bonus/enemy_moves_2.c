/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 11:52:56 by lbordona          #+#    #+#             */
/*   Updated: 2023/08/28 20:18:49 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	change_enemy_image_w(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_background, x * 32, y * 32);
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_enemy, x * 32, (y - 1) * 32);
	game->map[y][x] = '0';
	game->map[y - 1][x] = 'T';
}

void	change_enemy_image_a(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_background, x * 32, y * 32);
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_enemy, (x - 1) * 32, y * 32);
	game->map[y][x] = '0';
	game->map[y][x - 1] = 'T';
}

void	change_enemy_image_s(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_background, x * 32, y * 32);
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_enemy, x * 32, (y + 1) * 32);
	game->map[y][x] = '0';
	game->map[y + 1][x] = 'T';
}

void	change_enemy_image_d(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_background, x * 32, y * 32);
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_enemy, (x + 1) * 32, y * 32);
	game->map[y][x] = '0';
	game->map[y][x + 1] = 'T';
}
