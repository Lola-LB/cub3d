/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_draw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:23:09 by lle-bret          #+#    #+#             */
/*   Updated: 2023/03/30 18:17:27 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	img_pixel_put(t_img *img, int x, int y, int color)
{
	char    *pixel;

    pixel = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(int *) pixel = color;
}

t_img	get_texture(t_data *data)
{
	t_img	texture;
	int		id;

	if (data->rc->side)
	{
		id = (EA * (data->rc->player.x > data->rc->square.x)
		+ WE * (data->rc->player.x < data->rc->square.x));
	}
	else
	{
		id = (SO * (data->rc->player.y > data->rc->square.y)
		+ NO * (data->rc->player.y < data->rc->square.y));
	}
	texture = data->texture[id];
	return (texture);
}

t_int_vect	get_texCoord(t_data *data, t_img texture)
{
	t_int_vect	tex;
	double		wallX;

	if (data->rc->side)
		wallX = data->rc->player.x + data->rc->perpWallDist * data->rc->rayDir.x;
	else
		wallX = data->rc->player.y + data->rc->perpWallDist * data->rc->rayDir.y;
	wallX -= floor(wallX);
	tex.x = (int) round(wallX * texture.width);
	if (data->rc->side == 0 && data->rc->rayDir.x > 0)
		tex.x = texture.width - tex.x - 1;
    if (data->rc->side == 1 && data->rc->rayDir.y < 0)
		tex.x = texture.width - tex.x - 1;
	return (tex);
}

void	img_verLine_put(t_data *data, int screenX)
{
	t_img		texture;
	t_int_vect	tex;
	int			color;
	double		step;
	int			offset;
	int			y;

	texture = get_texture(data);
	tex = get_texCoord(data, texture);
	y = ft_max(0, data->rc->drawStart);
	step = (double) texture.height / (double) (data->rc->drawEnd - data->rc->drawStart);
	while (y < ft_min(data->rc->drawEnd, WINDOW_HEIGHT - 1))
	{
		tex.y = (int) (y - data->rc->drawStart) * step;
		offset = texture.line_length * tex.y + tex.x * (texture.bpp / 8);
		color = (texture.addr[offset] << 16) + (texture.addr[offset + 1] << 8)
			+ (texture.addr[offset + 2]);
		img_pixel_put(data->background, screenX, y, color);
		++y;
	}
}

