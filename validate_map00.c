/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map00.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Furaido <Furaido@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 07:10:09 by Furaido           #+#    #+#             */
/*   Updated: 2024/11/26 13:14:49 by Furaido          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_flood_fill(char **map, int y, int x, t_game *game)
{
	if (y < 0 || y >= game->max_y || x < 0 || x >= game->max_x)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'E')
	{
		game->found_exit++;
		return ;
	}
	map[y][x] = 'V';
	ft_flood_fill(map, y + 1, x, game);
	ft_flood_fill(map, y - 1, x, game);
	ft_flood_fill(map, y, x + 1, game);
	ft_flood_fill(map, y, x - 1, game);
}

int	ft_coin_reachable(char **map, t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->max_y)
	{
		while (x < game->max_x)
		{
			if (map[y][x] == 'C')
			{
				printf("Error\nnot reachable01\n");
				return (1);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int	ft_validate_map(char **map, t_game *game)
{
	if ((game->player_y == 0) && (game->player_x == 0))
	{
		printf("Error\nno player\n");
		return (1);
	}
	ft_flood_fill(map, game->player_y, game->player_x, game);
	if (game->found_exit < 1 || ft_check_walls00(map, game) \
	|| ft_check_walls01(map, game) || ft_coin_reachable(map, game))
	{
		printf("Error\nnot reachable00\n");
		return (1);
	}
	return (0);
}
