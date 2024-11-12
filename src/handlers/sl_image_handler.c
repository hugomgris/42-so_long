/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_image_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:31:00 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/11/07 16:58:31 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	sl_prep_textures(t_game *game)
{
	game->textu = ft_calloc(1, sizeof(t_textu));
	game->textu->floor1 = mlx_load_png("./sprites/enviro/grass1.png");
	game->textu->floor2 = mlx_load_png("./sprites/enviro/grass2.png");
	game->textu->floor3 = mlx_load_png("./sprites/enviro/grass3.png");
	game->textu->c_ul = mlx_load_png("./sprites/enviro/c_ul.png");
	game->textu->c_ur = mlx_load_png("./sprites/enviro/c_ur.png");
	game->textu->c_dl = mlx_load_png("./sprites/enviro/c_dl.png");
	game->textu->c_dr = mlx_load_png("./sprites/enviro/c_dr.png");
	game->textu->w_u = mlx_load_png("./sprites/enviro/w_u.png");
	game->textu->w_d = mlx_load_png("./sprites/enviro/w_d.png");
	game->textu->w_r = mlx_load_png("./sprites/enviro/w_r.png");
	game->textu->w_l = mlx_load_png("./sprites/enviro/w_l.png");
	game->textu->collec = mlx_load_png("./sprites/components/c32.png");
	game->textu->ch[0] = mlx_load_png("./sprites/char/char_u.png");
	game->textu->ch[1] = mlx_load_png("./sprites/char/char_d.png");
	game->textu->ch[2] = mlx_load_png("./sprites/char/char_l.png");
	game->textu->ch[3] = mlx_load_png("./sprites/char/char_r.png");
	game->textu->mid = mlx_load_png("./sprites/enviro/rock.png");
	game->textu->enem = mlx_load_png("./sprites/enem/enem.png");
	game->textu->enem2 = mlx_load_png("./sprites/enem/enem2.png");
	game->textu->exit_c = mlx_load_png("./sprites/components/exit_c.png");
	game->textu->exit_o = mlx_load_png("./sprites/components/exit_o.png");
}

void	sl_prep_imgs(t_game *game)
{
	game->img = ft_calloc(1, sizeof(t_img));
	game->img->floor1 = mlx_texture_to_image(game->mlx, game->textu->floor1);
	game->img->floor2 = mlx_texture_to_image(game->mlx, game->textu->floor2);
	game->img->floor3 = mlx_texture_to_image(game->mlx, game->textu->floor3);
	game->img->c_ul = mlx_texture_to_image(game->mlx, game->textu->c_ul);
	game->img->c_ur = mlx_texture_to_image(game->mlx, game->textu->c_ur);
	game->img->c_dl = mlx_texture_to_image(game->mlx, game->textu->c_dl);
	game->img->c_dr = mlx_texture_to_image(game->mlx, game->textu->c_dr);
	game->img->w_u = mlx_texture_to_image(game->mlx, game->textu->w_u);
	game->img->w_d = mlx_texture_to_image(game->mlx, game->textu->w_d);
	game->img->w_r = mlx_texture_to_image(game->mlx, game->textu->w_r);
	game->img->w_l = mlx_texture_to_image(game->mlx, game->textu->w_l);
	game->img->collec = mlx_texture_to_image(game->mlx, game->textu->collec);
	game->img->ch[0] = mlx_texture_to_image(game->mlx, game->textu->ch[0]);
	game->img->ch[1] = mlx_texture_to_image(game->mlx, game->textu->ch[1]);
	game->img->ch[2] = mlx_texture_to_image(game->mlx, game->textu->ch[2]);
	game->img->ch[3] = mlx_texture_to_image(game->mlx, game->textu->ch[3]);
	game->img->fch = mlx_texture_to_image(game->mlx, game->textu->ch[1]);
	game->img->mid = mlx_texture_to_image(game->mlx, game->textu->mid);
	game->img->enem = mlx_texture_to_image(game->mlx, game->textu->enem);
	game->img->enem2 = mlx_texture_to_image(game->mlx, game->textu->enem2);
	game->img->exit_c = mlx_texture_to_image(game->mlx, game->textu->exit_c);
	game->img->exit_o = mlx_texture_to_image(game->mlx, game->textu->exit_o);
	sl_delete_textures(game);
}

void	sl_delete_textures(t_game *game)
{
	mlx_delete_texture(game->textu->floor1);
	mlx_delete_texture(game->textu->floor2);
	mlx_delete_texture(game->textu->floor3);
	mlx_delete_texture(game->textu->c_ul);
	mlx_delete_texture(game->textu->c_ur);
	mlx_delete_texture(game->textu->c_dl);
	mlx_delete_texture(game->textu->c_dr);
	mlx_delete_texture(game->textu->w_u);
	mlx_delete_texture(game->textu->w_d);
	mlx_delete_texture(game->textu->w_r);
	mlx_delete_texture(game->textu->w_l);
	mlx_delete_texture(game->textu->collec);
	mlx_delete_texture(game->textu->ch[0]);
	mlx_delete_texture(game->textu->ch[1]);
	mlx_delete_texture(game->textu->ch[2]);
	mlx_delete_texture(game->textu->ch[3]);
	mlx_delete_texture(game->textu->mid);
	mlx_delete_texture(game->textu->enem);
	mlx_delete_texture(game->textu->enem2);
	mlx_delete_texture(game->textu->exit_c);
	mlx_delete_texture(game->textu->exit_o);
}

void	sl_disable_start(t_game *game)
{
	game->img->ch[0]->instances->enabled = false;
	game->img->ch[1]->instances->enabled = false;
	game->img->ch[2]->instances->enabled = false;
	game->img->ch[3]->instances->enabled = false;
}
