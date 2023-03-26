/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:05:56 by lle-bret          #+#    #+#             */
/*   Updated: 2023/03/24 18:08:09 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_walls(t_param *param, int i, int j)
{
	int	x;
	int	y;

	x = -1 * (i > 0) + (i == 0);
	while (x < 2 && i + x < param->map.len)
	{
		y = -1 * (j > 0) + (j == 0);
		while (y < 2 && j + y < param->map.width)
		{
			if (param->map.content[i + x][j + y] != '1'
				&& param->map.content[i + x][j + y] != ' ')
				ft_error(param, NO_WALLS);
			++y;
		}
		++x;
	}
}

void	init_player(t_param *param, int i, int j, int *start)
{
	char	c;

	if (*start)
		ft_error(param, MULT_START);
	++*start;
	param->player.x = i;
	param->player.y = j;
	c = param->map.content[i][j];
	param->camera.x = (c == 'S') - (c == 'N');
	param->camera.y = (c == 'E') - (c == 'W');
}

void	validate_map(t_param *param)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	start = 0;
	while (i < param->map.len)
	{
		j = 0;
		while (j < param->map.width)
		{
			if ((i == 0 || i == param->map.len || j == 0
				|| j == param->map.width) && !(param->map.content[i][j] == '1'
				|| param->map.content[i][j] == ' '))
				ft_error(param, NO_WALLS);
			if (ft_strchr("NSEW", param->map.content[i][j]))
				init_player(param, i, j, &start);
			else if (param->map.content[i][j] == ' ')
				check_walls(param, i, j) ;
			else if (!ft_strchr("01", param->map.content[i][j]))
				ft_error(param, FORBIDDEN_CHAR);
			++j;
		}
		++i;
	}
	if (!start)
		ft_error(param, NO_START);
}
