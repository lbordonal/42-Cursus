/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:41:35 by lbordona          #+#    #+#             */
/*   Updated: 2023/08/28 20:15:56 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	count_lines(char *av)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	fd = open(av, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
		i++;
	}
	free(line);
	close(fd);
	return (i);
}

int	count_cols(char	*line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
		i++;
	return (i);
}

void	player_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_rows)
	{
		j = 0;
		while (j < game->map_cols)
		{
			if (game->map[i][j] == 'P')
			{
				game->pos_x = j;
				game->pos_y = i;
				break ;
			}
			j++;
		}
		i++;
	}
}

int	flood_fill(t_game *game, char **map, int x, int y)
{
	static int	collects;
	static int	exits;

	if (y < 0 || x < 0 || y > game->map_rows || x > game->map_cols
		|| map[y][x] == '1' || map[y][x] == 'X')
		return (0);
	if (map[y][x] == 'E')
	{
		exits++;
		map[y][x] = 'X';
		return (0);
	}
	if (map[y][x] == 'C')
		collects++;
	map[y][x] = 'X';
	flood_fill(game, map, x + 1, y);
	flood_fill(game, map, x - 1, y);
	flood_fill(game, map, x, y + 1);
	flood_fill(game, map, x, y - 1);
	if (exits == 1 && collects == game->collect)
		return (1);
	else
		return (0);
}
