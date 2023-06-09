/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:31:03 by lle-bret          #+#    #+#             */
/*   Updated: 2023/04/10 18:08:07 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	free_texture(t_data *data)
{
	int	i;

	if (data->texture)
	{
		i = 0;
		while (i < 4)
		{
			if (data->texture[i].img)
				mlx_destroy_image(data->mlx, data->texture[i].img);
			++i;
		}
		free(data->texture);
	}
}

int	end_game(t_data *data)
{
	free_texture(data);
	if (data->screen)
	{
		if (data->screen->img)
			mlx_destroy_image(data->mlx, data->screen->img);
		free(data->screen);
	}
	if (data->rc)
		free(data->rc);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		free(data->mlx);
	}
	free_map(data->map);
	ft_free((void **) data->store_data, 6);
	exit(0);
	return (0);
}
