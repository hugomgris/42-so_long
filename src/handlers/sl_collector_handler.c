/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_collector_handler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:50:14 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/11/08 13:08:33 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	sl_count_collec(t_game *game)
{
	int	i;
	int	j;
	int	total;

	total = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == MAP_COLLEC)
				total++;
			j++;
		}
		i++;
	}
	return (total);
}

void	sl_delete_collec(t_game *game)
{
	int	i;
	int	count;

	i = 0;
	count = game->n_collec;
	while (i < count)
	{
		if (((game->img->collec->instances[i].y
					== game->img->fch->instances->y)
				&& (game->img->collec->instances[i].x
					== game->img->fch->instances->x))
			&& game->img->collec->instances[i].enabled == true)
		{
			count--;
			game->img->collec->instances[i].enabled = false;
			return ;
		}
		i++;
	}
}

void	sl_collector(t_game *game)
{
	if (game->map[game->img->fch->instances->y / T_S]
		[game->img->fch->instances->x / T_S] == MAP_COLLEC)
	{
		sl_delete_collec(game);
		game->map[game->img->fch->instances->y / T_S]
		[game->img->fch->instances->x / T_S] = MAP_FLOOR;
		game->collec_count++;
		if (game->collec_count == game->n_collec)
			game->img->exit_c->instances->enabled = false;
	}
	if (game->map[game->img->fch->instances->y / T_S]
		[game->img->fch->instances->x / T_S] == MAP_EXIT)
	{
		if (game->collec_count == game->n_collec)
			sl_cleanup_game(game);
	}
}
