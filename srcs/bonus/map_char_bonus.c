/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_char_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:05:56 by lle-bret          #+#    #+#             */
/*   Updated: 2023/01/17 19:07:24 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_char(t_param *param, int exit, int start, int collectible)
{
	if (exit > 1)
		ft_error(param, MULT_EXIT);
	if (start > 1)
		ft_error(param, MULT_START);
	if (!exit)
		ft_error(param, NO_EXIT);
	if (!start)
		ft_error(param, NO_START);
	if (!collectible)
		ft_error(param, NO_COLL);
}

void	init_loc(t_loc *loc, int *start, int i, int j)
{
	loc->x = i;
	loc->y = j;
	++*start;
}

void	char_contained(t_param *param, int exit, int start, int collectible)
{
	int	i;
	int	j;

	i = 1;
	while (param->map.map[i + 1])
	{
		j = 1;
		while (param->map.map[i][j + 1])
		{
			if (param->map.map[i][j] == 'E')
				init_loc(&param->exit, &exit, i, j);
			collectible += (param->map.map[i][j] == 'C');
			if (param->map.map[i][j] == 'P')
				init_loc(&param->player, &start, i, j);
			else if (!ft_strchr("01EC", param->map.map[i][j]))
				ft_error(param, FORBIDDEN_CHAR);
			++j;
		}
		++i;
	}
	param->coll = collectible;
	check_char(param, exit, start, collectible);
}
