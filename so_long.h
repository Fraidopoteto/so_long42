/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Furaido <Furaido@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:01:52 by joschmun          #+#    #+#             */
/*   Updated: 2024/11/26 13:48:10 by Furaido          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <fcntl.h>
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"

typedef struct s_textures
{
	void	*wall;
	void	*player;
	void	*floor;
	void	*exit;
	void	*coin;
	void	*enemy_y;
	void	*enemy_x;
	void	*enemy_v;
	void	*enemy_h;
}	t_textures;

typedef struct s_hud_textures
{
	void	*zero;
	void	*one;
	void	*two;
	void	*three;
	void	*four;
	void	*five;
	void	*six;
	void	*seven;
	void	*eight;
	void	*nine;
	void	*hud_heart;
	void	*hud_shoe;
	void	*hud_coin;
}	t_hud_textures;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	char			**map;
	int				max_y;
	int				max_x;
	int				player_x;
	int				player_y;
	int				enemy_y_y;
	int				enemy_y_x;
	int				enemy_x_y;
	int				enemy_x_x;
	int				enemy_v_y;
	int				enemy_v_x;
	int				enemy_h_y;
	int				enemy_h_x;
	int				enemy_y_dead;
	int				enemy_x_dead;
	int				enemy_h_dead;
	int				enemy_v_dead;
	int				found_coins;
	int				count_coins;
	int				direction_y;
	int				direction_x;
	int				direction_v;
	int				direction_h;
	int				step_counter;
	int				highscore;
	int				kill_highscore;
	int				kill_counter;
	int				coins_highscore;
	int				gold_rush;
	int				drain;
	int				found_exit;
	t_textures		textures;
	t_hud_textures	hud_textures;
}	t_game;

//enemy00.c
int				move_enemyx(t_game *game);
void			can_move_horizontalx(t_game *game);
int				check_player_collisionx00(t_game *game);
int				check_player_collisionx01(t_game *game);
void			change_directionx(t_game *game);
void			update_enemy_positionx(t_game *game);

//enemy01.c
int				move_enemyy(t_game *game);
void			can_move_verticaly(t_game *game);
int				check_player_collisiony00(t_game *game);
int				check_player_collisiony01(t_game *game);
void			change_directiony(t_game *game);
void			update_enemy_positiony(t_game *game);

//get_next_line.c
char			*read_join(int fd, char	*saved);
char			*savedtilnl(char *saved, char c);
char			*savedaftnl(char *saved, char c);
char			*get_next_line(int fd);

//gold_rush.c
void			ft_gold_drain(t_game *game);
void			ft_title_screen(void);
void			ft_print_number_gold_drain00(t_game *game);

//init_game.c
void			init_game00(t_game *game);
int				init_game01(int argc, char **argv, t_game *game);

//main.c
void			init_game(t_game *game);
int				start_game(t_game *game);
int				error(t_game *game);

//player00.c
int				check_end_game(t_game *game, int new_x, int new_y);
void			ft_print_highscore(t_game *game);
int				is_blocked(t_game *game, int new_x, int new_y);
void			collect_coin(t_game *game, int new_x, int new_y);

//player01.c
int				key_hook(int keycode, t_game *game);
void			move_player_update(t_game *game, int new_x, int new_y);
void			move_enemies(t_game *game);
int				move_player(t_game *game, int new_x, int new_y);

//position.c
void			find_positions(t_game *game);
void			count_coins(t_game *game);
void			find_positions_x(t_game *game);
void			find_positions_y(t_game *game);

//read_map00.c
char			**ft_copy_map(int max_y, int max_x, char **map);
char			**allocate_map_copy(int max_y, int max_x);

//read_map01.c
int				ft_line_length(char *line);
char			**ft_store_lines(int fd, int *max_y, int *max_x);
char			**ft_fill_map(char **line_storage, int max_y, int max_x);
char			**ft_read_map(int fd, int *max_y, int *max_x);

//render_map.c
void			*render_hud00(t_game *game, char cell);
void			render_cell(t_game *game, int x, int y);
void			render_row(t_game *game, int y);
void			render_map(t_game *game);
int				load_game_assets(t_game *game);

//textures00.c
t_textures		load_textures(void *mlx);
t_hud_textures	load_hud_textures00(void *mlx);
t_hud_textures	load_hud_textures01(void *mlx);

//validate_map00.c
void			ft_flood_fill(char **map, int y, int x, t_game *game);
int				ft_validate_map(char **map, t_game *game);
int				ft_coin_reachable(char **map, t_game *game);

//validate_map01.c
int				ft_check_walls00(char **map, t_game *game);
int				ft_check_walls01(char **map, t_game *game);

//window.c
int				init_window_and_map(t_game *game, char *map_filename);
int				create_window(t_game *game);
int				close_window(t_game *game);

#endif
