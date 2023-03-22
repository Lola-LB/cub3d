/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:26:01 by lle-bret          #+#    #+#             */
/*   Updated: 2023/02/07 18:00:51 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_len(char *file)
{
	int		len;
	int		fd;
	char	buff;

	len = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error(NULL, FILE_ERROR);
	buff = '\n';
	while (buff == '\n')
		read(fd, &buff, 1);
	while (read(fd, &buff, 1) > 0)
	{
		if (buff == '\n')
			++len;
	}
	if (buff != '\n')
		++len;
	if (close(fd) == -1)
		ft_error(NULL, SYST_ERROR);
	return (len);
}

void	check_extension(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 5 || ft_strcmp(".ber", file + len - 4) != 0)
		ft_error(NULL, "Map file must end with a .ber extension");
}

void	read_lines(t_map *map, int fd, int len)
{
	int		i;
	char	*line;

	i = 0;
	while (i < len)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free_map(*map);
			ft_error(NULL, GNL_ERROR);
		}
		*(map->map + i) = line;
		++i;
	}
	line = get_next_line(fd);
	*(map->map + i) = NULL;
}

t_map	parse_map(char *file)
{
	t_map	map;
	int		len;
	int		fd;

	check_extension(file);
	len = map_len(file);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error(NULL, FILE_ERROR);
	map.map = malloc(sizeof(char *) * (len + 1));
	if (!map.map)
		ft_error(NULL, MALLOC_ERROR);
	map.len = len;
	read_lines(&map, fd, len);
	if (close(fd) == -1)
	{
		free_map(map);
		ft_error(NULL, SYST_ERROR);
	}
	map.width = ft_strlen(map.map[0]) - 1;
	return (map);
}
