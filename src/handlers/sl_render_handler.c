/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_render_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:56:13 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/11/08 13:29:35 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	sl_render_wall(int index, int x, int y, t_game *game)
{
	if (index == 0)
		mlx_image_to_window(game->mlx, game->img->mid, x * T_S, y * T_S);
	if (index == 1)
		mlx_image_to_window(game->mlx, game->img->c_ul, x * T_S, y * T_S);
	else if (index == 2)
		mlx_image_to_window(game->mlx, game->img->c_ur, x * T_S, y * T_S);
	else if (index == 3)
		mlx_image_to_window(game->mlx, game->img->c_dl, x * T_S, y * T_S);
	else if (index == 4)
		mlx_image_to_window(game->mlx, game->img->c_dr, x * T_S, y * T_S);
	else if (index == 5)
		mlx_image_to_window(game->mlx, game->img->w_u, x * T_S, y * T_S);
	else if (index == 6)
		mlx_image_to_window(game->mlx, game->img->w_d, x * T_S, y * T_S);
	else if (index == 7)
		mlx_image_to_window(game->mlx, game->img->w_r, x * T_S, y * T_S);
	else if (index == 8)
		mlx_image_to_window(game->mlx, game->img->w_l, x * T_S, y * T_S);
}

int	sl_detect_wall(t_game *game, int x, int y)
{
	int	index;
	int	m_cols;
	int	m_rows;

	m_cols = ft_strlen(game->map[0]) - 1;
	m_rows = ft_array_count(game->map) - 1;
	index = 0;
	if (x == 0 && y == 0)
		index = 1;
	else if (x == m_cols && y == 0)
		index = 2;
	else if (x == 0 && y == m_rows)
		index = 3;
	else if (x == m_cols && y == m_rows)
		index = 4;
	else if (y == 0)
		index = 5;
	else if (y == m_rows)
		index = 6;
	else if (x == m_cols)
		index = 7;
	else if (x == 0)
		index = 8;
	return (index);
}

void	sl_render_f_tile(t_game *game, int x, int y, int r)
{
	if (r == 1)
		mlx_image_to_window(game->mlx, game->img->floor1, x * T_S, y * T_S);
	if (r == 2)
		mlx_image_to_window(game->mlx, game->img->floor2, x * T_S, y * T_S);
	if (r == 3)
		mlx_image_to_window(game->mlx, game->img->floor3, x * T_S, y * T_S);
}

void	sl_render_floor(t_game *game, t_img *image)
{
	int	x;
	int	y;
	int	r;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			r = (rand() % 3) + 1;
			sl_render_f_tile(game, x, y, r);
			if (game->map[y][x] == MAP_WALL)
				sl_render_wall(sl_detect_wall(game, x, y), x, y, game);
			if (game->map[y][x] == MAP_EXIT)
			{
				mlx_image_to_window(game->mlx, image->exit_o, x * T_S, y * T_S);
				mlx_image_to_window(game->mlx, image->exit_c, x * T_S, y * T_S);
			}
			x++;
		}
		y++;
	}
}

void	sl_render_map(t_game *game, t_img *img)
{
	int	x;
	int	y;

	sl_render_floor(game, img);
	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == MAP_COLLEC)
				mlx_image_to_window(game->mlx, img->collec, x * T_S, y * T_S);
			else if (game->map[y][x] == MAP_ENTRY)
			{
				mlx_image_to_window(game->mlx, img->fch, x * T_S, y * T_S);
				mlx_image_to_window(game->mlx, img->ch[0], x * T_S, y * T_S);
				mlx_image_to_window(game->mlx, img->ch[1], x * T_S, y * T_S);
				mlx_image_to_window(game->mlx, img->ch[2], x * T_S, y * T_S);
				mlx_image_to_window(game->mlx, img->ch[3], x * T_S, y * T_S);
				sl_disable_start(game);
			}
			else if (game->map[y][x] == MAP_ENEMY || game->map[y][x] == MAP_EN2)
				sl_render_enemy(game, x, y);
		}
	}
}
