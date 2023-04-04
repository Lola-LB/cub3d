/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_draw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:23:09 by lle-bret          #+#    #+#             */
/*   Updated: 2023/04/04 18:19:30 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	img_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(int *) pixel = color;
}

t_img	*get_texture(t_data *data)
{
	t_img	*texture;
	int		id;

	if (data->rc->side)
	{
		id = (EA * (data->rc->step.x == -1)
				+ WE * (data->rc->step.x == 1));
	}
	else
	{
		id = (SO * (data->rc->step.y == -1)
				+ NO * (data->rc->step.y == 1));
	}
	texture = (data->texture + id);
	return (texture);
}

t_int_vect	get_tex_coord(t_data *data, t_img texture)
{
	t_int_vect	tex;
	double		wall_x;

	if (data->rc->side)
		wall_x = data->rc->player.x + data->rc->perp_wall_dist
			* data->rc->rayDir.x;
	else
		wall_x = data->rc->player.y + data->rc->perp_wall_dist
			* data->rc->rayDir.y;
	wall_x -= floor(wall_x);
	tex.x = (int) round(wall_x * texture.width);
	if (data->rc->side == 0 && data->rc->rayDir.x > 0)
		tex.x = ft_max(0, texture.width - tex.x - 1);
	else if (data->rc->side == 1 && data->rc->rayDir.y < 0)
		tex.x = ft_max(0, texture.width - tex.x - 1);
	return (tex);
}

void	img_ver_line_put(t_data *data, int screenX)
{
	t_img		*texture;
	t_int_vect	tex;
	int			color;
	double		step;
	int			y;

	texture = get_texture(data);
	tex = get_tex_coord(data, *texture);
	y = 0;
	step = (double) texture->height
		/ (double)(data->rc->draw_end - data->rc->draw_start);
	while (y < WINDOW_HEIGHT)
	{
		if (y < data->rc->draw_start)
			color = data->ceiling_color;
		else if (y < data->rc->draw_end)
		{
			tex.y = ft_min((int)((y - data->rc->draw_start) * step),
					texture->height - 1);
			color = *(int *)(texture->addr + texture->line_length * tex.y
					+ tex.x * (texture->bpp / 8));
		}
		else
			color = data->floor_color;
		img_pixel_put(data->screen, screenX, y, color);
		++y;
	}
}
