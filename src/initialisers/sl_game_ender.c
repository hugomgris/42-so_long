/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_game_ender.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:47:03 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/11/08 13:31:09 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	sl_clean_img(t_game *game)
{
	mlx_delete_image(game->mlx, game->img->floor1);
	mlx_delete_image(game->mlx, game->img->floor2);
	mlx_delete_image(game->mlx, game->img->floor3);
	mlx_delete_image(game->mlx, game->img->c_ul);
	mlx_delete_image(game->mlx, game->img->c_ur);
	mlx_delete_image(game->mlx, game->img->c_dl);
	mlx_delete_image(game->mlx, game->img->c_dr);
	mlx_delete_image(game->mlx, game->img->w_u);
	mlx_delete_image(game->mlx, game->img->w_d);
	mlx_delete_image(game->mlx, game->img->w_r);
	mlx_delete_image(game->mlx, game->img->w_l);
	mlx_delete_image(game->mlx, game->img->collec);
	mlx_delete_image(game->mlx, game->img->fch);
	mlx_delete_image(game->mlx, game->img->ch[0]);
	mlx_delete_image(game->mlx, game->img->ch[1]);
	mlx_delete_image(game->mlx, game->img->ch[2]);
	mlx_delete_image(game->mlx, game->img->ch[3]);
	mlx_delete_image(game->mlx, game->img->mid);
	mlx_delete_image(game->mlx, game->img->enem);
	mlx_delete_image(game->mlx, game->img->enem2);
	mlx_delete_image(game->mlx, game->img->exit_c);
	mlx_delete_image(game->mlx, game->img->exit_o);
}

void	sl_cleanup_game(t_game *game)
{
	if (game->map)
	{
		ft_free(game->map);
		game->map = NULL;
	}
	if (game->textu)
	{
		free(game->textu);
		game->textu = NULL;
	}
	if (game->img)
	{
		sl_clean_img(game);
		free(game->img);
		game->img = NULL;
	}
	if (game->mlx)
	{
		mlx_close_window(game->mlx);
		mlx_terminate(game->mlx);
		game->mlx = NULL;
	}
	exit(0);
}

void	sl_game_over(t_game *game)
{
	ft_printf("OH NO! A GOBLIN GOT YOU!! GAME OVER!!!\n");
	sl_cleanup_game(game);
	exit(1);
}

int	sl_error(int code)
{
	if (code == 1)
		return (ft_printf(FILE_ERROR), 1);
	else if (code == 2)
		return (ft_printf(EXT_ERROR), 1);
	else if (code == 3)
		return (ft_printf(EMPTY_ERROR), 1);
	else if (code == 4)
		return (ft_printf(FORM_ERROR), 1);
	else if (code == 5)
		return (ft_printf(COMP_ERROR), 1);
	else if (code == 6)
		return (ft_printf(WALL_ERROR), 1);
	else if (code == 7)
		return (ft_printf(ENT_ERROR), 1);
	else
		return (ft_printf(PATH_ERROR), 1);
}
