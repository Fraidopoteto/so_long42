/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Furaido <Furaido@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 05:38:06 by Furaido           #+#    #+#             */
/*   Updated: 2024/11/26 13:40:52 by Furaido          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_end_game(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == 'E' && game->found_coins == 0)
	{
		if (game->enemy_h_dead <= 1 && game->enemy_v_dead <= 1)
		{
			printf("\nPINK_COWBOY: *Tch...* I didn't even\n\
	     need this damn rusty thing\n	     to get through!\n\n");
		}
		else
			printf("\nPINK_COWBOY: *Pew...* that was close...\n\n");
		ft_print_highscore(game);
		exit(0);
	}
	return (1);
}

void	ft_print_highscore(t_game *game)
{
	if (game->enemy_h_dead <= 1 && game->enemy_v_dead <= 1)
		printf("------★★★-------\n\n");
	else if ((game->enemy_h_dead > 1 && game->enemy_v_dead <= 1))
		printf("------★★☆-------\n\n");
	else if ((game->enemy_h_dead <= 1 && game->enemy_v_dead > 1))
		printf("------★★☆-------\n\n");
	else if ((game->enemy_h_dead > 1 && game->enemy_v_dead > 1))
		printf("------★☆☆-------\n\n");
	printf("COINS: %i   +%i\n", game->count_coins, \
	(game->count_coins * 500));
	printf("STEPS: %i  %i\n", game->step_counter, \
	(game->step_counter * -25));
	printf("KILLS: %i   %i\n", (game->kill_counter), \
	((game->kill_counter) * -250));
	printf("================\nHIGHSCORE:  %i\n\
================\n", game->highscore);
	return ;
}

int	is_blocked(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == '1' || \
	game->map[new_y][new_x] == 'E')
		return (1);
	if ((game->map[game->player_y][(game->player_x - 1)] \
	== 'X') && ((game->player_x - 1) != new_x))
		return (1);
	if ((game->map[(game->player_y + 1)][game->player_x] \
	== 'Y') && ((game->player_y + 1) != new_y))
		return (1);
	return (0);
}

void	collect_coin(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == 'C')
	{
		game->gold_rush = 10;
		game->map[new_y][new_x] = '0';
		game->found_coins--;
		game->highscore += 500;
		printf("\nCOIN COLLECTED +500\n\n");
	}
}
