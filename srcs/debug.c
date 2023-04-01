/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:49:43 by lle-bret          #+#    #+#             */
/*   Updated: 2023/04/01 14:37:35 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map(t_data *data)
{
	int	i;

	i = 0;
	printf("width: %i, length: %i\n", data->map->width, data->map->len);
	while (data->map->content[i])
	{
		printf("%s\n", data->map->content[i]);
		++i;
	}
}

void	print_vect(t_double_vect v)
{
	printf("x=%lf y=%lf\n", v.x, v.y);
}

void	print_rc(t_data *data)
{
	printf("\nplayer:\n");
	print_vect(data->rc->player);
	printf("map:\nx=%i y=%i\n", data->rc->square.x, data->rc->square.y);
	printf("rayDir:\n");
	print_vect(data->rc->rayDir);
	printf("sideDist:\n");
	print_vect(data->rc->sideDist);
	printf("deltaDist:\n");
	print_vect(data->rc->deltaDist);
	printf("step:\n");
	print_vect(data->rc->step);
	printf("side: %i\n", data->rc->side);
	printf("perpWallDist:\n %f\n", data->rc->perp_wall_dist);
	printf("lineheight:\n %i\n", data->rc->line_height);
	printf("drawStart=%i drawEnd=%i\n\n", data->rc->draw_start,
		data->rc->draw_end);
}

void	print_img(t_img *img)
{
	printf("addr: %p, bpp: %i, endian: %i, line_length: %i, ",
		img->addr, img->bpp, img->endian, img->line_length);
	printf("height: %i, width: %i\n", img->height, img->width);
}

void	print_adresses(t_data *data)
{
	printf("mlx: %p\nwin: %p\nmap: %p\nstore_data: %p\nidentifiers: %p\n",
		data->mlx, data->win, data->map, data->store_data, data->identifiers);
	printf("texture: %p\nscreen: %p\nrc: %p\n",
		data->texture, data->screen, data->rc);
}
