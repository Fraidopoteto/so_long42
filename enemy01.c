/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Furaido <Furaido@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 06:32:59 by Furaido           #+#    #+#             */
/*   Updated: 2024/11/26 13:20:48 by Furaido          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	can_move_verticaly(t_game *game)
{
	if (game->map[game->enemy_v_y + game->direction_v] \
	[game->enemy_v_x] == '1' || \
		game->map[game->enemy_v_y + game->direction_v] \
		[game->enemy_v_x] == 'E' || \
		game->map[game->enemy_v_y + game->direction_v] \
		[game->enemy_v_x] == 'C' || \
		game->map[game->enemy_v_y + game->direction_v] \
		[game->enemy_v_x] == 'X')
		game->direction_v *= -1;
	if (check_player_collisiony00(game))
		exit(0);
}

int	check_player_collisiony00(t_game *game)
{
	if ((game->map[game->enemy_v_y + 1][game->enemy_v_x] == 'P' || \
		game->map[(game->enemy_v_y + game->direction_v) + 1] \
		[game->enemy_v_x] == 'P' || \
		game->map[game->enemy_v_y][game->enemy_v_x] == 'P') && \
		(game->direction_v > 0))
	{
		printf("\nBLUE_COWBOY: Y'AIN'T GOIN' NOWHERE!\n	     *BANG*\n\n");
		printf("\n ==========\n YOUR DEAD.\n ==========\n\n");
		return (1);
	}
	else if ((game->map[(game->enemy_v_y + game->direction_v) + 1] \
	[game->enemy_v_x] == 'P' || \
		game->map[game->enemy_v_y][game->enemy_v_x] == 'P') && \
		(game->direction_v < 0))
	{
		printf("\nBLUE_COWBOY: Y'AIN'T GOIN' NOWHERE!\n	     *BANG*\n\n");
		printf("\n ==========\n YOUR DEAD.\n ==========\n\n");
		return (1);
	}
	check_player_collisiony01(game);
	return (0);
}

int	check_player_collisiony01(t_game *game)
{
	if (game->map[(game->enemy_v_y + game->direction_v) - 1] \
	[game->enemy_v_x] == 'P')
	{
		printf("\nBLUE_COWBOY: *Arrg!*\n\n");
		printf("\nCOWBOY KILLED  -250\n\n");
		game->highscore -= 250;
		game->enemy_v_dead = 2;
		game->kill_counter++;
		return (0);
	}
	else if (game->map[game->enemy_v_y - 1][game->enemy_v_x] == 'P')
	{
		printf("\nBLUE_COWBOY: *Arrg!*\n\n");
		printf("\nCOWBOY KILLED  -250\n\n");
		game->highscore -= 250;
		game->enemy_v_dead = 3;
		game->kill_counter++;
		return (0);
	}
	return (0);
}

void	update_enemy_positiony(t_game *game)
{
	game->map[game->enemy_v_y][game->enemy_v_x] = '0';
	game->map[game->enemy_v_y + game->direction_v] \
	[game->enemy_v_x] = 'Y';
	game->enemy_v_y = (game->enemy_v_y + game->direction_v);
}

int	move_enemyy(t_game *game)
{
	can_move_verticaly(game);
	if (game->enemy_v_dead <= 2)
		update_enemy_positiony(game);
	return (1);
}
