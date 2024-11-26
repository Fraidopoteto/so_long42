/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschmun < joschmun@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:05:54 by joschmun          #+#    #+#             */
/*   Updated: 2024/11/05 14:05:54 by joschmun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	start_game(t_game *game)
{
	char	**test_map;

	test_map = ft_copy_map(game->max_y, game->max_x, game->map);
	if (!test_map)
	{
		perror("Error\nfailed to copy map");
		free(game->map);
		free(game->mlx);
		return (1);
	}
	if (ft_validate_map(test_map, game))
		return (1);
	mlx_hook(game->win, 17, 0, close_window, game);
	load_game_assets(game);
	ft_title_screen();
	mlx_key_hook(game->win, key_hook, game);
	mlx_loop(game->mlx);
	free(game->map);
	free(game->mlx);
	return (0);
}

int	error(t_game *game)
{
	find_positions(game);
	find_positions_y(game);
	find_positions_x(game);
	count_coins(game);
	if (game->count_coins == 0)
	{
		perror("Error\nno coins\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (init_game01(argc, argv, &game))
		return (1);
	if (start_game(&game))
		return (1);
	return (0);
}
