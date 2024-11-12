/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_game_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:06:23 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/11/08 13:21:46 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	sl_move_up(t_game *game)
{
	if (game->map[game->img->fch->instances->y / T_S - 1]
		[game->img->fch->instances->x / T_S] != MAP_WALL)
	{
		game->img->fch->instances->y -= MOVE;
		game->img->ch[0]->instances->y -= MOVE;
		game->img->ch[1]->instances->y -= MOVE;
		game->img->ch[2]->instances->y -= MOVE;
		game->img->ch[3]->instances->y -= MOVE;
		game->img->fch->instances->enabled = false;
		game->img->ch[0]->instances->enabled = true;
		game->img->ch[1]->instances->enabled = false;
		game->img->ch[2]->instances->enabled = false;
		game->img->ch[3]->instances->enabled = false;
		game->move_count++;
		if (game->n_enem != 0)
			sl_move_en(game);
		ft_printf("MOVES: %i\n", game->move_count);
	}
}

void	sl_move_down(t_game *game)
{
	if (game->map[game->img->fch->instances->y / T_S + 1]
		[game->img->fch->instances->x / T_S] != MAP_WALL)
	{
		game->img->fch->instances->y += MOVE;
		game->img->ch[0]->instances->y += MOVE;
		game->img->ch[1]->instances->y += MOVE;
		game->img->ch[2]->instances->y += MOVE;
		game->img->ch[3]->instances->y += MOVE;
		game->img->fch->instances->enabled = false;
		game->img->ch[0]->instances->enabled = false;
		game->img->ch[1]->instances->enabled = true;
		game->img->ch[2]->instances->enabled = false;
		game->img->ch[3]->instances->enabled = false;
		game->move_count++;
		if (game->n_enem != 0)
			sl_move_en(game);
		ft_printf("MOVES: %i\n", game->move_count);
	}
}

void	sl_move_left(t_game *game)
{
	if (game->map[game->img->fch->instances->y / T_S]
		[game->img->fch->instances->x / T_S - 1] != MAP_WALL)
	{
		game->img->fch->instances->x -= MOVE;
		game->img->ch[0]->instances->x -= MOVE;
		game->img->ch[1]->instances->x -= MOVE;
		game->img->ch[2]->instances->x -= MOVE;
		game->img->ch[3]->instances->x -= MOVE;
		game->img->fch->instances->enabled = false;
		game->img->ch[0]->instances->enabled = false;
		game->img->ch[1]->instances->enabled = false;
		game->img->ch[2]->instances->enabled = true;
		game->img->ch[3]->instances->enabled = false;
		game->move_count++;
		if (game->n_enem != 0)
			sl_move_en(game);
		ft_printf("MOVES: %i\n", game->move_count);
	}
}

void	sl_move_right(t_game *game)
{
	if (game->map[game->img->fch->instances->y / T_S]
		[game->img->fch->instances->x / T_S + 1] != MAP_WALL)
	{
		game->img->fch->instances->x += MOVE;
		game->img->ch[0]->instances->x += MOVE;
		game->img->ch[1]->instances->x += MOVE;
		game->img->ch[2]->instances->x += MOVE;
		game->img->ch[3]->instances->x += MOVE;
		game->img->fch->instances->enabled = false;
		game->img->ch[0]->instances->enabled = false;
		game->img->ch[1]->instances->enabled = false;
		game->img->ch[2]->instances->enabled = false;
		game->img->ch[3]->instances->enabled = true;
		game->move_count++;
		if (game->n_enem != 0)
			sl_move_en(game);
		ft_printf("MOVES: %i\n", game->move_count);
	}
}

void	sl_input_handler(mlx_key_data_t keydata, void *param)
{
	t_game		*game;

	game = param;
	if ((keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		|| (keydata.key == MLX_KEY_UP && keydata.action == MLX_RELEASE))
		sl_move_up(game);
	if ((keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		|| (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE))
		sl_move_right(game);
	if ((keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		|| (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_RELEASE))
		sl_move_down(game);
	if ((keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		|| (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE))
		sl_move_left(game);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		mlx_close_window(game->mlx);
	sl_write_counter(game);
	if (game->n_enem != 0)
		sl_enemy_detector(game);
	sl_collector(game);
}
