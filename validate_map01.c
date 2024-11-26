/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Furaido <Furaido@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:18:03 by Furaido           #+#    #+#             */
/*   Updated: 2024/11/26 13:11:41 by Furaido          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_walls00(char **map, t_game *game)
{
	int	x;

	x = 0;
	while (x < game->max_x)
	{
		if (map[1][x] != '1')
		{
			printf("Error\nno walls00\n");
			return (1);
		}
		x++;
	}
	return (0);
}

int	ft_check_walls01(char **map, t_game *game)
{
	int	y;
	int	x;

	y = 1;
	x = 0;
	while (map[game->max_y - 1][x])
	{
		if (map[game->max_y - 1][x] != '1')
		{
			printf("Error\nno walls01\n");
			return (1);
		}
		x++;
	}
	while (y < game->max_y)
	{
		if (map[y][0] != '1' || map[y][game->max_x - 1] != '1')
		{
			printf("Error\nno walls02\n");
			return (1);
		}
		y++;
	}
	return (0);
}
