/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:31:03 by lle-bret          #+#    #+#             */
/*   Updated: 2023/02/06 19:23:14 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map map)
{
	int	i;

	i = 0;
	while (i < map.len)
	{
		free(map.map[i]);
		++i;
	}
	free(map.map);
}

void	ft_error(t_param *param, char *error)
{
	printf("Error\n%s\n", error);
	end_game(param);
}

void	init_param(t_param *param, t_map map)
{
	param->map = map;
	param->mlx = NULL;
	param->win = NULL;
	param->img = NULL;
	check_map(param);
	param->left = 0;
	param->burp = 0;
	param->move = 0;
	param->end_game = 0;
}

void	end_screen(t_param *param, int win)
{
	param->end_game = 1;
	if (win)
		mlx_put_image_to_window(param->mlx, param->win,
			param->img[15].img, 0, 0);
	else
		mlx_put_image_to_window(param->mlx, param->win,
			param->img[14].img, 0, 0);
}
