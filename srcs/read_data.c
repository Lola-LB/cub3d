/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:11:33 by lle-bret          #+#    #+#             */
/*   Updated: 2023/04/03 13:08:31 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_line(char *line, t_data *data)
{
	int	i;

	i = 0;
	while (i < 6 && ft_strncmp(line, data->identifiers[i],
			ft_strlen(data->identifiers[i])) != 0)
		++i;
	if (i == 6)
		ft_error(data, MISSING_DATA);
	if (!data->store_data[i])
	{
		data->store_data[i] = ft_strdup(line + ft_strlen(data->identifiers[i]));
		if (!data->store_data[i])
			ft_error(data, MALLOC_ERROR);
		data->store_data[i][ft_strlen(data->store_data[i]) - 1] = 0;
	}
	else
	{
		free(line);
		ft_error(data, DUPLICATE_DATA);
	}
	free(line);
}

int	parse_color(t_data *data, char *line)
{
	char	**tmp;
	int		color;

	tmp = ft_split(line, ',');
	if (ft_arlen(tmp) != 3
		&& !(ft_strdigit(tmp[0]) && ft_strdigit(tmp[1]) && ft_strdigit(tmp[2])))
	{
		ft_free((void **) tmp, 3);
		ft_error(data, INVALID_DATA);
	}
	color = (ft_atoi(tmp[0]) << 16 | ft_atoi(tmp[1]) << 8 | ft_atoi(tmp[2]));
	ft_free((void **) tmp, 3);
	return (color);
}

void	read_data(int fd, t_data *data)
{
	char	*line;
	int		id;

	id = 0;
	line = get_next_line(fd);
	while (id != 6 && line)
	{
		while (line && *line == '\n')
		{
			free(line);
			line = get_next_line(fd);
		}
		if (line)
		{
			parse_line(line, data);
			line = get_next_line(fd);
			++id;
		}
	}
	if (line)
		free(line);
	if (id != 6)
		ft_error(data, MISSING_DATA);
	data->floor_color = parse_color(data, data->store_data[4]);
	data->ceiling_color = parse_color(data, data->store_data[5]);
}
