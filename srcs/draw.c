/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:23:09 by lle-bret          #+#    #+#             */
/*   Updated: 2023/03/28 18:54:59 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	img_pixel_put(t_img *img, int x, int y, int color)
{
	char    *pixel;

    pixel = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(int *) pixel = color;
}

void	img_verLine_put(t_data *data, int screenX, t_raycaster rc)
{
	int	j;
	int color;

	j = rc.drawStart;
	color = 255 << 8;	
	if (rc.side == 1)
		color = color / 2;
	while (j < rc.drawEnd)
	{
		img_pixel_put(data->screen, screenX, j, color);
		++j;
	}
}

void	draw_background(t_data *data)
{
	int		i;
	int		j;

	if (!data->screen->img)
	{
		data->screen->img = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
		data->screen->addr = mlx_get_data_addr(data->screen->img, &data->screen->bpp,
			&data->screen->line_length, &data->screen->endian);
		i = 0;
		while (i < WINDOW_HEIGHT)
		{
			j = 0;
			while (j < WINDOW_WIDTH)
			{
				img_pixel_put(data->screen, j, i,
					data->ceiling_color * (i < WINDOW_HEIGHT / 2)
					+ data->floor_color * (i >= WINDOW_HEIGHT / 2));
				++j;
			}
			++i;
		}
	}
}
