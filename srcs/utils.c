/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:39:52 by lle-bret          #+#    #+#             */
/*   Updated: 2023/04/01 14:38:00 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_background(t_data *data, t_img *img)
{
	int		i;
	int		j;

	i = 0;
	while (i < img->height)
	{
		j = 0;
		while (j < img->width)
		{
			img_pixel_put(img, j, i,
				data->ceiling_color * (i < WINDOW_HEIGHT / 2)
				+ data->floor_color * (i >= WINDOW_HEIGHT / 2));
			++j;
		}
		++i;
	}
}

t_double_vect	rotate_vect(t_data *data, t_double_vect vect, int left)
{
	t_double_vect	new_vect;

	if (left)
	{
		new_vect.x = data->rc->rot.x * vect.x
			- data->rc->rot.y * vect.y;
		new_vect.y = data->rc->rot.y * vect.x
			+ data->rc->rot.x * vect.y;
	}
	else
	{
		new_vect.x = data->rc->rot.x * vect.x
			+ data->rc->rot.y * vect.y;
		new_vect.y = -data->rc->rot.y * vect.x
			+ data->rc->rot.x * vect.y;
	}
	return (new_vect);
}
