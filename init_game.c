/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Furaido <Furaido@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:26:10 by Furaido           #+#    #+#             */
/*   Updated: 2024/11/26 13:53:57 by Furaido          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game00(t_game *game)
{
	game->found_coins = 0;
	game->count_coins = 0;
	game->max_y = 0;
	game->max_x = 0;
	game->player_y = 0;
	game->player_x = 0;
	game->enemy_h_x = 0;
	game->enemy_h_y = 0;
	game->enemy_v_x = 0;
	game->enemy_v_y = 0;
	game->direction_v = 1;
	game->direction_h = 1;
	game->enemy_h_dead = 0;
	game->enemy_v_dead = 0;
	game->highscore = 0;
	game->coins_highscore = 0;
	game->kill_highscore = 0;
	game->step_counter = 0;
	game->kill_counter = 0;
	game->gold_rush = 10;
	game->found_exit = 0;
}

int	init_game01(int argc, char **argv, t_game *game)
{
	if (argc != 2)
		return (1);
	init_game00(game);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (1);
	if (init_window_and_map(game, argv[argc - 1]) || create_window(game) || \
		error(game))
	{
		free(game->map);
		free(game->mlx);
		return (1);
	}
	return (0);
}
