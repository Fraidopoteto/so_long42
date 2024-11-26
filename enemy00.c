/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Furaido <Furaido@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 06:00:54 by Furaido           #+#    #+#             */
/*   Updated: 2024/11/26 13:21:08 by Furaido          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	can_move_verticalx(t_game *game)
{
	if (game->map[game->enemy_h_y][game->enemy_h_x + game->direction_h] \
		== '1' || \
		game->map[game->enemy_h_y][game->enemy_h_x + game->direction_h] \
		== 'E' || \
		game->map[game->enemy_h_y][game->enemy_h_x + game->direction_h] \
		== 'C' || \
		game->map[game->enemy_h_y][game->enemy_h_x + game->direction_h] \
		== 'Y')
		game->direction_h *= -1;
	if (check_player_collisionx00(game))
		exit(0);
}

int	check_player_collisionx00(t_game *game)
{
	if ((game->map[game->enemy_h_y][game->enemy_h_x - 1] == 'P' || \
		game->map[game->enemy_h_y][(game->enemy_h_x + game->direction_h) - 1] \
		== 'P' || \
		game->map[game->enemy_h_y][game->enemy_h_x] == 'P') && \
		game->direction_h < 0)
	{
		printf("\nBLUE_COWBOY: HAND OVER THE GOLD,");
		printf("\n	     YA VARMINT! *BANG*\n\n");
		printf("\n ==========\n YOUR DEAD.\n ==========\n\n");
		return (1);
	}
	else if ((game->map[game->enemy_h_y] \
	[(game->enemy_h_x + game->direction_h) - 1] == 'P' || \
		game->map[game->enemy_h_y][game->enemy_h_x] == 'P') && \
		game->direction_h > 0)
	{
		printf("\nBLUE_COWBOY: HAND OVER THE GOLD,");
		printf("\n	     YA VARMINT! *BANG*\n\n");
		printf("\n ==========\n YOUR DEAD.\n ==========\n\n");
		return (1);
	}
	check_player_collisionx01(game);
	return (0);
}

int	check_player_collisionx01(t_game *game)
{
	if (game->map[game->enemy_h_y] \
	[(game->enemy_h_x + game->direction_h) + 1] == 'P')
	{
		printf("\nBLUE_COWBOY: *Arrg!*\n\n");
		printf("\nCOWBOY KILLED  -250\n\n");
		game->highscore -= 250;
		game->enemy_h_dead = 2;
		game->kill_counter++;
		return (0);
	}
	else if (game->map[game->enemy_h_y][game->enemy_h_x + 1] == 'P')
	{
		printf("\nBLUE_COWBOY: *Arrg!*\n\n");
		printf("\nCOWBOY KILLED  -250\n\n");
		game->highscore -= 250;
		game->enemy_h_dead = 3;
		game->kill_counter++;
		return (0);
	}
	return (0);
}

void	update_enemy_positionx(t_game *game)
{
	game->map[game->enemy_h_y][game->enemy_h_x] = '0';
	game->map[game->enemy_h_y][game->enemy_h_x + game->direction_h] = 'X';
	game->enemy_h_x = (game->enemy_h_x + game->direction_h);
}

int	move_enemyx(t_game *game)
{
	can_move_verticalx(game);
	if (game->enemy_h_dead <= 2)
		update_enemy_positionx(game);
	return (1);
}
