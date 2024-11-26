/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gold_rush.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Furaido <Furaido@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:49:18 by Furaido           #+#    #+#             */
/*   Updated: 2024/11/20 16:50:28 by Furaido          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_gold_drain(t_game *game)
{
	game->highscore -= 25;
	game->step_counter++;
	game->gold_rush--;
	ft_print_number_gold_drain00(game);
	printf("STEPS: %i\n", game->step_counter);
	if (game->gold_rush == 0)
	{
		printf("\n=====================\n");
		printf("AIN'T NO GOLD AROUND,\nSO YER SIX FEET DOWN!");
		printf("\n=====================\n");
		exit (0);
	}
}

void	ft_print_number_gold_drain00(t_game *game)
{
	if (game->gold_rush == 0)
		game->map[0][1] = 'O';
	else if (game->gold_rush == 1)
		game->map[0][1] = '!';
	else if (game->gold_rush == 2)
		game->map[0][1] = '2';
	else if (game->gold_rush == 3)
		game->map[0][1] = '3';
	else if (game->gold_rush == 4)
		game->map[0][1] = '4';
	else if (game->gold_rush == 5)
		game->map[0][1] = '5';
	else if (game->gold_rush == 6)
		game->map[0][1] = '6';
	else if (game->gold_rush == 7)
		game->map[0][1] = '7';
	else if (game->gold_rush == 8)
		game->map[0][1] = '8';
	else if (game->gold_rush == 9)
		game->map[0][1] = '9';
}

void	ft_title_screen(void)
{
	printf("  ▗▄▄▖ ▗▄▖ ▗▖   ▗▄▄▄ \n");
	printf(" ▐▌   ▐▌ ▐▌▐▌   ▐▌  █ \n");
	printf(" ▐▌▝▜▌▐▌ ▐▌▐▌   ▐▌  █ \n");
	printf(" ▝▚▄▞▘▝▚▄▞▘▐▙▄▄▖▐▙▄▄▀ \n");
	printf(" ▗▄▄▖ ▗▖ ▗▖ ▗▄▄▖▗▖ ▗▖ \n");
	printf(" ▐▌ ▐▌▐▌ ▐▌▐▌   ▐▌ ▐▌ \n");
	printf(" ▐▛▀▚▖▐▌ ▐▌ ▝▀▚▖▐▛▀▜▌ \n");
	printf(" ▐▌ ▐▌▝▚▄▞▘▗▄▄▞▘▐▌ ▐▌ \n");
	printf(" =====================\n");
	printf("  ===================\n\n\n\n\n");
	printf("!PRESS ARROW KEYS TO MOVE!\n\n\n\n");
	printf("\nPINK_COWBOY: *Sigh...* This rusty old\n\
	     knife won't get me anywhere...\n\
	     unless I sneak up behind 'em!\n\n");
}
