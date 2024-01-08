/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:52:14 by lbordona          #+#    #+#             */
/*   Updated: 2023/08/28 20:17:28 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	change_collectible(t_game *game, int x, int y, int flag)
{
	if (flag == 0)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_collect, x * 32, y * 32);
	}
	if (flag == 1)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_collect2, x * 32, y * 32);
	}
}

void	collectible_animation(t_game *game, int flag)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_rows)
	{
		j = 0;
		while (j < game->map_cols)
		{
			if (game->map[i][j] == 'C')
				change_collectible(game, j, i, flag);
			j++;
		}
		i++;
	}
}
