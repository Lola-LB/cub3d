/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 21:24:09 by lle-bret          #+#    #+#             */
/*   Updated: 2023/01/17 20:08:15 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	closed_walls(t_param *param)
{
	int	i;
	int	j;
	int	width;

	width = ft_strlen(param->map.map[0]);
	i = 1;
	while (*(param->map.map + i + 1))
	{
		if (**(param->map.map + i) != '1'
			|| *(*(param->map.map + i) + width - 1) != '1')
			ft_error(param, NO_WALLS);
		++i;
	}
	j = 0;
	while (*param->map.map && *(*param->map.map + j))
	{
		if (*(*param->map.map + j) != '1'
			|| *(*(param->map.map + i) + j) != '1')
			ft_error(param, NO_WALLS);
		++j;
	}
}

void	rectangular(t_param *param)
{
	int	len;
	int	i;

	len = ft_strlen(param->map.map[0]);
	i = 1;
	while (*(param->map.map + i))
	{
		if (ft_strlen(*(param->map.map + i)) != len)
			ft_error(param, NOT_RECTANGULAR);
		++i;
	}
}

void	clean_map(t_param *param)
{
	int	i;
	int	j;

	i = 0;
	while (param->map.map[i])
	{
		j = 0;
		while (param->map.map[i][j])
		{
			if (param->map.map[i][j] == '\n')
				param->map.map[i][j] = 0;
			++j;
		}
		++i;
	}
}

int	check_map(t_param *param)
{
	clean_map(param);
	rectangular(param);
	closed_walls(param);
	char_contained(param, 0, 0, 0);
	valid_path(param->map);
	return (1);
}
