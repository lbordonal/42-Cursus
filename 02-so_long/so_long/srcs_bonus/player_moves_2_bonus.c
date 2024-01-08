/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves_2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 20:56:15 by lbordona          #+#    #+#             */
/*   Updated: 2023/08/28 17:34:59 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	player_move_w(t_game *game, int new_x, int new_y)
{
	int		x;
	int		y;

	x = game->pos_x * SIZE;
	y = game->pos_y * SIZE;
	new_x *= SIZE;
	new_y *= SIZE;
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_background, x, y);
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_player_w, new_x, new_y);
	game->moves++;
	update_moves(game);
}

void	player_move_a(t_game *game, int new_x, int new_y)
{
	int	x;
	int	y;

	x = game->pos_x * SIZE;
	y = game->pos_y * SIZE;
	new_x *= SIZE;
	new_y *= SIZE;
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_background, x, y);
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_player_a, new_x, new_y);
	game->moves++;
	update_moves(game);
}

void	player_move_s(t_game *game, int new_x, int new_y)
{
	int	x;
	int	y;

	x = game->pos_x * SIZE;
	y = game->pos_y * SIZE;
	new_x *= SIZE;
	new_y *= SIZE;
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_background, x, y);
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_player_s, new_x, new_y);
	game->moves++;
	update_moves(game);
}

void	player_move_d(t_game *game, int new_x, int new_y)
{
	int	x;
	int	y;

	x = game->pos_x * SIZE;
	y = game->pos_y * SIZE;
	new_x *= SIZE;
	new_y *= SIZE;
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_background, x, y);
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_player_d, new_x, new_y);
	game->moves++;
	update_moves(game);
}

void	update_moves(t_game *game)
{
	char	*moves;

	moves = ft_itoa(game->moves);
	ft_printf("%s%d\n", "Moves: ", game->moves);
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_wall, 0, 0);
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_wall, 32, 0);
	mlx_string_put(game->mlx, game->win, 10, 15, 0xFFFFFF, "Moves: ");
	mlx_string_put(game->mlx, game->win, 50, 15, 0xFFFFFF, moves);
	free(moves);
}
