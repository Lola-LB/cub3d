/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_draw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:23:09 by lle-bret          #+#    #+#             */
/*   Updated: 2023/03/29 17:43:13 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	img_pixel_put(t_img *img, int x, int y, int color)
{
	char    *pixel;

    pixel = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(int *) pixel = color;
}

t_img	get_texture(t_data *data, t_raycaster rc)
{
	t_img	texture;
	int		id;

	if (rc.side)
	{
		id = (EA * (data->player.x > rc.map.x)
		+ WE * (data->player.x < rc.map.x));
	}
	else
	{
		id = (SO * (data->player.y > rc.map.y)
		+ NO * (data->player.y < rc.map.y));
	}
	texture = data->texture[id];
	return (texture);
}

t_int_vect	getTexCoord(t_data *data, t_raycaster rc, t_img texture)
{
	t_int_vect	tex;
	double		wallX;

	if (rc.side)
		wallX = data->player.x + rc.perpWallDist * rc.rayDir.x;
	else
		wallX = data->player.y + rc.perpWallDist * rc.rayDir.y;
	wallX -= floor(wallX);
	tex.x = (int) round(wallX * texture.width);
	if (rc.side == 0 && rc.rayDir.x > 0)
		tex.x = texture.width - tex.x - 1;
    if (rc.side == 1 && rc.rayDir.y < 0)
		tex.x = texture.width - tex.x - 1;
	return (tex);
}

void	img_verLine_put(t_data *data, int screenX, t_raycaster rc)
{
	t_img		texture;
	t_int_vect	tex;
	int			color;
	double		step;
	int			y;

	texture = get_texture(data, rc);
	tex = getTexCoord(data, rc, texture);
	y = rc.drawStart;
	step = (double) texture.height / (double) (rc.drawEnd - rc.drawStart);
	while (y < rc.drawEnd)
	{
		tex.y = (int) (y - rc.drawStart) * step;
		color = texture.addr[texture.line_length * tex.y + tex.x * (texture.bpp / 8)];
		img_pixel_put(data->screen, screenX, y, color);
		++y;
	}
}

void	draw_background(t_data *data)
{
	int		i;
	int		j;

	if (!data->screen->img)
	{
		data->screen->img = mlx_new_image(data->mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT);
		data->screen->addr = mlx_get_data_addr(data->screen->img,
			&data->screen->bpp, &data->screen->line_length,
			&data->screen->endian);
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
