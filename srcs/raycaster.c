/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:52:50 by lle-bret          #+#    #+#             */
/*   Updated: 2023/04/04 18:23:16 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	follow_ray(t_data *data)
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

t_double_vect	side_dist(t_data *data)
{
	t_double_vect	d;

	d.x = data->rc->step.x * (data->rc->square.x - data->rc->player.x
			+ (data->rc->step.x >= 0)) * data->rc->deltaDist.x;
	d.y = data->rc->step.y * (data->rc->square.y - data->rc->player.y
			+ (data->rc->step.y >= 0)) * data->rc->deltaDist.y;
	return (d);
}

void	draw_ver_line(t_data *data, int screen_x)
{
	data->rc->square.x = (int) data->rc->player.x;
	data->rc->square.y = (int) data->rc->player.y;
	data->rc->camera_x = 2 * screen_x / (double) WINDOW_WIDTH - 1;
	data->rc->rayDir = vect_sum(data->rc->dir, scalar_mult(data->rc->plane,
				data->rc->camera_x));
	data->rc->deltaDist = set_vect(ft_double_abs(1 / data->rc->rayDir.x),
			ft_double_abs(1 / data->rc->rayDir.y));
	data->rc->step = set_step(data->rc->rayDir);
	data->rc->sideDist = side_dist(data);
	data->rc->hit = 0;
	while (data->rc->hit == 0)
		follow_ray(data);
	if (data->rc->side)
		data->rc->perp_wall_dist = (data->rc->sideDist.y
				- data->rc->deltaDist.y);
	else
		data->rc->perp_wall_dist = (data->rc->sideDist.x
				- data->rc->deltaDist.x);
	data->rc->line_height = (int)(WINDOW_HEIGHT / data->rc->perp_wall_dist);
	data->rc->draw_start = -data->rc->line_height / 2 + WINDOW_HEIGHT / 2;
	data->rc->draw_end = data->rc->line_height / 2 + WINDOW_HEIGHT / 2;
	img_ver_line_put(data, screen_x);
}

void	raycaster(t_data *data, t_img *img, int start, int end)
{
	int			screen_x;

	screen_x = start;
	while (screen_x < end)
	{
		draw_ver_line(data, screen_x);
		++screen_x;
	}
	mlx_put_image_to_window(data->mlx, data->win, img->img, 0, 0);
}
