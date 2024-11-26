/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Furaido <Furaido@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 05:38:06 by Furaido           #+#    #+#             */
/*   Updated: 2024/11/20 16:56:23 by Furaido          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_game *game)
{
	int	moved;

	moved = 0;
	if (keycode == 65362)
		moved = move_player(game, game->player_x, (game->player_y - 1));
	else if (keycode == 65364)
		moved = move_player(game, game->player_x, (game->player_y + 1));
	else if (keycode == 65361)
		moved = move_player(game, (game->player_x - 1), game->player_y);
	else if (keycode == 65363)
		moved = move_player(game, (game->player_x + 1), game->player_y);
	else if (keycode == 65307)
	{
		printf("\n ===========\n QUITED GAME\n ===========\n");
		exit(0);
	}
	if (moved)
	{
		ft_gold_drain(game);
		render_map(game);
	}
	return (0);
}

void	move_player_update(t_game *game, int new_x, int new_y)
{
	game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
}

void	move_enemies(t_game *game)
{
	if (game->enemy_h_dead == 0)
		move_enemyx(game);
	if (game->enemy_v_dead == 0)
		move_enemyy(game);
}

int	move_player(t_game *game, int new_x, int new_y)
{
	if (!check_end_game(game, new_x, new_y))
		return (0);
	if (is_blocked(game, new_x, new_y))
		return (0);
	collect_coin(game, new_x, new_y);
	move_player_update(game, new_x, new_y);
	move_enemies(game);
	return (1);
}
