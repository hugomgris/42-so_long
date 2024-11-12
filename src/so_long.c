/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:25:46 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/11/06 11:43:10 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	srand(time(NULL));
	if (argc != 2)
		return (sl_error(1));
	game.map = sl_load_map(argv[1]);
	if (!game.map)
		return (1);
	sl_measure_map(&game, game.map);
	if (sl_init_game(&game) == FALSE)
		return (ft_printf(INIT_ERROR), 1);
	return (0);
}
