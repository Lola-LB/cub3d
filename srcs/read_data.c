/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:11:33 by lle-bret          #+#    #+#             */
/*   Updated: 2023/03/24 16:38:39 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_line(char *line, t_param *param)
{
	int	i;

	i = 0;
	while (i < 6 && ft_strncmp(line, param->identifiers[i],
		ft_strlen(param->identifiers[i])) != 0)
		++i;
	if (i == 6)
		ft_error(param, MISSING_DATA);
	if (!param->store_data[i])
	{
		param->store_data[i] = ft_strdup(line + ft_strlen(param->identifiers[i] + 1));
		if (!param->store_data[i])
			ft_error(param, MALLOC_ERROR);
	}
	else
		ft_error(param, DUPLICATE_DATA);
}

void	parse_color(t_param *param, char *line, t_RGB color)
{
	char	**tmp;

	tmp = ft_split(line, ',');
	if (ft_arlen(tmp) != 3
		&& !(ft_strdigit(tmp[0]) && ft_strdigit(tmp[1]) && ft_strdigit(tmp[2])))
	{
		ft_free((void **) tmp, 3);
		ft_error(param, INVALID_DATA);
	}
	color.R = ft_atoi(tmp[0]);
	color.G = ft_atoi(tmp[1]);
	color.B = ft_atoi(tmp[2]);
	ft_free((void **) tmp, 3);
}

void	read_data(int fd, t_param *param)
{
	char	*line;
	int		data;

	param->store_data = (char **) ft_calloc(6, sizeof(char *));
	if (!param->store_data)
		ft_error(param, MALLOC_ERROR);
	data = 0;
	line = get_next_line(fd);
	while (data != 6 && line)
	{
		while (line && *line == '\n')
			line = get_next_line(fd);
		if (line)
		{
			parse_line(line, param);
			line = get_next_line(fd);
			++data;
		}
	}
	if (data != 6)
		ft_error(param, MISSING_DATA);
	parse_color(param, param->store_data[4], param->floor_color);
	parse_color(param, param->store_data[5], param->ceiling_color);
}