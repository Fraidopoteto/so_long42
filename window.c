/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Furaido <Furaido@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:05:20 by Furaido           #+#    #+#             */
/*   Updated: 2024/11/26 13:14:11 by Furaido          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_window_and_map(t_game *game, char *map_filename)
{
	int	fd;

	fd = open(map_filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\ncant open map00");
		return (1);
	}
	game->map = ft_read_map(fd, &game->max_y, &game->max_x);
	close(fd);
	if (!game->map)
	{
		perror("Error\ncant open map01");
		return (1);
	}
	return (0);
}

int	create_window(t_game *game)
{
	int	screen_size_y;
	int	screen_size_x;

	screen_size_y = game->max_y * 32;
	screen_size_x = game->max_x * 32;
	game->win = mlx_new_window \
	(game->mlx, screen_size_x, screen_size_y, "so_long");
	if (!game->win)
	{
		perror("Error\nopen window failed00\n");
		return (1);
	}
	return (0);
}

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	printf("\n ===========\n QUITED GAME\n ===========\n");
	exit(0);
	free(game->map);
	free(game->mlx);
	return (0);
}
