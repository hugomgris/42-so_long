/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_game_initialiser.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:44:02 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/11/08 13:29:05 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

char	**sl_load_map(char *filename)
{
	int		rows;
	int		cols;
	char	**map;

	rows = 0;
	cols = 0;
	map = sl_map_parser(filename, &rows, &cols);
	if (!map)
		return (NULL);
	return (map);
}

void	sl_measure_map(t_game *game, char **map)
{
	int	i;

	i = 0;
	game->n_collec = sl_count_collec(game);
	game->map_width = ft_strlen(map[0]) * T_S;
	while (map[i])
		i++;
	game->map_height = i * T_S;
}

int	sl_init_game(t_game *game)
{
	game->move_count = 0;
	game->collec_count = 0;
	game->n_enem = 0;
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game->mlx = mlx_init(game->map_width, game->map_height, "so_long", true);
	if (!(game->mlx))
		return (FALSE);
	sl_prep_textures(game);
	sl_prep_imgs(game);
	sl_render_map(game, game->img);
	mlx_key_hook(game->mlx, &sl_input_handler, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	ft_free(game->map);
	free(game->textu);
	free(game->img);
	return (TRUE);
}
