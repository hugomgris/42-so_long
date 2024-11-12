/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_checker3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 08:50:10 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/11/07 17:05:03 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_point	*sl_create_point(int rows, int cols)
{
	t_point	*point;

	point = malloc(sizeof(t_point));
	if (point)
	{
		point->max_rows = rows;
		point->max_cols = cols;
		point->check = 0;
	}
	return (point);
}

int	sl_cleanup(t_point *char_pos, char **flood_map, int ret)
{
	free(char_pos);
	if (flood_map)
		ft_free(flood_map);
	return (ret);
}

int	sl_ent_count(char **map)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	res = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E' || map[i][j] == 'C')
				res++;
			j++;
		}
		i++;
	}
	return (res);
}

int	sl_valid_entities(char c)
{
	if (c == '1' || c == '0' || c == 'E' || c == 'P' || c == 'C' || c == 'M'
		|| c == 'W')
		return (1);
	return (0);
}

int	sl_entities_checker(char **map)
{
	int	i;
	int	j;

	if (map == NULL)
		return (1);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!sl_valid_entities(map[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
