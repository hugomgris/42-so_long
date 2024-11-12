/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_bonus_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:51:59 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/11/07 13:29:00 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	clear_counter(t_game *game, mlx_image_t **counter)
{
	if (*counter)
	{
		mlx_delete_image(game->mlx, *counter);
		*counter = NULL;
	}
}

mlx_image_t	*create_counter_image(t_game *game)
{
	mlx_image_t		*counter;
	unsigned int	i;
	uint32_t		b_c;

	counter = mlx_new_image(game->mlx, 100, 20);
	if (!counter)
		return (NULL);
	i = 0;
	b_c = 0xFF000000;
	while (i < counter->width * counter->height)
		((uint32_t *)counter->pixels)[i++] = b_c;
	return (counter);
}

void	sl_write_counter(t_game *game)
{
	char				*move_count;
	char				*move_numbers;
	static mlx_image_t	*counter;

	move_numbers = ft_itoa(game->move_count);
	if (!move_numbers)
		return ;
	move_count = ft_strjoin("moves: ", move_numbers);
	free(move_numbers);
	if (!move_count)
		return ;
	clear_counter(game, &counter);
	counter = create_counter_image(game);
	if (!counter)
	{
		free(move_count);
		return ;
	}
	mlx_image_to_window(game->mlx, counter, 10, 10);
	mlx_put_string(game->mlx, move_count, 10, 10);
	free(move_count);
}
