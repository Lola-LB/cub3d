/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:05:56 by lle-bret          #+#    #+#             */
/*   Updated: 2023/04/03 13:47:52 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_walls(t_data *data, int i, int j)
{
	int	x;
	int	y;

	x = -1 * (i > 0) + (i == 0);
	while (x < 2 && i + x < data->map->len)
	{
		y = -1 * (j > 0) + (j == 0);
		while (y < 2 && j + y < data->map->width)
		{
			if (data->map->content[i + x][j + y] != '1'
				&& data->map->content[i + x][j + y] != ' ')
			{
				if (!ft_strchr("NSEW01 ", data->map->content[i + x][j + y]))
					ft_error(data, FORBIDDEN_CHAR);
				ft_error(data, NO_WALLS);
			}
			++y;
		}
		++x;
	}
}

void	init_player(t_data *data, int i, int j, int *start)
{
	char	c;

	if (*start)
		ft_error(data, MULT_START);
	++*start;
	data->rc->player.y = i + 0.5;
	data->rc->player.x = j + 0.5;
	c = data->map->content[i][j];
	data->rc->dir.x = (c == 'E') - (c == 'W');
	data->rc->dir.y = (c == 'S') - (c == 'N');
	data->rc->plane = set_vect(-0.66 * data->rc->dir.y,
			-0.66 * data->rc->dir.x);
	if (c == 'S' || c == 'N')
		data->rc->rot.y *= -1;
}

void	validate_position(t_data *data, int i, int j, int *start)
{
	if (!ft_strchr("NSEW01 ", data->map->content[i][j]))
		ft_error(data, FORBIDDEN_CHAR);
	else if ((i == 0 || i == data->map->len || j == 0
			|| j == data->map->width)
		&& !(data->map->content[i][j] == '1'
		|| data->map->content[i][j] == ' '))
		ft_error(data, NO_WALLS);
	else if (ft_strchr("NSEW", data->map->content[i][j]))
		init_player(data, i, j, start);
	else if (data->map->content[i][j] == ' ')
		check_walls(data, i, j);
}

void	validate_map(t_data *data)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	start = 0;
	while (i < data->map->len)
	{
		j = 0;
		while (j < data->map->width)
		{
			validate_position(data, i, j, &start);
			++j;
		}
		++i;
	}
	if (!start)
		ft_error(data, NO_START);
}
