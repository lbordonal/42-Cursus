/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 20:48:19 by lbordona          #+#    #+#             */
/*   Updated: 2023/08/28 20:15:39 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	player_new_position(t_game *game, int x, int y)
{
	game->pos_x = x;
	game->pos_y = y;
}

int	check_next_position(t_game *game, int x, int y)
{
	if (game->map[y][x] == '0')
		return (1);
	if (game->map[y][x] == '1')
		return (0);
	if (game->map[y][x] == 'C')
	{
		game->collected++;
		return (1);
	}
	if (game->map[y][x] == 'E' && (game->collected != game->collect))
		return (0);
	if (game->map[y][x] == 'E' && (game->collected == game->collect))
	{
		ft_printf("\033[0;32mYOU HELPED THOR TO SAVE THE WORLD FROM THANOS!\n");
		exit_game(game);
	}
	return (0);
}

void	move(t_game *game, char key, int x, int y)
{
	if (key == 'W')
	{
		player_move_w(game, x, (y - 1));
		player_new_position(game, x, y - 1);
		game->map[y][x] = '0';
	}
	if (key == 'A')
	{
		player_move_a(game, (x - 1), y);
		player_new_position(game, (x - 1), y);
		game->map[y][x] = '0';
	}
	if (key == 'S')
	{
		player_move_s(game, x, (y + 1));
		player_new_position(game, x, (y + 1));
		game->map[y][x] = '0';
	}
	if (key == 'D')
	{
		player_move_d(game, (x + 1), y);
		player_new_position(game, (x + 1), y);
		game->map[y][x] = '0';
	}
}

void	player_moves(char key, t_game *game)
{
	int	x;
	int	y;

	x = game->pos_x;
	y = game->pos_y;
	if (key == 'W')
		if (check_next_position(game, x, y - 1) == 1)
			move(game, 'W', x, y);
	if (key == 'A')
		if (check_next_position(game, x - 1, y) == 1)
			move(game, 'A', x, y);
	if (key == 'S')
		if (check_next_position(game, x, y + 1) == 1)
			move(game, 'S', x, y);
	if (key == 'D')
		if (check_next_position(game, x + 1, y) == 1)
			move(game, 'D', x, y);
}
