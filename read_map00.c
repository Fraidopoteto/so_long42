/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschmun < joschmun@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:09:14 by joschmun          #+#    #+#             */
/*   Updated: 2024/11/11 15:09:14 by joschmun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**allocate_map_copy(int max_y, int max_x)
{
	char	**map_cpy;
	int		y;

	y = 0;
	map_cpy = malloc(sizeof(char *) * max_y);
	if (!map_cpy)
		return (NULL);
	while (y < max_y)
	{
		map_cpy[y] = malloc(sizeof(char) * (max_x + 1));
		if (!map_cpy[y])
		{
			while (y > 0)
			{
				y--;
				free(map_cpy[y]);
			}
			free(map_cpy);
			return (NULL);
		}
		y++;
	}
	return (map_cpy);
}

char	**ft_copy_map(int max_y, int max_x, char **map)
{
	char	**map_cpy;
	int		y;
	int		x;

	map_cpy = allocate_map_copy(max_y, max_x);
	if (!map_cpy)
		return (NULL);
	y = 0;
	while (y < max_y)
	{
		x = 0;
		while (x < max_x)
		{
			map_cpy[y][x] = map[y][x];
			x++;
		}
		map_cpy[y][x] = '\0';
		y++;
	}
	return (map_cpy);
}
