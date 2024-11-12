/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_checker2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:24:13 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/29 17:24:28 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	sl_c_checker(char **map, int *c)
{
	int	i;
	int	j;

	if (map == NULL || c == NULL)
		return ;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				*c += 1;
			j++;
		}
		i++;
	}
}

void	sl_e_checker(char **map, int *e)
{
	int	i;
	int	j;

	if (map == NULL || e == NULL)
		return ;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				*e += 1;
			j++;
		}
		i++;
	}
}

void	sl_p_checker(char **map, int *p)
{
	int	i;
	int	j;

	if (map == NULL || p == NULL)
		return ;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				*p += 1;
			j++;
		}
		i++;
	}
}

int	sl_content_checker(char	**map)
{
	int	p;
	int	e;
	int	c;

	if (map == NULL)
		return (1);
	p = 0;
	e = 0;
	c = 0;
	sl_p_checker(map, &p);
	sl_e_checker(map, &e);
	sl_c_checker(map, &c);
	if (p == 1 && e == 1 && c >= 1)
		return (0);
	return (1);
}
