/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:13:32 by lle-bret          #+#    #+#             */
/*   Updated: 2023/03/27 12:43:44 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	read_lines(int fd, t_data *data)
{
	int		i;
	int		len;
	char	*line;

	len = MAP_LEN;
	data->map.content = (char **) ft_calloc(len, sizeof(char *));
	i = 0;
	line = get_next_line(fd);
	while (line && *line == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	while (line)
	{
		if (i == len)
		{
			data->map.content = (char **) ft_realloc(data->map.content, sizeof(char *) * len, sizeof(char *) * (len + MAP_LEN));
			len += MAP_LEN;
		}
		data->map.content[i] = line;
		line = get_next_line(fd);
		++i;
	}
	data->map.content = (char **) ft_realloc(data->map.content, sizeof(char *) * (i + 1), sizeof(char *) * len);
	data->map.content[i] = NULL;
}

void	rectangular_map(t_data *data)
{
	int	max;
	int	len;
	int	i;

	max = 0;
	i = 0;
	while (data->map.content[i])
	{
		len = ft_strlen(data->map.content[i]) - 1;
		data->map.content[i][len] = 0;
		if (len > max)
			max = len;
		++i;
	}
	i = 0;
	while (data->map.content[i])
	{
		len = ft_strlen(data->map.content[i]);
		data->map.content[i] = ft_realloc(data->map.content[i], len, max + 1);
		ft_memset(data->map.content[i] + len, ' ', max - len);
		data->map.content[i][max] = 0;
		++i;
	}
	data->map.len = i;
	data->map.width = max;
}

void	read_map(int fd, t_data *data)
{
	read_lines(fd, data);
	rectangular_map(data);
	validate_map(data);
	printf("valid map\n");
}