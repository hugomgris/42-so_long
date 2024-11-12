/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_enemy_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 08:59:14 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/11/08 12:50:52 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

char	sl_detect_m(t_game *game)
{
	if ((game->img->enem2->instances->x < game->img->fch->instances->x)
		&& (game->map[game->img->enem2->instances->y / T_S]
			[game->img->enem2->instances->x / T_S + 1] != MAP_WALL))
		return ('r');
	else if ((game->img->enem2->instances->x > game->img->fch->instances->x)
		&& (game->map[game->img->enem2->instances->y / T_S]
			[game->img->enem2->instances->x / T_S - 1] != MAP_WALL))
		return ('l');
	else if ((game->img->enem2->instances->y < game->img->fch->instances->y)
		&& (game->map[game->img->enem2->instances->y / T_S + 1]
			[game->img->enem2->instances->x / T_S] != MAP_WALL))
		return ('d');
	else if ((game->img->enem2->instances->y > game->img->fch->instances->y)
		&& (game->map[game->img->enem2->instances->y / T_S - 1]
			[game->img->enem2->instances->x / T_S] != MAP_WALL))
		return ('u');
	else
		return ('x');
}

void	sl_move_en(t_game *game)
{
	if (sl_detect_m(game) == 'u')
		game->img->enem2->instances->y -= MOVE;
	else if (sl_detect_m(game) == 'd')
		game->img->enem2->instances->y += MOVE;
	else if (sl_detect_m(game) == 'l')
		game->img->enem2->instances->x -= MOVE;
	else if (sl_detect_m(game) == 'r')
		game->img->enem2->instances->x += MOVE;
}

void	sl_enemy_detector(t_game *game)
{
	if (game->map[game->img->fch->instances->y / T_S]
		[game->img->fch->instances->x / T_S] == MAP_ENEMY)
		sl_game_over(game);
	if (game->img->fch->instances->x == game->img->enem2->instances->x
		&& game->img->fch->instances->y == game->img->enem2->instances->y)
		sl_game_over(game);
}

void	sl_render_enemy(t_game *game, int x, int y)
{
	if (game->map[y][x] == MAP_ENEMY)
	{
		game->n_enem++;
		mlx_image_to_window(game->mlx, game->img->enem, x * T_S, y * T_S);
	}
	else if (game->map[y][x] == MAP_EN2)
	{
		game->n_enem++;
		mlx_image_to_window(game->mlx, game->img->enem2, x * T_S, y * T_S);
	}
}
