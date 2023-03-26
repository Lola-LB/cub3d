/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 21:41:26 by lle-bret          #+#    #+#             */
/*   Updated: 2023/03/26 19:00:11 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_param		param;

	if (ac < 2)
		ft_error(NULL, "Must provide a data file to launch the game");
	init_param(&param);
	parse_file(*(av + 1), &param);
	if (!param.map.content || !*param.map.content)
		ft_error(NULL, "Parsing of the file failed");
	// printf("len: %d width: %d\n", param.map.len, param.map.width);
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
			param->map.len * NB_PIXEL, "Welcome to Cub3d!");
	param->win = win;
	if (!win)
		ft_error(param, MLX_ERROR);
	init_images(param);
	// images_to_map(param);
	// mlx_hook(win, 2, (1L << 0), &handle_key, param);
	mlx_hook(win, 17, (1L << 1), &end_game, param);
	mlx_loop(mlx);
}
