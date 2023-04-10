/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 21:41:26 by lle-bret          #+#    #+#             */
/*   Updated: 2023/04/10 18:08:49 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_data		data;

	if (ac < 2)
		ft_error(NULL, "Must provide a data file to launch the game");
	init_data(&data);
	parse_file(*(av + 1), &data);
	if (!data.map->content || !*data.map->content)
		ft_error(NULL, "Parsing of the file failed");
	launch_game(&data);
	return (0);
}

void	launch_game(t_data	*data)
{
	void		*mlx;
	void		*win;

	mlx = mlx_init();
	if (!mlx)
		ft_error(data, MLX_ERROR);
	data->mlx = mlx;
	win = mlx_new_window(mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT, "Welcome to Cub3d!");
	data->win = win;
	if (!win)
		ft_error(data, MLX_ERROR);
	init_images(data);
	init_screen(data);
	raycaster(data, 0, WINDOW_WIDTH);
	mlx_mouse_get_pos(data->win, &data->mouse.x, &data->mouse.y);
	mlx_hook(win, 2, (1L << 0), &handle_key, data);
	mlx_hook(win, 17, (1L << 1), &end_game, data);
	mlx_loop(mlx);
}
