/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_checker1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:33:31 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/11/07 12:55:27 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	sl_check_row_wall(char *row, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
		if (row[i++] != '1')
			return (1);
	return (0);
}

int	sl_enclose_checker(char **map, int rows, int cols)
{
	int	i;

	i = 0;
	if (rows < 1 || cols < 1 || map[0] == NULL)
		return (1);
	if (sl_check_row_wall(map[0], cols)
		|| sl_check_row_wall(map[rows - 1], cols))
		return (1);
	while (i < rows)
	{
		if (map[i][0] != '1' || map[i][cols - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	sl_form_checker(char **map, int rows)
{
	int	row_l;
	int	row_c;
	int	i;

	if (rows == 0 || map[0] == NULL)
		return (1);
	row_l = ft_strlen(map[0]);
	row_c = 0;
	i = 0;
	while (map[i])
	{
		row_c = ft_strlen(map[i]);
		if (row_c != row_l)
			return (1);
		i++;
	}
	return (0);
}

int	sl_empty_checker(char **map, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		if (map[i][0] == '\0' || map[i][0] == '\n' || map[i][0] == '\r')
			return (1);
		i++;
	}
	return (0);
}

int	sl_checker(char	**map, int rows, int cols)
{
	int	checker;

	checker = sl_empty_checker(map, rows);
	if (checker)
		return (sl_error(3));
	checker += sl_form_checker(map, rows);
	if (checker)
		return (sl_error(4));
	checker += sl_enclose_checker(map, rows, cols);
	if (checker)
		return (sl_error(6));
	checker += sl_content_checker(map);
	if (checker)
		return (sl_error(5));
	checker += sl_entities_checker(map);
	if (checker)
		return (sl_error(7));
	checker += sl_path_checker(map, rows, cols);
	if (checker)
		return (sl_error(8));
	return (checker);
}
