/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:05:34 by lle-bret          #+#    #+#             */
/*   Updated: 2023/02/06 19:15:33 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	nb_enemy(t_param *param)
{
	int	nb;
	int	i;
	int	j;

	nb = 0;
	i = 1;
	while (i < param->map.len - 1)
	{
		j = 1;
		while (j < param->map.width - 1)
		{
			if (param->map.map[i][j] == '0')
				++nb;
			++j;
		}
		++i;
	}
	return ((nb / 30) + (nb < 30) * (nb > 0));
}

void	init_enemy(t_param *param)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	param->enemies.nb = nb_enemy(param);
	param->enemies.enemy = malloc(sizeof(t_enemy) * param->enemies.nb);
	if (!param->enemies.enemy)
		ft_error(param, MALLOC_ERROR);
	while (i < param->enemies.nb)
	{
		x = 0;
		y = 0;
		while (param->map.map[x][y] != '0')
		{
			x = rand() % param->map.len;
			y = rand() % param->map.width;
		}
		param->enemies.enemy[i].loc.x = x;
		param->enemies.enemy[i].loc.y = y;
		param->map.map[x][y] = 'X';
		param->enemies.enemy[i].dead = 0;
		++i;
	}
}

void	step_enemy(t_param *param, int i, int x, int y)
{
	if (!param->enemies.enemy[i].dead
		&& (param->map.map[param->enemies.enemy[i].loc.x
				+ x][param->enemies.enemy[i].loc.y + y] == '0'
		|| param->map.map[param->enemies.enemy[i].loc.x
			+ x][param->enemies.enemy[i].loc.y + y] == 'P'))
	{
		param->map.map[param->enemies.enemy[i].loc.x]
		[param->enemies.enemy[i].loc.y] = '0';
		param->enemies.enemy[i].loc.x += x;
		param->enemies.enemy[i].loc.y += y;
		param->map.map[param->enemies.enemy[i].loc.x]
		[param->enemies.enemy[i].loc.y] = 'X';
	}
}

void	move_enemy(t_param *param)
{
	int	i;
	int	dep;
	int	x;
	int	y;

	i = 0;
	while (i < param->enemies.nb)
	{
		x = 0;
		y = 0;
		while (!param->enemies.enemy[i].dead && !(x || y))
		{
			dep = rand() % 2;
			x = (dep == 0) * ((param->enemies.enemy[i].loc.x < param->player.x)
					- (param->enemies.enemy[i].loc.x > param->player.x));
			y = (dep == 1) * ((param->enemies.enemy[i].loc.y < param->player.y)
					- (param->enemies.enemy[i].loc.y > param->player.y));
		}
		step_enemy(param, i, x, y);
		++i;
	}
}

void	check_enemy(t_param *param)
{
	int	x;
	int	y;
	int	i;

	x = param->player.x;
	y = param->player.y;
	i = 0;
	while (i < param->enemies.nb)
	{
		if (!param->enemies.enemy[i].dead && param->enemies.enemy[i].loc.x
			== x && param->enemies.enemy[i].loc.y == y)
			end_screen(param, 0);
		++i;
	}
}
