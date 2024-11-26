/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures00.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Furaido <Furaido@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:14:57 by Furaido           #+#    #+#             */
/*   Updated: 2024/11/26 13:47:53 by Furaido          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_textures	load_textures(void *mlx)
{
	t_textures	textures;
	int			img_width;
	int			img_height;

	textures.wall = mlx_xpm_file_to_image \
	(mlx, "sprites/kaktus04.xpm", &img_width, &img_height);
	textures.player = mlx_xpm_file_to_image \
	(mlx, "sprites/cowboy_knife00.xpm", &img_width, &img_height);
	textures.floor = mlx_xpm_file_to_image \
	(mlx, "sprites/floor00.xpm", &img_width, &img_height);
	textures.exit = mlx_xpm_file_to_image \
	(mlx, "sprites/chest02.xpm", &img_width, &img_height);
	textures.coin = mlx_xpm_file_to_image \
	(mlx, "sprites/coin02.xpm", &img_width, &img_height);
	textures.enemy_y = mlx_xpm_file_to_image \
	(mlx, "sprites/cowboy_Y00.xpm", &img_width, &img_height);
	textures.enemy_x = mlx_xpm_file_to_image \
	(mlx, "sprites/cowboy_X00.xpm", &img_width, &img_height);
	return (textures);
}

t_hud_textures	load_hud_textures00(void *mlx)
{
	t_hud_textures	hud_textures;
	int				img_width;
	int				img_height;

	hud_textures.zero = mlx_xpm_file_to_image \
	(mlx, "sprites/number00.xpm", &img_width, &img_height);
	hud_textures.one = mlx_xpm_file_to_image \
	(mlx, "sprites/number01.xpm", &img_width, &img_height);
	hud_textures.two = mlx_xpm_file_to_image \
	(mlx, "sprites/number02.xpm", &img_width, &img_height);
	hud_textures.three = mlx_xpm_file_to_image \
	(mlx, "sprites/number03.xpm", &img_width, &img_height);
	hud_textures.four = mlx_xpm_file_to_image \
	(mlx, "sprites/number04.xpm", &img_width, &img_height);
	return (hud_textures);
}

t_hud_textures	load_hud_textures01(void *mlx)
{
	t_hud_textures	hud_textures;
	int				img_width;
	int				img_height;

	hud_textures.five = mlx_xpm_file_to_image \
	(mlx, "sprites/number05.xpm", &img_width, &img_height);
	hud_textures.six = mlx_xpm_file_to_image \
	(mlx, "sprites/number06.xpm", &img_width, &img_height);
	hud_textures.seven = mlx_xpm_file_to_image \
	(mlx, "sprites/number07.xpm", &img_width, &img_height);
	hud_textures.eight = mlx_xpm_file_to_image \
	(mlx, "sprites/number08.xpm", &img_width, &img_height);
	hud_textures.nine = mlx_xpm_file_to_image \
	(mlx, "sprites/number09.xpm", &img_width, &img_height);
	hud_textures.hud_heart = mlx_xpm_file_to_image \
	(mlx, "sprites/hud_heart00.xpm", &img_width, &img_height);
	return (hud_textures);
}
