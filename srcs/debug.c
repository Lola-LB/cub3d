/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:49:43 by lle-bret          #+#    #+#             */
/*   Updated: 2023/03/29 18:42:48 by lle-bret         ###   ########.fr       */
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
	printf("\nmap:\nx=%i y=%i\n", data->rc->square.x, data->rc->square.y);
	printf("rayDir:\n");
	print_vect(data->rc->rayDir);
	printf("sideDist:\n");
	print_vect(data->rc->sideDist);
	printf("deltaDist:\n");
	print_vect(data->rc->deltaDist);
	printf("step:\n");
	print_vect(data->rc->step);
	printf("side: %i\n", data->rc->side);
	printf("perpWallDist:\n %f\n", data->rc->perpWallDist);
	printf("lineheight:\n %i\n", data->rc->lineHeight);
	printf("drawStart=%i drawEnd=%i\n\n", data->rc->drawStart, data->rc->drawEnd);
}