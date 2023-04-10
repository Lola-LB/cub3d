/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:21:49 by lle-bret          #+#    #+#             */
/*   Updated: 2023/04/10 18:09:02 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_move(t_data *data, t_double_vect new_pos)
{
	int	x;
	int	y;

	x = (int) floor(new_pos.x);
	y = (int) floor(new_pos.y);
	if (x < 1 || y < 1 || x >= data->map->width || y >= data->map->len)
		return (0);
	if (data->map->content[y][x] == '1')
		return (0);
	return (1);
}

void	move_player(int keysym, t_data *data)
{
	t_double_vect	new_pos;
	double			alpha;
	int				way;

	mlx_mouse_get_pos(data->win, &data->mouse.x, &data->mouse.y);
	alpha = (2 * (double) data->mouse.x / (double) WINDOW_WIDTH - 1) * -1.1519;
	new_pos = data->rc->player;
	rotate_view(data, alpha);
	way = (keysym == W) + (keysym == D) - (keysym == S) - (keysym == A);
	if (keysym == W || keysym == S)
		new_pos = vect_sum(new_pos, scalar_mult(data->rc->dir,
					data->move_speed * way));
	else if (keysym == A || keysym == D)
		new_pos = vect_sum(new_pos, scalar_mult(data->rc->plane,
					data->move_speed * way));
	if (check_move(data, new_pos))
	{
		data->rc->player = new_pos;
		raycaster(data, 0, WINDOW_WIDTH);
	}
}

void	rotate_view(t_data *data, double alpha)
{
	data->rc->dir = rotate_vect(data, data->rc->dir, alpha);
	data->rc->plane = rotate_vect(data, data->rc->plane, alpha);
	raycaster(data, 0, WINDOW_WIDTH);
}

// printf("%i\n", keysym);
int	handle_key(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		end_game(data);
	else if (keysym == W || keysym == A || keysym == S || keysym == D)
		move_player(keysym, data);
	else if (keysym == DEBUG)
		print_rc(data);
	else if (keysym == RIGHT)
		rotate_view(data, -data->alpha);
	else if (keysym == LEFT)
		rotate_view(data, data->alpha);
	return (0);
}
