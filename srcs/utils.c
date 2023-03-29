/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:31:03 by lle-bret          #+#    #+#             */
/*   Updated: 2023/03/29 16:31:47 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	data->identifiers[0] = "NO ";
	data->identifiers[1] = "SO ";
	data->identifiers[2] = "WE ";
	data->identifiers[3] = "EA ";
	data->identifiers[4] = "F ";
	data->identifiers[5] = "C ";
	data->floor_color = -1;
	data->ceiling_color = -1;
	data->end_game = 0;
	data->screen->img = NULL;
	data->texture = (t_img *) ft_calloc(6, sizeof(t_img));
	if (!data->texture)
		ft_error(data, MALLOC_ERROR);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->content)
	{
		while (i < map->len)
		{
			free(map->content[i]);
			++i;
		}
		free(map->content);
	}
	free(map);
}

void	ft_error(t_data *data, char *error)
{
	printf("Error\n%s\n", error);
	if (data)
		end_game(data);
	exit(0);
}

int	end_game(t_data *data)
{
	int	i;

	if (data->texture)
	{
		i = 0;
		while (i < 6)
		{
			// if (data->texture[i].img)
			// 	mlx_destroy_image(data->mlx, data->texture[i].img);
			++i;
		}
		free(data->texture);
	}
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		// mlx_destroy_display(data->mlx); ??
		free(data->mlx);
	}
	free_map(data->map);
	ft_free((void **) data->store_data, 6);
	exit(0);
	return (0); //end_game needs to be of type 'int (*)()'
}
