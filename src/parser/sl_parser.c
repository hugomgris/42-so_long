/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:33:19 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/11/07 13:00:55 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

char	*sl_read_trimmed_line(int fd)
{
	char	*line;
	char	*trim;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	trim = ft_strtrim(line, "\r\n");
	free(line);
	return (trim);
}

int	sl_handle_overflow(char *trim, char **map, int fd, int *rows)
{
	if (*rows >= MAX_ROWS)
	{
		free(trim);
		ft_free(map);
		close(fd);
		return (1);
	}
	return (0);
}

int	sl_read_map(int fd, char **map, int *rows, int *cols)
{
	char	*trim;

	trim = sl_read_trimmed_line(fd);
	if (trim == NULL)
	{
		ft_printf("B\n");
		free(trim);
		ft_free(map);
		return (-1);
	}
	while (trim)
	{
		if (sl_handle_overflow(trim, map, fd, rows))
		{
			ft_free(map);
			return (-1);
		}
		map[*rows] = trim;
		*cols = ft_strlen(trim);
		(*rows)++;
		trim = sl_read_trimmed_line(fd);
	}
	return (0);
}

char	**sl_build_map(char *filename, char **map, int *rows, int *cols)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_free(map);
		return (NULL);
	}
	if (sl_read_map(fd, map, rows, cols) == -1)
	{
		close(fd);
		return (NULL);
	}
	close(fd);
	return (map);
}

char	**sl_map_parser(char *filename, int *rows, int *cols)
{
	int		invalid_map;
	char	**map;

	if (!ft_strnstr(filename + (ft_strlen(filename) - 4), ".ber", 4))
		return (ft_printf(EXT_ERROR), NULL);
	map = ft_calloc(MAX_ROWS, sizeof(char *));
	if (!map)
		return (ft_printf(ALLOC_ERROR), NULL);
	map = sl_build_map(filename, map, rows, cols);
	if (!map)
	{
		ft_free(map);
		return (ft_printf(BUILD_ERROR), NULL);
	}
	invalid_map = sl_checker(map, *rows, *cols);
	if (invalid_map)
	{
		ft_free(map);
		return (NULL);
	}
	return (map);
}
