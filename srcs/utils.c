/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:31:03 by lle-bret          #+#    #+#             */
/*   Updated: 2023/03/26 19:01:17 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_param(t_param *param)
{
	param->mlx = NULL;
	param->win = NULL;
	param->map.content = NULL;
	param->identifiers[0] = "NO ";
	param->identifiers[1] = "SO ";
	param->identifiers[2] = "WE ";
	param->identifiers[3] = "EA ";
	param->identifiers[4] = "F ";
	param->identifiers[5] = "C ";
	param->floor_color.R = -1;
	param->ceiling_color.R = -1;
	param->end_game = 0;
	param->texture = (t_img *) ft_calloc(6, sizeof(t_img));
	if (!param->texture)
		ft_error(param, MALLOC_ERROR);
}

void	init_images(t_param *param)
{
	int		i;

	param->texture = (t_img *) ft_calloc(sizeof(t_img), 4);;
	if (!param->texture)
		ft_error(param, MALLOC_ERROR);
	i = 0;
	while (i < 6)
	{
		param->texture[i].img = mlx_xpm_file_to_image(param->mlx, param->store_data[i],
				&param->texture[i].width, &param->texture[i].height);
		if (!param->texture[i].img)
			ft_error(param, FILE_ERROR);
		++i;
	}
}

void	free_map(t_map map)
{
	int	i;

	i = 0;
	while (i < map.len)
	{
		free(map.content[i]);
		++i;
	}
	free(map.content);
}

void	ft_error(t_param *param, char *error)
{
	printf("Error\n%s\n", error);
	if (param)
		end_game(param);
	exit(0);
}

int	end_game(t_param *param)
{
	int	i;

	if (param->texture)
	{
		i = 0;
		while (i < 6)
		{
			if (param->texture[i].img)
				mlx_destroy_image(param->mlx, param->texture[i].img);
			++i;
		}
		free(param->texture);
	}
	if (param->win)
		mlx_destroy_window(param->mlx, param->win);
	if (param->mlx)
	{
		// mlx_destroy_display(param->mlx); ??
		free(param->mlx);
	}
	free_map(param->map);
	ft_free((void **) param->store_data, 6);
	exit(0);
	return (0); //end_game needs to be of type 'int (*)()'
}
