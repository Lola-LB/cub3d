/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:49:43 by lle-bret          #+#    #+#             */
/*   Updated: 2023/03/29 17:47:39 by lle-bret         ###   ########.fr       */
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

void	print_rc(t_raycaster rc)
{
	printf("\nmap:\nx=%i y=%i\n", rc.map.x, rc.map.y);
	printf("rayDir:\n");
	print_vect(rc.rayDir);
	printf("sideDist:\n");
	print_vect(rc.sideDist);
	printf("deltaDist:\n");
	print_vect(rc.deltaDist);
	printf("step:\n");
	print_vect(rc.step);
	printf("side: %i\n", rc.side);
	printf("perpWallDist:\n %f\n", rc.perpWallDist);
	printf("lineheight:\n %i\n", rc.lineHeight);
	printf("drawStart=%i drawEnd=%i\n\n", rc.drawStart, rc.drawEnd);
}