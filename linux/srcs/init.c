/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:45:07 by lle-bret          #+#    #+#             */
/*   Updated: 2023/05/17 17:13:30 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_id(t_data *data)
{
	data->identifiers[0] = "NO ";
	data->identifiers[1] = "SO ";
	data->identifiers[2] = "WE ";
	data->identifiers[3] = "EA ";
	data->identifiers[4] = "F ";
	data->identifiers[5] = "C ";
}

void	init_data(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->map = malloc(sizeof(t_map));
	if (!data->map)
		ft_error(data, MALLOC_ERROR);
	data->map->content = NULL;
	data->screen = (t_img *) ft_calloc(sizeof(t_img), 1);
	if (!data->screen)
		ft_error(data, MALLOC_ERROR);
	data->rc = malloc(sizeof(t_raycaster));
	if (!data->rc)
		ft_error(data, MALLOC_ERROR);
	set_id(data);
	data->floor_color = -1;
	data->ceiling_color = -1;
	data->move_speed = 0.05;
	data->rotate_speed = WINDOW_WIDTH / 50;
	data->alpha = 0.5;
	data->screen->img = NULL;
	data->texture = NULL;
	data->store_data = (char **) ft_calloc(6, sizeof(char *));
	if (!data->store_data)
		ft_error(data, MALLOC_ERROR);
}

void	init_images(t_data *data)
{
	int		i;

	data->texture = (t_img *) ft_calloc(sizeof(t_img), 4);
	if (!data->texture)
		ft_error(data, MALLOC_ERROR);
	i = 0;
	while (i < 4)
	{
		data->texture[i].img = mlx_xpm_file_to_image(data->mlx,
				data->store_data[i], &data->texture[i].width,
				&data->texture[i].height);
		if (!data->texture[i].img)
			ft_error(data, FILE_ERROR);
		data->texture[i].addr = mlx_get_data_addr(data->texture[i].img,
				&data->texture[i].bpp, &data->texture[i].line_length,
				&data->texture[i].endian);
		++i;
	}
}

void	init_screen(t_data *data)
{
	data->screen->img = mlx_new_image(data->mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT);
	if (!data->screen->img)
		ft_error(data, MLX_ERROR);
	data->screen->addr = mlx_get_data_addr(data->screen->img,
			&data->screen->bpp, &data->screen->line_length,
			&data->screen->endian);
	data->screen->height = WINDOW_HEIGHT;
	data->screen->width = WINDOW_WIDTH;
}
