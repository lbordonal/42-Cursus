/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 12:58:08 by lbordona          #+#    #+#             */
/*   Updated: 2023/08/28 20:20:50 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

/* Includes: */
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

/* Define parameters: */
# define SIZE 32
# define HEIGHT 32
# define WIDTH 32

/* Define images: */
# define PLAYER_W "./assets/images/PW.xpm"
# define PLAYER_S "./assets/images/PS.xpm"
# define PLAYER_A "./assets/images/PA.xpm"
# define PLAYER_D "./assets/images/PD.xpm"
# define EXIT_IMG "./assets/images/E.xpm"
# define COLLECT_IMG "./assets/images/C.xpm"
# define COLLECT2_IMG "./assets/images/C2.xpm"
# define WALL_IMG "./assets/images/1.xpm"
# define BACKGROUND_IMG "./assets/images/0.xpm"
# define ENEMY_IMG "./assets/images/ENA.xpm"

/* Define keys: */
# define W 119
# define A 97
# define S 115
# define D 100
# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363

/* Game structure: */
typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img_player_w;
	void	*img_player_a;
	void	*img_player_s;
	void	*img_player_d;
	void	*img_exit;
	void	*img_collect;
	void	*img_collect2;
	void	*img_wall;
	void	*img_background;
	void	*img_enemy;
	char	**map;
	char	**temp_map;
	int		img_width;
	int		img_height;
	int		map_rows;
	int		map_cols;
	int		player;
	int		pos_x;
	int		pos_y;
	int		exit;
	int		collect;
	int		collected;
	int		wall;
	int		background;
	int		moves;
}	t_game;

/* animation_bonus.c: */
void	change_collectible(t_game *game, int x, int y, int flag);
void	collectible_animation(t_game *game, int flag);

/* draw_bonus.c: */
void	show_moves(t_game *game);
void	draw_img(t_game *game, void *img, int x, int y);
void	draw_map(t_game *game, int x, int y);

/* enemy_moves.c: */
void	random_move(t_game *game);
int		check_next_window(t_game *game, int x, int y);
int		enemy_position(t_game *game, int random_move);
void	enemy_move(t_game *game, int x, int y, int random_move);
int		animations(t_game *game);

/* enemy_moves_2.c: */
void	change_enemy_image_w(t_game *game, int x, int y);
void	change_enemy_image_a(t_game *game, int x, int y);
void	change_enemy_image_s(t_game *game, int x, int y);
void	change_enemy_image_d(t_game *game, int x, int y);

/* free_bonus.c: */
void	free_map(char **map, t_game *game);
void	exit_game(t_game *game);

/* game_and_events_bonus.c: */
int		handle_exit(t_game *game);
int		handle_keypress(int key, t_game *game);
void	gameplay(t_game *game);
void	start_game(t_game *game);

/* initialize_bonus.c: */
void	init_struct(t_game *game);
void	init_map(char *av, t_game *game);
void	init_temp_map(char *av, t_game *game);
void	init_imgs(t_game *game);

/* map_checker_bonus.c: */
void	check_map_struct(t_game *game);
void	check_map_empty_lines(t_game *game);
void	check_map_path(char *av, t_game *game);
void	full_map_checker(char *av, t_game *game);

/* map_checker_structs_bonus.c: */
int		map_is_rectangular(char **map);
int		map_wall_is_valid(char **map);
int		map_is_correct(char **map);
int		map_is_functional(t_game *game);

/* player_moves_bonus.c: */
int		check_next_position(t_game *game, int x, int y);
void	player_new_position(t_game *game, int x, int y);
void	move(t_game *game, char key, int x, int y);
void	player_moves(char key, t_game *game);

/*player_moves_2_bonus.c: */
void	player_move_w(t_game *game, int new_x, int new_y);
void	player_move_a(t_game *game, int new_x, int new_y);
void	player_move_s(t_game *game, int new_x, int new_y);
void	player_move_d(t_game *game, int new_x, int new_y);
void	update_moves(t_game *game);

/* utils_bonus.c: */
int		count_lines(char *av);
int		count_cols(char *line);
void	player_position(t_game *game);
int		flood_fill(t_game *game, char **map, int x, int y);

#endif
