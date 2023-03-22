/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 21:41:26 by lle-bret          #+#    #+#             */
/*   Updated: 2023/02/07 17:25:19 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int ac, char **av)
{
	t_param		param;
	t_map		map;

	if (ac < 2)
		ft_error(NULL, "Must provide a map to launch the game");
	map = parse_map(*(av + 1));
	if (!map.map || !*map.map)
	{
		free_map(map);
		ft_error(NULL, "Parsing of the map failed");
	}
	init_param(&param, map);
	launch_game(&param);
	return (0);
}

void	launch_game(t_param	*param)
{
	void		*mlx;
	void		*win;

	mlx = mlx_init();
	if (!mlx)
		ft_error(param, MLX_ERROR);
	param->mlx = mlx;
	win = mlx_new_window(mlx, param->map.width * NB_PIXEL,
			param->map.len * NB_PIXEL, "Welcome to So Long !");
	param->win = win;
	if (!win)
		ft_error(param, MLX_ERROR);
	init_images(param);
	images_to_map(param);
	mlx_loop_hook(mlx, &handle_live, param);
	mlx_hook(win, 2, (1L << 0), &handle_key, param);
	mlx_hook(win, 17, (1L << 1), &end_game, param);
	mlx_loop(mlx);
}

void	free_mlx(t_param *param)
{
	if (param && param->win)
		mlx_destroy_window(param->mlx, param->win);
	if (param && param->mlx)
	{
		mlx_destroy_display(param->mlx);
		free(param->mlx);
	}
}

int	end_game(t_param *param)
{
	int	i;

	if (param && param->img)
	{
		i = 0;
		while (i < NB_FILES)
		{
			if (param->img[i].img)
				mlx_destroy_image(param->mlx, param->img[i].img);
			++i;
		}
		free(param->img);
	}
	free_mlx(param);
	if (param)
	{
		free_map(param->map);
		free_enemy(param);
	}
	exit(0);
	return (0);
}
