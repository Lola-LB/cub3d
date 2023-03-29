/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:52:50 by lle-bret          #+#    #+#             */
/*   Updated: 2023/03/29 18:41:36 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	followRay(t_data *data)
{
	if (data->rc->sideDist.x < data->rc->sideDist.y)
	{
		data->rc->sideDist.x += data->rc->deltaDist.x;
		data->rc->square.x += data->rc->step.x;
		data->rc->side = 0;
	}
	else
	{
		data->rc->sideDist.y += data->rc->deltaDist.y;
		data->rc->square.y += data->rc->step.y;
		data->rc->side = 1;
	}
	if (data->map->content[data->rc->square.y][data->rc->square.x] == '1')
		data->rc->hit = 1;
}

void	draw_verLine(t_data *data, int screenX)
{
	data->rc->cameraX = 2 * screenX / (double) WINDOW_WIDTH - 1;
	data->rc->rayDir = vect_sum(data->rc->dir, scalar_mult(data->rc->plane, data->rc->cameraX));
	data->rc->square.x = (int) data->rc->pos.x;
	data->rc->square.y = (int) data->rc->pos.y;
	data->rc->deltaDist = set_vect(ft_doubleAbs(1 / data->rc->rayDir.x),
		ft_doubleAbs(1 / data->rc->rayDir.y));
	data->rc->step = set_step(data->rc->rayDir);
	data->rc->sideDist = set_vect(data->rc->step.x * (data->rc->square.x - data->rc->pos.x
		+ (data->rc->step.x >= 0)) * data->rc->deltaDist.x, data->rc->step.y
		* (data->rc->square.y - data->rc->pos.y + (data->rc->step.y >= 0)) * data->rc->deltaDist.y);
	data->rc->hit = 0;
	while (data->rc->hit == 0)
		followRay(data);
	if (data->rc->side)
		data->rc->perpWallDist = (data->rc->sideDist.y - data->rc->deltaDist.y);
	else
		data->rc->perpWallDist = (data->rc->sideDist.x - data->rc->deltaDist.x);
	data->rc->lineHeight = (int) (WINDOW_HEIGHT / data->rc->perpWallDist);
	data->rc->drawStart = ft_max(0, -data->rc->lineHeight / 2 + WINDOW_HEIGHT / 2);
	data->rc->drawEnd = ft_min(WINDOW_HEIGHT - 1, data->rc->lineHeight / 2
		+ WINDOW_HEIGHT / 2);
	img_verLine_put(data, screenX);
}

void	raycaster(t_data *data)
{
	double		time;
	double		oldTime;
	int			screenX;

	(void) time;
	(void) oldTime;
	draw_background(data);
	data->rc->pos = set_vect(data->player.x, data->player.y);
	data->rc->dir = set_vect(data->direction.x, data->direction.y);
	data->rc->plane = set_vect(-0.66 * data->direction.y, -0.66 * data->direction.x);
	time = 0;
	oldTime = 0;
	screenX = 0;
	while (screenX < WINDOW_WIDTH)
	{
		draw_verLine(data, screenX);
		++screenX;
    }
	mlx_put_image_to_window(data->mlx, data->win, data->screen->img, 0, 0);
}
