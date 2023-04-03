/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:13:32 by lle-bret          #+#    #+#             */
/*   Updated: 2023/04/03 13:08:43 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	read_lines(t_data *data, int fd, char *line, int *len)
{
	int	i;

	i = 0;
	while (line)
	{
		if (i == *len)
		{
			data->map->content = (char **) ft_realloc(data->map->content,
					sizeof(char *) * (*len), sizeof(char *) * (*len + MAP_LEN));
			*len += MAP_LEN;
		}
		data->map->content[i] = line;
		line = get_next_line(fd);
		i++;
	}
	return (i);
}

void	read_content(int fd, t_data *data)
{
	int		i;
	int		len;
	char	*line;

	len = MAP_LEN;
	data->map->content = (char **) ft_calloc(len, sizeof(char *));
	line = get_next_line(fd);
	while (line && *line == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	i = read_lines(data, fd, line, &len);
	data->map->content = (char **) ft_realloc(data->map->content,
			sizeof(char *) * (i + 1), sizeof(char *) * len);
	data->map->content[i] = NULL;
}

void	rectangular_map(t_data *data)
{
	int	max;
	int	len;
	int	i;

	max = 0;
	i = 0;
	while (data->map->content[i])
	{
		len = ft_strlen(data->map->content[i]) - 1;
		data->map->content[i][len] = 0;
		if (len > max)
			max = len;
		++i;
	}
	i = 0;
	while (data->map->content[i])
	{
		len = ft_strlen(data->map->content[i]);
		data->map->content[i] = ft_realloc(data->map->content[i], len, max + 1);
		ft_memset(data->map->content[i] + len, ' ', max - len);
		data->map->content[i][max] = 0;
		++i;
	}
	data->map->len = i;
	data->map->width = max;
}

void	read_map(int fd, t_data *data)
{
	read_content(fd, data);
	rectangular_map(data);
	validate_map(data);
}
