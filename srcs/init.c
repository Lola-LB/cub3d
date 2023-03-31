/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:45:07 by lle-bret          #+#    #+#             */
/*   Updated: 2023/03/31 13:00:49 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	init_data(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->map = malloc(sizeof(t_map));
	if (!data->map)
		ft_error(data, MALLOC_ERROR);
	data->map->content = NULL;
	data->column = (t_img *) ft_calloc(sizeof(t_img), 1);
	if (!data->column)
		ft_error(data, MALLOC_ERROR);
	data->screen = (t_img *) ft_calloc(sizeof(t_img), 1);
	if (!data->screen)
		ft_error(data, MALLOC_ERROR);
	data->rc = malloc(sizeof(t_raycaster));
	if (!data->rc)
		ft_error(data, MALLOC_ERROR);
	data->identifiers[0] = "NO ";
	data->identifiers[1] = "SO ";
	data->identifiers[2] = "WE ";
	data->identifiers[3] = "EA ";
	data->identifiers[4] = "F ";
	data->identifiers[5] = "C ";
	data->floor_color = -1;
	data->ceiling_color = -1;
	data->moveSpeed = 0.05;
	data->rotateSpeed = WINDOW_WIDTH / 50;
	data->rc->rot.x = cos(1.1519 * (data->rotateSpeed / WINDOW_WIDTH));
	data->rc->rot.y = sin(1.1519 * (data->rotateSpeed / WINDOW_WIDTH));
	data->end_game = 0;
	data->screen->img = NULL;
	data->texture = (t_img *) ft_calloc(6, sizeof(t_img));
	if (!data->texture)
		ft_error(data, MALLOC_ERROR);
}

void	init_images(t_data *data)
{
	int		i;

	data->texture = (t_img *) ft_calloc(sizeof(t_img), 4);;
	if (!data->texture)
		ft_error(data, MALLOC_ERROR);
	i = 0;
	while (i < 4)
	{
		data->texture[i].img = mlx_xpm_file_to_image(data->mlx, data->store_data[i],
				&data->texture[i].width, &data->texture[i].height);
		if (!data->texture[i].img)
			ft_error(data, FILE_ERROR);
		data->texture[i].addr = mlx_get_data_addr(data->texture->img,
			&data->texture[i].bpp, &data->texture[i].line_length,
			&data->texture[i].endian);
		++i;
	}
	data->screen->img = mlx_new_image(data->mlx, WINDOW_WIDTH,
		WINDOW_HEIGHT);
	data->screen->addr = mlx_get_data_addr(data->screen->img,
		&data->screen->bpp, &data->screen->line_length,
		&data->screen->endian);
	data->screen->height = WINDOW_HEIGHT;
	data->screen->width = WINDOW_WIDTH;
	data->column->img = mlx_new_image(data->mlx, data->rotateSpeed,
		WINDOW_HEIGHT);
	data->column->height = WINDOW_HEIGHT;
	data->column->width = data->rotateSpeed;
	data->column->addr = mlx_get_data_addr(data->column->img,
		&data->column->bpp, &data->column->line_length,
		&data->column->endian);
}

